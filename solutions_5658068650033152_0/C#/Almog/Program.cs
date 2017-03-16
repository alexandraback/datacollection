
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.IO;

namespace _3_Enclosure
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream fsInput = new FileStream(args[0], FileMode.Open, FileAccess.Read);
            StreamReader reader = new StreamReader(fsInput);
            FileStream fsOutput = new FileStream(args[0] + ".out", FileMode.Create, FileAccess.Write);
            StreamWriter writer = new StreamWriter(fsOutput);


            string sCases = reader.ReadLine();

            int iCases = int.Parse(sCases);

            for (int i = 0; i < iCases; i++)
            {
                string[] line = reader.ReadLine().Split(' ');
                int N = int.Parse(line[0]);
                int M = int.Parse(line[1]);
                int K = int.Parse(line[2]);
                /*
                if (i + 1 != 4)
                {
                    continue;
                }*/

                int[] arr = new int[5];
                arr[0] = minBorder(M, N, K);
                if ((N > 2) && (M > 2))
                {
                    //arr[1] = int.MaxValue;
                    //arr[2] = int.MaxValue;
                    arr[1] = minSquare(N, M, K);
                    arr[2] = minSquare(M, N, K);
                    arr[3] = minRect(N, M, K);
                    arr[4] = minRect(M, N, K);
                }
                else
                {
                    arr[1] = arr[2] = arr[3] = arr[4] = int.MaxValue;
                }

                int min = arr.Min();
                if (min == int.MaxValue)
                {
                    min = 2 * M + 2 * N - 4 - (M * N - K);
                }
                writer.WriteLine("Case #{0}: {1}", i + 1, min);
            }

            reader.Close();
            writer.Close();

        }

        private static int minBorder(int M, int N, int K)
        {
            if (N == 1)
            {
                return Math.Min(M, K);
            }

            if (M == 1)
            {
                return Math.Min(N, K);
            }

            int max = 2 * M + 2 * N - 4;

            if (K <= max)
            {
                return K;
            }

            return int.MaxValue;
        }

        private static int minSquare(int N, int M, int K)
        {
            int stones = 2;
            int close = 0;
            int i = 0, j = 0;
            while ((i < (N - 2)) || (j < (M - 2)))
            {
                if (stones + close >= K)
                {
                    return stones;
                }
                if (stones + close >= K - 1)
                {
                    return stones + 1;
                }

                if (i == j)
                {
                    if (i < N - 2)
                    {
                        i++;
                        stones += 2;
                        close += j + 1;
                    }
                    else if (j < M - 2)
                    {
                        j++;
                        stones += 2;
                        close += i;
                    }
                }
                else
                {
                    if (j < M - 2)
                    {
                        j++;
                        stones += 2;
                        close += i;
                    }
                    else if (i < N - 2)
                    {
                        i++;
                        stones += 2;
                        close += j + 1;
                    }
                }
            }

            if (stones + close >= K)
            {
                return stones;
            }
            if (stones + close >= K - 1)
            {
                return stones + 1;
            }

            return int.MaxValue;
        }

        private static int minRect(int N, int M, int K)
        {
            int stones = 2 * (M - 2);
            int close = 0;
            
            for (int i = 0; i < N - 2; i++)
            {
                if (stones + close >= K)
                {
                    return stones;
                }
                if (stones + close >= K - 1)
                {
                    return stones + 1;
                }

                stones += 2;
                close += M - 2;
            }

            if (stones + close >= K)
            {
                return stones;
            }
            if (stones + close >= K - 1)
            {
                return stones + 1;
            }

            return int.MaxValue;
        }
    }
}
