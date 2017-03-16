using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ13_1A_B1
{
    class Program
    {
        static int maxE;

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int nc = 1; nc <= T; nc++)
            {
                string[] ss = Console.ReadLine().Split(' ');
                int E = int.Parse(ss[0]);
                int R = int.Parse(ss[1]);
                int N = int.Parse(ss[2]);
                int[] v = new int[N];
                ss = Console.ReadLine().Split(' ');
                for (int i = 0; i < N; i++) v[i] = int.Parse(ss[i]);

                maxE = E;
                Console.WriteLine("Case #{0}: {1}", nc, findmax(E, R, v, 0));
            }
        }

        private static int findmax(int E, int R, int[] v, int p)
        {
            if (p >= v.Length) return 0;

            int max = 0;
            for (int i = 0; i <= E; i++)
            {
                max = Math.Max(max, i * v[p] + findmax(Math.Min(maxE, E - i + R), R, v, p + 1));
            }

            return max;
        }
    }
}
