using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Infinite_House_of_Pancakes
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            //const string filename = @"..\..\B-small-attempt4.in";
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
            int D = int.Parse(reader.ReadLine());
            string sss = reader.ReadLine();
            string[] ss = sss.Split(' ');

            var heap = new int[D];
            int max = 1;
            for (int i = 0; i < D; i++)
            {
                heap[i] = int.Parse(ss[i]);
                if (max < heap[i])
                    max = heap[i];
            }

            int time = max;
            for (int i = 1; i <= max; i++)
            {
                int count = 0;

                for (int j = 0; j < heap.Length; j++)
                {
                    if (heap[j] > i)
                    {
                        count += ((heap[j] + i - 1)/i) - 1;
                    }
                }

                count += i;

                if (time > count)
                    time = count;
            }


            Console.WriteLine("Case #{0}: {1} - {2}", Case, time, sss);
            writer.WriteLine("Case #{0}: {1}", Case, time);
        }
    }
}