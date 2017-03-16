using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SafetyInNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            int numTestCases = Convert.ToInt32(Console.ReadLine());

            for (int testCases = 0; testCases < numTestCases; testCases++)
            {

                string items = Console.ReadLine();
                string[] itemsStr_a = items.Split(' ');
                int numConts = Convert.ToInt32(itemsStr_a[0]);
                double[] judgeScores_a = new double[numConts];
                double judgeTotal = 0;
                for (int loopCnt = 0; loopCnt < numConts; loopCnt++)
                {
                    judgeScores_a[loopCnt] = Convert.ToInt32(itemsStr_a[loopCnt+1]);
                    judgeTotal += judgeScores_a[loopCnt];
                }
                Console.Write("Case #{0:d}:", testCases + 1);
                double requiredPoints = judgeTotal * 2 / numConts;
                double voteBetween = numConts;
                double origJT = judgeTotal;
                for (int loopCnt = 0; loopCnt < numConts; loopCnt++)
                {
                    if (requiredPoints - judgeScores_a[loopCnt] <= 0)
                    {
                        judgeTotal -= judgeScores_a[loopCnt];
//                        requiredPoints -= (judgeScores_a[loopCnt] / numConts);
                        voteBetween--;
                    }
                }

                requiredPoints = (origJT + judgeTotal) / voteBetween;
                double outputTot = 0;
                for (int loopCnt = 0; loopCnt < numConts; loopCnt++)
                {
                    if (judgeTotal != 0)
                        {
                            Console.Write(" {0:f6}", Math.Max(100.0 * (requiredPoints - judgeScores_a[loopCnt]) / origJT, 0.0));
                            outputTot += Math.Max(100.0 * (requiredPoints - judgeScores_a[loopCnt]) / origJT, 0.0);
                        }
                        else
                        {
                            if (judgeScores_a[loopCnt] > 0)
                            {
                                Console.Write(" {0:f6} ", 0.0);
                            }
                            else
                            {
                                Console.Write(" {0:f6}", 100.0 / voteBetween);
                                outputTot += (100.0 / voteBetween);
                            }
                        }
                    /*                    if (judgeTotal != 0)
                                        {
                                            Console.Write(" {0:f6}", Math.Max(100.0 * (requiredPoints - judgeScores_a[loopCnt]) / judgeTotal, 0.0));
                                        }
                                        else
                                        {
                                            if (judgeScores_a[loopCnt] > 0)
                                            {
                                                Console.Write("{0:f6} ", 0.0);
                                            }
                                            else
                                            {
                                                Console.Write(" {0:f6}", 100.0 / voteBetween);
                                            }
                                        }*/
                }
                Console.WriteLine();
/*                if ((outputTot < 99.99) || (outputTot > 100.01))
                {
                    Console.WriteLine("WOOHOOOOOOOOOO {0:f6}", outputTot);
                    Console.WriteLine();
                    Console.WriteLine();
                    Console.WriteLine();
                }*/
            }

        }
    }
}
