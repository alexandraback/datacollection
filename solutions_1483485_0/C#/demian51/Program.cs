using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace GCJ
{
    class Program
    {
        static char[] dtable = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

        static char decrypt(char c)
        {
            if (c == ' ')
            {
                return ' ';
            }
            else
            {
                return dtable[c - 'a'];
            }
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"D:\input.txt");
            StreamWriter sw = new StreamWriter(@"D:\output.txt");

            int t;
            string s;

            t = int.Parse(sr.ReadLine());

            for (int i = 0; i < t; i++)
            {
                s = sr.ReadLine();

                sw.Write("Case #" + (i + 1) + ": ");

                for (int j = 0; j < s.Length; j++)
                {
                    sw.Write(decrypt(s[j]));
                }

                sw.WriteLine("");
            }

            sr.Close();
            sw.Close();
        }
    }
}
