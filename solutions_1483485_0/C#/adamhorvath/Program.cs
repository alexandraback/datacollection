using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Program
    {
        static Dictionary<char, char> dict = new Dictionary<char,char>();

        static void Main(string[] args)
        {
            AddTranslation("y qeez", "a zooq");
            AddTranslation("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
            AddTranslation("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
            AddTranslation("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");

            //for (char c = 'a'; c <= 'z'; c++)
            //{
            //    Console.WriteLine(c + " " + dict[c]);
            //}

            int N = int.Parse(Console.ReadLine());

            for (int i = 1; i <= N; i++)
            {
                var s = Translate(Console.ReadLine());
                Console.WriteLine("Case #" + i + ": " + s);
            }
        }

        public static string Translate(string s)
        {
            char[] c = new char[s.Length];
            for (int i = 0; i < c.Length; i++)
            {
                c[i] = dict[s[i]];
            }

            return new String(c);
        }


        public static void AddTranslation(string from, string to)
        {
            for (int i = 0; i < from.Length; i++)
            {
                char c;
                if (dict.TryGetValue(from[i], out c))
                {
                    if (c != to[i])
                        throw new Exception();
                }
                else
                {
                    dict[from[i]] = to[i];
                }
            }
        }
    }


}
