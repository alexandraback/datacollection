using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace CodeJam
{
    public class DiamondInheritance : ProblemSolver
    {
        public override object SolveLine(string line)
        {
            int n = Int32.Parse(line);

            HashSet<int>[] classes = new HashSet<int>[n];

            for (int i = 0; i < n; i++)
            {
                string[] splitLine = Console.ReadLine().Split(' ');

                int m = Int32.Parse(splitLine[0]);
                classes[i] = new HashSet<int>();

                for (int j = 0; j < m; j++)
                {
                    classes[i].Add(Int32.Parse(splitLine[j + 1]) - 1);
                }
            }

            for (int i = 0; i < n; i++)
            {
                int[] pathsTo = new int[n];
                int currentNode = i;

                RecursiveThing(classes, pathsTo, currentNode);

                for (int j = 0; j < n; j++)
                {
                    if (pathsTo[j] >= 2)
                        return "Yes";
                }
            }

            return "No";
        }

        private static void RecursiveThing(HashSet<int>[] classes, int[] pathsTo, int currentNode)
        {
            foreach (int parentNode in classes[currentNode])
            {
                pathsTo[parentNode]++;
                RecursiveThing(classes, pathsTo, parentNode);
            }
        }
    }
}
