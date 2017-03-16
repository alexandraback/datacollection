using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Cookie_Clicker_Alpha
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //string filename = @"sample.in.txt";
            string filename = @"B-small-attempt0.in";

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

        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split(' ');

            double c = double.Parse(ss[0]);
            double f = double.Parse(ss[1]);
            double x = double.Parse(ss[2]);


            double time = x/2;

            double point = 0;
            double current = 2;

            g:
            double next = c/current;
            current += f;
            double tnext = x/current;

            if (point + tnext + next < time)
            {
                time = point + tnext + next;
                point = point + next;
                goto g;
            }


            Console.WriteLine("Case #{0}: {1:#.0000000}", C, time);
            writer.WriteLine("Case #{0}: {1:#.0000000}", C, time);
        }
    }
}