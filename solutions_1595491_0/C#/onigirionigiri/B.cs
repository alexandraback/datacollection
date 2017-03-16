using System;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

public class MyonBBB
{
    StreamReader sr;
    StreamWriter sw;

    public static void Main()
    {
        new MyonBBB().EntryBBB();
    }


    void SolveBBB()
    {
        int[] given = intSplit(' ');
        int N = given[0]; int S = given[1]; int p = given[2];
        int[] array = new int[N];
        for (int i = 3; i < given.Length; i++)
            array[i - 3] = given[i];
        Array.Sort(array); Array.Reverse(array);

        int res = 0;
        for (int i = 0; i < N; i++)
        {
            if (OK(array[i], ref S, p))
                res++;
        }//for i
        WriteLine(res);
    }

    private bool OK(int point, ref int S, int want)
    {
        if (point >= want+2 * (Math.Max(0,want-1)))
            return true;
        if (point >= want + 2 * (Math.Max(0, want - 2)))
        {
            if (S <= 0)
                return false;
            S--;
            return true;
        }
        return false;
    }

    void EntryBBB()
    {
        sr = new StreamReader(@"C:\Users\user1\Downloads\B-small-attempt0.in");
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