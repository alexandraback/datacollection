using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// Program written by Teun van Gils
// All rights reserved (c) 2014
namespace _D__Deceitful_War
{
    class Program
    {
        static void Main(string[] args)
        {
            // Fix globalization
            System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.CreateSpecificCulture("en-US");
            // Number of games
            int T = Int32.Parse(Console.ReadLine());
            // Set up output file
            TextWriter writer = new StreamWriter("out.txt", false);
            for (int t = 1; t <= T; t++)
            {
                // Output case number
                writer.Write("Case #" + t + ": ");
                // Read the data
                int N = Int32.Parse(Console.ReadLine());
                C5.TreeSet<double>[] Naomi = new C5.TreeSet<double>[2], Ken = new C5.TreeSet<double>[2];
                foreach (C5.TreeSet<double>[] set in new C5.TreeSet<double>[][] { Naomi, Ken })
                {
                    List<double> list = Console.ReadLine().Split(' ').ToList().ConvertAll(Double.Parse);
                    for (int i = 0; i < 2; i++)
                    {
                        set[i] = new C5.TreeSet<double>();
                        set[i].AddAll(list);
                    }   
                }
                // Set variables
                int normalScore = 0, deceitfulScore = 0;
                // Calculate the result
                // The normal War, played optimally
                while (Naomi[0].Count > 0)
                {
                    double chosenNaomi = Naomi[0].DeleteMax();
                    double chosenKen   = Ken[0].FindMax() > chosenNaomi ? Ken[0].Successor(chosenNaomi) : Ken[0].FindMin();
                    Ken[0].Remove(chosenKen);
                    if (chosenNaomi > chosenKen)
                        normalScore++;
                }
                // The deceitful War, where Naomi cheats
                double highest = 1;
                while (Naomi[1].Count > 0)
                {
                    double NaomiSucc, chosenNaomi, toldNaomi;
                    if (Naomi[1].TrySuccessor(Ken[1].FindMin(), out NaomiSucc)) {
                        chosenNaomi = NaomiSucc;
                        toldNaomi = (Ken[1].FindMax() + highest) / 2;
                        highest = toldNaomi;
                    } else {
                        toldNaomi = chosenNaomi = Naomi[1].FindMin();
                    }
                    Naomi[1].Remove(chosenNaomi);
                    double chosenKen = Ken[1].FindMax() > toldNaomi ? Ken[1].Successor(toldNaomi) : Ken[1].FindMin();
                    Ken[1].Remove(chosenKen);
                    if (chosenNaomi > chosenKen)
                        deceitfulScore++;
                }
                // Output the result
                writer.WriteLine(deceitfulScore + " " + normalScore);
            }
            // EOF
            writer.Close();
        }
    }
}
