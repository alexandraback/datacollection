using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemA
{
    class Program
    {
        static void WriteLine(StreamWriter sw, string format, params object[] args)
        {
            sw.WriteLine(format, args);
            Console.WriteLine(format, args);
        }

        static void Write(StreamWriter sw, string format, params object[] args)
        {
            sw.Write(format, args);
            Console.Write(format, args);
        }

        static void Main(string[] args)
        {
            //const string fileName = "large.in";
            const string fileName = "small.in";

            string dataFolder = Path.GetDirectoryName(Path.GetDirectoryName(Path.GetDirectoryName(new Uri(typeof(Program).Assembly.CodeBase).LocalPath)));

            using (StreamReader sr = File.OpenText(Path.Combine(dataFolder, fileName)))
            {
                using (StreamWriter sw = File.CreateText(Path.Combine(dataFolder, Path.GetFileNameWithoutExtension(fileName) + ".out")))
                {
                    int caseCount = int.Parse(sr.ReadLine());

                    for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                    {
                        string[] line = sr.ReadLine().Split(" ".ToCharArray());
                        int passed = 0;

                        int N = int.Parse(line[0]);
                        int S = int.Parse(line[1]);
                        int p = int.Parse(line[2]);
                        List<int> t = new List<int>();
                        for (int i = 0; i < N; i++)
                            t.Add(int.Parse(line[3 + i]));

                        t.Sort();
                        t.Reverse();

                        foreach (int score in t)
                        {
                            bool exit = false;
                            bool suprising = false;

                            for (int a = p; a <= 10 && !exit; a++)
                            {
                                int remaining = score - a;

                                for (int b = Math.Max(a - 2, 0); b < Math.Max(a + 2, 10); b++)
                                {
                                    int c = remaining - b;

                                    if (c >= 0 && c <= 10)
                                    {
                                        int diffA = Math.Abs(a - b);
                                        int diffB = Math.Abs(a - c);
                                        int diffC = Math.Abs(b - c);
                                        int maxDiff = Math.Max(Math.Max(diffA, diffB), diffC);

                                        if (maxDiff < 2) // Not-suprising solution
                                        {
                                            exit = true;
                                            break;
                                        }

                                        if (maxDiff < 3) // Suprising solution
                                            suprising = true;
                                    }
                                }
                            }

                            if (exit)
                                passed++;
                            else if (suprising && S > 0)
                            {
                                S--;
                                passed++;
                            }
                        }

                        WriteLine(sw, "Case #{0}: {1}", caseNumber, passed);
                    }
                }
            }
        }
    }
}
