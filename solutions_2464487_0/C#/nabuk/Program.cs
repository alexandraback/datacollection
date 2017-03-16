using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Z1
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; i++)
            {
                var rt = Console.ReadLine().Split(' ')
                    .Select(x => long.Parse(x))
                    .ToArray();

                Console.WriteLine("Case #{0}: {1}",
                    i + 1,
                    new Solver(rt[0], rt[1]).Solve());

            }
            
        }
    }

    class Solver
    {
        private long r;
        private long t;

        public Solver(long r, long t)
        {
            this.r = r;
            this.t = t;
        }

        public long Solve()
        {
            long result = 0;
            while (t > 0)
            {
                t -=
                    Area(r + 1) - Area(r);

                r += 2;

                if (t >= 0)
                    result++;
            }
            return result;

        }

        long Area(long r)
        {
            return (long)(r*r);

        }
    }
}
