using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Net.Configuration;

namespace ConsoleApplication1
{
    public class Program
    {
        private static Queue<Queue<string>> chunks = new Queue<Queue<string>>();
        private static void ReadChunks(TextReader tr) { string l; while ((l = tr.ReadLine()) != null) chunks.Enqueue(new Queue<string>(l.Split(' '))); }
        private static string rc() { var q = chunks.Peek(); if (q.Count == 1) chunks.Dequeue(); return q.Dequeue(); }
        private static int ri() { return int.Parse(rc()); }
        private static double rd() { return double.Parse(rc(), CultureInfo.InvariantCulture); }
        private static string rl() { return string.Join(" ", chunks.Dequeue()); }
        private static void swap<T>(ref T a, ref T b) { var x = a; a = b; b = x; }

        public static void Main()
        {
            using (var sr = new StreamReader("C-large.in"))
            using (var sw = new StreamWriter("out.txt"))
            {
                ReadChunks(sr);

                var t = ri();

                for (var ti = 1; ti <= t; ++ti)
                {
                    sw.WriteLine("Case #{0}:", ti);

                    int R = ri(), C = ri(), M = ri();
                    int total = R*C;
                    int blank = total - M;

                    if (R == 1 || C == 1)
                    {

                        var oneLineBoard = new char[Math.Max(R,C)];
                        oneLineBoard[0] = 'c';
                        for (int i = 1; i < blank; ++i)
                            oneLineBoard[i] = '.';

                        for (int i = blank; i < total; ++i)
                            oneLineBoard[i] = '*';

                        if (C > R)
                            sw.WriteLine(new string(oneLineBoard));
                        else foreach(var cell in oneLineBoard)
                            sw.WriteLine(cell);

                        continue;
                    }

                    if (R == 2 || C == 2)
                    {
                        if (blank > 1 && (blank%2 != 0 || blank == 2))
                        {
                            sw.WriteLine("Impossible");
                            continue;
                        }
                    }
                    else
                    {
                        if (new[] {2, 3, 5, 7}.Contains(blank))
                        {
                            sw.WriteLine("Impossible");
                            continue;
                        }
                    }

                    var board = new char[C, R];
                    for (int iC = 0; iC < C; iC++)
                        for (int iR = 0; iR < R; iR++)
                            board[iC, iR] = '*';

                    board[0, 0] = 'c';

                    if (blank > 1)
                    {
                        board[0, 1] = '.';
                        board[1, 0] = '.';
                        board[1, 1] = '.';

                        blank -= 4;

                        for (int i = 2; i < Math.Max(C, R); ++i)
                        {
                            if (blank < 2)
                                break;

                            if (i < C)
                            {
                                board[i, 0] = board[i, 1] = '.';
                                blank -= 2;
                            }

                            if (blank < 2)
                                break;

                            if (i < R)
                            {
                                board[0, i] = board[1, i] = '.';
                                blank -= 2;
                            }
                        }

                        for (int iC = 2; iC < C; iC++)
                            for (int iR = 2; iR < R && blank > 0; iR++, --blank)
                                board[iC, iR] = '.';
                    }

                    for (int iR = 0; iR < R; iR++)
                    {
                        sw.WriteLine(new string(Enumerable.Range(0, C).Select(iC => board[iC, iR]).ToArray()));
                    }


                }

            }
        }
    }
}