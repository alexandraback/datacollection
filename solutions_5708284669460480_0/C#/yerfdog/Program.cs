using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj15r1c
{
    class Program
    {
        static long total = 0;
        static double ocount = 0;
        static long max = 0;
        static void Main(string[] args)
        {
            {
                string root = @"C:\Users\Josiah\Downloads\";
                string problem = "B";
                string ptype = "small-attempt0";
                //string ptype = "Large";

                string[] lines = System.IO.File.ReadAllLines(string.Format("{0}{1}-{2}.in", root, problem, ptype));
                TextWriter tw = new StreamWriter(string.Format("{0}{1}-{2}.out", root, problem, ptype));

                int idx = 0;
                int t = int.Parse(lines[idx++]);
                for (int a = 0; a < t; a++)
                {
                    string[] line = lines[idx++].Split(' ');
                    int K = int.Parse(line[0]);
                    int L = int.Parse(line[1]);
                    int S = int.Parse(line[2]);
                    string keys = lines[idx++];
                    string word = lines[idx++];
                    total = 0;
                    ocount = 0;
                    max = 0;
                    calc("", keys, S, word);
                    tw.WriteLine("Case #{0}: {1}", a + 1, max - (total/ocount));
                }

                tw.Close();
            }
        }

        private static void calc(string w, string keys, int length, string word)
        {
            if (w.Length == length)
            {
                calc2(w, word);
            }
            else
            {
                for (int i = 0; i < keys.Length; i++)
                {
                    calc(w + keys[i], keys, length, word);
                }
            }
        }

        private static void calc2(string w, string word)
        {
            int bigCount = 0;
            for (int a = 0; a < w.Length; a++)
            {
                int b = a;
                int c = 0;
                int count = 0;
                while (b < w.Length && c < word.Length && w[b++] == word[c++])
                {
                    count++;
                }
                if (count == word.Length)
                {
                    bigCount++;
                }
            }
            if (bigCount > max)
            {
                max = bigCount;
            }
            total += bigCount;
            ocount++;
        }
    }
}
