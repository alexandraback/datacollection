using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Dancing
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(args[0]))
            {
                using (StreamWriter writer = new StreamWriter(args[1]))
                {
                    // read number of test cases
                    int rowCount;
                    int.TryParse(reader.ReadLine(), out rowCount);

                    // read line by line
                    for (int i = 0; i < rowCount; i++)
                    {
                        string[] data = reader.ReadLine().Split(' ');
                        int googlers, surprises, threshold, p = 0;
                        int.TryParse(data[0], out googlers);
                        int.TryParse(data[1], out surprises);
                        int.TryParse(data[2], out threshold);
                        List<int> scores = new List<int>();

                        for (int j = 3; j < data.Length; j++)
                        {
                            scores.Add(int.Parse(data[j]));
                        }

                        // sort descending
                        scores.Sort();
                        scores.Reverse();

                        foreach (int score in scores)
                        {
                            int multiplier = score / 3;
                            int remainder = score % 3;

                            if (multiplier >= threshold)
                            {
                                p++;
                            }
                            else if (remainder == 0)
                            {
                                if ((surprises > 0) && (score >= 2) && (score <= 28))
                                {
                                    if ((multiplier + 1) >= threshold)
                                    {
                                        p++;
                                    }

                                    surprises--;
                                }
                            }
                            else if (remainder == 1)
                            {
                                if ((multiplier + 1) >= threshold)
                                {
                                    p++;
                                }
                                else if ((surprises > 0) && (score >= 2) && (score <= 28))
                                {
                                    if ((multiplier + 1) >= threshold)
                                    {
                                        p++;
                                    }

                                    surprises--;
                                }
                            }
                            else if (remainder == 2)
                            {
                                if ((multiplier + 1) >= threshold)
                                {
                                    p++;
                                }
                                else if ((surprises > 0) && (score >= 2) && (score <= 28))
                                {
                                    if ((multiplier + 2) >= threshold)
                                    {
                                        p++;
                                    }

                                    surprises--;
                                }
                            }
                        }

                        writer.WriteLine("Case #{0}: {1}", i + 1, p);
                    }
                }
            }
        }
    }
}
