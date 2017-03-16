using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016_1B_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var s = Console.ReadLine();
                var counts = new int[26];
                foreach (var c in s)
                    counts[c - 'A']++;
                var digits = new int[10];
                digits[0] = counts['Z' - 'A'];
                counts['E' - 'A'] -= digits[0];
                counts['R' - 'A'] -= digits[0];
                counts['O' - 'A'] -= digits[0];
                digits[2] = counts['W' - 'A'];
                counts['T' - 'A'] -= digits[2];
                counts['O' - 'A'] -= digits[2];
                digits[6] = counts['X' - 'A'];
                counts['S' - 'A'] -= digits[6];
                counts['I' - 'A'] -= digits[6];
                digits[8] = counts['G' - 'A'];
                counts['E' - 'A'] -= digits[8];
                counts['I' - 'A'] -= digits[8];
                counts['H' - 'A'] -= digits[8];
                counts['T' - 'A'] -= digits[8];
                digits[3] = counts['H' - 'A'];
                counts['T' - 'A'] -= digits[3];
                counts['R' - 'A'] -= digits[3];
                counts['E' - 'A'] -= digits[3];
                counts['E' - 'A'] -= digits[3];
                digits[4] = counts['U' - 'A'];
                counts['F' - 'A'] -= digits[4];
                counts['O' - 'A'] -= digits[4];
                counts['R' - 'A'] -= digits[4];
                digits[5] = counts['F' - 'A'];
                counts['I' - 'A'] -= digits[5];
                counts['V' - 'A'] -= digits[5];
                counts['E' - 'A'] -= digits[5];
                digits[7] = counts['V' - 'A'];
                counts['S' - 'A'] -= digits[7];
                counts['E' - 'A'] -= digits[7];
                counts['E' - 'A'] -= digits[7];
                counts['N' - 'A'] -= digits[7];
                digits[1] = counts['O' - 'A'];
                digits[9] = counts['I' - 'A'];
                var res = "";
                for (int i = 0; i < 10; i++)
                {
                    res += new string((char)((int)'0' + i), digits[i]);
                }
                Console.WriteLine("Case #{0}: {1}", testN, res);
            }
        }
    }
}
