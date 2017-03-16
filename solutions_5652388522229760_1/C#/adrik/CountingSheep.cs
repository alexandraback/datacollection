using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Qualification
{
    public class CountingSheep
    {
        public int MaxDigits { get; private set; } = 0;
        public int MaxCount { get; private set; } = 0;

        public int Run(int n)
        {
            if (n == 0) return -1;

            var digits = new List<int>();
            var nCopy = n;
            while (nCopy > 0)
            {
                digits.Add(nCopy%10);
                nCopy = nCopy/10;
            }

            var nDigits = digits.ToArray();
            var seenDigits = new bool[10];
            var unseen = 10;

            foreach (var digit in nDigits.Where(digit => !seenDigits[digit]))
            {
                seenDigits[digit] = true;
                unseen--;
            }

            var count = 1;
            while (unseen > 0)
            {
                for (var i = 0; i < nDigits.Length; i++)
                    digits[i] += nDigits[i];

                for (var i = 0; i < digits.Count - 1; i++)
                {
                    if (digits[i] <= 9) continue;
                    digits[i + 1]++;
                    digits[i] -= 10;
                }

                if (digits[digits.Count - 1] > 9)
                {
                    digits[digits.Count - 1] -= 10;
                    digits.Add(1);
                }

                foreach (var digit in digits.Where(digit => !seenDigits[digit]))
                {
                    seenDigits[digit] = true;
                    unseen--;
                }
                count++;
            }

            MaxDigits = Math.Max(MaxDigits, digits.Count);
            MaxCount = Math.Max(MaxCount, count);

            return count*n;
        }

        public void Run(string inputFile, string outputFile)
        {
            var inputLines = File.ReadAllLines(inputFile);
            var outputLines = inputLines
                .Skip(1)
                .Take(int.Parse(inputLines[0]))
                .Select((l, i) => $"Case #{i+1}: {ToText(Run(int.Parse(l)))}");

            File.WriteAllLines(outputFile, outputLines);
        }

        private string ToText(int result)
        {
            return result < 0
                ? "INSOMNIA"
                : result.ToString();
        }
    }
}