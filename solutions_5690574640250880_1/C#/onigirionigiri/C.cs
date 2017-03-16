using System;
using System.IO;
using System.Text;
using System.Linq;
using System.Collections;
using System.Diagnostics;
using System.Collections.Generic;

public class ClassName
{
    public static void Main()
    {
        new ClassName().Entry();
    }//Main

    //StreamReader sr = new StreamReader(@"C:\Users\onigiri\Downloads\test.txt");
    StreamReader sr = new StreamReader(@"C:\Users\onigiri\Downloads\C-large.in");
    StreamWriter sw = new StreamWriter(@"C:\Users\onigiri\Documents\Visual Studio 2012\Projects\GCJ\GCJ\C.txt");

    void Entry()
    {
        int T = intRead();
        for (int i = 0; i < T; i++)
        {
            string res = Solve();
            Write("Case #" + (i + 1) + ":" + res);
        }//for i
        sw.Close();
        sr.Close();
    }

    const char bomb = '*';
    const char empty = '.';
    const char ignite = 'c';
    int row; int col;
    private string Solve()
    {
        var tmp = intSplit(' ');
        row = tmp[0];
        col = tmp[1];
        int M = tmp[2];
        Console.WriteLine(row + " " + col + " " + M);
        if (row == 4 && col == 5 && M == 13)
        {
            Console.WriteLine();
        }//if
        for (int i = 0; i <= row; i++)
        {
            for (int j = i; j <= row; j++)
            {
                for (int k = j; k <= row; k++)
                {
                    for (int p = 0; p <= col; p++)
                    {
                        for (int q = p; q <= col; q++)
                        {
                            for (int r = q; r <= col; r++)
                            {
                                int sum = 0;
                                sum += (i - 0) * (col - 0);
                                sum += (j - i) * (col - p);
                                sum += (k - j) * (col - q);
                                sum += (row - k) * (col - r);
                                if (sum != M)
                                {
                                    continue;
                                }//if
                                var map = Make(i, j, k, row, p, q, r, col);
                                if (Check(map, row, col))
                                {
                                    return Convert(map, row, col);
                                }//if
                            }//for r
                        }//for m
                    }//for k
                }//for k
            }//for j
        }//for i
        return "\r\nImpossible";
    }

    const int dir = 8;
    int[] dx = new int[dir] { 1, 1, 1, -1, -1, -1, 0, 0 };
    int[] dy = new int[dir] { 1, 0, -1, 1, 0, -1, 1, -1 };


    private bool Check(char[,] map, int R, int C)
    {
        map[R - 1, 0] = empty;
        var que = new Queue<int[]>();
        que.Enqueue(new int[] { R - 1, 0 });
        var used = new bool[R, C];
        var put = new bool[R, C];
        put[R - 1, 0] = true;
        while (que.Count > 0)
        {
            var deq = que.Dequeue();
            int r = deq[0];
            int c = deq[1];
            if (map[r, c] == bomb)
            {
                continue;
            }//if
            used[r, c] = true;
            bool open = true;
            for (int arround = 0; arround < dir; arround++)
            {
                int nx = r + dx[arround];
                int ny = c + dy[arround];
                if (!Inside(nx, ny))
                    continue;
                if (map[nx, ny] == bomb)
                {
                    open = false;
                    break;
                }//if
            }//for arround
            if (open)
            {
                for (int arround = 0; arround < dir; arround++)
                {
                    int nx = r + dx[arround];
                    int ny = c + dy[arround];
                    if (!Inside(nx, ny) || map[nx, ny] == bomb || used[nx, ny])
                        continue;
                    if (put[nx,ny])
                    {
                        continue;
                    }//if
                    put[nx, ny] = true;
                    que.Enqueue(new int[] { nx, ny });
                }//for arround
            }//if
        }//while
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (map[i, j] == empty && !used[i, j])
                {
                    return false;
                }//if
            }//for j
        }//for i
        map[R - 1, 0] = ignite;
        return true;
    }


    public bool Inside(int x, int y)
    {
        return 0 <= x && x < row && 0 <= y && y < col;
    }//Inside

    private string Convert(char[,] map, int R, int C)
    {
        string res = "";
        for (int i = 0; i < R; i++)
        {
            res += "\r\n";
            for (int j = 0; j < C; j++)
            {
                res += map[i, j];
            }//for j
        }//for i
        return res;
    }

    private char[,] Make(int a, int b, int c, int R, int p, int q, int r, int C)
    {
        var res = new char[R, C];
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                res[i, j] = empty;
            }//for j
        }//for i
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < C; j++)
            {
                res[i, j] = bomb;
            }//for j
        }//for i
        for (int i = a; i < b; i++)
        {
            for (int j = p; j < C; j++)
            {
                res[i, j] = bomb;
            }//for j
        }//for i
        for (int i = b; i < c; i++)
        {
            for (int j = q; j < C; j++)
            {
                res[i, j] = bomb;
            }//for j
        }//for i
        for (int i = c; i < R; i++)
        {
            for (int j = r; j < C; j++)
            {
                res[i, j] = bomb;
            }//for j
        }//for i
        res[R - 1, 0] = ignite;
        return res;
    }


    void Write(string str)
    {
        Console.WriteLine(str);
        sw.WriteLine(str);
    }

    string strRead()
    {
        return sr.ReadLine();
    }

    int intRead()
    {
        return int.Parse(sr.ReadLine());
    }

    long longRead()
    {
        return long.Parse(sr.ReadLine());
    }

    double doubleRead()
    {
        return double.Parse(sr.ReadLine());
    }

    string[] strSplit(char c)
    {
        return sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries);
    }

    int[] intSplit(char c)
    {
        return Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
    }

    long[] longSplit(char r)
    {
        return Array.ConvertAll<string, long>(sr.ReadLine().Split(new char[] { r }, StringSplitOptions.RemoveEmptyEntries), long.Parse);
    }

    double[] doubleSplit(char c)
    {
        return Array.ConvertAll<string, double>(sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries), double.Parse);
    }

}//ClassName