using System;
using System.Collections.Generic;
using System.Data.Common;
using System.IO;
using System.Linq;
using System.Management.Instrumentation;
using NUnit.Framework.Constraints;

namespace Problem1
{
    internal class Program
    {
        public static void RunTestCases(string[] rawTestCases,
            int numTestCases,
            Action<String> outputAction,
            Action<String> debugAction)
        {
            int currentLine = 0;
            for (int i = 0; i < numTestCases; i++)
            {
                long[] settings = rawTestCases.GetSettings(currentLine++);
                long rows = settings[0];
                long columns = settings[1];
                long width = settings[2];

                var total = CalcWorst(columns, width, width, rows);

                long count = total;

                outputAction("Case #" + (i + 1) + ": " + count);
            }
        }

        private static long CalcWorst(long columns, long scanwidth, long width, long rows)
        {

            var possibleTimesPerRow = columns/width;
            var remainderSpaces = columns%width;
            var scanningprobes = possibleTimesPerRow*rows;
            var total = scanningprobes + width-1;
            if (scanwidth+remainderSpaces>width){ total += 1;}
            //if (scanningprobes > 1 && remainderSpaces + )

            return total;
        }

        private static long Reverse(long val)
        {
            
            var valS = val.ToString();
            if (valS.Last() == '0') return val;
            return long.Parse(new string(valS.Reverse().ToArray()));
        }


        private static void Main(string[] args)
        {
            string filename = args.Length == 0 ? "" : args[0];
            if (filename == "")
            {
                var filenames = Directory.GetFiles(Environment.CurrentDirectory).Where(x => x.EndsWith(".in")).ToArray();
                Console.WriteLine("Test file?");
                int n = 0;
                foreach (var f in filenames)
                {
                    Console.WriteLine(n++ + ":" + f);
                }
                var i = int.Parse(Console.ReadLine());
                filename = filenames[i];
            }
            if (filename == "")
            {
                filename = Directory.GetFiles(Environment.CurrentDirectory).First(x => x.EndsWith(".in"));
            }

            string[] testFile = File.ReadAllLines(filename);
            int NumberOfTestCases = int.Parse(testFile.First().Trim());

            List<string> output = new List<string>();
            RunTestCases(testFile.Skip(1).ToArray(),
                NumberOfTestCases,
                output.Add,
                Console.WriteLine);
            File.WriteAllLines("output.out", output);
            Console.WriteLine("Finished " + filename);
            Console.WriteLine("-- press any key --");
            Console.ReadKey();
        }
    }

    internal static class Helpers
    {
        public static long[] GetSettings(this string[] rawFile, int line)
        {
            return rawFile[line].Split(' ')
                .Select(x => long.Parse(x.Trim())).ToArray();
        }
    }
}
