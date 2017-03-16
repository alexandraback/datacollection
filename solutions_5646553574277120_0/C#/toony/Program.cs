using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SolveT9
{
    class Program
    {

        static Dictionary<char, KeyValuePair<char, int>> sources = new Dictionary<char, KeyValuePair<char, int>>();

        static void Main(string[] args)
        {
            int counter = 1;
            string line;
            String[] files = Directory.GetFiles(@"C:\googleJam", "*.in");
            System.IO.StreamReader file = new System.IO.StreamReader(files[0]);
            StreamWriter resultFile = new StreamWriter(files[0].Replace(".in", ".out"));
            file.ReadLine();
            while ((line = file.ReadLine()) != null)
            {
                //int nbCoups = 0;
                System.Console.WriteLine(line);
                String[] c = line.Split(' ');
                int C = Convert.ToInt32(c[0]);
                int D = Convert.ToInt32(c[1]);
                int ValueMax = Convert.ToInt32(c[2]);

                line = file.ReadLine();
                List<int> currencies = line.Split(' ').Select(d => Convert.ToInt32(d)).ToList();
                int nbCurrencies = currencies.Count;
                int currencyMerge = ((int)Math.Pow(2, nbCurrencies)) - 1;

                List<int> bordels = new List<int>();
                bordels.Add(0);

                for (int j = 1; j <= currencyMerge; j++)
                {
                    int nb = 0;    
                    for (int a = 0; a < nbCurrencies; a++)
                        if ((j & (int)Math.Pow(2, a)) == (int)Math.Pow(2, a)) nb += currencies[a];
                    if (nb > ValueMax) break;
                    bordels.Add(nb);
                }

                int nbCoups = 0;

                for (int v = 1; v <= ValueMax; v++)
                {
                    if (bordels.Contains(v)) continue;
                    List<int> bordelsplus = bordels.Where(d => ((d + v) <= ValueMax)).Select(d => d + v).ToList();
                    bordels.AddRange(bordelsplus);
                    bordels.Sort();
                    bordels = bordels.Distinct().ToList();
                    nbCoups++;
                    if ((bordels.Count - 1) == ValueMax)
                        break;
                }
                
                resultFile.WriteLine("Case #" + counter + ": " + nbCoups);
                counter++;
            }
            file.Close();
            resultFile.Flush();
            resultFile.Close();
            System.Console.WriteLine("There were {0} lines.", counter);
            System.Console.ReadLine();
        }


    }
}
