using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ15
{
    using System.Globalization;

    class C
    {
        private int[,] mv =
            {
                { 0,1,2,3}, 
                { 1,0,3,2}, 
                { 2,3,0,1},
                { 3,2,1,0}
            };
        private int[,] ms =
            {
                { 0,0,0,0}, 
                { 0,1,0,1}, 
                { 0,1,1,0},
                { 0,0,1,1}
            };

        public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];

            for (int test = 0; test < cases; test++)
            {
                var li = lines[test*2 + 1].Split(' ').Select(d => long.Parse(d, CultureInfo.InvariantCulture)).ToList();
                string s = lines[test * 2 + 2];

                bool good = false;
                int cutoff = 100;
                if (li[1] > cutoff)
                {
                    int[] all = new int[li[0] * cutoff + 1];
                    int[] b = new int[all.Length];

                    int[] a = new int[li[0]];
                    for (int j = 0; j < s.Length; j++)
                    {
                        a[j] = s[j] == 'i' ? 1 : (s[j] == 'j' ? 2 : 3);
                    }

                    int cv = 0;
                    int cs = 0;
                    for (int i = 0; i < a.Length; i++)
                    {
                        cs = cs ^ ms[cv, a[i]];
                        cv = mv[cv, a[i]];
                    }

                    int zv = 0;
                    int zs = 0;
                    long pow = li[1] - cutoff;
                    
                    for (; pow > 0;)
                    {
                        if (pow % 2 == 1)
                        {
                            zs = zs ^ ms[zv, cv] ^ cs;
                            zv = mv[zv, cv];
                        }
                        cs = ms[cv, cv];
                        cv = mv[cv, cv];
                        pow /= 2;
                    }

                    for (int i = 0; i < cutoff; i++)
                        for (int j = 0; j < s.Length; j++)
                        {
                            all[s.Length * i + j] = s[j] == 'i' ? 1 : (s[j] == 'j' ? 2 : 3);
                        }
                    all[all.Length - 1] = zv;
                    b[all.Length - 1] = zs;

                    good |= this.check(all, b);

                    for (int i = 0; i < cutoff; i++)
                        for (int j = 0; j < s.Length; j++)
                        {
                            all[1+s.Length * i + j] = s[j] == 'i' ? 1 : (s[j] == 'j' ? 2 : 3);
                        }
                    all[0] = zv;
                    b[0] = zs;

                    good |= this.check(all, b);
                }
                else
                {
                    int[] all = new int[li[0] * li[1]];
                    int[] b = new int[all.Length];                    
                    for (int i = 0; i < li[1]; i++)
                        for (int j = 0; j < s.Length; j++)
                        {
                            all[s.Length * i + j] = s[j] == 'i' ? 1 : (s[j] == 'j' ? 2 : 3);
                        }
                    good = this.check(all, b);
                }

                res[test] = string.Format(
                    "Case #{0}: {1}",
                    (test + 1).ToString(CultureInfo.InvariantCulture),
                    good?"YES":"NO");
            }

            return res;
        }

        private bool check(int[] a, int[] b)
        {
            int v = 0;
            int s = 0;
            bool first = true;
            bool good = false;
            for (int i = 0; i < a.Length; i++)
            {
                s = s ^ ms[v, a[i]] ^ b[i];
                v = mv[v, a[i]];

                if (first && v == 1 && s == 0)
                    first = false;
                if (!first && v == 3 && s == 0)
                    good = true;
            }
            if (v != 0 || s != 1)
                return false;
            return good;
        }

    }
}
