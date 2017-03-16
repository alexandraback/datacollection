using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace b
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("in.txt");
            StreamWriter sw = new StreamWriter("out.txt");
            int T = int.Parse(sr.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                int N = int.Parse(sr.ReadLine());
                int[] a = new int[N];
                int[] b = new int[N];
                int[] star = new int[N];
                for (int i = 0; i < N; ++i)
                {
                    string[] ss = sr.ReadLine().Split();
                    a[i] = int.Parse(ss[0]);
                    b[i] = int.Parse(ss[1]);
                    star[i] = 0;
                }
                int score = 0;
                int times = 0;
                while (score < 2 * N)
                {
                    bool updated = false;
                    for (int i = 0; i < N; ++i)
                    {
                        if (star[i] < 2 && b[i] <= score)
                        {
                            score += 2 - star[i];
                            star[i] = 2;
                            ++times;
                            updated = true;
                        }
                    }
                    if (updated)
                        continue;
                    int k = -1;
                    for (int i = 0; i < N; ++i)
                    {
                        if (star[i] < 1 && a[i] <= score)
                        {
                            if (k == -1 || b[i] > b[k])
                            {
                                k = i;
                                updated = true;
                            }
                        }
                    }
                    if (!updated)
                        break;
                    score += 1;
                    star[k] = 1;
                    ++times;
                }
                if (score == 2 * N)
                    sw.WriteLine("Case #{0}: {1}", t, times);
                else
                    sw.WriteLine("Case #{0}: Too Bad", t);
            }
            sr.Close();
            sw.Close();
        }
    }
}
