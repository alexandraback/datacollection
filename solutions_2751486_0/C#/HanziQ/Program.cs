using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;

namespace GCJ
{
    class Program
    {
        public const string PATH = @"C:\Users\HanziQ\Downloads\";
        public const string EXERCISE = "A-small-attempt0.in";
        public const string EXERCISE_O = "conso_small.out";

        public static TextWriter OutputWriter;

        public static TextReader ExerciseReader;

        public static Stopwatch SW = new Stopwatch();

        static void Main(string[] args)
        {
            ExerciseReader = new StreamReader(PATH + EXERCISE);
            OutputWriter = new StreamWriter(File.Open(PATH + EXERCISE_O, FileMode.Create));
            int numTestCases = int.Parse(ExerciseReader.ReadLine());

            for (int i = 0; i < numTestCases; i++)
            {

                string[] s = ExerciseReader.ReadLine().Split(' ');
                Process(i + 1, s[0], int.Parse(s[1]));

            }

            OutputWriter.Close();
            ExerciseReader.Close();
            Console.ReadLine();
        }

        public static List<char> consonants = new List<char>(new char[] { 'a', 'e', 'i', 'o', 'u' });


        public static void Process(int numCase, string str, int n)
        {
            Console.WriteLine(numCase);

            int substringCount = 0;

            Dictionary<string, int> consCounts = new Dictionary<string, int>();

            List<string> substrings = new List<string>();

            Dictionary<Tuple<int, int>, string> substringsWithLengths = new Dictionary<Tuple<int, int>, string>();

            for (int i = 0; i <= str.Length - n; i++)
            {
                bool flag = true;
                string consStr = "";

                for (int j = 0; j < n; j++)
                {
                    if (!consonants.Contains(str[j + i]))
                    {
                        consStr += str[j + i];
                        continue;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {

                    int z = str.Length - n - i;

                    for (int y = 0; y <= z; y++)
                    {
                        for (int x = 0; x <= i; x++)
                        {
                           string substr = ""; 
                             substr = str.Substring(x, str.Length - x - y);

                            var t = new Tuple<int, int>(x, str.Length - y);

                            if (!substringsWithLengths.ContainsKey(t))
                                substringsWithLengths.Add(t, substr);

                        }
                    }

                }
            }



            OutputWriter.WriteLine("Case #" + numCase + ": " + substringsWithLengths.Count);
        }

    }
}

