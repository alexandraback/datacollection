using System;
using System.Collections.Generic;
using System.Text;

namespace Speaking_in_Tongues
{
    class Program
    {
        static Dictionary<char, char> r = new Dictionary<char, char>();

        static string translate(string s)
        {
            char[] chars = s.ToCharArray();
            for (int i = 0; i < chars.Length; i++)
            {
                chars[i] = r[chars[i]];
            }
            return new string(chars);
        }

        static void Main(string[] args)
        {
            /*
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv


Output
Case #1: our language is impossible to understand
Case #2: there are twenty six factorial possibilities
Case #3: so it is okay if you want to just give up
             */
            r[' '] = ' ';
            r['a'] = 'y';
            r['b'] = 'h';
            r['c'] = 'e';
            r['d'] = 's';
            r['e'] = 'o';
            r['f'] = 'c';
            r['g'] = 'v';
            r['h'] = 'x';
            r['i'] = 'd';
            r['j'] = 'u';
            r['k'] = 'i';
            r['l'] = 'g';
            r['m'] = 'l';
            r['n'] = 'b';
            r['o'] = 'k';
            r['p'] = 'r';
            r['q'] = 'z';
            r['r'] = 't';
            r['s'] = 'n';
            r['t'] = 'w';
            r['u'] = 'j';
            r['v'] = 'p';
            r['w'] = 'f';
            r['x'] = 'm';
            r['y'] = 'a';
            r['z'] = 'q';
            int T = Int32.Parse(Console.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                Console.WriteLine("Case #{0}: {1}", i, translate(Console.ReadLine()));
            }
        }
    }
}
