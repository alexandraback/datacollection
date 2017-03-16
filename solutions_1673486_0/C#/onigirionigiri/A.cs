
using System;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;
public class MyonAAA
{
    StreamReader sr;
    StreamWriter sw;

    static void Main()
    {
        new MyonAAA().EntryAAA();
    }


    void SolveAAA()
    {
        int[] tmp = intSplit(' ');
        int A = tmp[0]; int B = tmp[1];
        double[] array = Array.ConvertAll<string, double>(sr.ReadLine().Split(' '), double.Parse);
        double res = 2 + B;
        res = Math.Min(res, GoType(A, B, array));
        double[] correct = MakeArray(array);
        for (int i = 1; i < A; i++)            
        res = Math.Min(res, GoDelete(i,A, B, array,correct));
        WriteLine(res);
    }

    private double[] MakeArray(double[] array)
    {
        double[] res = new double[array.Length];
        res[0] = 1;
        for (int i = 1; i < res.Length; i++)
        {
            res[i] = res[i - 1] * array[i-1];
        }//for i
        return res;
    }

    private double GoDelete(int delete,int A, int B, double[] array,double[] correct)
    {
        double p = correct[A - delete];
        double res = (2 * delete + (B - A + 1)) * p+ (2 * delete + (B - A + 1) + (B + 1)) * (1 - p);
        return res;
    }

    private double GoType(int A, int B, double[] array)
    {
        double p = 1;
        foreach (double d in array)
            p *= d;
        double res = (B - A + 1) * p + ((B - A + 1) + (B + 1)) * (1 - p);
        return res;
    }



    void EntryAAA()
    {
        sr = new StreamReader(@"C:\Users\user1\Downloads\A-small-attempt0.in");
        sw = new StreamWriter(@"C:\Users\user1\Downloads\WriteAAA.txt");

        int rep = intRead();
        for (int i = 0; i < rep; i++)
        {
            sw.Write("Case #{0}: ", i + 1);
            Console.Write("Case #{0}: ", i + 1);
            SolveAAA();
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