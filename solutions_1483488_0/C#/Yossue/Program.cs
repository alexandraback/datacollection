using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace C
{
    class Program
    {
        static Dictionary<long, List<long>> mapRecycledNumbers = new Dictionary<long, List<long>>();

        static List<long> GetRecycledNumbers(long input)
        {
            if (mapRecycledNumbers.ContainsKey(input))
            {
                return mapRecycledNumbers[input];
            }
            else
            {
                List<long> recycledNumbers = new List<long>();

                int nDigit = 0;
                long tmpInput = input;
                while (tmpInput > 0)
                {
                    tmpInput /= 10;
                    nDigit++;
                }

                for (int i = 1; i < nDigit; ++i)
                {
                    long numberForDivide = 1;
                    for (int j = 0; j < nDigit - i; ++j)
                    {
                        numberForDivide *= 10;
                    }

                    long numberForSlide = 1;
                    for (int j = 0; j < i; ++j)
                    {
                        numberForSlide *= 10;
                    }

                    long recycledNumber = (input % numberForDivide) * numberForSlide + (input / numberForDivide);
                    if (recycledNumber > input)
                    {
                        recycledNumbers.Add(recycledNumber);
                    }
                }

                mapRecycledNumbers[input] = recycledNumbers;
                return recycledNumbers;
            }
        }

        static void Main(string[] args)
        {
            int numTestCases = 0;

            StreamReader r = new StreamReader(@"../../C-small-attempt0.in");
            StreamWriter w = new StreamWriter(@"../../C-small-attempt0.out");

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
                    int min = 0;
                    int max = 0;
                    int count = 0;
                    Dictionary<long, HashSet<long>> mapAnswers = new Dictionary<long, HashSet<long>>();

                    string[] inputNumbers = line.Split(new Char[] { ' ' });

                    int.TryParse(inputNumbers[0], out min);
                    int.TryParse(inputNumbers[1], out max);

                    for (long i = min; i <= max; ++i)
                    {
                        List<long> recycledNumbers = GetRecycledNumbers(i);
                        foreach (long num in recycledNumbers)
                        {
                            if (num <= max)
                            {
                                if (!mapAnswers.ContainsKey(i))
                                {
                                    mapAnswers[i] = new HashSet<long>();
                                }
                                if (!mapAnswers[i].Contains(num))
                                {
                                    mapAnswers[i].Add(num);
                                    count++;
                                }
                            }
                        }
                    }

                    Console.WriteLine("Case #{0}: {1}", index, count);
                    w.WriteLine("Case #{0}: {1}", index, count);

                    ++index;
                }
            }

            r.Close();
            w.Close();
        }
    }
}
