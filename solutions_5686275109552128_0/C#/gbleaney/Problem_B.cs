using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Google_Code_Jam
{
    public static class Problem_B
    {
        public static void Run()
        {
            List<string> output = new List<string>();

            // Open the file to read from. 
            using (StreamReader sr = File.OpenText(@"E:\My Documents\Google Drive\Coding\Google Code Jam\Google Code Jam\B-small-attempt1.in"))
            {
                int testCases = int.Parse(sr.ReadLine());
                for (int caseNum = 1; caseNum <= testCases; caseNum++)
                {
                    int numDiners = int.Parse(sr.ReadLine());

                    IEnumerable<string> platesEnumerable = sr.ReadLine()
                                                          .Split(' ');

                    IDictionary<int, int> platesDictionary = platesEnumerable.GroupBy(int.Parse, int.Parse)
                        .ToDictionary(group => group.Key, group => group.Count());

                    SortedList<int, int> pancakeStackCounts = new SortedList<int, int>(platesDictionary);

                    int bestTime = pancakeStackCounts.Max(v1 => v1.Key);
                    int numSplits = 0;

                    while (pancakeStackCounts.Count > 0 && pancakeStackCounts.Max(kv => kv.Key) > pancakeStackCounts.Count/2)
                    {
                        numSplits++;

                        // Remove the largest stack
                        int maxStackSize = pancakeStackCounts.Max(kv=>kv.Key);
                        if (pancakeStackCounts[maxStackSize] > 1)
                        {
                            pancakeStackCounts[maxStackSize]--;
                        }
                        else
                        {
                            pancakeStackCounts.Remove(maxStackSize);
                        }

                        // Add the two halves of the largest stack back on
                        int firstStack = maxStackSize/2;
                        int secondStack = maxStackSize - firstStack;
                        if (pancakeStackCounts.ContainsKey(firstStack))
                        {
                            pancakeStackCounts[firstStack]++;
                        }
                        else
                        {
                            pancakeStackCounts.Add(firstStack, 1);
                        }
                        if (pancakeStackCounts.ContainsKey(secondStack))
                        {
                            pancakeStackCounts[secondStack]++;
                        }
                        else
                        {
                            pancakeStackCounts.Add(secondStack, 1);
                        }

                        // Calculate time to finish
                        int timeToFinish = pancakeStackCounts.Max(v1 => v1.Key) + numSplits;
                        bestTime = Math.Min(timeToFinish, bestTime);


                    }

                    output.Add(String.Format("Case #{0}: {1}", caseNum, bestTime));
                }
            }


            using (StreamWriter sw = File.CreateText(@"E:\My Documents\Google Drive\Coding\Google Code Jam\Google Code Jam\problem-b-attempt1.out"))
            {
                foreach (var line in output)
                {
                    sw.WriteLine(line);
                }
            }
        }
    }
}
