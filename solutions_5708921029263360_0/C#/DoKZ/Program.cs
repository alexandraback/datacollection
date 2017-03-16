using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main()
        {
            File.Delete("output.txt");

            int t;
            using (var sr = new StreamReader(File.OpenRead("input.txt")))
            using (var sw = new StreamWriter(new FileStream("output.txt", FileMode.CreateNew)))
            {
                t = int.Parse(sr.ReadLine());

                for (int tRun = 0; tRun < t; tRun++)
                {
                    RunTest(tRun, sr, sw);
                }
            }
        }

        static void RunTest(int run, TextReader reader, TextWriter writer)
        {
            int[] tokens = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int jMax = tokens[0], pMax = tokens[1], sMax = tokens[2], kMax = tokens[3];
            Dictionary<string, int> kCount = new Dictionary<string, int>();
            List<string> results = new List<string>();

            for (int j = 1; j <= jMax; j++)
                for (int p = 1; p <= pMax; p++)
                    kCount.Add(j.ToString() + p.ToString() + "x", 0);

            for (int j = 1; j <= jMax; j++)
                for (int s = 1; s <= sMax; s++)
                    kCount.Add(j.ToString() + "x" + s.ToString(), 0);

            for (int p = 1; p <= pMax; p++)
                for (int s = 1; s <= sMax; s++)
                    kCount.Add("x" + p.ToString() + s.ToString(), 0);

            for (int i = 0; i < 1000; i++)
            {
                for (int j = 1; j <= jMax; j++)
                    for (int p = 1; p <= pMax; p++)
                        for (int s = 1; s <= sMax; s++)
                        {
                            if (IsAllowed(results, kCount, j, p, s, kMax))
                            {
                                results.Add(j.ToString() + " " + p.ToString() + " " + s.ToString());
                                kCount[j.ToString() + p.ToString() + "x"]++;
                                kCount[j.ToString() + "x" + s.ToString()]++;
                                kCount["x" + p.ToString() + s.ToString()]++;
                            }
                        }
            }

            writer.WriteLine("Case #{0}: {1}", run + 1, results.Count);
            foreach (var res in results)
                writer.WriteLine(res);
        }

        private static bool IsAllowed(List<string> results, Dictionary<string, int> counts, int j, int p, int s, int kMax)
        {
            if (results.Count > 0 && (results[results.Count - 1] == j.ToString() + " " + p.ToString() + " " + s.ToString()))
                return false;

            if (counts[j.ToString() + p.ToString() + "x"] >= kMax)
                return false;

            if (counts[j.ToString() + "x" + s.ToString()] >= kMax)
                return false;

            if (counts["x" + p.ToString() + s.ToString()] >= kMax)
                return false;

            return true;
        }
    }
}
