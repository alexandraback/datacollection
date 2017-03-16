using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace SafetyInNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("A-small-attempt2.in");
            StreamWriter sw = new StreamWriter("A-small-attempt2.out");

            int T = int.Parse(sr.ReadLine());
            for (int q = 0; q < T; q++)
            {
                String input = sr.ReadLine();
                String[] inputs = input.Split(' ');
                int N = int.Parse(inputs[0]);
                int[] jPoints = new int[N];
                int sum = 0;
                for (int i = 0; i < N; i++)
                {
                    jPoints[i] = int.Parse(inputs[i + 1]);
                    sum += jPoints[i];
                }

                double[] jFraction = new double[N];

                
                for (int i = 0; i < N; i++)
                {
                    jFraction[i] = ((double)jPoints[i]/sum);
                }

                double average = 2.0 / (double) N;
                bool[] qualified = new bool[N];


                int belowAverage = 0;
                double fractionUsed = 0;
                for (int i = 0; i < N; i++)
                {
                    if (jFraction[i] < average)
                    {
                        belowAverage++;
                        qualified[i] = false;
                    }
                    else
                    {
                        qualified[i] = true;
                        fractionUsed += jFraction[i];
                    }
                }

                average = (2 - fractionUsed) / (double)belowAverage;

                sw.Write(string.Format("Case #{0}:", (q + 1)));
                for (int i = 0; i < N; i++)
                {
                    double ans = average - jFraction[i];
                    if(qualified[i]) 
                        sw.Write(" 0.000000");
                    else
                        sw.Write(String.Format(" {0:0.000000}", ans * 100));
                }
                sw.WriteLine();
            }
            sw.Close();
            sr.Close();
        }
    }
}
