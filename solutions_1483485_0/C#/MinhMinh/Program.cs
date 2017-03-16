using System;
using System.Collections.Generic;
using System.IO;

class Program
{
    static String input = "A-small-attempt0.in";
    static String output = "a.out";

    static void Main(string[] args)
    {
        int numOfCases;
        StreamReader reader = new StreamReader(input);
        StreamWriter writter = new StreamWriter(output);
                
        Char[] maps = new Char[] {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 
                                  'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q',};

        numOfCases = int.Parse(reader.ReadLine());
        for (int index = 1; index <= numOfCases; index++)
        {
            String ans = "";
            String s = reader.ReadLine();
            for (int i = 0; i < s.Length; i++)
                if (s[i] == ' ') ans += ' ';
                else ans += maps[s[i] - 'a'];

            writter.WriteLine("Case #" + index + ": " + ans);
        }

        reader.Close();
        writter.Close();
    }
}
