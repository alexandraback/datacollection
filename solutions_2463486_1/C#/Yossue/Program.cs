using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace C
{
    class Program
    {
        static bool IsPalindrome(long num)
        {
            string numStr = num.ToString();
            int digitCount = numStr.Length;
            bool isPalindrome = true;

            for(int i=0; i<digitCount/2; ++i)
            {
                if(numStr[i] != numStr[digitCount-i-1])
                {
                    isPalindrome = false;
                    break;
                }
            }

            return isPalindrome;
        }

        static void Main(string[] args)
        {
            ArrayList answerList = new ArrayList();

            // 1 digit
            for(long i=1; i<10; i++)
            {
                long square = i * i;
                if(IsPalindrome(square))
                {
                    Console.WriteLine("{0}, {1}", i, square);
                    answerList.Add(square);
                }
            }

            // 2 digit
            for (long i = 1; i < 10; i++)
            {
                long number = i * 10 + i;
                long square = number * number;
                if (IsPalindrome(square))
                {
                    Console.WriteLine("{0}, {1}", number, square);
                    answerList.Add(square);
                }
            }

            // 3 digit
            for (long i = 1; i < 10; i++)
            {
                for (long j = 0; j < 10; j++)
                {
                    long number = i * 100 + j * 10 + i;
                    long square = number * number;
                    if (IsPalindrome(square))
                    {
                        Console.WriteLine("{0}, {1}", number, square);
                        answerList.Add(square);
                    }
                }
            }

            // 4 digit
            for (long i = 1; i < 10; i++)
            {
                for (long j = 0; j < 10; j++)
                {
                    long number = i * 1000 + j * 100 + j * 10 + i;
                    long square = number * number;
                    if (IsPalindrome(square))
                    {
                        Console.WriteLine("{0}, {1}", number, square);
                        answerList.Add(square);
                    }
                }
            }

            // 5 digit
            for (long i = 1; i < 10; i++)
            {
                for (long j = 0; j < 10; j++)
                {
                    for (long k = 0; k < 10; k++)
                    {
                        long number = i * 10000 + j * 1000 + k * 100 + j * 10 + i;
                        long square = number * number;
                        if (IsPalindrome(square))
                        {
                            Console.WriteLine("{0}, {1}", number, square);
                            answerList.Add(square);
                        }
                    }
                }
            }

            // 6 digit
            for (long i = 1; i < 10; i++)
            {
                for (long j = 0; j < 10; j++)
                {
                    for (long k = 0; k < 10; k++)
                    {
                        long number = i * 100000 + j * 10000 + k * 1000 + k * 100 + j * 10 + i;
                        long square = number * number;
                        if (IsPalindrome(square))
                        {
                            Console.WriteLine("{0}, {1}", number, square);
                            answerList.Add(square);
                        }
                    }
                }
            }

            // 7 digit
            for (long i = 1; i < 10; i++)
            {
                for (long j = 0; j < 10; j++)
                {
                    for (long k = 0; k < 10; k++)
                    {
                        for (long l = 0; l < 10; l++)
                        {
                            long number = i * 1000000 + j * 100000 + k * 10000 + l * 1000 + k * 100 + j * 10 + i;
                            long square = number * number;
                            if (IsPalindrome(square))
                            {
                                Console.WriteLine("{0}, {1}", number, square);
                                answerList.Add(square);
                            }
                        }
                    }
                }
            }

            // 8 digit
            for (long i = 1; i < 10; i++)
            {
                for (long j = 0; j < 10; j++)
                {
                    for (long k = 0; k < 10; k++)
                    {
                        for (long l = 0; l < 10; l++)
                        {
                            long number = i * 10000000 + j * 1000000 + k * 100000 + l * 10000 + l * 1000 + k * 100 + j * 10 + i;
                            long square = number * number;
                            if (IsPalindrome(square))
                            {
                                Console.WriteLine("{0}, {1}", number, square);
                                answerList.Add(square);
                            }
                        }
                    }
                }
            }

            Console.WriteLine(long.MaxValue);

            string inputFile = @"C:\yoshiko\programming\gcj\2013\QualificationROUnd\C\files\C-large-1.in";
            int index = 0;

            using (System.IO.StreamWriter file = new System.IO.StreamWriter(@"C:\yoshiko\programming\gcj\2013\QualificationROUnd\C\files\C-large-1.out", false))
            {
                foreach (string line in File.ReadLines(inputFile))
                {
                    if (index != 0)
                    {
                        string[] inputNumbers = line.Split(new Char[] { ' ' });
                        
                        long min;
                        long max;
                        long.TryParse(inputNumbers[0], out min);
                        long.TryParse(inputNumbers[1], out max);

                        long answer = 0;
                        foreach(long square in answerList)
                        {
                            if(square < min)
                            {
                                continue;
                            }
                            else if(square > max)
                            {
                                break;
                            }
                            else
                            {
                                answer++;
                            }
                        }

                        file.WriteLine("Case #{0}: {1}", index, answer);
                    }

                    index++;
                }

            }
        }
    }
}
