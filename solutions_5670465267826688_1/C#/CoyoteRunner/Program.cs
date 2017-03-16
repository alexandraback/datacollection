using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Numerics;
using System.Threading.Tasks;

namespace google_code_jam
{
    class InfiniteHouseofPancakes
    {
        public string solve(string s)
        {
            var x = new List<int>();

            foreach (var t in s.Split(' '))
            {
                x.Add(int.Parse(t));
            }

            int min = short.MaxValue;

            for (int i = 0; i <= 1000; i++)
            {
                int max = x.Max();
                min = Math.Min(min, i + max);

                int index = x.FindIndex(p => p == max);

                x.Add(max / 2 + (max % 2));
                x[index] /= 2;
            }

            return min.ToString();
        }
    }

    class InfiniteHouseofPancakes2
    {
        int min = short.MaxValue;

        void dfs(List<int> y, int n, int t)
        {
            int max = y.Max();

            if (max == 0)
            {
                min = Math.Min(min, t);
                return;
            }

            if (n > 0)
            {
                for (int i = 0; i < y.Count; i++)
                {
                    if (y[i] < 3)
                    {
                        continue;
                    }

                    for (int j = 2; j <= y[i] / 2; j++)
                    {
                        var x = new List<int>(y);

                        x[i] -= j;
                        x.Add(j);

                        dfs(x, n - 1, t + 1);
                    }
                }
            }

            dfs(y.Select(p => p - 1).ToList(), n, t + 1);
        }

        public string solve(string s)
        {
            var x = new List<int>();

            foreach (var t in s.Split(' '))
            {
                x.Add(int.Parse(t));
            }

            dfs(x, 8, 0);

            return min.ToString();
        }
    }

    class Dijkstra
    {
        int N;
        int[,] Mat;

        void init()
        {
            int n = 5;
            Mat = new int[n, n];

            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < n; j++)
                {
                    int u = 0;

                    if (i == 1 || j == 1)
                    {
                        u = i * j;
                    }
                    else if (i == j)
                    {
                        u = -1;
                    }
                    else if (i == 2 && j == 3)
                    {
                        u = 4;
                    }
                    else if (i == 2 && j == 4)
                    {
                        u = -3;
                    }
                    else if (i == 3 && j == 4)
                    {
                        u = 2;
                    }

                    Mat[i, j] = u;
                }
            }

            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < n; j++)
                {
                    if (Mat[i, j] == 0)
                    {
                        Mat[i, j] = -Mat[j, i];
                    }
                }
            }
        }

        public int M(int a, int b)
        {
            int t = 1;

            if (a < 0)
            {
                a *= -1;
                t *= -1;
            }

            if (b < 0)
            {
                b *= -1;
                t *= -1;
            }

            return t * Mat[a, b];
        }

        public string solve(string s, long n)
        {
            init();

            N = s.Length;

            var S = new int[s.Length];

            for (int i = 0; i < s.Length; i++)
            {
                char c = s[i];
                int t = 0;

                if (c == 'i')
                {
                    t = 2;
                }
                else if (c == 'j')
                {
                    t = 3;
                }
                else
                {
                    t = 4;
                }

                S[i] = t;
            }

            int x = 1;

            for (int i = 0; i < N; i++)
            {
                x = M(x, S[i]);
            }

            if (x == 1)
            {
                return "NO";
            }

            if (x == -1)
            {
                if (n % 2 == 0)
                {
                    return "NO";
                }
            }
            else
            {
                long rem = (n - 1) % 4;

                if (x > 0 || n % 2 == 0)
                {
                    if (rem != 1)
                    {
                        return "NO";
                    }
                }
                else
                {
                    if (rem != 3)
                    {
                        return "NO";
                    }
                }

            }

            long len1 = -1;
            int y = 1;

            for (int i = 0; i < 5; i++)
            {
                int z = 1;
                for (int j = 0; j < N; j++)
                {
                    z = M(z, S[j]);

                    int t = M(y, z);

                    if (t == 2)
                    {
                        len1 = N * i + j + 1;
                        break;
                    }
                }

                if (len1 >= 0)
                {
                    break;
                }

                y = M(y, x);
            }

            long len2 = -1;
            y = 1;

            for (int i = 0; i < 5; i++)
            {
                int z = 1;
                for (int j = N - 1; j >= 0; j--)
                {
                    z = M(S[j], z);

                    int t = M(z, y);

                    if (t == 4)
                    {
                        len2 = N * i + N - j;
                        break;
                    }
                }

                if (len2 >= 0)
                {
                    break;
                }

                y = M(x, y);
            }

            if (len1 < 0 || len2 < 0)
            {
                return "NO";
            }

            if (len1 + len2 < N * n)
            {
                return "YES";
            }

            return "NO";
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string folder = @"D:\tmp\";
            string input = "input";

            StreamReader reader = new StreamReader(folder + input + ".in", Encoding.ASCII);
            StreamWriter writer = new StreamWriter(folder + "out.txt");
            string s = reader.ReadLine();

            int T = int.Parse(s);

            for (int i = 0; i < T; i++)
            {
                //reader.ReadLine();
                //var x = reader.ReadLine();

                //string r = "Case #" + (i + 1).ToString() + ":" + " " + new InfiniteHouseofPancakes2().solve(x);

                var y = reader.ReadLine();
                var n = long.Parse(y.Split(' ')[1]);

                var x = reader.ReadLine();

                string r = "Case #" + (i + 1).ToString() + ":" + " " + new Dijkstra().solve(x, n);

                writer.WriteLine(r);
                Console.WriteLine(r);
            }
            reader.Close();
            writer.Close();
        }
    }
}
