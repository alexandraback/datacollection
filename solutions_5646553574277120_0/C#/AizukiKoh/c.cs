using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ._2015._1C
{
    class c
    {
        static void Main(string[] args)
        {
            var T = int.Parse(System.Console.ReadLine().Trim());
            for (int i = 0; i < T; ++i)
            {
                var line = System.Console.ReadLine().Trim().Split(' ');
                var C = int.Parse(line[0]);
                var D = int.Parse(line[1]);
                var V = int.Parse(line[2]);
                var line2 = System.Console.ReadLine().Trim().Split(' ');
                var d = new int[1000];
                for (var j = 0; j < line2.Length; ++j)
                {
                    d[j] = int.Parse(line2[j]);
                }
                Console.WriteLine("Case #{0:D}: {1:D}", i + 1, solve(C,D,V,d));
            }
        }

        private static int solve(int C, int D, int V, int[] d)
        {
            var ans = new HashSet<int>();
            search(C,D, V, d.ToArray<int>(), ref ans,0);
            var cnt = 0;
            while (true)
            {
                var t = 0;
                if (ans.Count == V)
                {
                    return cnt;
                }
                for (var i = 1; i <= V;++i )
                {
                    if (!ans.Contains(i))
                    {
                        t = i;
                        break;
                    }
                }
                d[D + cnt] = t;
                ++cnt;
                search(C, D + cnt, V, d, ref ans, 0);
            }
        }

        private static void search(int C,int D, int V, int[] d, ref HashSet<int> a, int sum)
        {
            if (D == 0)
            {
                return;
            }
            else
            {
                search(C,D - 1, V, d, ref a, sum);
                for (var i = 0; i < C; ++i)
                {
                    if (sum + d[D - 1] <= V)
                    {
                        sum += d[D - 1];
                        a.Add(sum);
                        search(C, D - 1, V, d, ref a, sum);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
}
