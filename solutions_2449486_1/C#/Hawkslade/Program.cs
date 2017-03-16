using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJam
{
    class Lawnmower
    {
        static void Main(string[] args)
        {
            using (TextReader input = new StreamReader("input.txt"))
            using (TextWriter output = new StreamWriter("output.txt"))
            //using (TextReader input = new StreamReader(Console.OpenStandardInput()))
            //using (TextWriter output = new StreamWriter(Console.OpenStandardOutput()))
            {
                Process(input, output);
            }
        }

        private static void Process(TextReader input, TextWriter output)
        {
            int numberOfCases = int.Parse(input.ReadLine());
            for (int currentCase = 0; currentCase < numberOfCases; currentCase++)
            {
                output.Write("Case #" + (currentCase + 1).ToString() + ": ");
                ProcessLine(input, output);
            }
        }

        private static void ProcessLine(TextReader input, TextWriter output)
        {
            int[] nm = ReadIntsLine(input);
            int n = nm[0];
            int m = nm[1];
            int[] highest = new int[m];
            int[] lowest = new int[m];
            for (int index = 0; index < m; index++)
            {
                highest[index] = -1;
                lowest[index] = 1000;
            }
            bool possible = true;
            for (int line = 0; line < n; line++)
            {
                if (!possible)
                {
                    input.ReadLine();
                }
                else
                {
                    int[] heights = ReadIntsLine(input);
                    int highestInRow = heights.Max();
                    for (int column = 0; column < m; column++)
                    {
                        if (heights[column] > highest[column])
                        {
                            highest[column] = heights[column];
                            if (highest[column] > lowest[column])
                            {
                                possible = false;
                                break;
                            }
                        }
                        if (heights[column] < highestInRow)
                        {
                            if (heights[column] < lowest[column])
                            {
                                lowest[column] = heights[column];
                                if (highest[column] > lowest[column])
                                {
                                    possible = false;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            output.WriteLine(possible ? "YES" : "NO");
        }

        private static int[] ReadIntsLine(TextReader input)
        {
            string[] numbers = input.ReadLine().Split(' ');
            int[] result = new int[numbers.Length];
            for (int index = 0; index < numbers.Length; index++)
            {
                result[index] = int.Parse(numbers[index]);
            }
            return result;
        }
    }
}
