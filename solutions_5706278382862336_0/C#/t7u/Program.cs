using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            var fileName = Helper.GetFileName();

            using(var reader = Helper.CreateReader(fileName))
            using(var writer = Helper.CreateWriter(fileName))
            using(var debugger = Helper.CreateWriter())
            {
                var T = reader.ReadInteger();
                for(int i = 0; i < T; ++i)
                {
                    var line = reader.ReadLine('/');
                    var P = long.Parse(line[0]);
                    var Q = long.Parse(line[1]);
                    var counter = 0;
                    var generations = 0L;
                    var correct = false;

                    Solve(P, Q, ref counter, ref generations, ref correct);

                    var s = string.Format("Case #{0}: {1}", i + 1, correct ? generations.ToString() : "impossible");
                    debugger.WriteLine(s);
                    writer.WriteLine(s);
                }
            }

            Console.ReadLine();
        }

        private static void Solve(long P, long Q, ref int counter, ref long generations, ref bool correct)
        {
            if (P == Q)
            {
                correct = true;
                return;
            }
            else if (P > Q)
            {
                correct = true;
                P = P % Q;
            }
            else if(!correct)
            {
                ++generations;
            }

            ++counter;

            if (counter > 40)
            {
                correct = false;
                return;
            }

            Solve(P * 2, Q, ref counter, ref generations, ref correct);
        }
    }


    static class Helper
    {
        public static string GetFileName()
        {
            var args = Environment.GetCommandLineArgs();
            if (args.Length < 2)
                return "sample";

            return Path.GetFileNameWithoutExtension(args[1]);
        }

        public static string[] ReadLine(this TextReader source, char delimiter)
        {
            return source.ReadLine().Split(delimiter);
        }

        public static int ReadInteger(this TextReader source)
        {
            return int.Parse(source.ReadLine());
        }

        public static int[] ReadIntegers(this TextReader source, char delimiter)
        {
            return ReadLine(source, delimiter)
                .Select(x => int.Parse(x))
                .ToArray();
        }

        public static double[] ReadDoubles(this TextReader source, char delimiter)
        {
            return ReadLine(source, delimiter)
                .Select(x => double.Parse(x))
                .ToArray();
        }

        public static void SkipLine(this TextReader source, int count)
        {
            for (int i = 0; i < count; ++i)
                source.ReadLine();
        }

        public static HashSet<T> ToHashSet<T>(this IEnumerable<T> source)
        {
            return new HashSet<T>(source);
        }

        public static HashSet<U> ToHashSet<T, U>(this IEnumerable<T> source, Func<T, U> selector)
        {
            return new HashSet<U>(source.Select(selector));
        }

        public static TextReader CreateReader(string fileName = null)
        {
            if (fileName == null)
                return Console.In;

            return new StreamReader(string.Format("..\\{0}.in", fileName));
        }

        public static TextWriter CreateWriter(string fileName = null)
        {
            if (fileName == null)
                return Console.Out;

            return new StreamWriter(string.Format("..\\{0}.out", fileName));
        }
    }
}
