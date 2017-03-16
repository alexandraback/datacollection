using System;
using System.IO;

namespace gcj16q
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\GCJ\B-large.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\B-large.out");
            for (int a = 0; a < t; a++)
            {
                tw.WriteLine("Case #{0}: {1}", a + 1, calcb(lines[idx++], 0));
            }
            tw.Close();
        }
        private static int calcb(string s, int moves)
        {
            if (s.Length == 0)
            {
                return moves;
            }

            int i = s.Length - 1;
            while (i >= 0 && s[i] == '+')
            {
                i--;
            }
            if (i != s.Length - 1)
            {
                return calcb(s.Substring(0, i + 1), moves);
            }

            i = 0;
            while (i < s.Length && s[i] == '-')
            {
                i++;
            }
            if (i != 0)
            {
                return calcb(flip(s, i), moves + 1);
            }

            i = 0;
            while (i < s.Length && s[i] == '+')
            {
                i++;
            }
            return calcb(flip(s, i), moves + 1);
        }

        private static string flip(string s, int i)
        {
            string front = s.Substring(0, i);
            string end = s.Substring(i);
            string res = "";
            for (int a = front.Length - 1; a >= 0; a--)
            {
                if (front[a] == '-')
                {
                    res += '+';
                }
                else
                {
                    res += '-';
                }
            }
            return res + end;
        }

        private static string calca(int N)
        {
            if (N == 0)
            {
                return "INSOMNIA";
            }
            int digits = 0;
            int done = (1 << 10) - 1;
            int cur = 0;
            while (done != digits)
            {
                cur += N;
                int curtemp = cur;
                while (curtemp > 0)
                {
                    int dig = curtemp % 10;
                    digits |= 1 << dig;
                    curtemp /= 10;
                }
            }
            return cur.ToString();
        }
    }
}