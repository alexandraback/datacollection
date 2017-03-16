using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

namespace Marius.CodeJam
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            var foreign = new[] { "ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv", "zq" };
            var english = new[] { "our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up", "qz" };

            var map = new char[256];
            var el = new char[256];
            for (int i = 0; i < foreign.Length; i++)
            {
                for (int k = 0; k < foreign[i].Length; k++)
                {
                    var c = foreign[i][k];
                    var e = english[i][k];

                    if (map[c] == 0)
                        map[c] = e;
                    else if (map[c] != e)
                        Debugger.Break();
                }
            }

            Console.SetOut(new StreamWriter("a.out"));

            var lines = int.Parse(Console.ReadLine());

            for (int i = 0; i < lines; i++)
            {
                var current = Console.ReadLine();
                var sb = new StringBuilder();

                foreach (var item in current)
                {
                    if (item >= 'a' && item <= 'z')
                        sb.Append(map[item]);
                    else
                        sb.Append(item);
                }

                Console.WriteLine("Case #{0}: {1}", i+1, sb.ToString());
            }

            Console.Out.Flush();
        }
    }
}
