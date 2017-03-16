using System;
using System.Linq;
using System.IO;
using System.Collections.Generic;

namespace _151BB
{
    class Program
    {
        private const bool DEBUG = false;
        static void debug()
        {
            Console.WriteLine(System.Text.RegularExpressions.Regex.Matches("ABABA", "A(?=BA)").Count);
        }

        static IEnumerable<IEnumerable<char>> allTexts(int length, IEnumerable<char> alphabet)
        {
            IEnumerable<IEnumerable<char>> start = new IEnumerable<char>[] { Enumerable.Empty<char>() };
            if (length > 1)
            {
                start = allTexts(length - 1, alphabet);
            }
            foreach (IEnumerable<char> shorter in start)
            {
                foreach (char n in alphabet)
                {
                    yield return shorter.Concat(new[] { n });
                }
            }
        }

        static string solveCase()
        {
            int[] kls = readMany<int>();
            string alph = read();
            string target = read();
            string starget = target.Substring(0, 1) + "(?=" + target.Substring(1, target.Length - 1) + ")";
            List<int> all = new List<int>();
            foreach (IEnumerable<char> a in allTexts(kls[2], alph))
            {
                all.Add(System.Text.RegularExpressions.Regex.Matches(new string(a.ToArray()), starget).Count);
            }
            return String.Format("{0:F7}", (all.Max() - all.Average()));
        }

        static void Main(string[] args)
        {
            if (DEBUG)
            {
                debug();
            }
            else
            {
                Initialize();
                SolveAll(solveCase);
            }
            Console.ReadKey();
        }

        private static StreamReader inf;
        private static StreamWriter outf;

        private delegate void o(string format, params object[] args);
        private static o Output;

        private static T read<T>()
        {
            return (T)Convert.ChangeType(inf.ReadLine(), typeof(T));
        }

        private static string read()
        {
            return inf.ReadLine();
        }

        private static T[] readMany<T>()
        {
            return readMany<T>(' ');
        }

        private static _[] readMany<_>(params char[] ___)
        {
            return read().Split(___).Select(__ => (_)Convert.ChangeType(__, typeof(_))).ToArray();
        }

        private static string[] readMany()
        {
            return readMany<string>();
        }

        private static T[][] readField<T>(int height, Func<char, T> map)
        {
            T[][] res = new T[height][];
            for (int _ = 0; _ < height; _++)
            {
                res[_] = read().Select(c => map(c)).ToArray();
            }
            return res;
        }

        private static char[][] readField(int height)
        {
            return readField(height, c => c);
        }

        private static T[][] readField<T>(int height, Dictionary<char, T> dic)
        {
            return readField(height, c => dic[c]);
        }

        public static void Initialize()
        {
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("Input file: ");
            inf = new StreamReader(Console.ReadLine());
            Console.Write("Output file: ");
            outf = new StreamWriter(Console.ReadLine());
            Console.ForegroundColor = ConsoleColor.White;
            Output = highlightedPrint;
            Output += outf.WriteLine;
        }

        private static void highlightedPrint(string format, params object[] args)
        {
            ConsoleColor prev = Console.ForegroundColor;
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine(format, args);
            Console.ForegroundColor = prev;
        }

        public static void SolveAll(Func<string> calc)
        {
            int cases = int.Parse(inf.ReadLine());
            for (int _ = 1; _ <= cases; _++)
            {
                Output("Case #{0}: {1}", _, calc());
            }
            inf.Close();
            outf.Close();
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("Eureka!");
        }
    }
}