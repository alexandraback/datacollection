using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam2012.Qualification
{
    class ProblemA
    {
        public static string Solve(string[] input)
        {
            Dictionary<char, char> cipher = new Dictionary<char, char>();
            cipher.Add('a', 'y');
            cipher.Add('b', 'h');
            cipher.Add('c', 'e');
            cipher.Add('d', 's');
            cipher.Add('e', 'o');
            cipher.Add('f', 'c');
            cipher.Add('g', 'v');
            cipher.Add('h', 'x');
            cipher.Add('i', 'd');
            cipher.Add('j', 'u');
            cipher.Add('k', 'i');
            cipher.Add('l', 'g');
            cipher.Add('m', 'l');
            cipher.Add('n', 'b');
            cipher.Add('o', 'k');
            cipher.Add('p', 'r');
            cipher.Add('q', 'z');
            cipher.Add('r', 't');
            cipher.Add('s', 'n');
            cipher.Add('t', 'w');
            cipher.Add('u', 'j');
            cipher.Add('v', 'p');
            cipher.Add('w', 'f');
            cipher.Add('x', 'm');
            cipher.Add('y', 'a');
            cipher.Add('z', 'q');

            StringBuilder sb = new StringBuilder();
            for (int i = 1; i < input.Length; i++)
            {
                sb.Append("Case #");
                sb.Append(i);
                sb.Append(": ");
                foreach (char x in input[i])
                    sb.Append(cipher.ContainsKey(x) ? cipher[x] : x);
                sb.Append(System.Environment.NewLine);
            }

            return sb.ToString();
        }
    }
}
