using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemD
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("D-large.in");
            StreamWriter sw = new StreamWriter("outlarge.txt");
            long T = Int64.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string[] line = sr.ReadLine().Split();
                long K, C, S;
                K = Int64.Parse(line[0]);
                C = Int64.Parse(line[1]);
                S = Int64.Parse(line[2]);
                if (C * S < K) sw.WriteLine("Case #{0}: IMPOSSIBLE", i + 1);
                else
                {
                    long j = 0;
                    List<long> num = new List<long>();
                    while (j < K)
                    {
                        num.Add(j);
                        j += C > K ? K : C;
                    }
                    //if (K % C != 0) num.Add(K - 1);
                    long[] arr = num.ToArray();
                    long x = K;
                    for (int k = 2; k <= C; k++)
                    {
                        x *= K;
                        for (int l = 0; l < arr.Length; l++)
                        {
                            if (k <= K)
                            {
                                if ((arr[l] + 1) % K != 0)
                                {
                                    arr[l] = arr[l] * K + (arr[l] % K) + 1;
                                }
                                else
                                {
                                    arr[l] = arr[l] * K + (arr[l] % K);
                                }
                            }
                           /* else
                            {
                                arr[l] = arr[l] * K + arr[l] % K;
                            }*/
                       //     if (arr[l] >= x) arr[l] = x - 1;
                        }
                    }
                    sw.Write("Case #{0}:", i + 1);
                    for (int l = 0; l < arr.Length; l++)
                    {
                        sw.Write(" {0}", arr[l] + 1);
                    }
                    sw.WriteLine();
                }
            }
            sw.Close();
        }
    }
}
