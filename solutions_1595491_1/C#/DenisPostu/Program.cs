using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ.B
{
    class Program
    {
        static void Main(string[] args)
        {
            var worker = new Worker();

            using (var reader = new StreamReader("d:/B-large.in"))
            {
                using (var writer = new StreamWriter("d:/B-large.txt"))
                {
                    int cases = int.Parse(reader.ReadLine());
                    for (int c = 1; c <= cases; c++)
                    {
                        var pairs = reader.ReadLine().Split().Select(s => int.Parse(s)).ToList();
                        var result = worker.Compute(pairs[0], pairs[1], pairs[2], pairs.Skip(3).ToArray());
                        writer.WriteLine(string.Format("Case #{0}: {1}", c, result));
                        Console.WriteLine(string.Format("Case #{0}/{2}: {1}", c, /*result,*/ result, cases));
                    }
                }
            }

            Console.ReadKey();
        }
    }

    class Worker
    {
        public int Compute(int g, int s, int p, int[] vals)
        {
            int sure = 0;
            int potential = 0;
            foreach (var val in vals)
            {
                if (IsSure(val, p)) sure++;
                else if (IsPotential(val, p)) potential++;
            }

            return sure + Math.Min(potential, s);
        }

        private bool IsSure(int val, int p)
        {
            return val >= 3 * p - 2;
        }

        private bool IsPotential(int val, int p)
        {
            return (val >= 3 * p - 4 && 3 * p - 4 > 0) || (val >= 3 * p - 3 && 3 * p - 3 > 0);
        }
    }
}
