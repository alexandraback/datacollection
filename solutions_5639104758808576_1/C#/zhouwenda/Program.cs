using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam
{
    class Program
    {
        static void Main(string[] args) {
            var problems = new List<ProblemInstance>();

            using (var f = File.Open(args[0], FileMode.Open))
            using (var tr = new StreamReader(f)) {
                problems = ParseProblem(tr);
            }

            var solutions = problems.Select(x => x.ComputeSolution()).ToList();

            OutputSolutions(solutions);
        }

        static List<ProblemInstance> ParseProblem(TextReader reader) {
            int problemCount = int.Parse(reader.ReadLine());

            var problems = new List<ProblemInstance>();

            for (int i = 0; i < problemCount; i++) {
                var instance = reader.ReadLine().Split(' ')[1];
                problems.Add(ProblemInstance.Parse(instance));
            }

            return problems;
        }

        static void OutputSolutions(List<int> solutions) {
            int i = 1;

            foreach (var solution in solutions) {
                Console.WriteLine("Case #{0}: {1}", i++, solution);
            }
        }
    }

    class ProblemInstance {
        private readonly int[] shynessCounts;

        public ProblemInstance(int[] shynessCounts) {
            this.shynessCounts = shynessCounts;
        }

        public static ProblemInstance Parse(string instance) {
            int[] shynessCounts = new int[instance.Length];

            for (int i = 0; i < instance.Length; i++) {
                shynessCounts[i] = int.Parse(instance.Substring(i, 1));
            }

            return new ProblemInstance(shynessCounts);
        }

        public int ComputeSolution() {
            int lastNonZero;

            for (lastNonZero = shynessCounts.Length - 1; lastNonZero >= 0; lastNonZero--) {
                if (shynessCounts[lastNonZero] != 0) {
                    break;
                }
            }

            int min = 0;
            int currentSum = 0;

            for (int i = 0; i < lastNonZero + 1; i++) {
                currentSum += shynessCounts[i];

                min = Math.Min(min, currentSum - (i + 1));
            }

            return -min;
        }
    }
}
