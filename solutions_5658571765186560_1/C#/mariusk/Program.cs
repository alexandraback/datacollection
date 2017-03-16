using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Marius.CodeJam
{
    public class Program
    {
        public static void Main(string[] args)
        {
            using (var input = new StreamReader(@"..\..\input.txt"))
            using (var output = new StreamWriter(@"..\..\output.txt"))
            {
                //var rem = 5;
                //var board = new byte[6][];
                //for (int i = 0; i < board.Length; i++)
                //{
                //    board[i] = new byte[6];
                //}

                //var seen = new HashSet<long>();
                //board[0][0] = 1;
                //RecurseGen(output, seen, board, rem);
                //return;

                var caseCount = int.Parse(input.ReadLine());
                for (var currentCase = 1; currentCase <= caseCount; currentCase++)
                {
                    var result = "RICHARD";
                    var parts = input.ReadLine().Split().Select(s => int.Parse(s)).ToArray();

                    var X = parts[0];
                    var R = parts[1];
                    var C = parts[2];

                    if (R > C)
                    {
                        R = parts[2];
                        C = parts[1];
                    }

                    if (X == 1)
                    {
                        result = "GABRIEL";
                    }
                    else if ((R * C) % X == 0)
                    {
                        // Manually checked for possible minimum guaranteed boards for each X-ominoe (6 was partial check for 4 * 6)
                        // >= 7, can have gaps thus ignored
                        switch (X)
                        {
                            case 2:
                                result = "GABRIEL";
                                break;
                            case 3:
                                if (R > 1 && C > 1)
                                    result = "GABRIEL";
                                break;
                            case 4:
                                if (R > 2 && C > 2)
                                    result = "GABRIEL";
                                break;
                            case 5:
                            case 6:
                                if (R > 3 && C > 3)
                                    result = "GABRIEL";
                                break;
                        }
                    }

                    output.WriteLine("Case #{0}: {1}", currentCase, result);
                }
            }
        }

        //private static int iccc = 0;
        //private static void RecurseGen(StreamWriter output, HashSet<long> seen, byte[][] set, int rem)
        //{
        //    if (rem == 0)
        //    {
        //        var anySeen = false;
        //        for (var i = 0; i < 2; i++)
        //        {
        //            for (var m = 0; m < 2; m++)
        //            {
        //                var id = GetFId(set, i - 1, m - 1);
        //                anySeen = anySeen || !seen.Add(id);
        //            }
        //        }
        //        for (var i = 0; i < 2; i++)
        //        {
        //            for (var m = 0; m < 2; m++)
        //            {
        //                var id = GetRId(set, i - 1, m - 1);
        //                anySeen = anySeen || !seen.Add(id);
        //            }
        //        }
        //        if (anySeen)
        //            return;

        //        for (int i = 0; i < set.Length; i++)
        //        {
        //            var line = string.Join("", set[i].Select(s => s == 1 ? "#" : " "));
        //            if (string.IsNullOrWhiteSpace(line))
        //                break;

        //            output.WriteLine(line);
        //        }
        //        output.WriteLine();

        //        Console.WriteLine(++iccc);
        //    }
        //    else
        //    {
        //        for (int i = 0; i < set.Length; i++)
        //        {
        //            for (int m = 0; m < set[i].Length; m++)
        //            {
        //                if (set[i][m] == 0)
        //                {
        //                    if (i > 0 && set[i - 1][m] == 1)
        //                    {
        //                        set[i][m] = 1;
        //                        RecurseGen(output, seen, set, rem - 1);
        //                        set[i][m] = 0;
        //                    }

        //                    if ((i + 1) < set.Length && set[i + 1][m] == 1)
        //                    {
        //                        set[i][m] = 1;
        //                        RecurseGen(output, seen, set, rem - 1);
        //                        set[i][m] = 0;
        //                    }

        //                    if (m > 0 && set[i][m - 1] == 1)
        //                    {
        //                        set[i][m] = 1;
        //                        RecurseGen(output, seen, set, rem - 1);
        //                        set[i][m] = 0;
        //                    }

        //                    if ((m + 1) < set[i].Length && set[i][m + 1] == 1)
        //                    {
        //                        set[i][m] = 1;
        //                        RecurseGen(output, seen, set, rem - 1);
        //                        set[i][m] = 0;
        //                    }
        //                }
        //            }
        //        }
        //    }
        //}

        //private static long GetFId(byte[][] set, int idir, int mdir)
        //{
        //    var id = 0L;
        //    var rows = (IEnumerable<byte[]>)set;
        //    if (idir < 0)
        //        rows = rows.Reverse();

        //    foreach (var iitem in rows)
        //    {
        //        var cols = (IEnumerable<byte>)iitem;
        //        if (mdir < 0)
        //            cols = cols.Reverse();
        //        foreach (var mitem in cols)
        //        {
        //            if (mitem == 1)
        //                id = id | 1L;

        //            id = id << 1;
        //        }
        //    }

        //    return id;
        //}

        //private static long GetRId(byte[][] set, int idir, int mdir)
        //{
        //    var id = 0L;
        //    var m = 0;
        //    while (true)
        //    {
        //        for (int i = 0; i < set.Length; i++)
        //        {
        //            if (set[i].Length <= m)
        //                return id;

        //            if (idir < 0)
        //            {
        //                if (mdir < 0)
        //                {
        //                    if (set[set.Length - i - 1][set[i].Length - m - 1] == 1)
        //                        id = id | 1L;
        //                }
        //                else
        //                {
        //                    if (set[set.Length - i - 1][m] == 1)
        //                        id = id | 1L;
        //                }
        //            }
        //            else
        //            {
        //                if (mdir < 0)
        //                {
        //                    if (set[i][set[i].Length - m - 1] == 1)
        //                        id = id | 1L;
        //                }
        //                else
        //                {
        //                    if (set[i][m] == 1)
        //                        id = id | 1L;
        //                }
        //            }

        //            id = id << 1;
        //        }
        //        m++;
        //    }
        //}
    }
}
