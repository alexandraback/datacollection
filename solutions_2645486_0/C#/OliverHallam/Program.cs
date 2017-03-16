using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Energy
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            using (var reader = new StreamReader("c:\\temp\\in.txt"))
            using (var writer = new StreamWriter("c:\\temp\\out.txt"))
            {
                var count = int.Parse(reader.ReadLine());
                for (var caseID = 1; caseID <= count; caseID++)
                {
                    var row = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                    var energy = row[0];
                    var regenRate = row[1];
                    var activityCount = row[2];
                    var weights = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();

                    var maxResult = GetOptimalResult(energy, 0, energy, regenRate, weights, 0, weights.Length);

                    writer.WriteLine("Case #{0}: {1}", caseID, maxResult);
                    writer.Flush();
                }
            }
        }

        private static int GetOptimalResult(
            int initialEnergy,
            int finalEnergy,
            int maxEnergy,
            int regenRate,
            int[] weights,
            int startIndex,
            int endIndex)
        {
            // find the best activity
            var bestIndex = MaxIndex(weights, startIndex, endIndex);

            // spend all the energy we can on this case.
            var generatedBefore = regenRate * (bestIndex - startIndex);
            var generatedAfter = regenRate * (endIndex - bestIndex);
            var remainingEnergy = Math.Max(finalEnergy - generatedAfter, 0);
            var availableEnergy = Math.Min(initialEnergy + generatedBefore, maxEnergy) - remainingEnergy;
            var gain = weights[bestIndex] * availableEnergy;

            var excessEnergy = Math.Min(generatedBefore + initialEnergy - maxEnergy, maxEnergy);
            if (excessEnergy > 0)
            {
                // we can spend some of the excess energy on earlier tasks
                gain += GetOptimalResult(initialEnergy, maxEnergy, maxEnergy, regenRate, weights, startIndex, bestIndex);
            }

            if (remainingEnergy + generatedAfter > finalEnergy && bestIndex + 1 < endIndex)
            {
                // we can spend more energy after this task
                gain += GetOptimalResult(remainingEnergy + regenRate, finalEnergy, maxEnergy, regenRate, weights, bestIndex + 1, endIndex);
            }

            return gain;
        }

        private static int MaxIndex(int[] weights, int startIndex, int endIndex)
        {
            int bestWeight = int.MinValue;
            int bestIndex = 0;

            for (var i = startIndex; i < endIndex; i++)
            {
                if (weights[i] > bestWeight)
                {
                    bestWeight = weights[i];
                    bestIndex = i;
                }
            }
            return bestIndex;
        }
    }
}
