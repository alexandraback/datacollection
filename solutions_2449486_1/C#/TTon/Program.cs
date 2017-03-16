using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lawnmower
{
    internal class Program
    {
        public static List<List<string>> ParseInput(string[] lines)
        {
            int caseCount = 0;
            int parameterCount = 0;

            List<List<string>> cases = new List<List<string>>();
            List<string> paramSet = new List<string>();
            for (int index = 0; index < lines.Length; index++)
            {
                string line = lines[index];

                if (index == 0)
                {
                    if (!Int32.TryParse(line, out caseCount))
                    {
                        Console.WriteLine("Invalid line {0}:{1}", index, line);
                        break;
                    }
                }
                else
                {
                    if (parameterCount == 0)
                    {
                        string[] ss = line.Split(' ');
                        if (!Int32.TryParse(ss[0], out parameterCount))
                        {
                            Console.WriteLine("Invalid line {0}:{1}", index, line);
                            break;
                        }
                    }
                    else
                    {
                        paramSet.Add(line);

                        if (paramSet.Count == parameterCount)
                        {
                            cases.Add(paramSet);
                            paramSet = new List<string>();
                            parameterCount = 0;
                        }
                    }
                }
            }

            if (cases.Count != caseCount)
            {
                Console.WriteLine("Invalid case count");
            }

            return cases;
        }

        private static void Main(string[] args)
        {
            string[] rawInput = System.IO.File.ReadAllLines(args[0]);
            List<List<string>> input = ParseInput(rawInput);

            for (int caseIndex = 0; caseIndex < input.Count; caseIndex++)
            {
                List<string> problem = input[caseIndex];
                List<List<int>> lawn = new List<List<int>>();

                foreach (string line in problem)
                {
                    List<int> row = new List<int>();
                    string[] strCells = line.Split(' ');
                    foreach (string strCell in strCells)
                    {
                        row.Add(Int32.Parse(strCell));
                    }
                    lawn.Add(row);
                }

                bool possible = true;
                for (int i = 0; i < lawn.Count; i++)
                {
                    for (int j = 0; j < lawn[i].Count; j++)
                    {
                        possible = isPossible(lawn, i, j);
                        if (!possible)
                        {
                            System.Console.WriteLine("Case #{0}: NO", caseIndex + 1);
                            break;
                        }
                    }

                    if (!possible)
                        break;
                }

                if (possible)
                {
                    System.Console.WriteLine("Case #{0}: YES", caseIndex + 1);
                }
            }
        }

        private static bool isPossible(List<List<int>> lawn, int ii, int jj)
        {
            int h = lawn[ii][jj];
            int jCount = lawn[0].Count;

            int i = 0;
            for (i = 0; i < lawn.Count; i++)
            {
                if (lawn[i][jj] > h)
                    break;
            }
            if (i == lawn.Count) return true;

            int j = 0;
            for (j = 0; j < lawn[0].Count; j++)
            {
                if (lawn[ii][j] > h)
                    break;
            }
            if (j == lawn[0].Count) return true;

            return false;
        }
    }
}