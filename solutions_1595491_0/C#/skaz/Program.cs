using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SpeakingInTongues
{
    class Program
    {
        static void Main(string[] args)
        {
            int testCaseCount = int.Parse(Console.ReadLine());

            for (int i = 0; i < testCaseCount; i++)
                ProcessTestCase(i + 1);
        }

        private static void ProcessTestCase(int caseNumber)
        {
            // Read in the next line of the program
            string[] line = Console.ReadLine().Split(' ');
            
            // number of GoOgLeRs
            int N = int.Parse(line[0]);

            // surprises
            int S = int.Parse(line[1]);

            int p = int.Parse(line[2]);

            List<int> googlerScores = new List<int>(N);

            for (int i = 0; i < N; i++)
            {
                googlerScores.Add(int.Parse(line[3 + i]));
            }

            googlerScores.OrderByDescending(i => i);

            int totalAbove = 0;

            int pLeft = S;

            foreach (int i in googlerScores)
            {
                int ave = (int)Math.Floor((double)((int)i / (int)3));
                int mod = i % 3;

                // IF the total is LESS than the max, it is impossible
                if (i < p)
                    continue;

                // if it is more, we know they made it
                if (ave >= p)
                {
                    totalAbove++;
                    continue;
                }
                    // It is less
                else
                {
                    if (mod == 0)
                    {
                        // Max is the ave - we can use an S
                        if (ave + 1 == p && pLeft > 0)
                        {
                            pLeft--;
                            totalAbove++;
                        }
                    }
                    else if (mod == 1)
                    {
                        // We can use one higher naturally
                        if (ave + 1 == p)
                            totalAbove++;
                    }
                    else if (mod == 2)
                    {
                        if (ave + 1 == p)
                            totalAbove++;
                        else if (ave + 2 == p)
                        {
                            if (pLeft > 0)
                            {
                                pLeft--;
                                totalAbove++;
                            }
                        }
                    }
                }
            }

        
            Console.WriteLine("Case #{0}: {1}", caseNumber, totalAbove);
        }
    }
}
