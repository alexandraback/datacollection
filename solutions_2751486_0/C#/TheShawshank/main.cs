using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.IO;


public class Islands
{
    public static int beachLength( string str, int n)
    {
        int count=0;
        for (int i = 0; i < str.Length; i++)
        {
            for (int j = 0; j + i <= str.Length; j++)
            {
                if (isCool(str.Substring(i, j), n))
                    count++;
            }
        }
        return count;
    }

    public static bool isCool(string str, int n)
    {
        bool ans= false;
        string[] values = str.Split('a','e','i','o','u');
        for (int i = 0; i < values.Length; i++)
        {
            if (values[i].Length >= n)
                return true;
        }
        return ans;
    }
    
    public static void Main()
    {
        int t = int.Parse(Console.ReadLine());
        string str;
        int n;
        string[] values;
        for (int i = 0; i < t; i++)
        {
            values = Console.ReadLine().Split(' ');
            str = values[0];
            n = int.Parse(values[1]);
            //fun(Islands.beachLength(x, y));
            Console.WriteLine("Case #{0}: {1}",i+1,Islands.beachLength(str,n));
        } 
        Console.ReadLine();
    }
}