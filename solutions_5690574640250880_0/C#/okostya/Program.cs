using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Minesweeper_Master
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //string filename = @"../../sample.in.txt";
            string filename = @"../../C-small-attempt3.in";

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
            string[] ss = reader.ReadLine().Split(' ');

            int r = int.Parse(ss[0]);
            int c = int.Parse(ss[1]);
            int m = int.Parse(ss[2]);

            Console.WriteLine("Case #{0}:", C);
            writer.WriteLine("Case #{0}:", C);

            if (r == 1)
            {
                if (c >= m + 1)
                {
                    Write(writer, 'c');
                    int count = c - (m) - 1;
                    for (int i = 0; i < count; i++)
                    {
                        Write(writer, '.');
                    }
                    for (int i = 0; i < m; i++)
                    {
                        Write(writer, '*');
                    }
                    WriteLine(writer);
                }
                else
                {
                    Write(writer, "Impossible");
                    WriteLine(writer);
                }
            }
            else if (c == 1)
            {
                if (r >= m + 1)
                {
                    Write(writer, 'c');
                    WriteLine(writer);
                    int count = r - (m) - 1;
                    for (int i = 0; i < count; i++)
                    {
                        Write(writer, '.');
                        WriteLine(writer);
                    }
                    for (int i = 0; i < m; i++)
                    {
                        Write(writer, '*');
                        WriteLine(writer);
                    }
                }
                else
                {
                    Write(writer, "Impossible");
                    WriteLine(writer);
                }
            }
            else if (m + 1 == r*c)
            {
                Write(writer, 'c');
                for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                    {
                        if (i == 0 && j == 0)
                            continue;
                        Write(writer, '*');
                    }
                    WriteLine(writer);
                }
            }
            else
            {
                int free = r*c - m;
                if (free < 4 || free == 5 || free == 7 || ((free%2 == 1) && (Math.Min(r, c) == 2)))
                {
                    Write(writer, "Impossible");
                    WriteLine(writer);
                }
                else
                {
                    bool tr = r < c;
                    int rr = tr ? c : r;
                    int cc = tr ? r : c;

                    var p = new char[rr,cc];
                    for (int i = 0; i < rr; i++)
                    {
                        for (int j = 0; j < cc; j++)
                        {
                            p[i, j] = '*';
                        }
                    }
                    p[0, 0] = 'c';

                    if (free >= 2*cc)
                    {
                        free--;
                        for (int i = 0; i < rr; i++)
                        {
                            for (int j = 0; j < cc; j++)
                            {
                                if (i == 0 && j == 0)
                                    continue;
                                p[i, j] = '.';
                                free--;
                                if (free == 0)
                                    break;
                            }
                            if (free == 0)
                                break;


                            if (free == 1)
                            {
                                if (i%2 == 0)
                                {
                                    p[i, cc - 1] = '*';
                                    free++;
                                }
                                else
                                {
                                    p[i, cc - 1] = '*';
                                    if (i < rr - 2)
                                    {
                                        p[i - 1, cc - 1] = '*';
                                        free += 2;
                                    }
                                    else
                                    {
                                        free++;
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        var delta = (int) Math.Sqrt(free);
                        if ((delta*delta) != free)
                            delta++;
                        free--;
                        for (int i = 0; i < delta; i++)
                        {
                            for (int j = 0; j < delta; j++)
                            {
                                if (i == 0 && j == 0)
                                    continue;
                                p[i, j] = '.';
                                free--;
                                if (free == 0)
                                    break;
                            }
                            if (free == 0)
                                break;

                            if (free == 1)
                            {
                                if (i%2 == 0)
                                {
                                    p[i, delta - 1] = '*';
                                    free++;
                                }
                                else
                                {
                                    p[i, delta - 1] = '*';
                                    p[i - 1, delta - 1] = '*';
                                    free += 2;
                                }
                            }
                        }
                    }

                    if (tr)
                    {
                        for (int j = 0; j < cc; j++)
                        {
                            for (int i = 0; i < rr; i++)
                            {
                                Write(writer, p[i, j]);
                            }
                            WriteLine(writer);
                        }
                    }
                    else
                    {
                        for (int i = 0; i < rr; i++)
                        {
                            for (int j = 0; j < cc; j++)
                            {
                                Write(writer, p[i, j]);
                            }
                            WriteLine(writer);
                        }
                    }
                }
            }
        }

        private static void Write(TextWriter writer, char c)
        {
            writer.Write(c);
            Console.Write(c);
        }

        private static void Write(TextWriter writer, string c)
        {
            writer.Write(c);
            Console.Write(c);
        }

        private static void WriteLine(TextWriter writer)
        {
            writer.WriteLine();
            Console.WriteLine();
        }
    }
}