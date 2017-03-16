using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Google_Code
{
    class Program
    {
        const string root = @"B:\Users\Justin\Desktop\Temp\Google Code\ConsoleApplication4\";
        static void Main(string[] args)
        {
            var reader = new StreamReader(root + "in.txt");
            var writer = new StreamWriter(root + "out.txt", false);

            int numCases = int.Parse(reader.ReadLine());
            for (int cc = 1; cc <= numCases; cc++)
            {
                int numBlocks = int.Parse(reader.ReadLine());
                double[] b1 = reader.ReadLine().Split(' ').Select(p => double.Parse(p)).OrderBy(p => p).ToArray();
                double[] b2 = reader.ReadLine().Split(' ').Select(p => double.Parse(p)).OrderBy(p => p).ToArray();

                int warWins = War(b1, b2);
                int deceitWins = Deceit(b1, b2);

                Console.WriteLine(string.Format("Case #{0}: {1} {2}", cc, deceitWins, warWins));
                writer.WriteLine(string.Format("Case #{0}: {1} {2}", cc, deceitWins, warWins));
            }
            
            writer.Flush();
            writer.Close();
            //Console.ReadKey();
        }

        private static int Deceit(double[] ab, double[] bb)
        {
            int wins = 0;
            var abList = ab.ToList();
            var b2List = bb.ToList();
            for (int i = 0; i < ab.Length; i++)
            {
                double bChosen = b2List[0]; // always choose the smallest number.
                b2List.RemoveAt(0); // remove smallest element
                                                                                  /// 
                double aChosen = abList.Where(p => p > bChosen).FirstOrDefault();

                if (aChosen == 0)
                {
                    abList.RemoveAt(0); // remove smallest element if nothing found above it.
                }
                else
                {
                    wins++;
                    abList.Remove(aChosen);
                }
            }
            return wins;
        }


        private static int War(double[] ab, double[] bb)
        {
            int wins = 0;
            
            var b2List = bb.ToList();
            for (int i = 0; i < ab.Length; i++)
            {
                double aChosen = ab[ab.Length-i-1]; // go by descending

                double bChosen = b2List.Where(p => p > aChosen).FirstOrDefault(); /// relies on sort

                if (bChosen == 0)
                {
                    wins++;
                    b2List.RemoveAt(0); // remove smallest element
                }
                else
                {
                    b2List.Remove(bChosen);
                }
            }
            return wins;
        }

    }
}
