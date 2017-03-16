using System;
using System.Globalization;
using System.IO;
using System.Linq;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            var fin = new StreamReader(@"A-large.in");
            var fout = new StreamWriter(@"output.txt");
            var T = Int32.Parse(fin.ReadLine());
            for (var t = 1; t <= T; t++)
            {
                var line = fin.ReadLine().Split('/').Select(Int64.Parse).ToArray();
                var P = line[0];
                var Q = line[1];

                var g = GCD(P, Q);
                P /= g;
                Q /= g;

                var r = -1;
                if (IsAll2(Q))
                    r = Len(P, Q);

                fout.WriteLine("Case #{0}: {1}", t, r == -1 ? "impossible" : r.ToString(CultureInfo.InvariantCulture));
            }
            fout.Close();
            fin.Close();

        }

        static long GCD(long a, long b)
        {
            return b == 0 ? a : GCD(b, a % b);
        }

        static bool IsAll2(long n)
        {
            while (true)
            {
                if (n == 1) return true;
                if (n%2 != 0) return false;
                n /= 2;
            }
        }

        static int Len(long p, long q)
        {
            for (var i = 1; i <= 40; i++)
            {
                p = p*2;
                if (p >= q) return i;
            }
            return -1;
        }
    }
}
