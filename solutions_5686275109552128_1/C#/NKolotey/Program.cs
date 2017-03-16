using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                int D = int.Parse(Console.ReadLine());
                int[] P = Array.ConvertAll(Console.ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);

                int best = int.MaxValue;
                for (int lim = 1; lim <= 1000; lim++)
                {
                    int total = 0;
                    for(int i = 0; i < D; i++)
                    {
                        int splits = (P[i] + lim - 1) / lim - 1;
                        total += splits;
                    }

                    best = Math.Min(best, lim + total);
                }

                Console.WriteLine("Case #{0}: {1}", t, best);
            }
        }
    }
}
