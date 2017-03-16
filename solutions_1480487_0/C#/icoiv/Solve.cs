using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;

namespace A
{
    public class Solve
    {
        public Solve(TextReader r, TextWriter w)
        {
            int t = int.Parse(r.ReadLine());
            for (int i = 0; i < t; ++i)
            {
                var p = from ss in r.ReadLine().Split() select int.Parse(ss);
                var n = p.First();
                var s = p.Skip(1).ToArray();
                var X = s.Aggregate(0, (a, x) => a + x);
                var Y = X;
                

                var result = new double?[s.Length];
                int m = n;
                for (int j = 0; j < n; ++j)
                {
                    if (s[j] >= (((double)2 * X) / n))
                    {
                        result[j] = 0;
                        --m;
                        Y -= s[j];
                    }
                }
                for (int j = 0; j < n; ++j)
                {
                    if (result[j] == null)
                    {
                        result[j] = (((double) Y + X)/m - s[j])*100/X;
                    }
                }
                w.Write(string.Format("Case #{0}:", i + 1));
                foreach (var rr in result) w.Write(string.Format(CultureInfo.InvariantCulture, " {0:0.000000}", rr));
                w.WriteLine();
            }
        }
    }
}