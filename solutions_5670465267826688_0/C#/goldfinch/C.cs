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

                int[] all = new int[li[0] * li[1]];
                for(int i = 0;i<li[1];i++)
                    for (int j = 0; j < s.Length; j++)
                    {
                        all[s.Length * i + j] = s[j] == 'i' ? 1 : (s[j] == 'j' ? 2 : 3);
                    }

                res[test] = string.Format(
                    "Case #{0}: {1}",
                    (test + 1).ToString(CultureInfo.InvariantCulture),
                    this.check(all)?"YES":"NO");
            }

            return res;
        }

        private bool check(int[] a)
        {
            int v = 0;
            int s = 0;
            bool first = true;
            bool good = false;
            for (int i = 0; i < a.Length; i++)
            {
                s = s ^ ms[v, a[i]];
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
