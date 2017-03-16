using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace GCJ
{
    class Program
    {
        public const string PATH = @"C:\";
        public const string EXERCISE = "input.in";
        public const string EXERCISE_O = "WTF3.txt";

        public static TextWriter OutputWriter;

        public static TextReader ExerciseReader;

        public static Stopwatch SW = new Stopwatch();

        static void Main(string[] args)
        {
            ExerciseReader = new StreamReader(PATH + EXERCISE);
            OutputWriter = new StreamWriter(
                new FileStream(PATH + EXERCISE_O, FileMode.Create, FileAccess.ReadWrite),
    Encoding.ASCII);

            int numTestCases = int.Parse(ExerciseReader.ReadLine());

            for (int i = 0; i < numTestCases; i++)
            {
                //Console.WriteLine(ExerciseReader.ReadLine());
                long r = 0, t = 0;
                string[] s = ExerciseReader.ReadLine().Split(' ');
                r = long.Parse(s[0]);
                t = long.Parse(s[1]);
                Process(i + 1, r, t);

            }

            OutputWriter.Close();
            ExerciseReader.Close();

            Console.WriteLine("Finished");
            Console.ReadLine();
        }

        public static void Process(int caseNum, long r, long t)
        {
            long paint = t;
            long radius = r;

            int i = 0;
            while (true)
            {
                long bA = ((radius + 1) * (radius + 1) - radius * radius);
                paint -= bA;
                if (paint >= 0)
                {
                    i++;
                    radius += 2;
                }
                else
                    break;
            }
            OutputWriter.WriteLine("Case #" + caseNum + ": " + i);

        }

    }
}
