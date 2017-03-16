using System;
using System.IO;
using System.Linq;

namespace ConsoleApplication1
{
    public static class Program
    {
        private static Tuple<byte, byte, byte>[] ReadInput()
        {
            using (var reader = new StreamReader("input.txt"))
            {
                var testsNum = int.Parse(reader.ReadLine());
                var testCases = new Tuple<byte, byte, byte>[testsNum];

                for (int i = 0; i < testsNum; i++)
                {
                    var array = reader.ReadLine().Split(' ').Select(byte.Parse).ToArray();
                    testCases[i] = new Tuple<byte, byte, byte>(array[0], array[1], array[2]);
                }

                return testCases;
            }
        }

        private static void WriteOutput(ulong[][] solutions)
        {
            using (var writer = new StreamWriter("output.txt"))
            {
                for (int i = 0; i < solutions.Length; i++)
                {
                    writer.WriteLine("Case #{0}: {1}",
                                     i + 1,
                                     solutions[i] != null
                                         ? string.Join(" ", solutions[i])
                                         : "IMPOSSIBLE");
                }
            }
        }

        private static void Main()
        {
            WriteOutput(ReadInput().Select(t => Solve(t.Item1, t.Item2, t.Item3)).ToArray());
        }

        public static ulong[] Solve(byte k, byte c, byte s)
        {
            if (k > c * s)
                return null;

            // not the best in terms of speed but good enough
            return Enumerable.Range(1, k)
                             .Select(tile => (ulong) tile)
                             .GroupBy(tile => (tile - 1) / c) // divide into subsequences of length ≤ c)
                             .Select(tileSet =>
                                     {
                                         ulong index = 1, seqShift = 1;
                                         foreach (var tile in tileSet.Reverse())
                                         {
                                             index += seqShift * (tile - 1);
                                             seqShift *= k;
                                         }
                                         return index;
                                     })
                             .ToArray();
        }
    }
}