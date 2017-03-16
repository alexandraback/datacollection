using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ13_1C_C1
{
    class Program
    {
        struct Attack
        {
            public int w, e, s;
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int nc = 1; nc <= T; nc++)
            {
                int N = int.Parse(Console.ReadLine());
                int[] wall = new int[401];

                SortedList<int, List<Attack>> a = new SortedList<int, List<Attack>>();
                for (int i = 0; i < N; i++)
                {
                    string[] ss = Console.ReadLine().Split(' ');
                    int d = int.Parse(ss[0]);
                    int n = int.Parse(ss[1]);
                    int w = int.Parse(ss[2]);
                    int e = int.Parse(ss[3]);
                    int s = int.Parse(ss[4]);
                    int dd = int.Parse(ss[5]);
                    int dp = int.Parse(ss[6]);
                    int ds = int.Parse(ss[7]);

                    while (n > 0)
                    {
                        if (!a.ContainsKey(d)) a[d] = new List<Attack>();
                        a[d].Add(new Attack { w = w, e = e, s = s });
                        w += dp;
                        e += dp;
                        s += ds;
                        d += dd;
                        n--;
                    }
                }

                var ea = a.GetEnumerator();
                int nb = 0;
                while (ea.MoveNext())
                {
                    List<Attack> aa = ea.Current.Value;
                    bool breached = false;
                    int mins = 0;
                    for (int i = 0; i < aa.Count; i++)
                    {
                        bool cb = false;
                        for (int j = aa[i].w; j < aa[i].e; j++)
                        {
                            if (wall[j + 200] < aa[i].s)
                            {
                                cb = true;
                                break;
                            }
                        }
                        if (cb) nb++;
                        breached |= cb;
                        mins = Math.Max(mins, aa[i].s);
                    }

                    if (breached)
                    {
                        for (int i = 0; i < aa.Count; i++)
                            for (int j = aa[i].w; j < aa[i].e; j++)
                                wall[j + 200] = Math.Max(aa[i].s, wall[j + 200]);
                    }
                }
                Console.WriteLine("Case #{0}: {1}", nc, nb);
            }
        }
    }
}
