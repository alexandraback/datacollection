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

                string solution = Solve(nums.FirstOrDefault(), nums.Skip(1).ToArray());

                Console.WriteLine(string.Format("Case #{0}:", i + 1));
                Console.WriteLine(solution);
            }
        }

        private static IEnumerable<Tuple<int[], int[]>> Subsets(IEnumerable<int> ns)
        {
            if (!ns.Any())
            {
                yield break;
            }

            int n = ns.FirstOrDefault();

            if (ns.Count() == 1)
            {
                yield return Tuple.Create(new int[0], new int[] { ns.FirstOrDefault() });
                yield return Tuple.Create(new int[] { ns.FirstOrDefault() }, new int[0]);
            }
            else
            {
                foreach (Tuple<int[], int[]> pair in Subsets(ns.Skip(1)))
                {
                    yield return Tuple.Create(pair.Item1.Concat(new[] { n }).ToArray(), pair.Item2);
                    yield return Tuple.Create(pair.Item1, pair.Item2.Concat(new[] { n }).ToArray());
                    yield return pair;
                }
            }
        }

        private static string Solve(int len, int[] vals)
        {
            foreach (var pair in Subsets(vals))
            {
                if (pair.Item1.Sum() == pair.Item2.Sum())
                {
                    return string.Join(" ", pair.Item1) + "\n" + string.Join(" ", pair.Item2);
                }
            }

            return "Impossible";
        }
    }
}
