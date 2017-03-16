using System;
using System.Globalization;
using System.IO;
using System.Threading;
using System.Collections.Generic;

namespace Rank_and_File
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            //const string filename = @"..\..\B-small-attempt0.in";
            const string filename = @"..\..\B-large.in";

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
            int n = int.Parse(reader.ReadLine());
            int[] counts = new int[2501];
            for (int i = 2 * n - 1; i > 0; i--)
            {
                string[] ss = reader.ReadLine().Split(' ');
                for (int j = 0; j < n; j++)
                {
                    counts[int.Parse(ss[j])]++;
                }
            }

            List<int> res = new List<int>(n);

            for (int i = 1; i < counts.Length; i++)
            {
                if (counts[i] % 2 == 1)
                    res.Add(i);
            }

            Console.Write("Case #{0}:", Case);
            writer.Write("Case #{0}:", Case);

            foreach (int i in res)
            {
                Console.Write(" ");
                writer.Write(" ");
                Console.Write(i);
                writer.Write(i);
            }

            Console.WriteLine();
            writer.WriteLine();
        }
    }
}