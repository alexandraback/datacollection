using System;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;
public class MyonBBB
{
    StreamReader sr;
    StreamWriter sw;

    static void Main()
    {
        new MyonBBB().EntryBBB();
    }

    const int INF = (int)1e9;
    const string bad = "Too Bad";
    void SolveBBB()
    {
        int n = intRead();
        int[,] cost = new int[n, 2];
        for (int i = 0; i < n; i++)
        {
            int[] tmp = intSplit(' ');
            cost[i, 0] = tmp[0];
            cost[i, 1] = tmp[1];
        }//for i

        int power = 0;
        int[] used = new int[n];
        int res = 0;

        while (true)
        {
        int nextPos = -1;
        int next = -1;
            for (int i = 0; i < n; i++)
            {
                if (used[i] == 0)
                {
                    if (power >= cost[i, 1])
                    {
                        nextPos = i;
                        next = 1;
                        break;
                    }
                }
                if (used[i] == 1)
                {
                    if (power >= cost[i, 1])
                    {
                        nextPos = i;
                        next = 1;
                        break;
                    }
                }
                if (used[i] == 0)
                {
                    if (power >= cost[i, 0])
                    {
                        if (nextPos == -1 || cost[nextPos, 1] <= cost[i, 1])
                        {
                            nextPos = i;
                            next = 0;
                        }
                    }
                }
            }//for i
            if (nextPos == -1)
                break;

            res++;
            if (next == 0)
            {
                power++;
                used[nextPos] = 1;
            }
            else
            {
                power += (used[nextPos] == 0 ? 2 : 1);
                used[nextPos] = 2;
            }            
        }

        bool flg = true;
        for (int i = 0; i < n; i++)
        {
            if (used[i] < 2)
            {
                WriteLine(bad);
                flg = false;
                break;
            }
        }//for i

        if (flg)
        {
            WriteLine(res);
        }

    }


    void EntryBBB()
    {
        sr = new StreamReader(@"C:\Users\user1\Downloads\B-large.in");
        sw = new StreamWriter(@"C:\Users\user1\Downloads\WriteBBB.txt");

        int rep = intRead();
        for (int i = 0; i < rep; i++)
        {
            sw.Write("Case #{0}: ", i + 1);
            Console.Write("Case #{0}: ", i + 1);
            SolveBBB();
        }//for i

        sw.Close();
        sr.Close();
    }

    string stringRead()
    { return sr.ReadLine(); }

    int intRead()
    { return int.Parse(sr.ReadLine()); }

    long longRead()
    { return long.Parse(sr.ReadLine()); }

    string[] stringSplit(char a)
    { return sr.ReadLine().Split(a); }

    int[] intSplit(char a)
    { return Array.ConvertAll<string, int>(sr.ReadLine().Split(a), int.Parse); }

    long[] longSplit(char a)
    { return Array.ConvertAll<string, long>(sr.ReadLine().Split(a), long.Parse); }

    void WriteLine<T>(T str)
    {
        Console.WriteLine(str.ToString());
        sw.WriteLine(str.ToString());
    }

}