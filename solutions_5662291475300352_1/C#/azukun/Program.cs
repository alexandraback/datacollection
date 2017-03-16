using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

// (づ°ω°)づﾐ★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜
public class Solver
{
    public void Solve()
    {
        int nt = ReadInt();
        for(int tt = 1; tt <= nt; tt++)
        {
            int n = ReadInt();
            var a = new List<Tuple<int, int>>();
            for (; n > 0; n--)
            {
                int d = ReadInt();
                int h = ReadInt();
                int m = ReadInt();
                for (int i = 0; i < h; i++)
                    a.Add(Tuple.Create(d, m + i));
            }

            int ans = a.Count;
            for (int i = 0; i < a.Count; i++)
            {
                int x = 0;
                long t = (360 - a[i].Item1) * a[i].Item2;
                for (int j = 0; j < a.Count; j++)
                    if (i != j)
                    {
                        int l = 0, r = 20;
                        while (l < r)
                        {
                            int mid = (l + r + 1) / 2;
                            long v = (360 * mid - a[j].Item1);
                            bool ok = true;
                            if (v > t || v * a[j].Item2 < v || v * a[j].Item2 > t)
                                ok = false;
                            if (ok)
                                l = mid;
                            else
                                r = mid - 1;
                        }
                        x += Math.Abs(1 - l);
                    }
                ans = Math.Min(ans, x);
            }

            writer.WriteLine("Case #{0}: {1}", tt, ans);
        }
    }

    #region Main

    protected static TextReader reader;
    protected static TextWriter writer;

    static void Main()
    {
#if DEBUG
        reader = new StreamReader("..\\..\\input.txt");
        writer = Console.Out;
        writer = new StreamWriter("..\\..\\output.txt");
#else
        reader = new StreamReader(Console.OpenStandardInput());
        writer = new StreamWriter(Console.OpenStandardOutput());
        //reader = new StreamReader("game.in");
        //writer = new StreamWriter("game.out");
#endif
        try
        {
            new Solver().Solve();
        }
        catch (Exception ex)
        {
#if DEBUG
            Console.WriteLine(ex);
#else
            Console.WriteLine(ex);
            throw;
#endif
        }
        reader.Close();
        writer.Close();
    }

    #endregion

    #region Read / Write

    private static Queue<string> currentLineTokens = new Queue<string>();

    private static string[] ReadAndSplitLine()
    {
        return reader.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
    }

    public static string ReadToken()
    {
        while (currentLineTokens.Count == 0)
            currentLineTokens = new Queue<string>(ReadAndSplitLine());
        return currentLineTokens.Dequeue();
    }

    public static int ReadInt()
    {
        return int.Parse(ReadToken());
    }

    public static long ReadLong()
    {
        return long.Parse(ReadToken());
    }

    public static double ReadDouble()
    {
        return double.Parse(ReadToken(), CultureInfo.InvariantCulture);
    }

    public static int[] ReadIntArray()
    {
        return ReadAndSplitLine().Select(int.Parse).ToArray();
    }

    public static long[] ReadLongArray()
    {
        return ReadAndSplitLine().Select(long.Parse).ToArray();
    }

    public static double[] ReadDoubleArray()
    {
        return ReadAndSplitLine().Select(s => double.Parse(s, CultureInfo.InvariantCulture)).ToArray();
    }

    public static int[][] ReadIntMatrix(int numberOfRows)
    {
        int[][] matrix = new int[numberOfRows][];
        for (int i = 0; i < numberOfRows; i++)
            matrix[i] = ReadIntArray();
        return matrix;
    }

    public static int[][] ReadAndTransposeIntMatrix(int numberOfRows)
    {
        int[][] matrix = ReadIntMatrix(numberOfRows);
        int[][] ret = new int[matrix[0].Length][];
        for (int i = 0; i < ret.Length; i++)
        {
            ret[i] = new int[numberOfRows];
            for (int j = 0; j < numberOfRows; j++)
                ret[i][j] = matrix[j][i];
        }
        return ret;
    }

    public static string[] ReadLines(int quantity)
    {
        string[] lines = new string[quantity];
        for (int i = 0; i < quantity; i++)
            lines[i] = reader.ReadLine().Trim();
        return lines;
    }

    public static void WriteArray<T>(IEnumerable<T> array)
    {
        writer.WriteLine(string.Join(" ", array));
    }

    public static void Write<T>(params T[] array)
    {
        WriteArray(array);
    }

    public static void WriteLines<T>(IEnumerable<T> array)
    {
        foreach (var a in array)
            writer.WriteLine(a);
    }

    #endregion
}