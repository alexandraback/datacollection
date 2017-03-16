using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam.Solvers
{
    class PasswordProblem
    {
        public static void Main(string[] args)
        {
            string problemName = args[0];
            string inputFileName = problemName + ".in";
            string outputFileName = problemName + ".out.txt";

            using (var reader = System.IO.File.OpenText(inputFileName))
            using (var writer = new System.IO.StreamWriter(outputFileName))
            {
                var sw = System.Diagnostics.Stopwatch.StartNew();
                SolveProblem(reader, writer);
                Console.WriteLine(sw.Elapsed.ToString());
            }
        }

        private static void SolveProblem(System.IO.TextReader input, System.IO.TextWriter output)
        {
            int numberOfTestCases = Int32.Parse(input.ReadLine());

            for (int i = 0; i < numberOfTestCases; i++)
            {
                output.Write("Case #{0}:", i + 1);
                SolveTestCase(input, output);
                output.WriteLine();
            }
        }

        private static void SolveTestCase(System.IO.TextReader input, System.IO.TextWriter output)
        {
            string line = input.ReadLine();
            string[] parts = line.Split(' ');
            line = input.ReadLine();
            double[] probabilities = line.Split(' ').Select(o => double.Parse(o)).ToArray();
            int typed = Int32.Parse(parts[0]);
            int total = Int32.Parse(parts[1]);
            output.Write(' ');
            output.Write(Solve(typed, total, probabilities).ToString("0.000000"));
        }

        private static double Solve(int typed, int total, double[] probabilities)
        {
            double expectedIfPressEnterRightAway = 2 + total;
            int leftToType = total - typed;

            double probabilityOfAllCorrect = Product(probabilities);
            double ifIKeepTryingAndAllCorrect = 1 + leftToType;
            double ifIKeepTryingAndNotAllCorrect = ifIKeepTryingAndAllCorrect + 1 + total;

            double expectedIfIKeepTrying = probabilityOfAllCorrect * ifIKeepTryingAndAllCorrect +
                (1.0 - probabilityOfAllCorrect) * ifIKeepTryingAndNotAllCorrect;

            double[] expectedIfIBackspaceNTimes = new double[typed];

            for (int n = 1; n < typed; n++)
            {
                double ifCorrect = 2 * n + 1 + leftToType;
                double ifIncorrect = ifCorrect + 1 + total;
                double probabilityCorrect = 1.0;
                for (int i = 0; i < (typed - n); i++)
                {
                    probabilityCorrect *= probabilities[i];
                }
                expectedIfIBackspaceNTimes[n - 1] =
                    probabilityCorrect * ifCorrect + (1.0 - probabilityCorrect) * ifIncorrect;
            }
            expectedIfIBackspaceNTimes[expectedIfIBackspaceNTimes.Length - 1] = typed + 1 + total;

            return Min(expectedIfIKeepTrying, expectedIfPressEnterRightAway, Min(expectedIfIBackspaceNTimes));
        }

        private static double Min(params double[] numbers)
        {
            double result = numbers[0];
            for (int i = 1; i < numbers.Length; i++)
            {
                if (numbers[i] < result)
                {
                    result = numbers[i];
                }
            }
            return result;
        }

        private static double Product(double[] numbers)
        {
            double result = 1.0;
            foreach (var n in numbers)
            {
                result *= n;
            }
            return result;
        }
    }
}
