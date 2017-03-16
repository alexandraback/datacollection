using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static Dictionary<char, char> map = new Dictionary<char, char>();

        public static string SolveA(string line)
        {
            StringBuilder res = new StringBuilder();

            foreach (char c in line)
            {
                if (c != ' ')
                {
                    if (map.ContainsKey(c))
                    {
                        res.Append(map[c].ToString());
                    }
                    else
                    {
                        res.Append("?");
                    }
                }
                else
                {
                    res.Append(' '.ToString());
                }
            }


            return res.ToString();
        }

        public static string SolveB(string line)
        {

            return "";
        }

        public static string SolveC(string line)
        {


            return "";
        }

        public static string SolveD(string line)
        {


            return "";
        }


        static void Main(string[] args)
        {
            map['a'] = 'y';
            map['o'] = 'k';
            map['z'] = 'q';
            map['e'] = 'o';
            map['j'] = 'u';
            map['p'] = 'r';
            map['m'] = 'l';
            map['y'] = 'a';
            map['s'] = 'n';
            map['l'] = 'g';
            map['c'] = 'e';
            map['k'] = 'i';
            map['d'] = 's';
            map['x'] = 'm';
            map['v'] = 'p';
            map['n'] = 'b';
            map['r'] = 't';
            map['i'] = 'd';
            map['b'] = 'h';
            map['t'] = 'w';
            map['h'] = 'x';
            map['w'] = 'f';
            map['f'] = 'c';
            map['u'] = 'j';
            map['g'] = 'v';
            map['q'] = 'z';

            using (StreamReader sr = new StreamReader("A-small-attempt1.in"))
            {
                using (StreamWriter sw = new StreamWriter("a-small1.out"))
                {
                    string ll = sr.ReadLine().Trim();

                    int cases = Int32.Parse(ll);

                    for (int kkk = 1; kkk <= cases; kkk++)
                    {
                        string line = sr.ReadLine().Trim();

                        string res = SolveA(line);

                        sw.WriteLine("Case #{0}: {1}", kkk, res);
                        Console.WriteLine("Case #{0}: {1}", kkk, res);
                    }

                }
            }

            Console.ReadLine();
        }
    }
}
