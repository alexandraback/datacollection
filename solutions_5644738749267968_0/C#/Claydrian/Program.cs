using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codejam
{
    class Program
    {

        static void Main(string[] args)
        {
            // Your submission system killed my google chrome.
            // IE 8 was fine!
            string path = "D-small-attempt1.in";
            System.IO.StreamReader reader = new System.IO.StreamReader(path);
            System.IO.StreamWriter output = new System.IO.StreamWriter("output.txt");
            int testCases = int.Parse(reader.ReadLine());
            for (int i = 0; i < testCases; i++)
            {
                output.Write("Case #");
                output.Write(i + 1);
                output.Write(": ");
                int N = int.Parse(reader.ReadLine());

                var naomi = readRow(reader.ReadLine());
                var ken = readRow(reader.ReadLine());
                var warWins = optimalWar(naomi, ken);
                var deceitfulWar = optimalDeceitfulWar(naomi, ken);
                output.WriteLine(deceitfulWar + " " + warWins);
            }
            output.Close();
            reader.Close();
        }

        static int optimalDeceitfulWar(IEnumerable<double> naomi, IEnumerable<double> ken)
        {
            int wins = 0;
            List<double> ken1 = ken.OrderByDescending(d => d).ToList();
            List<double> naomi1 = naomi.ToList();
            while (ken1.Count > 0)
            {
                if (ken1.Count == 1)
                {
                    if (naomi1[0] > ken1[0])
                    {
                        wins++;
                    }
                    ken1.RemoveAt(0);
                }
                else
                {
                    var biggestNaomi = naomi1.OrderByDescending(d => d).First();
                    var smallestNaomi = naomi1.OrderBy(d => d).First();
                    if (biggestNaomi < ken1[0])
                    {
                        naomi1.Remove(smallestNaomi);
                        ken1.RemoveAt(0);
                    }
                    else
                    {
                        var smallestKen = ken1[ken1.Count - 1];
                        var naomisWinner = naomi1.OrderBy(d => d).FirstOrDefault(d => d > smallestKen);
                        if ( naomisWinner == 0 )
                        {
                            naomi1.Remove(smallestNaomi);
                        }
                        else
                        {
                            wins++;
                            naomi1.Remove(naomisWinner);
                        }
                        ken1.RemoveAt(ken1.Count - 1);
                    }
                    

                }
            }

            return wins;
        }

        static int optimalWar(IEnumerable<double> naomi, IEnumerable<double> ken )
        {
            List<double> ken1 = ken.OrderBy(d => d).ToList();
            int wins = 0;
            foreach( double d in naomi.OrderByDescending(d => d) ) 
            {
                var kensChoice = ken1.FirstOrDefault(k => k > d);
                if (kensChoice == 0.0)
                {
                    ken1.RemoveAt(0);
                    wins++;
                }
                else
                {
                    ken1.Remove(kensChoice);
                }
            }
            return wins;
        }

        static IEnumerable<double> readRow(string row)
        {
            return row.Split(' ').Select(s => double.Parse(s));
        }
    }
}
