using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace C
{
    class Program
    {
        static void Main(string[] args)
        {
            int CN = int.Parse(Console.ReadLine());
            for (int cn = 1; cn <= CN; cn++)
            {
                string[] l = Console.ReadLine().Split(' ');
                int R = int.Parse(l[0]), N = int.Parse(l[1]), M = int.Parse(l[2]), K = int.Parse(l[3]);
                UInt64[] P = new UInt64[K];
                bool[] map = new bool[M + 1];
                List<int> p = new List<int>();

                string msg = "Case #" + cn + ":";
                Console.WriteLine(msg);
                Console.Error.WriteLine(msg + " " + R + " " + N + " " + M + " " + K);

                for (int n = 0; n < R; n++)
                {
                    Array.Clear(map, 0, M + 1);
                    l = Console.ReadLine().Split(' ');
                    for (int k = 0; k < K; k++)
                    {
                        P[k] = UInt64.Parse(l[k]);
                        if (P[k] == 1)
                        {
                            map[2]=true;
                            continue;
                        }
                        for (int m = 2; m <= M; m++)
                        {
                            if (!map[m] && (P[k] % (UInt64)m) == 0) map[m]=true;
                        }
                    }
                    int minK = 0, minC = N;
                    for (int k = 0; k < K; k++)
                    {
                        p.Clear();
                        UInt64 Pk = P[k];
                        int m = M;
                        while (Pk > 1)
                        {
                            while (m >= 2)
                            {
                                if ((Pk % (UInt64)m) == 0)
                                {
                                    p.Add(m);
                                    Pk /= (UInt64)m;
                                }
                                else m--;
                            }
                        }
                        if (p.Count == N) break;
                        if (Math.Abs(p.Count - N) < minC)
                        {
                            minC = Math.Abs(p.Count - N);
                            minK = k;
                        }
                    }
                    if (p.Count != N)
                    {
                        p.Clear();
                        UInt64 Pk = P[minK];
                        int m = M;
                        while (Pk > 1)
                        {
                            while (m >= 2)
                            {
                                if ((Pk % (UInt64)m) == 0)
                                {
                                    p.Add(m);
                                    Pk /= (UInt64)m;
                                }
                                else m--;
                            }
                        }
                    }
                    for (int k = 0; k < p.Count; k++)
                    {
                        Console.Write(p[k]);
                        Console.Error.Write(p[k]);
                    }
                    for (int k = p.Count; k < N; k++)
                    {
                        Console.Write('2');
                        Console.Error.Write('2');
                    }
                    Console.WriteLine();
                    Console.Error.WriteLine();
                }
            }
        }
    }
}
