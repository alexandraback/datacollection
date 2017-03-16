using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;

namespace ConsoleApplication1
{
    public static class Program
    {
        private static Tuple<int, int>[] ReadInput()
        {
            using (var reader = new StreamReader("input.txt"))
            {
                var testsNum = int.Parse(reader.ReadLine());
                var testCases = new Tuple<int, int>[testsNum];

                for (int i = 0; i < testsNum; i++)
                {
                    var array = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                    testCases[i] = new Tuple<int, int>(array[0], array[1]);
                }

                return testCases;
            }
        }

        private static void WriteOutput(KeyValuePair<JamCoin, BigInteger[]>[][] solutions)
        {
            using (var writer = new StreamWriter("output.txt"))
            {
                for (int i = 0; i < solutions.Length; i++)
                {
                    writer.WriteLine("Case #{0}:", i + 1);
                    foreach (var pair in solutions[i])
                    {
                        writer.WriteLine("{0} {1}", pair.Key, string.Join(" ", pair.Value));
                    }
                }
            }
        }

        private static void Main()
        {
            WriteOutput(ReadInput().Select(t => Solve(t.Item1, t.Item2)).ToArray());
        }

        private static BigInteger TryFindDivisor(BigInteger number)
        {
            //var bound = (BigInteger) (Math.Exp(BigInteger.Log(number) / 2) + 1);
            var bound = 12; // 3 2 5 2 7 2 3 2 11 mostly
            for (BigInteger divisor = 2; divisor < bound; divisor++)
                if (number % divisor == 0)
                    return divisor;
            return 0;
        }

        public static KeyValuePair<JamCoin, BigInteger[]>[] Solve(int n, int j)
        {
            return JamCoin.AllOfLength(n)
                          .Select(jamcoin =>
                                  new KeyValuePair<JamCoin, BigInteger[]>(
                                      jamcoin,
                                      jamcoin.Values.Select(TryFindDivisor).ToArray()))
                          .Where(pair => pair.Value.All(divisor => divisor != 0))
                          .Take(j)
                          .ToArray();
        }
    }
}