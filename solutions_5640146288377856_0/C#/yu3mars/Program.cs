using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace a
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamWriter w = new StreamWriter(@"output-small0.txt"))
            {
                using (StreamReader r = new StreamReader(@"A-small-attempt0.in"))
                {
                    int t = int.Parse(r.ReadLine());
                    for (long i = 0; i < t; i++)
                    {
                        string[] scx = r.ReadLine().Split(' ');
                        int s = int.Parse(scx[0]);
                        int c = int.Parse(scx[1]);
                        int x = int.Parse(scx[2]);
                        int ans = 0;
                        ans += s * (c / x);
                        ans += x;
                        if (c % x == 0) ans -= 1;
                        w.WriteLine("Case #{0}: {1}", i + 1, ans);
                    }
                }
            }
        }
        static long Gcd(long a, long b)
        {
            if (b == 0) return a;
            return Gcd(b, a % b);
        }

        static long Lcm(long a, long b)
        {
            return (long)a / Gcd(a, b) * b;
        }
    }
}
