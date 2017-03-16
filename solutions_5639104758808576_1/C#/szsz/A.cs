using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;



class Program
{

    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader("D:\\in.in");
        StreamWriter sw = new StreamWriter("D:\\out.out");
        sw.AutoFlush = true;
        int n = int.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }

    static public long GCD(long a, long b)
    { if (b == 0) return a; return GCD(b, a % b); }



    static string Solution(StreamReader sr)
    {
        string[] t = sr.ReadLine().Split(' ');
        int r = 0;
        int v = 0;
        int p = 0;
        foreach (char c in t[1])
        {
            int x = (int)(c - '0');
            if (r + v < p)
            {
                r += p - v - r;
            }
            v += x;
            p++;
        }
        return r.ToString();
    }
}