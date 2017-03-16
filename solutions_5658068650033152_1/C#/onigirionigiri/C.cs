using System;
using System.IO;
using System.Text;
using System.Linq;
using System.Collections;
using System.Diagnostics;
using System.Numerics;
using System.Collections.Generic;

public class ClassName
{
    public static void Main()
    {
        new ClassName().Entry();
    }//Main

    const string inputName = @"C-large.in";
    StreamReader sr = new StreamReader(@"C:\Users\onigiri\Downloads\" + inputName);
    StreamWriter sw = new StreamWriter(@"C:\Users\onigiri\Documents\Visual Studio 2012\Projects\GCJ\GCJ\C.txt");

    void Entry()
    {
        //C();
        int T = intRead();
        for (int i = 0; i < T; i++)
        {
            if (i == 11)
            {
                //Debugger.Break();
            }//if
            string res = Solve();
            Write("Case #" + (i + 1) + ": " + res);
        }//for i
        sw.Close();
        sr.Close();
    }


    private void C()
    {
        StreamReader sw = new StreamReader(@"C:\Users\onigiri\Documents\Visual Studio 2012\Projects\GCJ\GCJ\C1c.txt");

        StreamReader sw0 = new StreamReader(@"C:\Users\onigiri\Documents\Visual Studio 2012\Projects\GCJ\GCJ\C1opt.txt");

        for (int i = 0; i < 100; i++)
        {
            string a = sw.ReadLine();
            string b = sw0.ReadLine();
            if (a != b)
            {
                Debugger.Break();
            }//if
        }//for i
        sw.Close();
        sw0.Close();

    }

    private string Solve()
    {
        var split = intSplit(' ');
        int N = split[0];
        int M = split[1];
        int K = split[2];
        int res = K;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (i * j >= K)
                {
                    int cnt = i * j - Math.Max(0, i - 2) * Math.Max(0, j - 2);
                    res = Math.Min(res, cnt);
                    if (i >= 3 && j >= 3)
                    {
                        for (int k = 0; k <= 4; k++)
                        {
                            if (i * j - k >= K)
                            {
                                res = Math.Min(res, cnt - k);
                                int blank = Math.Max(0, i - 2) * Math.Max(0, j - 2);
                                int used = cnt - k;
                                int sum = blank + used;
                                int diff =  Math.Min((sum - K) / 2, blank - 1);
                                if (diff>=0)
                                {
                                    res = Math.Min(res, used - diff);
                                    if (res<0)
                                    {
                                        //Debugger.Break();
                                    }//if
                                }//if
                            }//if
                        }//for k
                    }//if
                }//if
            }//for j
        }//for i
        return res.ToString();
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