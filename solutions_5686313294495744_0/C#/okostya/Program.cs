using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Technobabble
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            const string filename = @"..\..\C-small-attempt0.in";
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
            int n = int.Parse(reader.ReadLine());

            var array = new Tuple<string, string>[n];
            for (int i = 0; i < n; i++)
            {
                string[] ss = reader.ReadLine().Split(' ');
                array[i] = new Tuple<string, string>(ss[0], ss[1]);
            }

            int time = 0;

            int maxmask = (1 << n);

            for (int i = 0; i < maxmask; i++)
            {
                bool f = true;
                int count = 0;
                for (int j = 0; j < n; j++)
                {
                    if ((i & (1 << j)) == 0)
                    {
                        count++;
                        bool ok1 = false;
                        bool ok2 = false;
                        for (int k = 0; k < n; k++)
                        {
                            if ((i & (1 << k)) != 0)
                            {
                                if (array[k].Item1 == array[j].Item1)
                                {
                                    ok1 = true;
                                    if (ok2)
                                    {
                                        break;
                                    }
                                }
                                if (array[k].Item2 == array[j].Item2)
                                {
                                    ok2 = true;
                                    if (ok1)
                                    {
                                        break;
                                    }
                                }
                            }
                        }

                        if (ok1 && ok2)
                        {
                        }
                        else
                        {
                            f = false;
                            break;
                        }
                    }
                }
                if (f)
                {
                    time = Math.Max(time, count);
                }
            }

            Console.WriteLine("Case #{0}: {1}", Case, time);
            writer.WriteLine("Case #{0}: {1}", Case, time);
        }
    }
}