using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Marks
{
    class Program
    {
        private static StreamReader reader = null;
        private static StreamWriter writer = null;

        static void Main()
        {
            //reader = new StreamReader("B-small-attempt0.in");
            //writer = new StreamWriter("B-small.out");
            //reader = new StreamReader("B-large-attempt0.in");
            //writer = new StreamWriter("B-large.out");

            using (reader)
            {
                using (writer)
                {
                    int tests = int.Parse(Console.ReadLine());
                    string line = null;
                    int n = 0;
                    int s = 0;
                    int p = 0;
                    int[] grades = null;
                    int result = 0;

                    for (int test = 0; test < tests; test++)
                    {
                        line = Console.ReadLine();

                        ParseData(ref n, ref s, ref p, line,ref grades);

                        result = CountOfGooglers(s, p, grades);

                        Console.WriteLine("Case #{0}: {1}", test + 1, result);
                    }
                }
            }
        }

        private static void ParseData(ref int n, ref int s, ref int p,
            string line,ref int[] grades)
        {
            string[] data = line.Split(' ');

            n = int.Parse(data[0]);
            s = int.Parse(data[1]);
            p = int.Parse(data[2]);

            grades = new int[n];

            for (int i = 3; i < data.Length; i++)
            {
                grades[i - 3] = int.Parse(data[i]);
            }
        }

        private static int CountOfGooglers(int s, int p, int[] grades)
        {
            int count = 0;
            int surprisingCount = 0;
            int canBeSurprisingCount = 0;
            int remainder = -1;
            int digit = -1;

            for (int grade = 0; grade < grades.Length; grade++)
            {
                digit = grades[grade] / 3;
                remainder = grades[grade] - 3 * digit;

                if (remainder == 2)
                {
                    if (digit + 1 >= p)
                    {
                        count++;
                        if (digit + 2 <= 10)
                        {
                            canBeSurprisingCount++;
                        }
                    }
                    else
                    {
                        if (digit + 2 >= p &&
                            surprisingCount < s)
                        {
                            count++;
                            surprisingCount++;
                        }
                    }
                }
                else if (remainder == 1)
                {
                    if (digit + 1 >= p)
                    {
                        count++;
                        if (digit + 2 <= 10)
                        {
                            canBeSurprisingCount++;
                        }
                    }
                }
                else
                {
                    if (digit >= p)
                    {
                        count++;
                        if (digit + 2 <= 10)
                        {
                            canBeSurprisingCount++;
                        }
                    }
                    else
                    {
                        if (digit + 1 >= p &&
                            surprisingCount < s &&
                            digit != 0)
                        {
                            count++;
                            surprisingCount++;
                        }

                    }
                }
            }

            if (surprisingCount + canBeSurprisingCount < s)
            {
                count = 0;
            }

            return count;
        }
    }
}
