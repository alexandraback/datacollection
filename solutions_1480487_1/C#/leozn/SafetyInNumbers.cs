using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;

namespace CodeJam
{
    class SafetyInNumbers
    {
        List<int> points;

        public SafetyInNumbers(List<int> points)
        {
            this.points = points;
        }

        public List<double> Solve()
        {
            var result = new List<double>();

            double total = points.Sum(x => x);
            double target = 2*total / points.Count;

            for (int i = 0; i < points.Count; i++)
            {
                double p = (double)(target - points[i]) / (double)total;
                result.Add(p);
            }

            double neg = result.Sum(x => 
                {
                    if (x < 0)
                        return x;
                    else
                        return 0;
                    }
                );

            int positiveCount = 0;
            int negativeCount = 0;
            double sum = 0.0;
            for (int i = 0; i < result.Count; i++)
            {
                if(result[i] > 0)
                    positiveCount++;

                if (result[i] < 0)
                    negativeCount++;

                sum += result[i];
            }

            if (negativeCount > 0)
            {
                for (int i = 0; i < result.Count; i++)
                {
                    if (result[i] < 0)
                    {
                        result[i] = 0;
                    }
                    else
                    {
                        result[i] = result[i] + neg / positiveCount;
                    }
                }
            }

            for (int i = 0; i < result.Count; i++)
            {
                result[i] = result[i] * 100;
            }

            return result;
        }

        static void Main(string[] args)
        {
            string fileName = "SafetyInNumbersL";
            using (StreamReader sr = new StreamReader(File.OpenRead(fileName + ".in")))
            {
                using (StreamWriter sw = new StreamWriter(File.OpenWrite(fileName + ".out")))
                {
                    string line = sr.ReadLine();
                    int numOfTests = Int32.Parse(line);
                    for (int i = 0; i < numOfTests; i++)
                    {
                        line = sr.ReadLine();
                        var row = Regex.Split(line, "\\s+").Select(x => Int32.Parse(x)).ToList();
                        var points = new List<int>();

                        int n = row[0];
                        for (int j = 0; j < n; ++j)
                        {
                            points.Add(row[j + 1]);
                        }
                        var program = new SafetyInNumbers(points);
                        var result = program.Solve();
                        sw.WriteLine("Case #{0}: {1}", i + 1, string.Join(" ", result));
                    }
                }
            }
        }
    }
}
