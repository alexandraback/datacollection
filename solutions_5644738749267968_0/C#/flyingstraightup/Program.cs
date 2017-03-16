using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace google_war
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamWriter writer = new StreamWriter("result.txt");
            using (StreamReader reader = new StreamReader("D-small-attempt2.in"))
            {
                int numGames = Int32.Parse(reader.ReadLine());

                for (int i = 0; i < numGames; i++)
                {
                    // read in pattern
                    int numBlocks = Int32.Parse(reader.ReadLine());     // don't need this, prob

                    List<Double> NaomiBlocks = reader.ReadLine().Split(' ').Select(Double.Parse).ToList();
                    List<Double> KenBlocks = reader.ReadLine().Split(' ').Select(Double.Parse).ToList();
                    NaomiBlocks.Sort();
                    KenBlocks.Sort();

                    // calculate game
                    string result = "Case #" + (i + 1).ToString() + ": " + DeceitfulWar(NaomiBlocks, KenBlocks).ToString() 
                        + " " + NormalWar(NaomiBlocks, KenBlocks).ToString();
                    writer.WriteLine(result);

                    // *** debug
                    /*
                    StringBuilder builder = new StringBuilder();
                    foreach (Double n in NaomiBlocks)
                    {
                        // Append each int to the StringBuilder overload.
                        builder.Append(n).Append(" ");
                    }
                    writer.WriteLine(builder.ToString());
                    builder = new StringBuilder();
                    foreach (Double n in KenBlocks)
                    {
                        // Append each int to the StringBuilder overload.
                        builder.Append(n).Append(" ");
                    }
                    writer.WriteLine(builder.ToString());
                    */
                }
            }

            writer.Close();
        }

        static int DeceitfulWar(List<Double> naomi, List<Double> ken)
        {
            int result = naomi.Count();
            int kenSmallest = 0;

            for (int i = 0; i < naomi.Count(); i++)
            {
                if (naomi[i] < ken[kenSmallest])
                {
                    // can't win this one
                    result--;
                }
                else
                {
                    // won this one
                    kenSmallest++;
                }
            }

            return result;
        }

        static int NormalWar(List<Double> naomi, List<Double> ken)
        {
            int result = naomi.Count();

            int kenFirst = 0;
            int kenLast = ken.Count() - 1;
            int naomiLast = naomi.Count() - 1;

            while (kenFirst <= kenLast)
            {
                // naomi's biggest > ken's biggest
                if (ken[kenLast] < naomi[naomiLast])
                {
                    naomiLast--;    // naomi uses up biggest block
                    kenFirst++;     // ken uses up smallest block
                }
                else
                {
                    // ken's biggest > naomi's biggest
                    result--;       // ken gets a point
                    kenLast--;      // ken uses up biggest block
                    naomiLast--;    // naomi uses up biggest block
                }
            }

            return result;
        }
    }
}
