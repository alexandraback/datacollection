using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Deceitful_War
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string filename = @"../../D-large.in";
            //string filename = @"../../C-small-attempt1.in";

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
                        Console.Write("N=" + i + " ");
                        Process(i, reader, writer);
                        Console.WriteLine(" Time=" + (DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            int N = int.Parse(reader.ReadLine());

            string[] ss = reader.ReadLine().Split(' ');

            var naomi = new List<double>(N);
            var ken = new List<double>(N);

            for (int i = 0; i < N; i++)
            {
                naomi.Add(double.Parse(ss[i]));
            }

            ss = reader.ReadLine().Split(' ');

            for (int i = 0; i < N; i++)
            {
                ken.Add(double.Parse(ss[i]));
            }

            naomi.Sort();
            ken.Sort();

            int count1 = 0;
            int count2 = 0;

            int indexken = 0;
            for (int i = 0; i < N; i++)
            {
                while (indexken<N && naomi[i]>ken[indexken])
                {
                    indexken++;
                }
                if (indexken==N)
                    break;

                count2++;
                indexken++;
            }

            count2 = N - count2;

            indexken = 0;
            for (int i = 0; i < N; i++)
            {
                if (naomi[i] > ken[indexken])
                {
                    count1++;
                    indexken++;
                }
            }

            Console.WriteLine("Case #{0}: {1} {2}", C, count1, count2);
            writer.WriteLine("Case #{0}: {1} {2}", C, count1, count2);
        }
    }
}