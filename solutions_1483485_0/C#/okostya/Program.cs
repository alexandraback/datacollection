using System;
using System.Collections;
using System.IO;

namespace Speaking_in_Tongues
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string filename = @"A-small-attempt0.in.txt";

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            Init();

            using (StreamReader reader = new StreamReader(filename))
            {
                using (StreamWriter writer = new StreamWriter(filename.Replace(".in.", ".out."), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static void Init()
        {
            int[] k = new int[('z' - 'a') + 1];
            for (int i = 0; i < ss2.Length; i++)
            {
                string s = ss2[i];
                for (int j = 0; j < s.Length; j++)
                {
                    char c = s[j];
                    if (c != ' ')
                    {
                        k[c - 'a']++;
                        h[c] = ss1[i][j];
                    }
                }
            }
            for (char c = 'a'; c <= 'z'; c++)
            {
                Console.WriteLine(c + "->" + h[c]);
            }
            h['q'] = 'z';
            h['z'] = 'q';
            h[' '] = ' ';
        }

        private static Hashtable h = new Hashtable();

        private static string[] ss2 =
            new string[]
                {
                    "ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                    "de kr kd eoya kw aej tysr re ujdr lkgc jv"
                };

        private static string[] ss1 =
            new string[]
                {
                    "our language is impossible to understand", "there are twenty six factorial possibilities",
                    "so it is okay if you want to just give up"
                };

        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            string s = reader.ReadLine();

            char[] cc = new char[s.Length];
            for (int i = 0; i < s.Length; i++)
                cc[i] = (char) h[s[i]];

            Console.WriteLine("Case #{0}: {1}", C, new string(cc));
            writer.WriteLine("Case #{0}: {1}", C, new string(cc));
        }
    }
}