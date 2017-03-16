using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
//            string fileName = "test";
    //        string fileName = "input";
        //    string fileName = "D-small-attempt0";
             string fileName = "D-large";

            string line;

            System.IO.StreamReader inFile =
               new System.IO.StreamReader(fileName + ".in");
            System.IO.StreamWriter outFile = 
                new System.IO.StreamWriter(fileName + ".out");

            line = inFile.ReadLine();

            int testcases;
            bool success = int.TryParse(line, out testcases);

            for (int i = 0; i < testcases; i++)
            {
                solveSingleTestcase(inFile, outFile, i + 1);
            }

            inFile.Close();
            outFile.Close();

            Console.ReadLine();
        }

        private static void solveSingleTestcase(System.IO.StreamReader inFile, System.IO.StreamWriter outFile, int testcaseNumber)
        {
            string line = inFile.ReadLine();

            int blocks;
            int.TryParse(line, out blocks);

            line = inFile.ReadLine();
            string[] tokensW1 = line.Split();
            line = inFile.ReadLine();
            string[] tokensW2 = line.Split();

            double[] w1 = new double[blocks];
            double[] w2 = new double[blocks];
            for (int i = 0; i < blocks; i++)
            {
                double.TryParse(tokensW1[i], NumberStyles.Any, CultureInfo.InvariantCulture, out w1[i]);
                double.TryParse(tokensW2[i], NumberStyles.Any, CultureInfo.InvariantCulture, out w2[i]);

//                Console.Write(w1[i] + " " + w2[i] + "; ");
            }

           Console.Write("Case #" + testcaseNumber + ": ");
           outFile.Write("Case #" + testcaseNumber + ": ");

            double[] w11 = new double[blocks];
            double[] w12 = new double[blocks];
            double[] w21 = new double[blocks];
            double[] w22 = new double[blocks];
            Array.Copy(w1, w11, blocks);
            Array.Copy(w1, w12, blocks);
            Array.Copy(w2, w21, blocks);
            Array.Copy(w2, w22, blocks);

            int deceitfulWarScore = playDeceitfulWar(w11, w21, blocks);
            int warScore = playWar(w12, w22, blocks);

            Console.WriteLine(deceitfulWarScore + " " + warScore);
            outFile.WriteLine(deceitfulWarScore + " " + warScore);
        }

        private static int playDeceitfulWar(double[] naomi, double[] ken, int blocks)
        {
            Array.Sort(naomi);
            Array.Sort(ken);

            int naomiScore = 0;


            for (int i = 0; i < blocks; i++)
            {
/*                 Console.WriteLine("Round " + (i + 1));
                Console.Write("Naomi: ");
                for (int k = 0; k < naomi.Length; k++)
                {
                    Console.Write(naomi[k] + " ");
                }
                Console.WriteLine();

                Console.Write("Ken: ");
                for (int k = 0; k < ken.Length; k++)
                {
                    Console.Write(ken[k] + " ");
                }
                Console.WriteLine(); */

                double naomiWeight = -1;
                double kenWeight = -1; 
                
                // has naomi anything that can score? 
                double kenMin = ken[0];

                int naomiChoice = -1;
                for (int j = 0; j < naomi.Length; j++)
                {
                    if (naomi[j] > kenMin)
                    {
                        // naomi can score

                        naomiChoice = j;
                        naomiWeight = naomi[j];
                        naomi = removeWeight(naomi, j);

                        kenWeight = ken[0];
                        ken = removeWeight(ken, 0);

                        break;
                    }
                }

                if (naomiChoice == -1)
                {
                    // naomi can NOT score
                    naomiWeight = naomi[0];
                    naomi = removeWeight(naomi, 0);

                    kenWeight = ken[ken.Length - 1];
                    ken = removeWeight(ken, ken.Length - 1);
                }




/*                // can naomi score? 
                double kenMax = ken[ken.Length - 1];
                double naomiMax = naomi[naomi.Length - 1];

                if (naomiMax > kenMax)
                {
                    // naomi can score, play the highest block, ken plays the lowest... ########## naomi can play a lower one then!
                    naomiWeight = naomi[naomi.Length - 1];
                    naomi = removeWeight(naomi, naomi.Length - 1);

                    kenWeight = ken[0];
                    ken = removeWeight(ken, 0);

                    Console.WriteLine("naomi can score, plays " + naomiWeight + ". ken plays " + kenWeight);
                }
                else
                {
                    // naomi can't score, play the lowest block, ken plays his highest
                    naomiWeight = naomi[0];
                    naomi = removeWeight(naomi, 0);

                    kenWeight = ken[ken.Length - 1];
                    ken = removeWeight(ken, ken.Length - 1);

                    Console.WriteLine("naomi can NOT score, plays " + naomiWeight + ". ken plays " + kenWeight);
                }*/

                if (naomiWeight > kenWeight)
                {
                    naomiScore++;
                }
            }

            return naomiScore;
        }

        private static int playWar(double[] naomi, double[] ken, int blocks)
        {
//            Console.WriteLine("War: ");
            Array.Sort(naomi);
            Array.Sort(ken);

            int naomiScore = 0, kenScore = 0;

            for (int i = 0; i < blocks; i++)
            {
/*                Console.WriteLine("Round " + (i + 1));
                Console.Write("Naomi: ");
                for (int k = 0; k < naomi.Length; k++)
                {
                    Console.Write(naomi[k] + " ");
                }
                Console.WriteLine();

                Console.Write("Ken: ");
                for (int k = 0; k < ken.Length; k++)
                {
                    Console.Write(ken[k] + " ");
                }
                Console.WriteLine();*/


                double naomiWeight = -1;
                double kenWeight = -1; 

                // Naomi's turn
                naomiWeight = naomi[naomi.Length - 1];
                naomi = removeWeight(naomi, naomi.Length - 1);
//                naomiWeight = naomi[0];
  //              naomi = removeWeight(naomi, 0);

                // Ken's turn
                for (int j = 0; j < ken.Length; j++)
                {
                    if (ken[j] > naomiWeight)
                    {
                        kenWeight = ken[j];
                        ken = removeWeight(ken, j);
                        break;
                    }
                }

                if (kenWeight == -1)
                {
                    kenWeight = ken[0];
                    ken = removeWeight(ken, 0);
                }

//                Console.WriteLine("naomi: " + naomiWeight + ", ken: " + kenWeight);
                if (naomiWeight > kenWeight)
                {
                    naomiScore++;
                }
                else
                {
                    kenScore++;
                }
            }

            return naomiScore;
        }

        private static double[] removeWeight(double[] weights, int p)
        {
            for (int i = p; i < weights.Length - 1; i++)
            {
                weights[i] = weights[i + 1];
            }
            Array.Resize(ref weights, weights.Length - 1);
            return weights;
        }
    }
}
