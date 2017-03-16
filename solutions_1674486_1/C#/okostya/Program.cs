using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Diamond_Inheritance
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            string filename = @"A-large.in.txt";

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (StreamReader reader = new StreamReader(filename))
            {
                using (StreamWriter writer = new StreamWriter(filename.Replace(".in.", ".out."), false))
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
            int N = int.Parse(reader.ReadLine());

            List<int>[] classes = new List<int>[1 + N];
            List<int>[] classes2 = new List<int>[1 + N];
            for (int i = 0; i < N; i++)
            {
                string[] s = reader.ReadLine().Split(' ');
                int K = int.Parse(s[0]);

                classes[i + 1] = new List<int>();
                classes2[i + 1] = new List<int>();
                classes2[i + 1].Add(i + 1);
                for (int j = 0; j < K; j++)
                {
                    int m = int.Parse(s[1 + j]);
                    classes[i + 1].Add(m);
                }
            }
            bool swap = false;
            bool found;
            do
            {
                found = false;
                for (int i = 1; i <= N; i++)
                {
                    if (classes[i] != null && classes[i].Count == 0)
                    {
                        classes[i] = null;
                        for (int j = 1; j <= N; j++)
                        {
                            if (classes[j] != null && classes[j].Contains(i))
                            {
                                classes[j].Remove(i);
                                foreach (int i1 in classes2[i])
                                {
                                    if (classes2[j].Contains(i1))
                                    {
                                        swap = true;
                                        goto m;
                                    }
                                    else
                                        classes2[j].Add(i1);
                                }
                            }
                        }
                        found = true;
                        break;
                    }
                }
            } while (found);


            m:
            Console.WriteLine("Case #{0}: {1}", C, swap ? "Yes" : "No");
            writer.WriteLine("Case #{0}: {1}", C, swap ? "Yes" : "No");
        }
    }
}