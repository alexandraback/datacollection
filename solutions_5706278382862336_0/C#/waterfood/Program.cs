using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace waterfood.CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputs = File.ReadAllLines(@"../../A-small-attempt0.in");
            var outputs = new StringBuilder();

            int T = int.Parse(inputs[0]);
            for (int x = 0; x < T; x++)
            {
                var line = inputs[x + 1].Split('/').ToArray();
                long P = long.Parse(line[0]);
                long Q = long.Parse(line[1]);
                long f = MaxCommonFactor(P, Q);
                P = P / f;
                Q = Q / f;

                string ans = "impossible";
                if ((Q & (Q - 1)) == 0)
                {
                    int n = (int)Math.Log(Q, 2);
                    // find leading zeros
                    long k = ((long)1 << n);
                    int a = 0;
                    while (k > P)
                    {
                        a++;
                        k = (k >> 1);
                    }
                    ans = a.ToString();
                }
                outputs.AppendLine(string.Format("Case #{0}: {1}", x + 1, ans));
            }

            File.WriteAllText(@"../../A-small-attempt0.out", outputs.ToString());
        }

        static long MaxCommonFactor(long p, long q)
        {
            long s = q % p;
            while (s != 0)
            {
                q = p;
                p = s;
                s = q % p;
            }
            return p;
        }
    }
}
