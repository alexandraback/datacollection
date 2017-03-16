using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1BQ1
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine().Trim());

            for (int i = 0; i < t; i++)
                SolveProblem(i + 1);
        }

        private static void SolveProblem(int testNum)
        {
            string s = Console.ReadLine().Trim();
            Dictionary<char, int> chars = new Dictionary<char, int>();

            int[] counts = new int[10];
            

            foreach (char ch in s)
            {
                if(chars.ContainsKey(ch))
                    chars[ch] += 1;
                else
                    chars[ch] = 1;

                if (ch == 'Z')
                    counts[0] += 1;
                else if (ch == 'W')
                    counts[2] += 1;
                else if (ch == 'U')
                    counts[4] += 1;
                else if (ch == 'X')
                    counts[6] += 1;
                else if (ch == 'G')
                    counts[8] += 1;

            }

            if (counts[0] > 0)
            {
                chars['Z'] -= counts[0];
                chars['E'] -= counts[0];
                chars['R'] -= counts[0];
                chars['O'] -= counts[0];
            }
            if (counts[2] > 0)
            {
                chars['T'] -= counts[2];
                chars['W'] -= counts[2];
                chars['O'] -= counts[2];
            }
            if (counts[4] > 0)
            {
                chars['F'] -= counts[4];
                chars['O'] -= counts[4];
                chars['U'] -= counts[4];
                chars['R'] -= counts[4];
            }
            if (counts[6] > 0)
            {
                chars['S'] -= counts[6];
                chars['I'] -= counts[6];
                chars['X'] -= counts[6];
            }
            if (counts[8] > 0)
            {
                chars['E'] -= counts[8];
                chars['I'] -= counts[8];
                chars['G'] -= counts[8];
                chars['H'] -= counts[8];
                chars['T'] -= counts[8];
            }

            if (chars.ContainsKey('F') && chars['F'] > 0)
            {
                int count = chars['F'];
                chars['F'] -= count;
                chars['I'] -= count;
                chars['V'] -= count;
                chars['E'] -= count;
                counts[5] = count;
            }

            if (chars.ContainsKey('H') && chars['H'] > 0)
            {
                int count = chars['H'];
                chars['T'] -= count;
                chars['H'] -= count;
                chars['R'] -= count;
                chars['E'] -= count;
                chars['E'] -= count;
                counts[3] = count;
            }
            if (chars.ContainsKey('O') && chars['O'] > 0)
            {
                int count = chars['O'];
                chars['O'] -= count;
                chars['N'] -= count;
                chars['E'] -= count;
                counts[1] = count;
            }
            if (chars.ContainsKey('I') && chars['I'] > 0)
            {
                int count = chars['I'];
                chars['N'] -= count;
                chars['I'] -= count;
                chars['N'] -= count;
                chars['E'] -= count;
                counts[9] = count;
            }

            if (chars.ContainsKey('V') && chars['V'] > 0)
            {
                counts[7] = chars['V'];
            }

            StringBuilder result = new StringBuilder();
            for (int i = 0; i < 10; i++)
            {
                if (counts[i] > 0)
                {
                    string item = new string((char)('0' + i), counts[i]);
                    result.Append(item);
                }
            }

            Console.WriteLine("Case #{0}: {1}", testNum, result);
        }
    }
}
