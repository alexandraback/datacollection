using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Numerics;
using System.Threading.Tasks;

namespace google_code_jam
{
    class NewLotteryGame
    {
        int[] a, b, k;
        int N;
        long?[, , ,] dp;

        int X(int x, int c, int u)
        {
            if (c + u - x > 0)
            {
                return 1;
            }

            return 0;
        }

        long R(int pos, int x, int y, int z)
        {
            if (pos == N)
            {
                if (x + y + z == 0)
                {
                    return 1;
                }

                return 0;
            }

            if (dp[pos, x, y, z].HasValue)
            {
                return dp[pos, x, y, z].Value;
            }

            long sum = 0;

            for (int i = 0; i <= 1; i++)
            {
                for (int j = 0; j <= 1; j++)
                {
                    int l = X(a[pos], x, i);
                    int m = X(b[pos], y, j);
                    int n = X(k[pos], z, i & j);

                    sum += R(pos + 1, l, m, n);
                }
            }

            dp[pos, x, y, z] = sum;
            return sum;
        }

        int[] Y(long x)
        {
            int[] y = new int[N];

            for (int i = 0; i < N; i++)
            {
                if (x % 2 != 0)
                {
                    y[i] = 1;
                }

                x /= 2;
            }

            return y;
        }

        public string solve(string[] arg)
        {
            string[] s = arg[0].Split(' ');
            N = 60;

            dp = new long?[N, 2, 2, 2];

            long A = long.Parse(s[0]) - 1;
            long B = long.Parse(s[1]) - 1;
            long K = long.Parse(s[2]) - 1;

            a = Y(A);
            b = Y(B);
            k = Y(K);

            long sum = R(0, 0, 0, 0);

            return sum.ToString();
        }
    }


    class ProperShuffle
    {
        int N;
        double[,] p;

        public void init(int n)
        {
            N = n;
            p = new double[N, N];
            double m = N;
            m = 1 / m;

            double s = 1 - m;

            for (int i = 0; i < N; i++)
            {
                p[i, i] = 1;
            }

            for (int i = 0; i < N; i++)
            {
                var p2 = new double[N, N];

                for (int x = 0; x < N; x++)
                {
                    for (int y = 0; y < N; y++)
                    {
                        p2[x, i] += p[x, y] * m;

                        if (i != y)
                        {
                            p2[x, y] = p[x, y] * s + p[x, i] * m;
                        }
                    }
                }
                p = p2;
            }
        }

        public string solve(string[] arg)
        {
            var A = arg[1].Split(' ').Select(p => int.Parse(p)).ToArray();

            double x = N;
            x = -x * Math.Log(x);

            double y = 0;

            for (int i = 0; i < N; i++)
            {
                y += Math.Log(p[A[i], i]);
            }

            if (x - y > 0)
            {
                return "GOOD";
            }

            return "BAD";
        }
    }

    class PartElf
    {
        long gcd(long m, long n)
        {
            if (n > m)
            {
                long t = m;
                m = n;
                n = t;
            }

            if (n == 0)
            {
                return m;
            }

            return gcd(n, m % n);
        }

        int R(long P, long Q)
        {
            int n = 0;

            if (P * Q == 1)
            {
                return 1;
            }

            while (P / Q < 1)
            {
                if (P == 0)
                {
                    return 0;
                }

                if (Q % 2 == 1)
                {
                    return -1;
                }

                Q /= 2;
                n++;
            }

            P -= Q;

            int x = R(P, Q);

            if (x == -1)
            {
                return -1;
            }

            return n;
        }

        public string solve(string[] arg)
        {
            string[] s = arg[0].Split('/');

            var P = long.Parse(s[0]);
            var Q = long.Parse(s[1]);

            long t = gcd(P, Q);

            P /= t;
            Q /= t;

            long y = Q;

            while (y != 1)
            {
                if (y % 2 == 1)
                {
                    return "impossible";
                }

                y /= 2;
            }

            int n = R(P, Q);

            if (n == -1 || n > 40)
            {
                return "impossible";
            }

            return n.ToString();
        }
    }


    class ReorderingTrainCars
    {
        //int N;

        //int[,] M;
        //int[] g;


        //int R(int n)
        //{


        //}

        //public string solve(string[] arg)
        //{

        // }
    }

    class Enclosure
    {
        int N;
        int M;
        int K;

        int min;

        int[,] X;
        int[,] T;

        int dfs(int n, int m)
        {
            if (T[n, m] == 1)
            {
                return 0;
            }

            if (X[n, m] == 1)
            {
                return 0;
            }

            if (n == 0 || n == N - 1 || m == 0 || m == M - 1)
            {
                return -1;
            }

            T[n, m] = 1;

            int sum = 1;

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int x = dfs(n + i, m + j);

                    if (x == -1)
                    {
                        sum = -1;
                    }

                    if (sum != -1)
                    {
                        sum += x;
                    }
                }
            }

            return sum;
        }

        void R(int n, int m, int b)
        {
            if (b >= min)
            {
                return;
            }

            if (n == N)
            {
                T = new int[N, M];

                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        if (X[i, j] == 1 || T[i, j] == 1)
                        {
                            continue;
                        }

                        int x = dfs(i, j);

                        if (x != -1)
                        {
                            if (x + b >= K)
                            {
                                min = Math.Min(min, b);
                            }
                        }
                    }
                }

                return;
            }

            if (m == M)
            {
                R(n + 1, 0, b);
                return;
            }

            X[n, m] = 0;
            R(n, m + 1, b);

            X[n, m] = 1;
            R(n, m + 1, b + 1);
        }

        public string solve(string[] arg)
        {
            string[] s = arg[0].Split(' ');

            N = int.Parse(s[0]);
            M = int.Parse(s[1]);
            K = int.Parse(s[2]);

            X = new int[N, M];

            min = K;

            R(0, 0, 0);

            return min.ToString();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string folder = @"D:\TMP\";
            string input = "input";

            StreamReader reader = new StreamReader(folder + input + ".in", Encoding.ASCII);
            StreamWriter writer = new StreamWriter(@"D:\TMP\out.txt");
            string s = reader.ReadLine();

            int T = int.Parse(s);

            for (int i = 0; i < T; i++)
            {
                int n = 1;// int.Parse(reader.ReadLine());

                string[] x = new string[n];

                for (int j = 0; j < n; j++)
                {
                    x[j] = reader.ReadLine();
                }

                string r = "Case #" + (i + 1).ToString() + ":" + " " + new Enclosure().solve(x);
                writer.WriteLine(r);
            }
            reader.Close();
            writer.Close();
        }
    }
}
