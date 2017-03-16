using System;
using System.Collections.Generic;
using System.Text;

namespace Problem_A
{
    class Program
    {
        static void Main(string[] args)
        {
            new Program().Run();
        }

        private void Run()
        {
            int cases = int.Parse(Console.ReadLine());
            for (int c = 1; c <= cases; c++)
            {
                string line = Console.ReadLine();

                string result = ProcessCase(line);

                Console.WriteLine(String.Format("Case #{0}: {1}", c, result));
            }
        }

        string Natural =    "abcdefghijklmnopqrstuvwxyz";
        string Googlerese = "ynficwlbkuomxsevzpdrjgthaq";
        
        // our language is impossible to understand
        // ejp mysljylc kd kxveddknmc re jsicpdrysi

        // there are twenty six factorial possibilities
        // rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd

        // so it is okay if you want to just give up
        // de kr kd eoya kw aej tysr re ujdr lkgc jv

        private string ProcessCase(string line)
        {
            StringBuilder result = new StringBuilder(line);

            for (int c = line.Length - 1; c >= 0; c--)
            {
                if (line[c] != ' ')
                {
                    result[c] = Natural[Googlerese.IndexOf(line[c])];
                }
            }

            return result.ToString();
        }
    }
}
