using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

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

            Stopwatch swatch = Stopwatch.StartNew();

            using (StreamReader sr = File.OpenText(Path.Combine(dataFolder, fileName)))
            {
                using (StreamWriter sw = File.CreateText(Path.Combine(dataFolder, Path.GetFileNameWithoutExtension(fileName) + ".out")))
                {
                    long caseCount = long.Parse(sr.ReadLine());

                    for (long caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                    {
                        string[] s = sr.ReadLine().Split();
                        long A = long.Parse(s[0]);
                        long B = long.Parse(s[1]);
                        long count = 0;
                        Dictionary<long, long> found = new Dictionary<long, long>();

                        long digits = (long)Math.Log10(B);                        
                        long trailingBase = (long)Math.Pow(10, digits);
                        long inputBase = trailingBase * 10;
                        long leadingBase = 10;

                        for (long power = 1; power <= digits; power++)
                        {                            
                            for (long i = A; i <= B; i++)
                            {
                                long leading = i / leadingBase;
                                long trailing = i % leadingBase;

                                if (trailing >= leadingBase / 10) // Must have enough digits
                                {
                                    long switched = trailing * trailingBase + leading;

                                    if (switched >= A && switched <= B && i != switched)
                                    {
                                        long pair = i + switched * inputBase;

                                        if (!found.ContainsKey(pair))
                                        {
                                            found.Add(pair, i);
                                            found.Add(switched + i * inputBase, i);

                                            //WriteLine(sw, "{0}", pair);

                                            count++;                                            
                                        }
                                    }
                                }
                            }

                            trailingBase /= 10;
                            leadingBase *= 10;
                        }


                        WriteLine(sw, "Case #{0}: {1}", caseNumber, count);
                    }
                }
            }

            swatch.Stop();
            Console.WriteLine(swatch.ElapsedMilliseconds);
        }
    }
}
