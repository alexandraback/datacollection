using System;
using System.IO;
using System.Text;
using System.Collections;
using System.Diagnostics;
using System.Collections.Generic;
using System.Numerics;

public class ClassName
{
    public static void Main()
    {
        new ClassName().Entry();
    }//Main

    StreamReader sr = new StreamReader(@"C:\Users\user1\Downloads\D-small-attempt1.in");
    StreamWriter sw = new StreamWriter(@"C:\Users\user1\Documents\Visual Studio 2012\Projects\GCJ\GCJ\D.txt");


    void Entry()
    {
        int T = intRead();
        for (int i = 0; i < T; i++)
        {
            string res = Solve();
            //sw.WriteLine("Case #1:\n");
            Write("Case #" + (i + 1) + ": " + res);
        }//for i
        sw.Close();
        sr.Close();
    }

    string richard = "RICHARD";
    string gabriel = "GABRIEL";
    private string Solve()
    {
        var tmp = intSplit(' ');
        int X = tmp[0];
        int min = Math.Min(tmp[1], tmp[2]);
        int max = Math.Max(tmp[1], tmp[2]);
        if ((min*max)%X!=0)
        {
            return richard;
        }//if
        if (min!=max&&X>=2*min+1)
        {
            return richard;
        }//if
        if (min==max&&X>=2*min)
        {
            return richard;
        }//if
        if (X>=7)
        {
            return richard;
        }//if

        return gabriel;
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