using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Qualification
{
    public class JamCoinSmall
    {
        public JamCoin[] Run(int n, int j)
        {
            var max = long.Parse(new string(Enumerable.Repeat('1', n).ToArray()));
            var bases = Enumerable.Range(2, 9).ToArray();
            var primes = CalculatePrimes((long) Math.Sqrt(max));
            var jamcoins = new List<JamCoin>();

            for (var i = 0; i < 1 << (n - 2); i++)
            {
                var s = "1" + new string(
                    Enumerable.Range(0, n - 2).Select(
                        d => (i & 1 << d) > 0 ? '1' : '0').ToArray()) + "1";
                var coin = long.Parse(s);
                var isJam = true;
                var dividers = new List<long>();

                foreach (var inBase in bases.Select(b => ToBase(coin, b)))
                {
                    var divider = FindDivider(inBase, primes);
                    if (divider == 0)
                    {
                        isJam = false;
                        break;
                    }
                    dividers.Add(divider);
                }

                if (isJam)
                    jamcoins.Add(new JamCoin(coin, dividers.ToArray()));

                if (jamcoins.Count == j)
                    break;
            }

            return jamcoins.ToArray();
        }

        public void Run(string inputFile, string outputFile)
        {
            var splitters = new[] { ' ' };
            var inputLines = File.ReadAllLines(inputFile);
            var outputLines = inputLines
                .Skip(1)
                .Take(int.Parse(inputLines[0]))
                .SelectMany((l, i) =>
                {
                    var parts = l.Split(splitters, StringSplitOptions.RemoveEmptyEntries);
                    var n = int.Parse(parts[0]);
                    var j = int.Parse(parts[1]);

                    return Enumerable.Repeat($"Case #{i + 1}:", 1).Union(
                        Run(n, j).Select(jc => jc.ToString()));
                });

            File.WriteAllLines(outputFile, outputLines);
        }

        public class JamCoin
        {
            public JamCoin(long coin, long[] divisors)
            {
                Coin = coin;
                Divisors = divisors;
            }

            public long Coin { get; private set; } 

            public long[] Divisors { get; private set; }

            public override string ToString()
            {
                return Coin + " " + string.Join(" ", Divisors.Select(c => c.ToString()));
            }
        }

        private long FindDivider(long number, IEnumerable<long> primes)
        {
            var sqrt = (long)Math.Sqrt(number);
            return primes.TakeWhile(p => p <= sqrt).FirstOrDefault(p => number % p == 0);
        }

        private long[] CalculatePrimes(long max)
        {
            var primes = new List<long> { 2 };
            for (var i = 3; i < max; i += 2)
            {
                if (FindDivider(i, primes) == 0) primes.Add(i);
            }
            return primes.ToArray();
        }

        private long ToBase(long number, int b)
        {
            if (number == 0) return 0;
            if (b == 10) return number;

            return ToBase(number/10, b)*b + number%10;
        }
    }
}