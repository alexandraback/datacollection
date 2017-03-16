using System;
using System.Linq;
using System.IO;
using System.Collections.Generic;

namespace _151BA
{
    class Program
    {
        private const bool DEBUG = false;
        static void debug()
        {
            Console.WriteLine(nines(7));
        }

        static string solveCase()
        {
            long N = read<long>();
            long res = 0;
            int nd = numd(N);
            if (nd == 1)
                return N.ToString();
            for (int d = 1; d < nd; d++)
            {
                res += nines(d / 2) + nines((d / 2) + (d % 2)) + 1;
            }
            int cutoff = nd / 2;
            string nsr = N.ToString();
            long[] r = Enumerable.Repeat(long.MaxValue, nd).ToArray();
            for (int i = 1; i < nd; i++)
            {
                long left = long.Parse(new string(nsr.Take(i).Reverse().ToArray()));
                long right = long.Parse(new string(nsr.Skip(i).ToArray()));
                r[i] = left + right;
            }
            res += Math.Min(r.Min(), N - (long)Math.Pow(10, nd - 1));
            return res.ToString();
        }

        static long nines(int l)
        {
            long r = 0;
            for (int i = 0; i < l; i++)
            {
                r *= 10;
                r += 9;
            }
            return r;
        }

        static long rev(long a)
        {
            return long.Parse(new string(a.ToString().Reverse().ToArray()));
        }

        //static bool newn(long n)
        //{
        //    if (n % 10 == 0) return n + 1;
        //    int num = numd(n);
        //    for (int d = 1; d <= num; d++)
        //    {
        //        long left = nthd(n, d);
        //        long right = nthd(n, num - d);

        //    }
        //}

        static int numd(long i)
        {
            return (int)Math.Floor(Math.Log10(i) + 1);
        }

        static long nthd(long i, long n)
        {
            while (i >= Math.Pow(10, n))
            {
                i /= 10;
            }
            return i % 10;
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