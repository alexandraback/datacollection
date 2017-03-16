using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace r0pb
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader("../../input.txt"))
            using (var outputStream = new StreamWriter("../../output.txt", false, Encoding.Default))
            {
                var caseCount = int.Parse(inputStream.ReadLine());

                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    inputStream.ReadLine();
                    var stacks = inputStream.ReadLine().Split().Select(s => int.Parse(s)).OrderBy(s => s).ToList();

                    var currentBestTime = BruteForce(stacks);
                    outputStream.WriteLine("Case #{0}: {1}", caseNumber, currentBestTime);
                }
            }
        }

        private static int BruteForce(List<int> stacks)
        {
            if (stacks.Count == 0)
                return 0;
            var topStack = stacks[stacks.Count - 1];
            if (topStack == 1)
                return 1;
            var bestSplitted = int.MaxValue;
            for (var half = 2; half <= topStack / 2; half++)
            {
                var splitted = new List<int>(stacks);
                splitted[stacks.Count - 1] = topStack - half;
                splitted.Add(half);
                splitted.Sort();

                var splittedCost = 1 + BruteForce(splitted);
                if (splittedCost < bestSplitted)
                    bestSplitted = splittedCost;
            }
            var eaten = stacks.Where(s => s > 1).Select(s => s - 1).ToList();
            var bestEaten = 1 + BruteForce(eaten);

            return Math.Min(bestSplitted, bestEaten);
            //return Math.Min(bestSplitted, topStack);
        }

        private static int Optimized(List<int> stacks)
        {
            var currentBestTime = stacks[stacks.Count - 1];
            var penalty = 0;
            while (true)
            {
                var topStack = stacks[stacks.Count - 1];
                //if (topStack == 9 || topStack == 5 || topStack == 3)
                //{
                //    for (var i = 0; i < stacks.Count; i++)
                //    {
                //        stacks[i]--;
                //    }
                //    penalty++;
                //    var newBestTime = stacks[stacks.Count - 1] + penalty;
                //    if (newBestTime < currentBestTime)
                //    {
                //        currentBestTime = newBestTime;
                //    }
                //}
                //else 
                if (topStack >= 4)
                {
                    penalty++;
                    var half = topStack / 2;
                    if (topStack == 9)
                        half = 3;
                    else if (topStack == 8)
                        half = 3;
                    stacks[stacks.Count - 1] = topStack - half;
                    stacks.Add(half);
                    stacks.Sort();
                    var newBestTime = stacks[stacks.Count - 1] + penalty;
                    if (newBestTime < currentBestTime)
                    {
                        currentBestTime = newBestTime;
                    }
                }
                else
                {
                    break;
                }
            }
            return currentBestTime;
        }
    }
}
