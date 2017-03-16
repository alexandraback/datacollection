using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Fractiles
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            const string filename = @"..\..\D-small-attempt0.in";
            //const string filename = @"..\..\B-large.in";

            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (var reader = new StreamReader(filename))
            {
                using (var writer = new StreamWriter(filename.Replace(".in", ".out"), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split(' ');
            int K = int.Parse(ss[0]);
            int C = int.Parse(ss[1]);
            int S = int.Parse(ss[2]);

            Console.Write("Case #{0}:", Case);
            writer.Write("Case #{0}:", Case);

            for (int i = 1; i <= S; i++)
            {
                Console.Write(" {0}", i);
                writer.Write(" {0}", i);
            }

            Console.WriteLine();
            writer.WriteLine();
        }
    }
}