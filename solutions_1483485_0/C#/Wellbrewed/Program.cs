using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace SpeakingInToungues
{
    class Program
    {
        public static Dictionary<char, char> map = new Dictionary<char, char>();

        public static void CreateMap()
        {
            map['a'] = 'y';
            map['b'] = 'h';
            map['c'] = 'e';
            map['d'] = 's';
            map['e'] = 'o';
            map['f'] = 'c';
            map['g'] = 'v';
            map['h'] = 'x';
            map['i'] = 'd';
            map['j'] = 'u';
            map['k'] = 'i';
            map['l'] = 'g';
            map['m'] = 'l';
            map['n'] = 'b';
            map['o'] = 'k';
            map['p'] = 'r';
            map['q'] = 'z';
            map['r'] = 't';
            map['s'] = 'n';
            map['t'] = 'w';
            map['u'] = 'j';
            map['v'] = 'p';
            map['w'] = 'f';
            map['x'] = 'm';
            map['y'] = 'a';
            map['z'] = 'q';
            map[' '] = ' ';
        }

        static void Main(string[] args)
        {
            CreateMap();

            var testcount = map.Values.Distinct().Count();

            using (var sr = new StreamReader("input.txt"))
            using (var sw = new StreamWriter("output.txt"))
            {
                var T = int.Parse(sr.ReadLine());
                for (int i = 1; i <= T; i++)
                {
                    var result = string.Empty;

                    var input = sr.ReadLine();
                    var sb = new StringBuilder();
                    foreach (var ch in input)
                        sb.Append(map[ch]);

                    result = sb.ToString();

                    sw.WriteLine("Case #{0}: {1}", i, result);
                }
            }
        }
    }
}
