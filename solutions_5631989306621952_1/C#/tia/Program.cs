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

        static void Main(string[] args)
        {
            string inputFileName = "AL.in";
            var reader = new StreamReader(inputFileName);
            int caseCount = reader.ReadLine().ToInt32();
            var writer = new StreamWriter(ToOutputFileName(inputFileName));
            for (int i = 0; i < caseCount; i++)
            {
                string s = reader.ReadLine();
                string result = "";
                foreach (var c in s)
                {
                    if (result == "" || result[0] > c)
                        result += c;
                    else
                        result = c + result;
                }
                writer.WriteCaseOutput(result);
            }
            reader.Close();
            writer.Close();

            // show explorer to access output file
            Process.Start("Explorer", Environment.CurrentDirectory);
        }
    }
}
