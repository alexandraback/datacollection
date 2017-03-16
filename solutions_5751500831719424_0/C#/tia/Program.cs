using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace MainApp
{
    public static class CodeJamExtensions
    {
        public static IEnumerable<string> ReadDataLines(this StreamReader reader)
        {
            int lineCount = reader.ReadLine().ToInt32();
            return reader.ReadLines(lineCount);

        }

        public static IEnumerable<string> ReadLines(this StreamReader reader, int lineCount)
        {
            for (int i = 0; i < lineCount; i++)
            {
                yield return reader.ReadLine();
            }
        }

        public static int ToInt32(this string str)
        {
            return int.Parse(str);
        }

        public static double ToDouble(this string str)
        {
            return double.Parse(str);
        }

        public static List<string> Split(this string str)
        {
            return str.Split(' ').ToList();
        }

        public static List<int> SplitAsInt32(this string str)
        {
            return str.Split(' ').Select(s => s.ToInt32()).ToList();
        }

        public static List<double> SplitAsDouble(this string str)
        {
            return str.Split(' ').Select(s => s.ToDouble()).ToList();
        }

        private static int caseIndex = 0;

        public static void WriteCaseOutput(this StreamWriter writer, params object[] values)
        {
            writer.Write("Case #{0}:", caseIndex + 1);
            foreach (var val in values)
            {
                writer.Write(" ");
                writer.Write(val);                
            }
            writer.WriteLine();
            caseIndex++;
        }

    }

    class Program
    {
        static string ToOutputFileName(string fileName)
        {
            return Path.GetFileNameWithoutExtension(fileName) + ".out";
        }

        private static string D(string s)
        {
            var sb = new StringBuilder();
            char cc = ' ';
            foreach (var c in s)
            {
                if (c != cc) {
                    cc = c;
                    sb.Append(c);
                }
            }
            return sb.ToString();
        }

        private static int P(List<string> ss)
        {
            var list = ss.Select(s => D(s)).Distinct().ToList();
            if (list.Count > 1) return -1;
            var mapmap = new List<List<int>>();
            foreach (var s in ss)
            {
                var map = new List<int>();
                int i = 0;
                char lc = s[0];
                int count = 0;
                foreach (var c in s + ' ')
                {
                    if (lc != c)
                    {
                        if (count > 0)
                        {
                            map.Add(count);
                        }
                        lc = c;
                        count = 0;
                    }
                    count++;
                }
                //var m = s.GroupBy(se => se).Select(g => new { g.Key, Count = g.Count() }).ToDictionary(n => n.Key, n => n.Count);
                mapmap.Add(map);
                //map.Add(m);
            }
            int r = 0;
            //int i = 0;
            //foreach (var c in list[0])
            for (int i = 0; i < list[0].Length; i++)
            {
                List<int> l = mapmap.Select(m => m[i]).ToList();
                l.Sort();
                int i2 = l[mapmap.Count / 2];
                int sum = l.Select(t => Math.Abs(t - i2)).Sum();
                r += sum;
            }
            return r;
        }

        static void Main(string[] args)
        {
            string inputFileName = "A-small-attempt1 (1).in";
            var reader = new StreamReader(inputFileName);
            int caseCount = reader.ReadLine().ToInt32();
            var writer = new StreamWriter(ToOutputFileName(inputFileName));
            for (int i = 0; i < caseCount; i++)
            {
                int N = reader.ReadLine().ToInt32();
                var ss = reader.ReadLines(N).ToList();
                int p = P(ss);
                writer.WriteCaseOutput(p >= 0 ? p.ToString() : "Fegla Won");
            }
            reader.Close();
            writer.Close();

            // show explorer to access output file
            Process.Start("Explorer", Environment.CurrentDirectory);
        }
    }
}
