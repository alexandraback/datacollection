namespace CodeJam
{
    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Linq;
    using System.Numerics;

    class Program
    {
        private const string OutputFile = "C:/temp/output.txt";

        private const string InputFilePath =
            @"C:\Users\Kai\Downloads\A-small-attempt1.in";
        //@"C:\temp\input.txt";

        #region Common

        static void Main(string[] args)
        {
            Console.SetOut(new StreamWriter(OutputFile));

            var input = ReadInput();
            var output = Compute(input);
            PrintOutput(output);

            Console.Out.Flush();
        }

        private static void PrintOutput(Output output)
        {
            for (int i = 0; i < output.Results.Count; i++)
            {
                Console.WriteLine("Case #{0}: {1}", i + 1, output.Results[i].ToString());
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

        private static Input ReadInput()
        {
            using (var inputReader = new InputReader(InputFilePath))
            {
                var input = new Input { Cases = new List<TestCase>() };
                var numTestCases = inputReader.ReadInt();
                for (int i = 0; i < numTestCases; i++)
                {
                    var testCase = ReadTestCase(inputReader);
                    input.Cases.Add(testCase);
                }

                return input;
            }
        }

        #endregion

        private static Result Compute(TestCase input)
        {
            //var count = 0;
            //var radius = input.r;

            //while (input.t > 0)
            //{
            //    var requiredMils = 2 * radius + 1;

            //    if (requiredMils < input.t)
            //    {
            //        count++;
            //        input.t -= requiredMils;
            //        radius += 2;
            //    }
            //    else
            //    {
            //        break;
            //    }
            //}
            var upper = FindUpper(input);
            var count = BinarySearch(input, upper / 10, upper);

            return new Result { Rings = count.Value };

            //return new Result { Rings = count };
        }

        private static BigInteger FindUpper(TestCase input)
        {
            var firstTerm = GetTermN(input.r, 1);

            BigInteger n = 1;
            while (GetArithmeticSum(firstTerm, GetTermN(input.r, n), n) <= input.t)
            {
                n *= 10;
            }

            return n;
        }

        private static BigInteger? BinarySearch(TestCase input, BigInteger lower, BigInteger upper)
        {
            BigInteger min = lower;
            BigInteger max = upper;
            var firstTerm = GetTermN(input.r, 1);
            while (min < max)
            {
                BigInteger mid = (max + min) / 2;
                var midItem = GetArithmeticSum(firstTerm, GetTermN(input.r, mid), mid);
                //TKey midKey = keySelector(midItem);
                int comp = midItem.CompareTo(input.t);
                if (comp < 0)
                {
                    min = mid + 1;
                }
                else if (comp > 0)
                {
                    max = mid - 1;
                }
                else
                {
                    break;
                }
            }

            max++;
            do
            {
                max -= 1;
            }
            while (GetArithmeticSum(firstTerm, GetTermN(input.r, max), max) > input.t);

            return max;
        }

        private static BigInteger GetTermN(BigInteger r, BigInteger n)
        {
            return 2 * (r + 2 * (n - 1)) + 1;
        }

        private static BigInteger GetArithmeticSum(BigInteger firstTerm, BigInteger lastTerm, BigInteger n)
        {
            var sum = n * (firstTerm + lastTerm) / 2;
            return sum;
        }

        private static TestCase ReadTestCase(InputReader reader)
        {
            var testCase = new TestCase();

            var tokens = reader.ReadBigIntegers();
            testCase.r = tokens[0];
            testCase.t = tokens[1];

            return testCase;
        }
    }

    internal class TestCase
    {
        public BigInteger r { get; set; }
        public BigInteger t { get; set; }
    }

    internal class Result
    {
        public BigInteger Rings { get; set; }

        public override string ToString()
        {
            return Rings.ToString();
        }
    }

    #region Common Classes

    internal class Input
    {
        public IList<TestCase> Cases { get; set; }
    }

    internal class Output
    {
        public Output()
        {
            Results = new List<Result>();
        }

        public IList<Result> Results { get; set; }
    }

    internal class InputReader : IDisposable
    {
        private List<string>.Enumerator input;

        public InputReader(string path)
        {
            input = File.ReadLines(path).ToList().GetEnumerator();
        }

        public string ReadString()
        {
            input.MoveNext();
            return input.Current;
        }

        public string[] ReadStrings()
        {
            return ReadString().Split(' ').ToArray();
        }

        public int ReadInt()
        {
            return Convert.ToInt32(ReadString());
        }

        public int[] ReadInts()
        {
            return ReadString().Split(' ').Select(s => Convert.ToInt32(s)).ToArray();
        }

        public BigInteger[] ReadBigIntegers()
        {
            return ReadString().Split(' ').Select(BigInteger.Parse).ToArray();
        }

        public void Dispose()
        {
            input.Dispose();
        }

        public Matrix<T> ReadMatrix<T>(InputReader reader, int rows, int columns, Func<string, T> converter)
        {
            var matrix = new Matrix<T>(rows, columns);
            for (int i = 0; i < rows; i++)
            {
                var tokens = reader.ReadStrings();

                for (int j = 0; j < columns; j++)
                {
                    matrix.SetValue(i, j, converter(tokens[j]));
                }
            }

            return matrix;
        }
    }

    internal class Matrix<T>
    {
        private T[,] array;

        public Matrix(int rows, int columns)
        {
            array = new T[rows, columns];
        }

        public int Rows
        {
            get
            {
                return array.GetLength(0);
            }
        }

        public int Columns
        {
            get
            {
                return array.GetLength(1);
            }
        }

        public void SetValue(int row, int column, T value)
        {
            array[row, column] = value;
        }

        public T GetValue(int row, int column)
        {
            return array[row, column];
        }

        public IEnumerable<T> GetRow(int row)
        {
            for (int i = 0; i < array.GetLength(1); i++)
            {
                yield return array[row, i];
            }
        }

        public IEnumerable<T> GetCol(int col)
        {
            for (int i = 0; i < array.GetLength(0); i++)
            {
                yield return array[i, col];
            }
        }

        /// <summary>
        /// index = 0 => descending diagonal
        /// index = 1 => ascending diagonal
        /// </summary>
        public IEnumerable<T> GetDiagonal(int index)
        {
            for (int i = 0, j = index == 0 ? 0 : array.GetLength(0) - 1;
                 i < array.GetLength(0);
                 i++, j = index == 0 ? j + 1 : j - 1)
            {
                yield return array[i, j];
            }
        }
    }

    #endregion
}