using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2015_1B_A
{
    class Program
    {
        static long Cost(long n)
        {
            if (n == 1)
                return 1;
            if (n % 10 == 0)
                return Cost(n - 1) + 1;
            var s = n.ToString();
            if (s.Length == 1)
                return n;
            var bs = 1;
            for (int i = 0; i < s.Length - 1; i++)
			{
                bs *= 10;
			}
            var rSideL = (s.Length + 1) / 2;
            var lSide = long.Parse(new String(s.Substring(0, s.Length - rSideL).Reverse().ToArray()));
            var rSide = long.Parse(s.Substring(s.Length - rSideL));
            if (lSide == 1)
                return rSide + Cost(bs);
            return rSide + lSide + Cost(bs);
        }

        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var N = long.Parse(Console.ReadLine());

                Console.WriteLine("Case #{0}: {1}", testN, Cost(N));
            }
        }
    }
}
