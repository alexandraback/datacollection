using System;
using System.IO;
using System.Collections.Generic;

namespace Problem1
{
    class Program
    {
        static void Main(string[] args)
        {
            int counter = 1;
            StreamReader file = new StreamReader("a.txt");
            counter = int.Parse(file.ReadLine());
            for (int i = 1; i <= counter; i++)
            {
                Console.Write(string.Format("Case #{0}:", i));
                string line = file.ReadLine();
                string[] all = line.Split();

                List<int> nn1 = new List<int>();

                int count = int.Parse(all[0]);
                int sum = 0;
                for (int j = 0; j < all.Length-1; j++)
                {
                    int now = int.Parse(all[j+1]);
                    sum += now;
                    nn1.Add(now);
                }

                List<int> nn2 = new List<int>(nn1);
                nn2.Sort();
                int thisSum = 0;
                int jj = 1;
                for (; jj < nn2.Count; jj++)
                {
                    thisSum += (jj) * (nn2[jj] - nn2[jj - 1]);
                    if (thisSum > sum)
                        break;
                }

                int n2 = Math.Min(jj, nn2.Count);

                double sum2 = sum;
                for (int kk = 0; kk < n2; kk++)
                {
                    sum2 += nn2[kk];
                }

                double avg = sum2 / n2;

                for (int ii = 0; ii < nn1.Count; ii++)
                {
                    int first = nn1[ii];

                    double result = (avg - first) / sum * 100.0;
                    if (result < 0) result = 0;
                    Console.Write(string.Format(" {0:0.0000000}", result));
                }

                Console.WriteLine();
            }
        }
    }
}
