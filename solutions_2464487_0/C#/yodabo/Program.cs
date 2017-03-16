using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Problem1
{
    class Program
    {
        static int Solve(BigInteger r, BigInteger t)
        {
            BigInteger a = 2;
            BigInteger b = (2 * r - 1);
            BigInteger c = (-t);
            BigInteger n0 = (BigInteger)((-b + (BigInteger)(Math.Sqrt((double)(b * b - 4 * a * c)))) / (2 * a));
            if (n0 < 0)
                n0 = 0;

            // this gets us close, but there may be rounding issues... step up or down until we found the right number
            while (n0 * a * n0 + n0 * b < t) n0++; // if we can paint more, paint it
            while (n0 * a * n0 + n0 * b > t) n0--; // step down if we painted too much

            return (int)(n0);
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                // read input...
                String[] line = Console.ReadLine().Trim(' ').Split(' ');
                long r = long.Parse(line[0]);
                long t = long.Parse(line[1]);
                Console.WriteLine("Case #{0}: {1}", 1 + i, Solve(r, t));
            }
        }
    }
}
