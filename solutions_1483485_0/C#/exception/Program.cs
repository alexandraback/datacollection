using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader tr = new StreamReader("C:\\Users\\Avinash\\Desktop\\input.txt");
            TextWriter tw = new StreamWriter("C:\\Users\\Avinash\\Desktop\\output.txt");

            int T;
            T = int.Parse(tr.ReadLine());
            //int start = Environment.TickCount;
            string input = null;
            string mapstring = "yhesocvxduiglbkrztnwjpfmaq";
            char[] mapArr = new char[26];
            for (int i = 0; i < 26; i++)
                mapArr[i] = mapstring[i];
            for (int caseno = 1; caseno <= T; caseno++)
            {
                input = tr.ReadLine();
                string final = null;
                for (int i = 0; i < input.Length; i++)
                {
                    if (input[i] == ' ')
                    {
                        final += input[i];
                        continue;
                    }
                    final += mapArr[input[i] - 'a'];
                }
                tw.WriteLine("Case #{0}: {1}", caseno, final);
            }
            //int end = Environment.TickCount;
            //int time = end - start;
            tr.Close();
            tw.Close();
        }
    }
}