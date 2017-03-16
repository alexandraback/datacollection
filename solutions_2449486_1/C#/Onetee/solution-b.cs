using System.Collections.Generic;
using System.Linq;

namespace CodeJam2013Cs
{
    using System;
    using System.IO;

    class Program
    {
        public static bool CellValidInGrid(List<List<int>> grid, int x, int y)
        {
            var value = grid[y][x];
            var horizontal = !grid[y].Any(v => v > value);
            var verticalItems = grid.Select(v => v[x]);
            var vertical = !verticalItems.Any(v => v > value);
            if (horizontal || vertical)
            {
                return true;
            }
            return false;
        }

        public static void LawnMower(string fileName)
        {
            // Read file
            var inputLines = File.ReadAllLines(fileName).Skip(1).ToList();
            var testCases = new List<List<List<int>>>();
            var outputLines = new List<string>();
            var testCaseIndex = 1;
            
            while(inputLines.Any())
            {
                var line = inputLines[0].Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                var n = Convert.ToInt32(line[0]);
                var m = Convert.ToInt32(line[1]);
                inputLines.RemoveRange(0, 1);

                var lines = inputLines.Take(n).ToList();
                inputLines.RemoveRange(0, n);

                var numLines = new List<List<int>>();
                foreach (var l in lines)
                {
                    List<int> nums = new List<int>();
                    foreach (var c in l.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries))
                    {
                        nums.Add(Convert.ToInt32(c));
                    }
                    numLines.Add(nums);
                }

                testCases.Add(numLines);
            }

            // Solve the problem.
            foreach (var testCase in testCases)
            {
                bool possible = true;

                for (int i = 0; i < testCase.Count; i++)
                {
                    if (possible == false)
                    {
                        break;
                    }

                    var line = testCase[i];

                    for (int j = 0; j < line.Count; j++)
                    {
                        var result = CellValidInGrid(testCase, j, i);
                        if (result == false)
                        {
                            possible = false;
                        }
                    }
                }

                outputLines.Add(string.Format("Case #{0}: {1}", testCaseIndex, possible ? "YES" : "NO"));
                testCaseIndex++;
            }

            // Print the file.
            using (var file = new StreamWriter(@"C:\codejam\b-large-output.txt"))
            {
                foreach (var line in outputLines)
                {
                    file.WriteLine(line);
                }
            }
        }

        static void Main()
        {
            const string inputFile = @"C:\codejam\B-large.in";
            LawnMower(inputFile);
        }
    }
}
