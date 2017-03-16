using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamGoogleese
{
    class Program
    {
        static char[] lookup = new[] {
            'y',
            'h',
            'e',
            's',
            'o',
            'c',
            'v',
            'x',
            'd',
            'u',
            'i',
            'g',
            'l',
            'b',
            'k',
            'r',
            'z',
            't',
            'n',
            'w',
            'j',
            'p',
            'f',
            'm',
            'a',
            'q'
        };

        static char MapChar(char c)
        {
            if (c == ' ')
            {
                return ' ';
            }

            char mapped = lookup[(int)c - (int)'a'];

            if ((int)mapped == 0)
            {
                throw new Exception("Unmapped char.");
            }

            return mapped;
        }

        static void Main(string[] args)
        {
            string numCasesString = Console.ReadLine();

            int numCases = int.Parse(numCasesString);

            for (int i = 0; i < numCases; i++)
            {
                string line = Console.ReadLine();
                string mapped = new string(line.Select(MapChar).ToArray());
                Console.WriteLine(string.Format("Case #{0}: {1}", i + 1, mapped));
            }
        }
    }
}
