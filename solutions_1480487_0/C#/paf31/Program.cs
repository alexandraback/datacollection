using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Question3
{
    class Program
    {
        static void Main(string[] args)
        {
            int numCases = int.Parse(Console.ReadLine());

            for (int i = 0; i < numCases; i++)
            {
                int[] nums = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

                var solution = Solve(nums.FirstOrDefault(), nums.Skip(1).ToArray());

                Console.WriteLine(string.Format("Case #{0}: {1}", i + 1, string.Join(" ", solution)));
            }
        }

        private static IEnumerable<double> Solve(int len, int[] vals)
        {
            int total = vals.Sum();

            for (int i = 0; i < len; i++)
            {
                yield return Math.Max(0, 100.0 * (total / (double)len * 2 - vals[i]) / (double)total);
            }
        }
    }
}
