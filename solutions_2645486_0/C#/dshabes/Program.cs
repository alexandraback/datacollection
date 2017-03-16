using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ1B
{
    class Program
    {
        static long E;
        static long R;
        static long[] values;

        static long best(long e, int step)
        {
            if (step >= values.Length)
                return 0;
            var max = 0L;
            for (int i = 0; i <= e; i++)
                max = Math.Max(max, best(Math.Min(E, e - i + R), step + 1) + i * values[step]);
            return max;
        }

        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testNumber = 1; testNumber <= testCount; testNumber++)
            {
                var parts = Console.ReadLine().Split();
                E = long.Parse(parts[0]);
                R = long.Parse(parts[1]);

                values = Console.ReadLine().Split().Select(long.Parse).ToArray();


                Console.WriteLine("Case #{0}: {1}", testNumber, best(E, 0));
            }
        }
    }
}
