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
        public string solve(string[] arg)
        {
            string[] s = arg[0].Split(' ');

            long A = long.Parse(s[0]);
            long B = long.Parse(s[1]);
            long K = long.Parse(s[2]);

            long sum = 0;

            for (long a = 0; a < A; a++)
            {
                for (long b = 0; b < B; b++)
                {
                    long t = a & b;

                    if (t < K)
                    {
                        sum++;
                    }
                }
            }

            return sum.ToString();
        }
    }

    class FullBinaryTree
    {
        List<int>[] T;
        int N;

        int[,] m;
        int?[,] dp;

        int R(int p, int c)
        {
            var t = new List<int>();

            if (dp[p, c].HasValue)
            {
                return dp[p, c].Value;
            }

            for (int i = 0; i < T[c].Count; i++)
            {
                if (T[c][i] == p)
                {
                    continue;
                }

                int n = R(c, T[c][i]);
                t.Add(n);
            }

            int x = T[c].Count;

            if (p != -1)
            {
                x -= 1;
            }

            if (x == 0)
            {
                return 0;
            }

            if (x == 1)
            {
                return t.Sum() + 1;
            }

            if (x == 2)
            {
                return t.Sum();
            }

            if (x > 2)
            {
                int y = T[c].Count - 3;
                if (p == -1)
                {
                    y++;
                }

                return t.Sum() + y;
            }

            return 0;
        }

        public string solve(string[] arg)
        {
            N = arg.Length + 2;
            T = new List<int>[N];

            for (int i = 0; i < N; i++)
            {
                T[i] = new List<int>();
            }

            for (int i = 0; i < N - 1; i++)
            {
                string[] t = arg[i].Split(' ');
                int x = int.Parse(t[0]);
                int y = int.Parse(t[1]);

                T[x].Add(y);
                T[y].Add(x);
            }

            int min = int.MaxValue;

            for (int i = 0; i < N; i++)
            {
                min = Math.Min(min, R(-1, i));
            }

            return min.ToString();
        }
    }

    class TheRepeater
    {
        public string solve(string[] arg)
        {
            int N = arg.Length;

            int n = 0;

            int[,] X = new int[N, 100];

            while (arg[0].Length > 0)
            {
                char t = arg[0][0];

                for (int i = 0; i < N; i++)
                {
                    if (arg[i].Length == 0 || arg[i][0] != t)
                    {
                        return "Fegla Won";
                    }

                    while (arg[i].Length > 0 && arg[i][0] == t)
                    {
                        arg[i]=arg[i].Remove(0, 1);
                        X[i, n]++;
                    }
                }
                n++;
            }

            for (int i = 0; i < N; i++)
            {
                if (arg[i].Length > 0)
                {
                    return "Fegla Won";
                }
            }

            int sum = 0;

            for (int i = 0; i < X.GetLength(1); i++)
            {
                int min = int.MaxValue;

                for (int j = 0; j <= 100; j++)
                {
                    int m = 0;

                    for (int k = 0; k < N; k++)
                    {
                        m += Math.Abs(j - X[k, i]);
                    }

                    min = Math.Min(min, m);
                }

                sum += min;
            }


            return sum.ToString();
        }
    }


    class Program
    {
        delegate string SOLVE(string[] x);

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

                string r = "Case #" + (i + 1).ToString() + ":" + " " + new NewLotteryGame().solve(x);
                writer.WriteLine(r);
            }
            reader.Close();
            writer.Close();
        }
    }
}
