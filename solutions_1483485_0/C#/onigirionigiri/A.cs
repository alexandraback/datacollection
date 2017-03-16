using System;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;
public class MyonAAA
{
    StreamReader sr;
    StreamWriter sw;

    public static void Main()
    {
        new MyonAAA().EntryAAA();
    }


    void SolveAAA()
    {
        //WriteAAA();
        Dictionary<char, char> dict = MakeDict();
        //Check(dict);
        //Dictionary<char, char> mapping = Reverse(dict);
        StringBuilder res = new StringBuilder( );
        string given = stringRead();
        foreach (char c  in given)
        {
            if (c == ' ')
                res.Append(' ');
            else
                res.Append(dict[c]);
        }//foreach c 
        WriteLine(res);
    }

    private Dictionary<char, char> Reverse(Dictionary<char, char> dict)
    {
        Dictionary<char, char> res = new Dictionary<char, char>();
        foreach (var item in dict)
        {
            res[item.Value] = item.Key;
        }//foreach item
        return res;
    }

    private static void Check(Dictionary<char, char> dict)
    {
        List<char> c = new List<char>();
        foreach (var v in dict.Values)
            c.Add(v);
        c.Sort();
        int cnt = 0;
        foreach (var v in c)
        {
            Console.WriteLine(v+" "+(char)(cnt++ +'a'));
        }
    }

    private Dictionary<char, char> MakeDict()
    {
        Dictionary<char, char> dict = new Dictionary<char, char>();

        dict['a'] = 'y';
        dict['b'] = 'h';
        dict['c'] = 'e';
        dict['d'] = 's';
        dict['e'] = 'o';
        dict['f'] = 'c';
        dict['g'] = 'v';
        dict['h'] = 'x';
        dict['i'] = 'd';
        dict['j'] = 'u';
        dict['k'] = 'i';
        dict['l'] = 'g';
        dict['m'] = 'l';
        dict['n'] = 'b';
        dict['o'] = 'k';
        dict['p'] = 'r';
        dict['q'] = 'z';
        dict['r'] = 't';
        dict['s'] = 'n';
        dict['t'] = 'w';
        dict['u'] = 'j';
        dict['v'] = 'p';
        dict['w'] = 'f';
        dict['x'] = 'm';
        dict['y'] = 'a';
        dict['z'] = 'q';

        return dict;
    }

    const int rep = 3;
    const int alph = 26;
    private void WriteAAA()
    {
        string[] given = new string[rep];
        for (int i = 0; i < rep; i++)
            given[i] = Console.ReadLine();
        string[] ans = new string[rep];
        for (int i = 0; i < rep; i++)
            ans[i] = Console.ReadLine();
        char[] array = new char[alph];
        for (int i = 0; i < alph; i++)
            array[i] = ' ';
        for (int i = 0; i < rep; i++)
            for (int j = 0; j < given[i].Length; j++)
            {
                if (given[i][j] == ' ')
                    continue;
                array[given[i][j] - 'a'] = ans[i][j];
            }//for j
        for (int i = 0; i < alph; i++)
            WriteLine("dict['"+(char)(i+'a')+"'] = '"+array[i]+"';");
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