using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace EqualSums
{
    class Program
    {
        static int SN = 20;
        static int SMAX = 100000;

        static void Main(string[] args)
        {
            //Console.WriteLine(SolveNaive(20, new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 }));

            TextReader tr = new StreamReader("C-small-attempt0.in");
            TextWriter tw = new StreamWriter("C-small-attempt0.out");

            int T = int.Parse(tr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                string[] data = tr.ReadLine().Split(' ');
                int N = int.Parse(data[0]);
                int[] S = new int[N];
                for (int j = 0; j < N; j++)
                    S[j] = int.Parse(data[j + 1]);

                tw.WriteLine("Case #" + i + ":\n" + SolveNaive(N, S));
            }

            tr.Close();
            tw.Close();
        }

        static string SolveNaive(int N, int[] S)
        {
            int[][] sums = new int[SN * SMAX + 1][];

            int[] which = new int[SN];
            int sum = 0;

            while (true)
            {
                if (sum != 0)
                {
                    if (sums[sum] != null)
                    {
                        string ret = "";
                        for (int i = 0; i < SN; i++)
                        {
                            if (which[i] == 1)
                            {
                                ret += S[i] + " ";
                            }
                        }
                        ret += "\n";
                        for (int i = 0; i < SN; i++)
                        {
                            if (sums[sum][i] == 1)
                            {
                                ret += S[i] + " ";
                            }
                        }
                        return ret;
                    }
                    else
                    {
                        sums[sum] = (int[])which.Clone();
                    }
                }

                which[0]++;
                sum += S[0];
                for (int i = 0; i < SN; i++)
                {
                    if (which[i] == 2)
                    {
                        which[i] = 0;
                        sum -= 2 * S[i];

                        which[i + 1]++;
                        sum += S[i + 1];
                    }
                    else
                    {
                        break;
                    }
                }
            }

            return "Impossible";
        }

        /*static string SolveNaive(int[] S)
        {
            int[] which1 = new int[S.Length];

            while (true)
            {
                int sum1 = Sum(which1, S);

                int[] which2 = new int[S.Length];

                while (true)
                {
                    int sum2 = Sum(which2, S);

                    if (sum1 == sum2 && !AreTheSame(which1, which2))
                    {
                        string ret = "";
                        for (int i = 0; i < S.Length; i++)
                        {
                            ret += which1[i] + " ";
                        }
                        ret += "\n";
                        for (int i = 0; i < S.Length; i++)
                        {
                            ret += which2[i] + " ";
                        }
                        return ret;
                    }

                    Next(which2);
                    if (which2[S.Length - 1] == 2)
                    {
                        break;
                    }
                }

                Next(which1);
                if (which1[S.Length - 1] == 2)
                {
                    break;
                }
            }

            return "Impossible";
        }

        static bool AreTheSame(int[] which1, int[] which2)
        {
            for (int i = 0; i < which1.Length; i++)
            {
                if (which1[i] != which2[i])
                {
                    return false;
                }
            }
            return true;
        }

        static void Next(int[] which)
        {
            which[0]++;
            for (int i = 0; i < which.Length - 1; i++)
            {
                if (which[i] == 2)
                {
                    which[i + 1]++;
                }
                else
                {
                    break;
                }
            }
        }

        static int Sum(int[] which, int[] S)
        {
            int sum = 0;
            for (int i = 0; i < S.Length; i++)
            {
                sum += which[i] * S[i];
            }
            return sum;
        }*/
    }
}
