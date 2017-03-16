using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace CodeJamQ1
{
    class Problem1
    {
        static void Main(string[] args)
        {
            StreamReader fin = new StreamReader("p1.in");
            StreamWriter fout = new StreamWriter("p1.out");

            int t = int.Parse(fin.ReadLine());

            Dictionary<char, char> mappings = new Dictionary<char, char>();
            mappings.Add(' ', ' ');

            mappings.Add('y', 'a');
            mappings.Add('n', 'b');
            mappings.Add('f', 'c');
            mappings.Add('i', 'd');
            mappings.Add('c', 'e');
            mappings.Add('w', 'f');
            mappings.Add('l', 'g');
            mappings.Add('b', 'h');
            mappings.Add('k', 'i');
            mappings.Add('u', 'j');
            mappings.Add('o', 'k');

            mappings.Add('m', 'l');
            mappings.Add('x', 'm');
            mappings.Add('s', 'n');
            mappings.Add('e', 'o');
            mappings.Add('v', 'p');
            mappings.Add('z', 'q');
            mappings.Add('p', 'r');

            mappings.Add('d', 's');
            mappings.Add('r', 't');
            mappings.Add('j', 'u');
            mappings.Add('g', 'v');
            mappings.Add('t', 'w');
            mappings.Add('h', 'x');
            mappings.Add('a', 'y');
            mappings.Add('q', 'z');

            for (int tn = 0; tn < t; tn++)
            {
                string inp = fin.ReadLine();
                StringBuilder sb = new StringBuilder();

                foreach (char c in inp)
                    sb.Append(mappings[c]);

                fout.WriteLine("Case #{0}: {1}", tn + 1, sb.ToString());
            }

            fin.Close();
            fout.Close();
        }
    }
}
