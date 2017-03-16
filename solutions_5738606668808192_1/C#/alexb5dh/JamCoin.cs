using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;

namespace ConsoleApplication1
{
    public sealed class JamCoin: IReadOnlyDictionary<int, BigInteger>
    {
        private readonly Dictionary<int, BigInteger> _base2Value;

        public JamCoin(ulong mask)
        {
            if ((mask%2) != 1)
                throw new ArgumentException("", nameof(mask));

            _base2Value = Enumerable.Range(2, 9)
                                    .ToDictionary(@base => @base,
                                                  @base => ParseInBase(mask, @base));
        }

        private static BigInteger ParseInBase(ulong mask, int @base)
        {
            BigInteger value = 0, add = 1;
            while (mask > 0)
            {
                if ((mask & 1) == 1)
                    value += add;
                add *= @base;
                mask >>= 1;
            }
            return value;
        }

        public IEnumerator<KeyValuePair<int, BigInteger>> GetEnumerator()
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

        public bool TryGetValue(int key, out BigInteger value)
        {
            return _base2Value.TryGetValue(key, out value);
        }

        public BigInteger this[int key]
        {
            get { return _base2Value[key]; }
        }

        public IEnumerable<int> Keys
        {
            get { return _base2Value.Keys; }
        }

        public IEnumerable<BigInteger> Values
        {
            get { return _base2Value.Values; }
        }
    }
}