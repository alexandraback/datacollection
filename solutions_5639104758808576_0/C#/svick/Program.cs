using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using GCJ_base;

namespace GCJ_QA
{
    class Program
    {
        static void Main()
        {
            new GcjQA().Run();
        }
    }

    class GcjQA : Gcj
    {
        public GcjQA()
        {
            Problem = 'A';
            Small = true;
        }

        protected override string ComputeCase(TextReader reader)
        {
            string countsString = reader.ReadLine().Split(' ')[1];
            var counts = countsString.Select(c => int.Parse(c.ToString())).ToList();

            var sums = Sums(counts);
            var requireds = Enumerable.Range(1, counts.Count);

            var toAdd = sums.Zip(requireds, (sum, required) => required - sum);

            var toAddMax = Math.Max(0, toAdd.Max());

            return toAddMax.ToString();
        }

        private static IEnumerable<int> Sums(IEnumerable<int> input)
        {
            int sum = 0;
            foreach (var x in input)
            {
                sum += x;
                yield return sum;
            }
        }
    }
}