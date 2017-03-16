using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;

namespace GoogleCodeJam
{
    class C
    {
        static void Main(string[] args)
        {
            //Console.WriteLine(Solver.CanGetDijkstra(10 * 1000, 1000L * 50, "i" + new string('j', 99999)));
            var input = @"C:\Users\kaspir\Downloads\C-small-attempt1.in";

            File.WriteAllLines(Path.ChangeExtension(input, "out"), Solver.Solve(File.ReadAllLines(input)));

            Console.WriteLine("Press ENTER to finish");
            Console.ReadLine();
        }

        public class Solver
        {
            public static IEnumerable<string> Solve(IEnumerable<string> input)
            {
                var reader = new Reader(input);

                var testCount = Int32.Parse(reader.Next());

                for (var i = 0; i < testCount; i++)
                {
                    var parts = reader.Next().Split(' ').Select(Int64.Parse).ToList();
                    var L = parts[0];
                    var X = parts[1];
                    var str = reader.Next();
                    var message = String.Format("Case #{0}: {1}", i + 1, CanGetDijkstra(L, X, str) ? "YES" : "NO");
                    Console.WriteLine(message);
                    yield return message;
                }
            }

            static readonly int[][] MulMatrix =
            {
                new[] { 0, 1, 2, 3 },
                new[] { 1, 0, 3, 2 },
                new[] { 2, 3, 0, 1 },
                new[] { 3, 2, 1, 0 }
            };

            static readonly bool[][] IsNegative =
            {
                new[] { false, false, false, false },
                new[] { false, true, false, true },
                new[] { false, true, true, false },
                new[] { false, false, true, true }
            };

            static void Multiply(int left, int right, out int result, out bool isNegative)
            {
                result = MulMatrix[left][right];
                isNegative = IsNegative[left][right];
            }

            public static bool CanGetDijkstra(long L, long X, string str)
            {
                Console.WriteLine("L={0}, X={1}", L, X);
                var result = 0;

                var targets = new[] { 1, 2, 3 };
                var targetIndex = 0;
                var isPositive = true;

                var values = str.Select(Q.GetValueIndex).ToList();

                for (var i = 0L; i < L * X; i++)
                {
                    var c = values[(int)(i % str.Length)];
                    bool changeSign;
                    Multiply(result, c, out result, out changeSign);

                    if (changeSign)
                        isPositive = !isPositive;

                    if (targetIndex < targets.Length && isPositive && targets[targetIndex].Equals(result))
                    {
                        targetIndex++;
                        result = 0;
                    }
                }

                return targetIndex == targets.Length && result == 0 && isPositive;
            }
        }

        class Reader
        {
            readonly IEnumerator<string> _enumerator;

            public Reader(IEnumerable<string> lines)
            {
                _enumerator = lines.GetEnumerator();
            }

            public string NextOrNull()
            {
                if (!_enumerator.MoveNext())
                    return null;

                return _enumerator.Current;
            }

            public string Next()
            {
                if (!_enumerator.MoveNext())
                    throw new ApplicationException("End of input");

                return _enumerator.Current;
            }
        }
    }

    public struct Q
    {
        public static int GetValueIndex(char c)
        {
            switch (c)
            {
                case '1':
                    return 0;
                case 'i':
                    return 1;
                case 'j':
                    return 2;
                case 'k':
                    return 3;
                default:
                    return -1;
            }
        }
    }
}