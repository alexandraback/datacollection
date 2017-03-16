using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace QualificationProblemA
{
    using System.IO;
    using System.Numerics;

    class Program
    {
        private static string inputFilePath = @"C:\Users\Kai\Downloads\C-small-attempt1.in";

        static void Main(string[] args)
        {
            Console.SetOut(new StreamWriter("C:/temp/output.txt"));

            var input = ReadInput();
            var output = Compute(input);
            PrintOutput(output);

            Console.Out.Flush();
            //Console.ReadLine();
        }

        private static void PrintOutput(Output output)
        {
            for (int i = 0; i < output.Results.Count; i++)
            {
                Console.WriteLine("Case #{0}: {1}", i + 1, output.Results[i].Count);
            }
        }

        private static Output Compute(Input input)
        {
            var output = new Output();

            foreach (var c in input.Cases)
            {
                output.Results.Add(Compute(c));
            }

            return output;
        }

        private static Result Compute(TestCase input)
        {
            var sqrt = Sqrt(input.A);
            var sqrtB = Sqrt(input.B);

            var count = 0;
            for (int i = sqrt.ToString().Length; i <= sqrtB.ToString().Length; i++)
            {
                count += GetCountForLength(i, input);
            }

            if (9 >= input.A && 9 <= input.B)
            {
                count++;
            }

            return new Result { Count = count };
        }

        private static int GetCountForLength(int length, TestCase testCase)
        {
            var count = GetMixedCountForLength(length, testCase, "1", "2");
            count += GetMixedCountForLength(length, testCase, "2", "1");
            count += GetOneCountForLength(length, testCase);

            return count;
        }

        private static int GetOneCountForLength(int length, TestCase testCase)
        {
            var minValue = MakeValue("1", length);
            return RecursiveCount(minValue, testCase, minValue.ToString().Length - 2, 1, true);
        }

        private static int GetMixedCountForLength(int length, TestCase testCase, string first, string second)
        {
            int count = 0;

            var minValue = MakeValue(first, length);
            var square = minValue * minValue;

            if (square >= testCase.A && square <= testCase.B)
            {
                count++;
            }

            // odd and 3 or longer
            if (length > 1 && length % 2 == 1)
            {
                var addition = second.PadRight(length / 2, '0');
                var newValue = minValue + BigInteger.Parse(addition);

                square = newValue * newValue;

                if (square >= testCase.A && square <= testCase.B)
                {
                    count++;
                }
            }

            return count;
        }

        private static BigInteger MakeValue(string firstDigit, int length)
        {
            var stringValue = length > 2
                                    ? firstDigit.PadRight(length - 1, '0') + firstDigit
                                    : length > 1 ? firstDigit + firstDigit : firstDigit;

            return BigInteger.Parse(stringValue);
        }

        private static int RecursiveCount(BigInteger currentNumber, TestCase testCase, int frontPosition, int backPosition, bool sameNumber)
        {
            int count = 0;
            var square = currentNumber * currentNumber;

            if (!sameNumber && square >= testCase.A && square <= testCase.B)
            {
                count++;
            }
            else if (square > testCase.B)
            {
                return count;
            }

            if (frontPosition < backPosition)
            {
                // no more to do
            }
            else
            {
                // try with a 0
                count += RecursiveCount(currentNumber, testCase, frontPosition - 1, backPosition + 1, true);

                var numOnes = currentNumber.ToString().Count(c => c == '1');

                // try with another 1
                if (frontPosition == backPosition)
                {
                    if (numOnes < 9)
                    {
                        currentNumber = currentNumber + BigInteger.Parse("1".PadRight(frontPosition - 1, '0'));
                        count += RecursiveCount(currentNumber, testCase, frontPosition - 1, backPosition + 1, false);
                    }
                }
                else if (numOnes < 8)
                {
                    currentNumber = currentNumber
                                    + BigInteger.Parse(
                                        "1".PadRight(frontPosition - backPosition - 1, '0') + "1".PadRight(backPosition, '0'));
                    count += RecursiveCount(currentNumber, testCase, frontPosition - 1, backPosition + 1, false);
                }
                
            }

            return count;
        }

        public static BigInteger Sqrt(BigInteger n)
        {
            if (n == 0) return 0;
            if (n > 0)
            {
                int bitLength = Convert.ToInt32(Math.Ceiling(BigInteger.Log(n, 2)));
                BigInteger root = BigInteger.One << (bitLength / 2);

                while (!isSqrt(n, root))
                {
                    root += n / root;
                    root /= 2;
                }

                return root;
            }

            throw new ArithmeticException("NaN");
        }

        private static Boolean isSqrt(BigInteger n, BigInteger root)
        {
            BigInteger lowerBound = root * root;
            BigInteger upperBound = (root + 1) * (root + 1);

            return (n >= lowerBound && n < upperBound);
        }

        private static Input ReadInput()
        {
            var input = new Input();

            var inputFile = File.ReadLines(inputFilePath);
            input.Cases = new List<TestCase>();

            foreach (var line in inputFile.Skip(1))
            {
                var testCase = new TestCase();
                var tokens = line.Split(' ');

                testCase.A = BigInteger.Parse(tokens[0]);
                testCase.B = BigInteger.Parse(tokens[1]);

                input.Cases.Add(testCase);
            }

            return input;
        }
    }

    internal class Output
    {
        public Output()
        {
            Results = new List<Result>();
        }

        public IList<Result> Results { get; set; }
    }

    internal class Input
    {
        public IList<TestCase> Cases { get; set; }
    }

    internal class TestCase
    {
        public BigInteger A { get; set; }
        public BigInteger B { get; set; }
    }

    internal class Result
    {
        public int Count { get; set; }
    }
}
