using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Z2
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; i++)
            {
                var ern = Console.ReadLine().Split(' ')
                    .Select(x => int.Parse(x))
                    .ToArray();

                int E = ern[0];
                int R = ern[1];
                int N = ern[2];

                Console.WriteLine("Case #{0}: {1}",
                    i + 1,
                    new Solver(E,R,Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray()).Solve());

            }
        }
    }

    public class Solver
    {
        int E;
        int R;
        int[] v;

        public Solver(int E, int R, int[] v)
        {
            this.E = E;
            this.R = R;
            this.v = v;

            if (R > E)
                R = E;
        }

        private int max = 0;

        public int Solve()
        {
            if (E == R)
                return v.Sum(x => x * E);

            Solve(0, E, 0);

            return max;
        }

        public void Solve(int lvl, int e, int pts)
        {
            if (lvl == v.Length)
            {
                max = Math.Max(max, pts);
                return;
            }

            for (int i = 0; i <= e; i++)
                Solve(lvl + 1, Math.Min(e - i + R, E), pts + (i * v[lvl]));
        }

    }
}
