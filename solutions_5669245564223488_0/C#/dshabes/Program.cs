using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2014_1C_B
{
    public struct Permutation : IEnumerable<int>, IEquatable<Permutation>, IComparable<Permutation>
    {
        private int size;
        private ulong bits;

        private Permutation(int size, ulong bits)
        {
            if (size > 16 || size < 0)
                throw new ArgumentOutOfRangeException("size", "Supported permutation sizes are 1-16");
            this.size = size;
            this.bits = bits;
        }

        public Permutation(int size)
            : this(size, 0L)
        {
            for (int i = 0; i < size; i++)
                this[i] = i;
        }

        public Permutation(params int[] elements)
            : this(elements.Length, 0L)
        {
            for (int i = 0; i < size; i++)
                this[i] = elements[i];
        }

        public Permutation(string elements) : this(elements.Select(c => c - '0').ToArray()) { }

        public int Size { get { return size; } }

        public int this[int i]
        {
            get
            {
                int shift = 4 * i;
                return (int)(((0xFUL << shift) & bits) >> shift);
            }
            private set
            {
                int shift = 4 * i;
                bits = (~(0xFUL << shift) & bits) | ((ulong)value << shift);
            }
        }

        public int GetPosition(int element)
        {
            var result = 0;
            foreach (int item in this)
            {
                if (item == element)
                    return result;
                result++;
            }
            throw new Exception("Element is not found in permutation");
        }

        public IEnumerator<int> GetEnumerator()
        {
            var b = bits;
            for (int i = 0; i < size; i++)
            {
                yield return (int)(b & 0xFUL);
                b >>= 4;
            }
        }

        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        public bool Equals(Permutation other)
        {
            return size == other.size && bits == other.bits;
        }

        public int CompareTo(Permutation other)
        {
            var result = size.CompareTo(other.size);
            if (result == 0)
                result = bits.CompareTo(other.bits);
            return result;
        }

        public override bool Equals(object obj)
        {
            return obj is Permutation && Equals((Permutation)obj);
        }

        public override int GetHashCode()
        {
            unchecked { return size.GetHashCode() * 29 + bits.GetHashCode(); }
        }

        private void swap(int i, int j)
        {
            var t = this[i];
            this[i] = this[j];
            this[j] = t;
        }

        public Permutation ApplyTo(Permutation x)
        {
            if (size != x.size)
                throw new InvalidOperationException("Composition requires equal size of permutations");

            Permutation result = new Permutation(size, 0L);
            for (int i = 0; i < size; i++)
                result[this[i]] = x[i];
            return result;
        }

        public Permutation ApplyTo(Permutation x, Permutation subSet)
        {
            Permutation result = new Permutation(x.size, x.bits);
            for (int i = 0; i < size; i++)
                result[subSet[this[i]]] = x[subSet[i]];
            return result;
        }

        public override string ToString()
        {
            return new string(this.Select(e => (char)('0' + e)).ToArray());
        }

        static Random random = new Random();

        public static Permutation Random(int size)
        {
            var result = new Permutation(size);
            for (int i = 0; i < size - 1; i++)
            {
                var r = random.Next(size - i);
                result.swap(i, i + r);
            }
            return result;
        }

        public static IEnumerable<Permutation> All(int size)
        {
            var result = new Permutation(size);
            if (size == 0)
            {
                yield return result;
                yield break;
            }
            while (true)
            {
                yield return result;
                var flipStart = size - 1;
                while (flipStart > 0 && result[flipStart] < result[flipStart - 1])
                    flipStart--;
                if (flipStart == 0)
                    yield break;
                for (int i = flipStart, j = size - 1; i < j; i++, j--)
                    result.swap(i, j);
                var swap = flipStart;
                while (result[swap] < result[flipStart - 1])
                    swap++;
                result.swap(flipStart - 1, swap);
            }
        }

        public static IEnumerable<Permutation> NChooseK(int n, int k)
        {
            var result = new Permutation(k);
            if (k == 0)
            {
                yield return result;
                yield break;
            }
            while (true)
            {
                yield return result;
                var incrementLevel = 0;
                while (incrementLevel < k - 1 && result[incrementLevel] + 1 == result[incrementLevel + 1])
                    incrementLevel++;
                if (result[incrementLevel] == n - 1)
                    yield break;
                result[incrementLevel]++;
                for (int i = 0; i < incrementLevel; i++)
                    result[i] = i;
            }
        }

        public static IEnumerable<Permutation> NChooseKWithRepeats(int n, int k)
        {
            var result = new Permutation(k, 0L);
            if (k == 0)
            {
                yield return result;
                yield break;
            }
            while (true)
            {
                yield return result;
                var incrementLevel = 0;
                while (incrementLevel < k - 1 && result[incrementLevel] == result[incrementLevel + 1])
                    incrementLevel++;
                if (result[incrementLevel] == n - 1)
                    yield break;
                result[incrementLevel]++;
                for (int i = 0; i < incrementLevel; i++)
                    result[i] = 0;
            }
        }

        public static IEnumerable<Permutation> GenerateInBase(int n, int radix)
        {
            var result = new Permutation(n, 0L);
            if (n == 0)
            {
                yield return result;
                yield break;
            }
            while (true)
            {
                yield return result;
                var incrementLevel = 0;
                while (incrementLevel < n && result[incrementLevel] == radix - 1)
                    result[incrementLevel++] = 0;
                if (incrementLevel == n)
                    yield break;
                result[incrementLevel]++;
            }
        }
    }

    class Program
    {
        static long verify(string[] sets)
        {
            var total = 0L;
            foreach (var perm in Permutation.All(sets.Length))
            {
                var r = string.Concat(perm.Select(i => sets[i]));
                var chars = new HashSet<char>();
                var broke = false;
                for (int j = 0; j < r.Length; j++)
                {
                    if (chars.Contains(r[j]))
                    {
                        if (r[j - 1] != r[j])
                        {
                            broke = true;
                            break;
                        }
                    }
                    else
                    {
                        chars.Add(r[j]);
                    }
                }
                if (!broke)
                    total++;
            }
            return total;
        }

        private static long modulo = 1000000007;
        static long factorialMod(int n)
        {
            var result = 1L;
            for (int i = 2; i <= n; i++)
            {
                result = (result * i) % modulo;
            }
            return result;
        }

        static long countMod(string[] sets)
        {
            var connectorCount = 0;
            var blocks = 0;
            var total = 1L;
            for (char c = 'a'; c <= 'z'; c++)
            {
                var twoSided = 0;
                var leftSided = false;
                var rightSided = false;
                foreach (string t in sets)
                {
                    if (t[0] == c)
                    {
                        if (t[t.Length - 1] == c)
                            twoSided++;
                        else
                        {
                            if (leftSided)
                                return 0L;
                            leftSided = true;
                        }
                    }
                    else
                    {
                        if (t[t.Length - 1] == c)
                        {
                            if (rightSided)
                                return 0L;
                            rightSided = true;
                        }
                    }
                }
                total = (total * factorialMod(twoSided)) % modulo;
                if (leftSided)
                    connectorCount++;
                if (rightSided)
                    connectorCount++;
                if (twoSided > 0 || leftSided || rightSided)
                    blocks++;
            }
            var chunks = new List<char>[26];
            foreach (var single in sets)
                if (single[0] != single[single.Length - 1])
                {
                    var chunk = chunks[single[0] - 'a'];
                    var chunk2 = chunks[single[single.Length - 1] - 'a'];
                    if (chunk != null)
                    {
                        if (chunk.Last() != single[0])
                            return 0;
                        if (chunk2 != null)
                        {
                            if (chunk2.First() != single[single.Length - 1])
                                return 0;
                            else
                            {
                                chunk.AddRange(chunk2);
                                chunks[single[single.Length - 1] - 'a'] = chunk;
                            }
                        }
                        else
                        {
                            chunk.Add(single[single.Length - 1]);
                            chunks[single[single.Length - 1] - 'a'] = chunk;
                        }
                    }
                    else if (chunk2 != null)
                    {
                        if (chunk2.First() != single[single.Length - 1])
                            return 0;
                        chunk2.Insert(0, single[0]);
                        chunks[single[0] - 'a'] = chunk2;
                    }
                    else
                    {
                        chunk = new List<char> { single[0], single[single.Length - 1] };
                        chunks[single[0] - 'a'] = chunk;
                        chunks[single[single.Length - 1] - 'a'] = chunk;
                    }
                }
            return (total * factorialMod((blocks * 2 - connectorCount) / 2)) % modulo;
        }

        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (var testN = 1; testN <= testCount; testN++)
            {
                var parts = Console.ReadLine().Split().Select(long.Parse).ToArray();
                var N = parts[0];

                var sets = Console.ReadLine().Split().ToArray();

                var broke = false;
                for (int i = 0; i < N; i++)
                {
                    var chars = new HashSet<char>();
                    for (int j = 0; j < sets[i].Length - 1; j++)
                    {
                        if (chars.Contains(sets[i][j]))
                        {
                            if (sets[i][j - 1] != sets[i][j])
                            {
                                broke = true;
                                break;
                            }
                        }
                        else
                        {
                            chars.Add(sets[i][j]);
                        }
                    }
                    if (broke)
                        break;

                    for (int j = 1; j < sets[i].Length - 1; j++)
                    {
                        if (sets[i][j] != sets[i][0] && sets[i][j] != sets[i][sets[i].Length - 1])
                        {
                            for (int k = 0; k < N; k++)
                            {
                                if (k != i && sets[k].Contains(sets[i][j]))
                                {
                                    broke = true;
                                    break;
                                }
                            }
                            if (broke)
                                break;
                        }
                    }
                    if (broke)
                        break;
                }

                var total = 0L;

                if (!broke)
                {
                    total = countMod(sets);
                    //if (total != verify(sets))
                    //{
                    //    Console.WriteLine("Case #{0} wrong! Should be {1}. Got {2}", testN, verify(sets), total);
                    //    break;
                    //}
                }
                String result = total.ToString();

                Console.WriteLine("Case #{0}: {1}", testN, result);
            }
        }
    }
}
