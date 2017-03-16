using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemD
{
    class Program
    {
        private static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Invalid input parameters!");
                return;
            }

            string inputFile = args[0];
            string outputFile = args[1];

            using (var reader = new StreamReader(inputFile))
            using (var writer = new StreamWriter(outputFile))
            {
                int testCases = int.Parse(reader.ReadLine());
                for (int caseNumber = 1; caseNumber <= testCases; caseNumber++)
                {
                    var N = int.Parse(reader.ReadLine());
                    var naomiBlocks = reader.ReadLine().Split().Select(decimal.Parse);
                    var kenBlocks = reader.ReadLine().Split().Select(decimal.Parse);

                    var warPoint = CalculateWarPoints(naomiBlocks.ToList(), kenBlocks.ToList());
                    var deceitfullWarPoint = CalculateDeceitfulWarPoints(naomiBlocks.ToList(), kenBlocks.ToList());

                    Console.WriteLine("Case #{0}: {1} {2}", caseNumber, deceitfullWarPoint, warPoint);
                    writer.WriteLine("Case #{0}: {1} {2}", caseNumber, deceitfullWarPoint, warPoint);
                }
            }
        }

        private static int CalculateWarPoints(List<decimal> naomiBlocks, List<decimal> kenBlocks)
        {
            naomiBlocks.Sort();
            kenBlocks.Sort();

            int points = 0;

            while (naomiBlocks.Any())
            {
                bool win = true;
                var naomiBlock = naomiBlocks.First();
                for (int i = 0; i < kenBlocks.Count; ++i)
                {
                    if (kenBlocks[i] > naomiBlock)
                    {
                        kenBlocks.RemoveAt(i);
                        win = false;
                        break;
                    }
                }
                if (win)
                {
                    points++;
                }
                naomiBlocks.RemoveAt(0);
            }

            return points;
        }

        private static int CalculateDeceitfulWarPoints(List<decimal> naomiBlocks, List<decimal> kenBlocks)
        {
            naomiBlocks.Sort();
            kenBlocks.Sort();

            int points = 0;

            while (naomiBlocks.Any())
            {
                var naomiBlock = naomiBlocks.First();
                if (naomiBlock > kenBlocks.First())
                {
                    naomiBlocks.RemoveAt(0);
                    kenBlocks.RemoveAt(0);
                    points++;
                }
                else
                {
                    naomiBlocks.RemoveAt(0);
                    kenBlocks.Remove(kenBlocks.Last());
                }
            }
            return points;
        }
    }
}
