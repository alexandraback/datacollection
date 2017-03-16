using System;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;
public class MyonCCC
{
    StreamReader sr;
    StreamWriter sw;

    public static void Main()
    {
        new MyonCCC().EntryCCC();
    }


    void SolveCCC()
    {
        int[] array = intSplit(' ');
        int A = array[0]; int B = array[1];
        int res = 0;
        for (int i = A; i <= B; i++)
        {
            res += Count(i,A,B);
        }//fore i
        WriteLine(res);
    }

    private int Count(int now, int A, int B)
    {
        string str = now.ToString();
        int[] num = new int[str.Length];
        for (int i = 0; i < str.Length; i++)
            num[i] = str[i] - '0';
        Dictionary<int, object> res = new Dictionary<int, object>();
        for (int i = 0; i < num.Length; i++)
        {
            int next = Get(num,i);
            if (now < next && next <= B)
                res[next] = null;
        }//for i
        return res.Count;
    }

    private int Get(int[] num,int start)
    {
        int res = 0;
        int i = start;
        do
        {
            res *= 10;
            res += num[i];

            i++;
            if (i == num.Length) 
                i = 0;
        } while (i!=start);
        return res;
    }

    void EntryCCC()
    {
        sr = new StreamReader(@"C:\Users\user1\Downloads\C-large.in");
        sw = new StreamWriter(@"C:\Users\user1\Downloads\WriteCCC.txt");

        int rep = intRead();
        for (int i = 0; i < rep; i++)
        {
            sw.Write("Case #{0}: ", i + 1);
            Console.Write("Case #{0}: ", i + 1);
            SolveCCC();
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