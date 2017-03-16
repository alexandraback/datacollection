using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            var T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; i++)
            {
                // Read input
                var input = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries).Select(s => long.Parse(s)).ToArray();
                long A = input[0];
                long N = input[1];
                var Motes = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries).Select(s => long.Parse(s)).ToArray();
                var sortedMotes = new List<long>(Motes);
                sortedMotes.Sort();
                // Process

                var result = GetResult(A, sortedMotes, 0);
                // Write Output

                Console.WriteLine("Case #{0}: {1}", i + 1, result);
            }
        }

        static long GetResult(long A, List<long> sortedMotes, long stackCount)
        {
            //Console.WriteLine("Stack Count is {0}", stackCount);
            if (sortedMotes.Count == 0)
                return 0;
            var bestResult = (long)sortedMotes.Count;
            if (A == 1)
                return bestResult;
            if (A <= sortedMotes[0])
            {
                var result = 1 + GetResult(A + A - 1, sortedMotes, stackCount + 1);
                if (result < bestResult)
                {
                    bestResult = result;
                }
            }
            else if (A > sortedMotes[0])
            {
                var result = GetResult(A + sortedMotes[0], sortedMotes.GetRange(1, sortedMotes.Count - 1), stackCount + 1);
                if (result < bestResult)
                {
                    bestResult = result;
                }
            }

            return bestResult;
        }
    }
}
