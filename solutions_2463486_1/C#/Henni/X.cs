using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Reflection;

public class X 
{
    public int Case { get; set; }
        // Get Programm type (A,B,C,D,...)
    static public Type XType()
    {
        Type t = (from x in Assembly.GetEntryAssembly().GetTypes() where (x.BaseType.Name == "X") select x).FirstOrDefault();
        return t;
    }
    static public X XNew(int i)
    {
        Type t = XType();
        X x= (X)Activator.CreateInstance(t, new object[]{});
        x.Case = i;
        return x;
    }

    static public void Main(string[] args)
    {
        // Read Count of Test Cases
        ReadLine();
        int N = ReadIntLine();

          // for each Test Case : Create an Instance of Program Type and solve
        for (int i = 1; i <= N; i++) 
            if (XNew(i).solve())
                break;
    }

    public void trace(int i)
    {
        if (Case == i)
           return; // tu nix TRACE ;
    }
    public virtual bool solve() { return false; }

#region Write

    public void WriteCaseLine(string f, params object[] o)
    {
        WriteCase();
        WriteLine(f, o);
    }
    
    public void WriteCase()
    {
        Console.Write("Case #{0}: ",Case);
    }

    public void Write(string f, params object[] o)
    {
        Console.Write(f, o);
    }

    public void WriteLine(string f, params object[] o)
    {
        Console.WriteLine(f, o);
    }
#endregion

#region Read
		
    static public string buffer = "";
    static public string Buffer { get {return buffer;} set {return;} }

    static public string ReadLine()
    {
        buffer= Console.ReadLine();
        return buffer;
    }

    static public string ReadString()
    {
        string[] s = buffer.Split(new Char[] { ' ' }, 2);
        if (s.Length == 1)
            buffer = "";
        else
            buffer = s[1];
        return s[0];
    }
    static public string ReadStringLine()
    {
        var s = ReadString();
        ReadLine();
        return s;
    }

    static public int ReadInt()
    {
        return Int32.Parse(ReadString());
    }
    static public int ReadIntLine()
    {
        var s = ReadInt();
        ReadLine();
        return s;
    }
    static public Int64 ReadLong()
    {
        return Int64.Parse(ReadString());
    }
    static public Int64 ReadLongLine()
    {
        var s = ReadLong();
        ReadLine();
        return s;
    }
    static public double ReadDouble()
    {
        return Double.Parse(ReadString());
    }
    static public double ReadDoubleLine()
    {
        var s = ReadDouble();
        ReadLine();
        return s;
    }
    static public string[] ReadStringArray()
    {
        string[] s = buffer.Split();
        return s;
    }
    static public string[] ReadStringArrayLine()
    {
        var s = ReadStringArray();
        ReadLine();
        return s;
    }
    static public int[] ReadIntArray()
    {
        int[] ia;
        string[] s = ReadStringArray();
        ia = new int[s.Length];
        for (int i = 0; i < ia.Length; i++)
        {
            ia[i] = Int32.Parse(s[i]);
        }
        return ia;
    }
    static public int[] ReadIntArrayLine()
    {
        var s = ReadIntArray();
        ReadLine();
        return s;
    }
    static public long[] ReadLongArray()
    {
        long[] ia;
        string[] s = ReadStringArray();
        ia = new long[s.Length];
        for (int i = 0; i < ia.Length; i++)
        {
            ia[i] = long.Parse(s[i]);
        }
        return ia;
    }
    static public long[] ReadLongArrayLine()
    {
        var s = ReadLongArray();
        ReadLine();
        return s;
    }
    static public double[] ReadDoubleArray()
    {
        double[] ia;
        string[] s = ReadStringArray();
        ia = new double[s.Length];
        for (int i = 0; i < ia.Length; i++)
        {
            ia[i] = Double.Parse(s[i]);
        }
        return ia;
    }
    static public double[] ReadDoubleArrayLine()
    {
        var s = ReadDoubleArray();
        ReadLine();
        return s;
    }
    static public double R9(double x)
    {
        return Math.Round(x, 9);
    }
    static public string FormatDouble(double d)
    {
        return String.Format("{0:0.0000000}", d);
    }
	#endregion    
    
}

public static class Extensions
{
    public static int Max(this int l, int i)
    {
        if (l > i) return l; else return i;
    }
    public static int Max(this int l, int i, params int[] a)
    {
        l = l.Max(i);
        l = l.Max(a.Max());
        return l;
    }
    public static int Min(this int l, int i)
    {
        if (l < i) return l; else return i;
    }
    public static int Min(this int l, int i, params int[] a)
    {
        l = l.Min(i);
        l = l.Min(a.Min());
        return l;
    }
    public static string Format(this string f, params object[] o)
    {
        return String.Format(f, o);
    }
    public static void For<T>(this IEnumerable<T> list, Action<T> act)
    {
        foreach (T x in list)
            act(x);
    }
    public static void For<T>(this IEnumerable<T> list, Action<T,int> act)
    {
        for (int i = 0; i < list.Count(); i++)
        {
            act(list.ElementAt(i),i);
        }
    }
    public static void For(this string s, Action<char> act)
    {
        foreach (char x in s)
            act(x);
    }
    public static void For(this string s, Action<char,int> act)
    {
        for (int i = 0; i < s.Length; i++)
        {
            act(s[i],i);
        }
    }
    public static void For(this int l, Action<int> act)
    {
        for (int i = 0; i < l; i++)
        {
            act(i);
        }
    } 
    public static string[] Split(this string s, string separator)
    {
        return s.Split(separator.ToCharArray());
    }
    public static string[] Split(this string s, string separator, StringSplitOptions opt)
    {
        return s.Split(separator.ToCharArray(),opt);
    }
    public static string Left(this string f, int l)
    {
        if (l < 0) return f.Substring(0,f.Length+l);
        return f.Substring(0,l);
    }
    public static string Right(this string f, int l)
    {
        if (l < 0) return f.Substring(-l);
        return f.Substring(f.Length-l);
    }
    public static char Left(this string f)
    {
        return f.Left(1)[0];
    }
    public static char Right(this string f)
    {
        return f.Right(1)[0];
    }

}