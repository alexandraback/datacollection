using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Speaking_in_tongues
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<char, char> mapping = new Dictionary<char, char>();

            mapping[' '] = ' ';
            mapping['a'] = 'y';
            mapping['b'] = 'h';
            mapping['c'] = 'e';
            mapping['d'] = 's';
            mapping['e'] = 'o';
            mapping['f'] = 'c';
            mapping['g'] = 'v';
            mapping['h'] = 'x';
            mapping['i'] = 'd';
            mapping['j'] = 'u';
            mapping['k'] = 'i';
            mapping['l'] = 'g';
            mapping['m'] = 'l';
            mapping['n'] = 'b';
            mapping['o'] = 'k';
            mapping['p'] = 'r';
            mapping['q'] = 'z';
            mapping['r'] = 't';
            mapping['s'] = 'n';
            mapping['t'] = 'w';
            mapping['u'] = 'j';
            mapping['v'] = 'p';
            mapping['w'] = 'f';
            mapping['x'] = 'm';
            mapping['y'] = 'a';
            mapping['z'] = 'q';



            string filename = args[0];
            StreamReader reader = new StreamReader(filename);
            int nbCase = int.Parse(reader.ReadLine());
            for (int i = 0; i < nbCase; i++)
            {
                string line = reader.ReadLine();
                string res = "";
                foreach (var item in line)
                {
                    res += mapping[item];
                }
                Console.WriteLine("Case #{0}: {1}", i + 1, res);
            }
            //Console.ReadLine();
        }



    }
}
