using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pancakes
{
    class Program
    {
        static void Main(string[] args)
        {
            List<ProblemInstance> problems;

            using (var f = File.Open(args[0], FileMode.Open))
            using (var tr = new StreamReader(f)) {
                problems = ParseProblem(tr);
            }

            var solutions = problems.Select(x => x.ComputeSolution());

            PrintSolutions(solutions);
        }

        private static void PrintSolutions(IEnumerable<int> solutions) {
            int i = 1;

            foreach (var solution in solutions) {
                Console.WriteLine("Case #{0}: {1}", i++, solution);
            }
        }

        private static List<ProblemInstance> ParseProblem(TextReader tr) {
            int problemCount = int.Parse(tr.ReadLine());

            var result = new List<ProblemInstance>();

            for (int i = 0; i < problemCount; i++) {
                tr.ReadLine();
                var diners = tr.ReadLine().Split(' ').Select(int.Parse);
                var dinersCount = new int[1000];

                foreach (var pancakeCount in diners) {
                    dinersCount[pancakeCount - 1] += 1;
                }

                result.Add(new ProblemInstance(dinersCount));
            }

            return result;
        }
    }

    public class ProblemInstance {
        private readonly int[] dinnersCount;

        public ProblemInstance(int[] dinnersCount) {
            this.dinnersCount = dinnersCount;
        }

        static int ComputeSolutionRecursive(int[] dinnersCount) {
            int topPancake;

            for (topPancake = dinnersCount.Length - 1; topPancake >= 0; topPancake--) {
                if (dinnersCount[topPancake] != 0) {
                    break;
                }
            }

            if (topPancake == 0) {
                // everyone has fewer than one pancake left.
                return 1;
            }


            // the only possibly helpful action is to split all of the pancakes of those who have the most.

            var topPancakeDiners = dinnersCount[topPancake];
            var pancakeCount = topPancake + 1;

            int[] afterSplitCost = new int[pancakeCount - 1];
            int[] newDinnersCount = new int[pancakeCount];

            for (int i = 1; i < pancakeCount; i++) {
                Array.Copy(dinnersCount, newDinnersCount, pancakeCount - 1);
                newDinnersCount[i - 1] += topPancakeDiners;
                newDinnersCount[pancakeCount - i - 1] += topPancakeDiners;

                afterSplitCost[i - 1] = ComputeSolutionRecursive(newDinnersCount);
            }

            var minSplitCost = afterSplitCost.Min() + topPancakeDiners;

            return Math.Min(topPancake + 1, minSplitCost);
        }

        public int ComputeSolution() {
            return ComputeSolutionRecursive(dinnersCount);
        }
    }
}
