using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            int numTestCases = 0;

            StreamReader r = new StreamReader(@"../../files/B-small-attempt0.in");
            StreamWriter w = new StreamWriter(@"../../files/B-small-attempt0.out");

            string line;
            bool isFirstLine = true;
            int index = 1;
            while ((line = r.ReadLine()) != null)
            {
                if (isFirstLine)
                {
                    isFirstLine = false;
                    int.TryParse(line, out numTestCases);
                }
                else
                {
                    int N = 0;
                    int M = 0;
                    List<int> s = new List<int>();

                    string[] inputNumbers = line.Split(new Char[] { ' ' });
                    int len = inputNumbers.Length;

                    int.TryParse(inputNumbers[0], out N);
                    int.TryParse(inputNumbers[1], out M);

                    int[][] heights = new int[N][];
                    int[] maxValueH = new int[M];
                    int[] maxValueV = new int[N];
                    for (int i = 0; i < N; ++i)
                    {
                        line = r.ReadLine();
                        string[] numbers = line.Split(new Char[] { ' ' });

                        heights[i] = new int[M];
                        for (int j = 0; j < M; ++j)
                        {
                            int.TryParse(numbers[j], out heights[i][j]);

                            if(heights[i][j] > maxValueH[j])
                            {
                                maxValueH[j] = heights[i][j];
                            }
                            if(heights[i][j] > maxValueV[i])
                            {
                                maxValueV[i] = heights[i][j];
                            }
                        }
                    }

                    bool isPossible = true;
                    for (int i = 0; i < N; ++i)
                    {
                        for (int j = 0; j < M; ++j)
                        {
                            if (heights[i][j] < maxValueH[j] && heights[i][j] < maxValueV[i])
                            {
                                isPossible = false;
                                break;
                            }
                        }
                        
                    }

                    Console.WriteLine("Case #{0}: {1}", index,isPossible ? "YES" : "NO");
                    w.WriteLine("Case #{0}: {1}", index, isPossible ? "YES" : "NO");

                    ++index;
                }
            }

            r.Close();
            w.Close();

        }
    }
}
