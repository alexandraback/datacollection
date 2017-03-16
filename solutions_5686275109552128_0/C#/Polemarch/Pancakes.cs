using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Pancakes
    {
        public static void Run(CodeJamHelper helper)
        {
            var numTestCases = helper.ReadLineInt32();
            foreach (var n in Enumerable.Range(1, numTestCases))
            {
                var diners = helper.ReadLineInt32();
                var counts = helper.ReadInt32Array();                

                var optimalMinutes = Solve(counts);

                helper.OutputCase(optimalMinutes);
            }
        }

        public static int Solve(int[] countArray)
        {
            var counts = countArray.OrderByDescending(x => x).ToList();
            //for(int i=1; i <= counts[0]; ++i)
            //{
            //    Console.WriteLine("Max {0} pancakes: {1} minutes", i, SolveHelper(counts, i));
            //}
            return Enumerable.Range(1, counts[0]).Min(i => SolveHelper(counts, i));
        }

        public static int SolveHelper(List<int> counts, int maxPancakes)
        {
            return counts.Sum(c => (c + (maxPancakes - 1)) / maxPancakes - 1) + maxPancakes;
        }
    }
}
