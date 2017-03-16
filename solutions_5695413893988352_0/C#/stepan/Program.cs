using System;
using System.IO;
using System.Collections.Generic;

namespace P1
{
    class Solution
    {
        public int CodersScore { get; set; }

        public int JammersScore { get; set; }

        public string JammersString { get; set; }

        public string CodersString { get; set; }

        public int Difference
        {
            get { return System.Math.Abs(CodersScore - JammersScore); }
        }
    }

    class Program
    {
        const string size = "small";

        static void Main()
        {
            using(var streamReader = new StreamReader($"B-{size}.in"))
            using(var streamWriter = new StreamWriter($"output-{size}.txt"))
            {
                int t = int.Parse(streamReader.ReadLine());

                for(int j = 0; j < t; j++)
                {
                    string[] lineString = streamReader.ReadLine().Split(' ');
                    string coders = lineString[0]; string jammers = lineString[1];
                    int nDigits = coders.Length;

                    Solution best = null;

                    for(int randomCoders = 0; randomCoders < Math.Pow(10,nDigits); randomCoders++)
                    {
                        string rcString = randomCoders.ToString($"D{nDigits}");
                        for (int randomJammers = 0; randomJammers < Math.Pow(10, nDigits); randomJammers++)
                        {
                            string rjString = randomJammers.ToString($"D{nDigits}");
                            
                            string newCoders = string.Empty;
                            string newJammers = string.Empty;

                            for (int k = 0; k < nDigits; k++)
                            {
                                char co = coders[k]; char ja = jammers[k];
                                if (co == '?')
                                    newCoders += rcString[k];
                                else
                                    newCoders += co;

                                if (ja == '?')
                                    newJammers += rjString[k];
                                else
                                    newJammers += ja;
                            }

                            var sol = new Solution
                            {
                                CodersScore = int.Parse(newCoders),
                                JammersScore = int.Parse(newJammers),
                                CodersString = newCoders,
                                JammersString = newJammers
                            };

                            if (best == null || sol.Difference < best.Difference)
                                best = sol;
                            else if (sol.Difference == best.Difference)
                            {
                                if(sol.CodersScore < best.CodersScore)
                                {
                                    best = sol;
                                }
                                else if(sol.JammersScore < best.JammersScore)
                                {
                                    // Probably redundant:
                                    best = sol;
                                }
                            }
                        }
                    }

                    // TODO: logic

                    streamWriter.WriteLine($"Case #{j + 1}: {best.CodersString} {best.JammersString}");
                    // TODO: result
                }
            }
        }
    }
}
