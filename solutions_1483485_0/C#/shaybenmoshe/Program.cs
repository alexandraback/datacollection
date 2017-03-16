using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace SpeakinginTongues
{
    class Program
    {
        static int[] map = new int[26];
        static int[] revmap = new int[26];
        static int a = (int)'a';

        static void Main(string[] args)
        {
            TextReader tr = new StreamReader("input.txt");
            TextWriter tw = new StreamWriter("output.txt");

            Prepare();

            int T = int.Parse(tr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                string temp = ToEnglish(tr.ReadLine());
                tw.WriteLine("Case #" + i + ": " + temp);
            }

            tr.Close();
            tw.Close();
        }

        static void Prepare()
        {
            for (int i = 0; i < map.Length; i++)
            {
                map[i] = -1;
            }
            for (int i = 0; i < revmap.Length; i++)
            {
                revmap[i] = -1;
            }

            SetMap('a', 'y');
            SetMap('o', 'e');
            SetMap('z', 'q');

            GetSmarter("our language is impossible to understand", "ejp mysljylc kd kxveddknmc re jsicpdrysi");
            GetSmarter("there are twenty six factorial possibilities", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
            GetSmarter("so it is okay if you want to just give up", "de kr kd eoya kw aej tysr re ujdr lkgc jv");

            SetMap('q', 'z'); /* Found ampiricly using:
            for (int i = 0; i < map.Length; i++)
            {
                Console.WriteLine((char)(i + a) + " " + (char)(map[i] + a));
            }
            for (int i = 0; i < revmap.Length; i++)
            {
                Console.WriteLine((char)(i + a) + " " + (char)(revmap[i] + a));
            }*/
        }

        static void GetSmarter(string s1, string s2)
        {
            for (int i = 0; i < s1.Length; i++)
            {
                SetMap(s1[i], s2[i]);
            }
        }

        static void SetMap(char from, char to)
        {
            int val1 = (int)from - a, val2 = (int)to - a;
            if (val1 >= 0 && val1 < map.Length)
            {
                map[val1] = val2;
                revmap[val2] = val1;
            }
        }

        static char ToGooglerese(char c)
        {
            int val = (int)c - a;
            if (val >= 0 && val < map.Length)
            {
                return (char)(map[val] + a);
            }
            return c;
        }

        static char ToEnglish(char c)
        {
            int val = (int)c - a;
            if (val >= 0 && val < revmap.Length)
            {
                return (char)(revmap[val] + a);
            }
            return c;
        }

        static string ToGooglerese(string s)
        {
            char[] t = new char[s.Length];
            for (int i = 0; i < s.Length; i++)
            {
                t[i] = ToGooglerese(s[i]);
            }
            return new string(t);
        }

        static string ToEnglish(string s)
        {
            char[] t = new char[s.Length];
            for (int i = 0; i < s.Length; i++)
            {
                t[i] = ToEnglish(s[i]);
            }
            return new string(t);
        }
    }
}
