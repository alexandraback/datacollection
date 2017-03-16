using System.Collections.Generic;
using System.Linq;

namespace CodeJam2013Cs
{
    using System;
    using System.IO;
    using System.Numerics;
    using System.Text;

    class Program
    {
        public static string ReverseString(string input)
        {
            var chars = input.Reverse();
            var sb = new StringBuilder();

            foreach (var c in chars)
            {
                sb.Append(c);
            }
            return sb.ToString();
        }

        public static void FairAndSquare(string fileName)
        {
            // Read the file.
            var inputLines = File.ReadAllLines(fileName).Skip(1);
            var testCases = new List<Tuple<BigInteger, BigInteger>>();
            var outputLines = new List<string>();
            var testCaseIndex = 1;

            foreach (var line in inputLines)
            {
                var parts = line.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                testCases.Add(new Tuple<BigInteger, BigInteger>(BigInteger.Parse(parts[0]), BigInteger.Parse(parts[1])));
            }

            // Pre-compute some values.
            var start = new BigInteger(Convert.ToInt32(1));
            var max = testCases.Max(x => x.Item2);
            var palindromes = new Dictionary<BigInteger, BigInteger>();

            for (var i = start; i <= Sqrt(max); i++)
            {
                var s = i.ToString();
                var sr = ReverseString(s);

                var number = BigInteger.Parse(s + sr.Substring(1));
                if (number > max)
                {
                    break;
                }

                var numberTwo = BigInteger.Parse(s + sr);

                var nTo2 = number * number;
                var n2To2 = numberTwo * numberTwo;

                var nTo2s = nTo2.ToString();
                var n2To2s = n2To2.ToString();

                if (nTo2s == ReverseString(nTo2s))
                {
                    palindromes.Add(nTo2, number);
                }
                if (n2To2s == ReverseString(n2To2s))
                {
                    palindromes.Add(n2To2, numberTwo);
                }
            }

            // Solve the problem.
            foreach (var test in testCases)
            {
                outputLines.Add(string.Format("Case #{0}: {1}", testCaseIndex, palindromes.Keys.Count(x => x >= test.Item1 && x <= test.Item2)));
                testCaseIndex++;
            }

            // Write the output.
            using (var file = new StreamWriter(@"C:\codejam\c-large-1-out.txt"))
            {
                foreach (var line in outputLines)
                {
                    file.WriteLine(line);
                }
            }
        }

        public static BigInteger Sqrt(BigInteger value)
        {
            return new BigInteger(Math.Exp(BigInteger.Log(value) / 2));
        }

        static void Main()
        {
            const string inputFile = @"C:\codejam\C-large-1.in";
            FairAndSquare(inputFile);
        }
    }
}
