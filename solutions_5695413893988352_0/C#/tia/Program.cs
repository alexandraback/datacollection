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

        public static List<string> Split(this string str)
        {
            return str.Split(' ').ToList();
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

        private static bool m2(string pattern, long a) {
            string sv = a.ToString().PadLeft(pattern.Length, '0');
            if (sv.Length != pattern.Length)
                return false;
            
            string p = pattern;
            for (int i = 0; i < sv.Length; i++)
            {
                if (p[i] != '?' && p[i] != sv[i])
                {
                    return false;
                }
            }
            return true;
        }

        private static bool m(string pattern, long a, long inc) {
            long value = a + inc;
            if (value < 0)
                return false;
            string sv = value.ToString();
            if (sv.Length > a.ToString().Length)
                return false;
            if (sv.Length > pattern.Length)
                return false;
            string p = pattern.Substring(0, sv.Length);
            for (int i = 0; i < sv.Length; i++)
            {
                if (p[i] != '?' && p[i] != sv[i])
                {
                    return false;
                }
            }
            return true;
        }

        private static IEnumerable<Tuple<long, long>> brute(string s1, string s2) {
            for (long i = 0; i < 1000; i++)
            {
                if (m2(s1, i)) {
                    for (long j = 0; j < 1000; j++)
                    {
                        if (m2(s2, j))
                        {
                            yield return Tuple.Create(i, j);
                        }
                    }
                }
            }
        }



        static void Main(string[] args)
        {
            string inputFileName = "B-small-attempt5.in";
            var reader = new StreamReader(inputFileName);
            int caseCount = reader.ReadLine().ToInt32();
            var writer = new StreamWriter(ToOutputFileName(inputFileName));
            for (int i = 0; i < caseCount; i++)
            {
                var ss = reader.ReadLine().Split(' ');
                string s1 = ss[0];
                string s2 = ss[1];

                var result = brute(s1, s2)
                    .OrderBy(t => Math.Abs(t.Item1 - t.Item2))
                    .ThenBy(t => t.Item1)
                    .ThenBy(t => t.Item2)
                    .First();
                string svv1 = result.Item1.ToString().PadLeft(s1.Length, '0');
                string svv2 = result.Item2.ToString().PadLeft(s2.Length, '0');

                writer.WriteCaseOutput(svv1, svv2);
                continue;

                long v1 = 0;
                long v2 = 0;
                bool f1 = false;
                bool f2 = false;
                bool n1 = false;
                bool n2 = false;
                for (int j = 0; j < s1.Length; j++)
                {
                    char c1 = s1[j];
                    char c2 = s2[j];
                    f1 = f1 || c1 != '?';
                    f2 = f2 || c2 != '?';

                    if (v1 == v2)
                    {
                        if (c1 == '?' && c2 == '?')
                        {
                            c1 = '0';
                            c2 = '0';
                        }
                        else if (j > 0 && c1 != '?' && c2 != '?')
                        {
                            //if (c1 - c2 > 5 && s2[j - 1] == '?' && m(s2, v2 + 1))
                            //    v2++;
                            if (c1 - c2 >= 5)
                            {
                                if (s1[j - 1] == '?' && m(s1, v1, - 1))
                                {
                                    v1--;
                                }
                                else if (c1 - c2 != 5 && s2[j - 1] == '?' && m(s2, v2, + 1))
                                {
                                    v2++;
                                } 
                            }
                            else if (c2 - c1 >= 5)
                            {
                                if (s2[j - 1] == '?' && m(s2, v2, - 1))
                                {
                                    v2--;
                                }
                                else if (c2-c1 != 5 && s1[j - 1] == '?' && m(s1, v1, + 1))
                                {
                                    v1++;
                                }
                            }
                        }
                        if (c1 == '?')
                            c1 = c2;
                        if (c2 == '?')
                            c2 = c1;
                    }
                    else if (v1 > v2)
                    {
                        if (c1 == '?' && c2 == '?') {
                            c1 = '0'; c2 = '9';
                        }
                        if (c1 == '?')
                            c1 = '0';
                        if (c2 == '?')
                            c2 = '9';
                    }
                    else if (v1 < v2)
                    {
                        if (c1 == '?' && c2 == '?') {
                            c1 = '9'; c2 = '0';
                        }

                        if (c1 == '?')
                            c1 = '9';
                        if (c2 == '?')
                            c2 = '0';
                    }
                    v1 *= 10;
                    v1 += int.Parse(c1.ToString());
                    v2 *= 10;
                    v2 += int.Parse(c2.ToString());
                }
                string sv1 = v1.ToString().PadLeft(s1.Length, '0');
                string sv2 = v2.ToString().PadLeft(s2.Length, '0');
                writer.WriteCaseOutput(sv1, sv2);
            }
            reader.Close();
            writer.Close();

            // show explorer to access output file
            Process.Start("Explorer", Environment.CurrentDirectory);
        }
    }
}
