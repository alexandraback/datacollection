using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ConsoleApplication1
{
    public sealed class JamCoin: IReadOnlyDictionary<int, ulong>
    {
        private readonly Dictionary<int, ulong> _base2Value;

        public JamCoin(ulong mask)
        {
            if ((mask%2) != 1)
                throw new ArgumentException("", nameof(mask));

            _base2Value = Enumerable.Range(2, 9)
                      .ToDictionary(@base => @base,
                                    @base => ParseInBase(mask, @base));
        }

        private static ulong ParseInBase(ulong mask, int @base)
        {
            ulong value = 0, add = 1;
            while (mask > 0)
            {
                if ((mask & 1) == 1)
                    value += add;
                add *= (ulong) @base;
                mask >>= 1;
            }
            return value;
        }

        public IEnumerator<KeyValuePair<int, ulong>> GetEnumerator()
        {
            return _base2Value.GetEnumerator();
        }

        public override string ToString()
        {
            return Convert.ToString((long) _base2Value[2], 2);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return _base2Value.GetEnumerator();
        }

        public static IEnumerable<JamCoin> AllOfLength(int length)
        {
            ulong number = (1UL << (length - 1)) + (length != 1 ? 1UL : 0);
            ulong bound = 1UL << length;
            do
            {
                yield return new JamCoin(number);
                number += 2;
            } while (number < bound);
        }

        public int Count
        {
            get { return _base2Value.Count; }
        }

        public bool ContainsKey(int key)
        {
            return _base2Value.ContainsKey(key);
        }

        public bool TryGetValue(int key, out ulong value)
        {
            return _base2Value.TryGetValue(key, out value);
        }

        public ulong this[int key]
        {
            get { return _base2Value[key]; }
        }

        public IEnumerable<int> Keys
        {
            get { return _base2Value.Keys; }
        }

        public IEnumerable<ulong> Values
        {
            get { return _base2Value.Values; }
        }
    }

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

        private static void WriteOutput(KeyValuePair<JamCoin, ulong[]>[][] solutions)
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

        private static ulong FindDivisor(ulong number)
        {
            for (var divisor = 2UL; divisor < Math.Sqrt(number) + 1; divisor++)
                if (number % divisor == 0)
                    return divisor;
            return 0;
        }

        public static KeyValuePair<JamCoin, ulong[]>[] Solve(int n, int j)
        {
            return JamCoin.AllOfLength(n)
                          .Select(jamcoin =>
                                  new KeyValuePair<JamCoin, ulong[]>(
                                      jamcoin,
                                      jamcoin.Values.Select(FindDivisor).ToArray()))
                          .Where(pair => pair.Value.All(divisor => divisor != 0))
                          .Take(j)
                          .ToArray();
        }
    }
}