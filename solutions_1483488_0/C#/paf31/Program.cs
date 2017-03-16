using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamRecycledNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            string numCasesString = Console.ReadLine();

            int numCases = int.Parse(numCasesString);

            for (int i = 0; i < numCases; i++)
            {
                string problem = Console.ReadLine();
                int solved = Solve(problem);
                Console.WriteLine(string.Format("Case #{0}: {1}", i + 1, solved));
            }
        }

        private static IEnumerable<int> Rotations(int i)
        {
            int numDigits = i.ToString().Length;

            int n = i;

            int multiplier = 1;

            for (int j = 0; j < numDigits - 1; j++)
            {
                multiplier *= 10;
            }

            for (int j = 0; j < numDigits - 1; j++)
            {
                int leading = n / 10;
                int trailing = n % 10;
                n = trailing * multiplier + leading;
                yield return n;
            }
        }

        private static int Solve(string problem)
        {
            string[] split = problem.Split(' ');

            int lower = int.Parse(split[0]);
            int upper = int.Parse(split[1]);

            var pairs =
                from a in Enumerable.Range(lower, upper - lower)
                from b in Rotations(a)
                where b > a && b >= lower && b <= upper
                select new { A = a, B = b };

            return pairs.Distinct().Count();
        }
    }
}
