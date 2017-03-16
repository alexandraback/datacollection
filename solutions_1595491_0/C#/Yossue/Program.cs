using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace B
{
    class Program
    {
        /// <summary>
        /// Get highest scores for surprising/non-surprising result.
        /// </summary>
        /// <returns>2 integer array. First integer is highest score of surprising result, second integer is of not surprising result.</returns>
        static int[] getMaximumScore(int sum)
        {
            int[] highestScores = new int[2];

            if (sum == 0)
            {
                highestScores[0] = 0;
                highestScores[1] = 0;
            }
            else
            {
                switch (sum % 3)
                {
                    case 0:
                        highestScores[0] = sum / 3 + 1;
                        highestScores[1] = sum / 3;
                        break;
                    case 1:
                        highestScores[0] = sum / 3 + 1;
                        highestScores[1] = sum / 3 + 1;
                        break;
                    case 2:
                        highestScores[0] = sum / 3 + 2;
                        highestScores[1] = sum / 3 + 1;
                        break;
                    default:
                        throw new Exception("Unexpected sum value: " + sum.ToString());
                }
            }

            if (highestScores[0] > 10)
            {
                highestScores[0] = 10;
            }

            return highestScores;
        }

        /// <summary>
        /// Get maximum number of Googlers that could have had a best result of at least p.
        /// </summary>
        /// <returns>maximum number of Googlers that could have had a best result of at least p</returns>
        static int getMaximumNumberWithPOrLarger(int N, int S, int p, List<int> t)
        {
            int result = 0;

            int availableSurprisingResult = S;
            foreach (int sum in t)
            {
                int[] highestScores = getMaximumScore(sum);
                if (highestScores[1] >= p)
                {
                    result++;
                }
                else if ((availableSurprisingResult > 0) && (highestScores[0] >= p))
                {
                    result++;
                    availableSurprisingResult--;
                }
            }

            return result;
        }

        static void Main(string[] args)
        {
            int numTestCases = 0;

            StreamReader r = new StreamReader(@"../../B-small-attempt0.in");
            StreamWriter w = new StreamWriter(@"../../B-small-attempt0.out");

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
                    int S = 0;
                    int p = 0;
                    List<int> t = new List<int>();

                    string[] inputNumbers = line.Split(new Char[] { ' ' });
                    int len = inputNumbers.Length;

                    int.TryParse(inputNumbers[0], out N);
                    int.TryParse(inputNumbers[1], out S);
                    int.TryParse(inputNumbers[2], out p);
                    for (int i = 3; i < len; ++i)
                    {
                        int tmp = 0;
                        int.TryParse(inputNumbers[i], out tmp);
                        t.Add(tmp);
                    }

                    int result = getMaximumNumberWithPOrLarger(N, S, p, t);
                    Console.WriteLine("Case #{0}: {1}", index, result);
                    w.WriteLine("Case #{0}: {1}", index, result);

                    ++index;
                }
            }

            r.Close();
            w.Close();
        }
    }
}
