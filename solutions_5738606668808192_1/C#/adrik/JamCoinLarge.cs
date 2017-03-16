using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Qualification
{
    public class JamCoinLarge
    {
        public string[] Run(int n, int j)
        {
            var coins = new List<string>();
            GenerateCoins(n, j, "", coins);

            return coins.ToArray();
        }

        public void Run(string inputFile, string outputFile)
        {
            var splitters = new[] { ' ' };
            var dividers = " 3 2 3 2 7 2 3 2 3";
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
                        Run(n, j).Select(jc => jc + dividers));
                });

            File.WriteAllLines(outputFile, outputLines);
        }

        private bool IsJam(string coin)
        {
            var ones = coin.Count(c => c == '1');
            if (ones%6 != 0) return false; // divides by 3 in base 10 and by 2 in odd bases

            var inb6 = ToBase(coin, 6);
            if (Math.Truncate(inb6/7)*7 != inb6)
                return false; // is not divided by 7 in base 6

            foreach (var b in new[] {2,4,8})
            {
                var inb = ToBase(coin, b);
                if (Math.Truncate(inb / 3) * 3 != inb)
                    return false;
            }

            return true;
        }

        private void GenerateCoins(int n, int j, string pref, List<string> coins)
        {
            if (coins.Count == j) return;

            if (pref.Length == n)
            {
                if (IsJam(pref))
                    coins.Add(pref);
                return;
            }
            if (pref.Length == n - 1)
            {
                GenerateCoins(n, j, pref + "1", coins);
                return;
            }

            if (pref.Length != 0)
                GenerateCoins(n, j, pref + "0", coins);
            GenerateCoins(n, j, pref + "1", coins);
        }

        private decimal ToBase(string coin, int b)
        {
            decimal num = 0;

            foreach (var digit in coin)
            {
                num *= b;
                if (digit == '1')
                    num += 1;
            }

            return num;
        }
    }
}