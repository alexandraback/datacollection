using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace a
{
    class Program
    {
        static Dictionary<int, int>[] p;
        static Dictionary<int, int>[] come;
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("in.txt");
            StreamWriter sw = new StreamWriter("out.txt");

            int T = int.Parse(sr.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                int N = int.Parse(sr.ReadLine());
                //p = new Dictionary<int, int>[N];
                //come = new Dictionary<int, int>[N];
                //for (int i = 0; i < N; ++i)
                //{
                //    p[i] = new Dictionary<int, int>();
                //    come[i] = new Dictionary<int, int>();
                //}
                for (int i = 0; i < N; ++i)
                {
                    string[] ss = sr.ReadLine().Split();
                    int M = int.Parse(ss[0]);
                    for (int j = 0; j < M; ++j)
                    {
                        int x = int.Parse(ss[j + 1]) - 1;
                        p[i].Add(x, 1);
                        p[x].Add(i, 0);
                    }
                }
                for (int i = 0; i < N; ++i)
                {
                    int c = 0;
                    foreach (KeyValuePair<int, int> pair in p[i])
                    {
                        if (pair.Value == 0)
                            ++c;
                    }
                    if (c == 0)
                    {
                        Dfs(i);
                    }
                }
                bool ans = false;
                for (int i = 0; i < N; ++i)
                {
                    foreach (KeyValuePair<int, int> pair in come[i])
                    {
                        if (pair.Value > 1)
                        {
                            ans = true;
                            break;
                        }
                    }
                }
                if (ans)
                {
                    sw.WriteLine("Case #{0}: Yes", t);
                }
                else
                {
                    sw.WriteLine("Case #{0}: No", t);
                }
            }

            sw.Close();
            sr.Close();
        }

        static void Dfs(int x)
        {
            foreach (KeyValuePair<int, int> pair in p[x])
            {
                if (pair.Value == 1)
                {
                    int y = pair.Key;
                    foreach (KeyValuePair<int, int> p2 in come[x])
                    {
                        if (come[y].ContainsKey(p2.Key))
                            come[y][p2.Key]++;
                        else
                            come[y].Add(p2.Key, 1);
                    }
                    if (come[y].ContainsKey(x))
                        come[y][x]++;
                    else
                        come[y].Add(x, 1);
                    
                    Dfs(y);
                }
            }
        }
    }
}
