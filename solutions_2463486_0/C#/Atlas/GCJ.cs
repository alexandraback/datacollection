using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Data;
using System.Numerics;

class GCJ
{
    protected StreamReader sr;
    protected StreamWriter sw;
    protected char[] splitors = { ' ', '\t' };

    public virtual void Input(int testcase)
    {
    }

    public virtual void Search(int testcase)
    {
    }

    public void Run(string fileInput, string fileOutput)
    {
        sr = new StreamReader(fileInput);
        sw = new StreamWriter(fileOutput);
        int testcase = Int32.Parse(sr.ReadLine());
        for (int i = 1; i <= testcase; i++)
        {
            Console.Write("Case #" + i + ":");
            sw.Write("Case #" + i + ":");
            Input(i);
            Search(i);
        }
        sw.Flush();
    }
}

class PC : GCJ
{
    public PC(string fileInput, string fileOutput)
    {
        base.Run(fileInput, fileOutput);
    }

    Int64 a, b;

    public override void Input(int testcase)
    {
        string[] str = sr.ReadLine().Split(splitors, StringSplitOptions.RemoveEmptyEntries);
        a = Int64.Parse(str[0]);
        b = Int64.Parse(str[1]);        
    }

    Int64 p1(Int64 x)
    {
        Int64 ret = x;
        Int64 t = x, y = 0;
        t /= 10;
        while (t > 0)
        {
            ret *= 10;
            y = y * 10 + (t % 10);
            t /= 10;
        }
        return ret + y;
    }

    Int64 p2(Int64 x)
    {
        Int64 ret = x;
        Int64 t = x, y = 0;
        while (t > 0)
        {
            ret *= 10;
            y = y * 10 + (t % 10);
            t /= 10;
        }
        return ret + y;
    }

    bool isP(Int64 x)
    {
        string str = x.ToString();
        for (int i = 0; i < str.Length; i++)
            if (str[i] != str[str.Length - 1 - i])
                return false;
        return true;
    }

    public override void Search(int testcase)
    {
        Int64 ret = 0;

        for (Int64 i = 1; i <= 10000; i++)
        {
            Int64 s1 = p1(i);
            s1 *= s1;
            Int64 s2 = p2(i);
            s2 *= s2;
            if (s1 > b)
                break;
            if (s1 >= a && s1 <= b)
                if (isP(s1))
                    ret++;
            if (s2 >= a && s2 <= b)
                if (isP(s2))
                    ret++;            
        }
        sw.WriteLine(" " + ret);
        Console.WriteLine(" " + ret);
    }
}
