using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        private static int X;
        private static double T;

        static void Main(string[] args)
        {
            var dir = "d:\\";
            var inputFileName = "A-small-attempt5";// "A-small-attempt1";
            var inputFile = inputFileName + ".txt";
            var outputFile = inputFile.Replace(".txt", "_out.txt");

            using (var reader = new StreamReader(dir + inputFile))
            {
                using (var writer = new StreamWriter(dir + outputFile))
                {
                    var cases = int.Parse(reader.ReadLine());
                    for (int c = 1; c <= cases; c++)
                    {
                        var parts = reader.ReadLine().Split(new[] { " " }, StringSplitOptions.RemoveEmptyEntries);
                        var votes = parts.Skip(1).Select(v => int.Parse(v)).ToArray();
                        X = votes.Sum();
                        T = 2.0 * X / votes.Length;

                        var votes2 = votes.Where(v => v < T).ToList();

                        var percentages = votes
                            .Select(v => (v >= T) ? 0 : GetPercentage(votes2.ToArray(), votes2.IndexOf(v)))
                            .Select(v => Math.Round(v, 6));
                        
                        //var percentages = votes
                        //    .Select(v => (T - v) * 100.0 / X)
                        //    .Select(v => Math.Max(0, v))
                        //    .Select(v => Math.Round(v, 6))
                        //    .ToArray();

                        //var percSum = percentages.Sum();

                        //if (percSum > 100)
                        //    percentages = percentages.Select(v => v * 100 / percSum).ToArray();

                        var outputArray = percentages
                            .Select(v => string.Format("{0:0.000000}", v))
                            .ToArray();

                        var line = string.Format("Case #{0}: {1}", c, string.Join(" ", outputArray));

                        Console.WriteLine(line);
                        writer.WriteLine(line);
                    }
                }
            }

            Console.ReadKey();
        }

        private static double GetPercentage(int[] votes, int i)
        {
            var max = 100.0; var min = 0.0; var mid = (max + min) / 2;
            var epsilon = Math.Pow(10, -7);
            while (max - min > epsilon)
            {
                mid = (max + min) / 2;
                if (IsGood(votes, i, mid))
                {
                    max = mid;
                }
                else
                {
                    min = mid;
                }
            }

            return mid;
        }

        private static bool IsGood(int[] votes, int i, double percentage)
        {
            var leftPercentage = 100 - percentage;
            var iPoints = votes[i] + X * percentage / 100;
            for (var j = 0; j < votes.Length; j++)
            {
                if (i == j) continue;

                var toEqual = (iPoints - votes[j]) * 100.0 / X;

                leftPercentage -= toEqual;
                if (leftPercentage < 0) return true;
            }

            return false;
        }
    }
}
