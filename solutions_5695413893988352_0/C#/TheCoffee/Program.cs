using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace ConsoleApplication2
{
    class Program
    {
        static StreamWriter output;
        static string root = @"C:\Users\Michael\Documents\Visual Studio 2015\Projects\ConsoleApplication1\";

        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines(root + "B-small-attempt1.in");
            output = new StreamWriter(root + "out.txt");

            int cases = int.Parse(input[0]);
            for (int i = 1; i < input.Length; i++)
            {
                var inputs = input[i].Split();

                Say("Case #" + i + ": " + ProcessSimple(inputs[0], inputs[1]));
            }

            output.Close();
            Console.ReadLine();
        }

        static string ProcessSimple(string stringA, string stringB)
        {
            int length = stringA.Length;
            string format = "D" + length;
            int max = (int)Math.Pow(10, length);

            string regExA = stringA.Replace('?', '.');
            string regExB = stringB.Replace('?', '.');

            long bestA = 0;
            long bestB = 0;

            long minDifference = long.MaxValue;

            for (int a = 0; a < max; a++)
            {
                if (Regex.IsMatch(a.ToString(format), regExA))
                {
                    for (int b = 0; b < max; b++)
                    {
                        if (Regex.IsMatch(b.ToString(format), regExB))
                        {
                            long difference = Math.Abs(a - b);

                            if(difference < minDifference)
                            {
                                bestA = a;
                                bestB = b;
                                minDifference = difference;
                            }
                        }
                    }
                }
            }

            return bestA.ToString(format) + " " + bestB.ToString(format);
        }

        static string Process(string stringA, string stringB)
        {
            int length = stringA.Length;

            long scoreA = 0;
            long scoreB = 0;

            string ansA = "";
            string ansB = "";
            
            for (int i = 0; i < length; i++)
            {
                bool hasQA = false;
                bool hasQB = false;

                long oldScoreA = scoreA;
                long oldScoreB = scoreB;

                // ---------- A
                int numA;
                if(int.TryParse(stringA.Substring(i, 1), out numA))
                {
                    scoreA += numA * (long)Math.Pow(10, length - i - 1);
                    ansA += numA.ToString();
                }
                else
                {
                    hasQA = true;
                }

                // ---------- B
                int numB;
                if (int.TryParse(stringB.Substring(i, 1), out numB))
                {
                    scoreB += numB * (long)Math.Pow(10, length - i - 1);
                    ansB += numB.ToString();
                }
                else
                {
                    hasQB = true;
                }

                // ------------------------

                if(hasQA && hasQB)
                {
                    if(scoreA < scoreB)
                    {
                        scoreA += 9 * (long)Math.Pow(10, length - i - 1);
                        ansA += 9.ToString();

                        //scoreB += 9 * (long)Math.Pow(10, length - i - 1);
                        ansB += 0.ToString();
                    }
                    else if(scoreB < scoreA)
                    {
                        scoreB += 9 * (long)Math.Pow(10, length - i - 1);
                        ansB += 9.ToString();

                        //scoreB += 9 * (long)Math.Pow(10, length - i - 1);
                        ansA += 0.ToString();
                    }
                    else
                    {
                        ansA += 0.ToString();
                        ansB += 0.ToString();
                    }
                }
                else if (hasQA && !hasQB)
                {
                    if (oldScoreA == oldScoreB)
                    {
                        scoreA += numB * (long)Math.Pow(10, length - i - 1);
                        ansA += numB.ToString();
                    }
                    else if (scoreA < scoreB)
                    {
                        scoreA += 9 * (long)Math.Pow(10, length - i - 1);
                        ansA += 9.ToString();
                    }
                    else if (scoreB <= scoreA)
                    {
                        ansA += 0.ToString();
                    }
                }
                else if (!hasQA && hasQB)
                {
                    if(oldScoreA == oldScoreB)
                    {
                        scoreB += numA * (long)Math.Pow(10, length - i - 1);
                        ansB += numA.ToString();
                    }
                    else if (scoreB < scoreA)
                    {
                        scoreB += 9 * (long)Math.Pow(10, length - i - 1);
                        ansB += 9.ToString();
                    }
                    else if (scoreA <= scoreB)
                    {
                        ansB += 0.ToString();
                    }
                }

            }


            return ansA + " " + ansB;
        }
        

        static void Say(string text)
        {
            Console.WriteLine(text);
            output.WriteLine(text);
        }
    }
}
