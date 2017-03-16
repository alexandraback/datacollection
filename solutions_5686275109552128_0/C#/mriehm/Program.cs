using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int testCaseCount;

            using (StreamReader file = new StreamReader("B-small-attempt1.in"))
            {
                using (StreamWriter output = new StreamWriter("output.txt"))
                {
                    testCaseCount = int.Parse(file.ReadLine());
                    for (int testCaseIndex = 0; testCaseIndex < testCaseCount; ++testCaseIndex)
                    {
                        int dinerCount = int.Parse(file.ReadLine());
                        string[] splitLine = file.ReadLine().Split(new char[] { ' ' });
                        List<int> pancakeCounts = new List<int>(new int[2000]);
                        int maxPancakeCount = 0;
                        foreach (string number in splitLine)
                        {
                            int pancakeCount = int.Parse(number);
                            pancakeCounts[pancakeCount] += 1;
                            maxPancakeCount = Math.Max(maxPancakeCount,pancakeCount);
                        }

                        int minMinutes = MinMinutes(pancakeCounts, 0, int.MaxValue, maxPancakeCount);

                        output.WriteLine("Case #" + (testCaseIndex + 1) + ": " + minMinutes);
                        Console.WriteLine("Case #" + (testCaseIndex + 1) + ": " + minMinutes);
                    }
                }
            }
        }

        static int MinMinutes(List<int> pancakeCounts, int splitsSoFar, int minMinutesSoFar, int maxPancakeCount)
        {
            minMinutesSoFar = Math.Min(minMinutesSoFar, maxPancakeCount + splitsSoFar);

            if (splitsSoFar >= minMinutesSoFar || maxPancakeCount < 2)
            {
                return minMinutesSoFar;
            }

            int dinerCount = pancakeCounts[maxPancakeCount];
            
            if (dinerCount > 0)
            {
                for(int divisor = 2; divisor * divisor <= maxPancakeCount; ++divisor)
                {
                    int smallVal = maxPancakeCount / divisor;
                    int largeValCount = (maxPancakeCount % divisor) * dinerCount;
                    int smallValCount = dinerCount * divisor - largeValCount;

                    pancakeCounts[smallVal] += smallValCount;
                    pancakeCounts[smallVal + 1] += largeValCount;

                    minMinutesSoFar = Math.Min(minMinutesSoFar, MinMinutes(pancakeCounts, splitsSoFar + dinerCount * (divisor - 1), minMinutesSoFar, maxPancakeCount - 1));

                    pancakeCounts[smallVal] -= smallValCount;
                    pancakeCounts[smallVal + 1] -= largeValCount;
                }
            }
            else
            {
                minMinutesSoFar = MinMinutes(pancakeCounts, splitsSoFar, minMinutesSoFar, maxPancakeCount - 1);
            }

            return minMinutesSoFar;
        }
    }
}
