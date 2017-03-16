using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;
using System.Numerics;
using System.Globalization;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            Stopwatch sw = Stopwatch.StartNew();

            KingdomRush.Go();

            sw.Stop();
            Console.WriteLine("Time spent {0} ms.", sw.ElapsedMilliseconds);
            Console.ReadKey(false);
        }
    }

    class KingdomRush
    {
        public static void Go()
        {
            using (StreamReader sr = new StreamReader(@"C:\MyWorks\CodeJam\Data\KingdomRush\B-large.in"))
            using (StreamWriter sw = new StreamWriter(@"C:\MyWorks\CodeJam\Data\KingdomRush\B-large.out"))
            {
                string line = sr.ReadLine().Trim();
                int T = Int32.Parse(line);

                for (int i = 0; i < T; i++)
                {
                    Console.WriteLine("Processing Case #{0} ...", i + 1);

                    line = sr.ReadLine().Trim();
                    int N = Int32.Parse(line);

                    int[,] cost = new int[N, 2];

                    for (int j = 0; j < N; j++)
                    {
                        line = sr.ReadLine().Trim();
                        string[] split = line.Split();

                        cost[j, 0] = Int32.Parse(split[0]);
                        cost[j, 1] = Int32.Parse(split[1]);
                    }

                    sw.WriteLine("Case #{0}: {1}", i + 1, Solve(N, cost));
                }
            }
        }

        private static string Solve(int N, int[,] cost)
        {
            int iStep = 0;
            
            int[] completion = new int[N];
            for (int i = 0; i < N; i++)
                completion[i] = 0;

            int score = 0;

            while (!Done(ref completion))
            {
                int iNextAttemp = -1;

                for (int i = 0; i < N; i++)
                {
                    if (completion[i] < 2 && cost[i,1]<=score)
                    {
                        iNextAttemp = i;
                        break;
                    }
                }

                if (iNextAttemp < 0)
                {
                    int iMax = 0;
                    
                    for (int i = 0; i < N; i++)
                    {
                        if (completion[i] < 1 && cost[i, 0] <= score)
                        {
                            if (iNextAttemp < 0 || iMax < cost[i, 1])
                            {
                                iNextAttemp = i;
                                iMax = cost[i, 1];
                            }
                        }
                    }
                }

                if (iNextAttemp < 0)
                    return "Too Bad";

                if (completion[iNextAttemp] == 0)
                {
                    if (cost[iNextAttemp, 1] <= score)
                    {
                        score += 2;
                        completion[iNextAttemp] = 2;
                    }
                    else
                    {
                        score += 1;
                        completion[iNextAttemp] = 1;
                    }
                }
                else
                {
                    score += 1;
                    completion[iNextAttemp] = 2;
                }

                iStep++;
            
            }

            return iStep.ToString();
        }

        private static bool Done(ref int[] completion)
        {
            foreach (int ic in completion)
            {
                if (ic < 2)
                    return false;
            }
            return true;
        }
    }
}
