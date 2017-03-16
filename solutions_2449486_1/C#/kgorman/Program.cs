using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace QualificationProblemB
{
    using System.IO;

    class Program
    {
        private static string inputFilePath = @"C:\Users\Kai\Downloads\B-large.in";
        //private static string inputFilePath = @"C:\temp\input.txt";

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
                Console.WriteLine("Case #{0}: {1}", i + 1, output.Results[i].CanMow ? "YES" : "NO");
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
            IDictionary<int, IEnumerable<int>> rows = new Dictionary<int, IEnumerable<int>>();
            IDictionary<int, IEnumerable<int>> cols = new Dictionary<int, IEnumerable<int>>();

            for (int i = 0; i < input.Lawn.GetLength(0); i++)
            {
                rows[i] = GetRow(input.Lawn, i).ToList();
            }

            for (int i = 0; i < input.Lawn.GetLength(1); i++)
            {
                cols[i] = GetCol(input.Lawn, i).ToList();
            }

            foreach (var row in rows)
            {
                var max = row.Value.Max();

                for (int i = 0; i < row.Value.Count(); i++)
                {
                    if (row.Value.ElementAt(i) < max)
                    {
                        if (cols[i].Any(c => c > row.Value.ElementAt(i)))
                        {
                            return new Result { CanMow = false };
                        }
                    }
                }
            }

            foreach (var col in cols)
            {
                var max = col.Value.Max();

                for (int i = 0; i < col.Value.Count(); i++)
                {
                    if (col.Value.ElementAt(i) < max)
                    {
                        if (rows[i].Any(c => c > col.Value.ElementAt(i)))
                        {
                            return new Result { CanMow = false };
                        }
                    }
                }
            }

            return new Result { CanMow = true };
        }

        private static IEnumerable<int> GetRow(int[,] lawn, int row)
        {
            for (int i = 0; i < lawn.GetLength(1); i++)
            {
                yield return lawn[row, i];
            }
        }

        private static IEnumerable<int> GetCol(int[,] lawn, int col)
        {
            for (int i = 0; i < lawn.GetLength(0); i++)
            {
                yield return lawn[i, col];
            }
        }

        private static Input ReadInput()
        {
            var input = new Input();

            var inputFile = File.ReadLines(inputFilePath).ToList();
            input.Cases = new List<TestCase>();

            inputFile.RemoveAt(0);
            while (inputFile.Count > 0)
            {
                var tokens = inputFile[0].Split(' ');
                var N = Convert.ToInt32(tokens[0]);
                var M = Convert.ToInt32(tokens[1]);
                inputFile.RemoveAt(0);

                var testCase = new TestCase() { Lawn = new int[N,M] };
                for (int i = 0; i < N; i++)
                {
                    tokens = inputFile[0].Split(' ');
                    inputFile.RemoveAt(0);
                    
                    for (int j = 0; j < M; j++)
                    {
                        testCase.Lawn[i, j] = Convert.ToInt32(tokens[j]);
                    }
                }

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
        public int[,] Lawn { get; set; }
    }

    internal class Result
    {
        public bool CanMow { get; set; }
    }
}
