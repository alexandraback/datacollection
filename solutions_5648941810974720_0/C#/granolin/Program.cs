using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phone
{
    class Program
    {


        static string[] digits = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

        static void Main(string[] args)
        {
            Reader reader = new Reader("A-small-attempt0.in");
            StreamWriter sw = new StreamWriter("out.txt");

            int nTest = reader.ReadInt();
            for (int T = 1; T <= nTest; T++)
            {
                string s = reader.Next();
                string res = Compute(s);
                sw.WriteLine("Case #" + T + ": " + res);
            }
            sw.Close();
        }

        private static string Compute(string s)
        {


            for (int i = 0; i <= 9; i++)
            {
                try
                {
                    string s2 = Remove(s, i);

                    if (s2.Length == 0)
                        return i.ToString();

                    return i.ToString() + Compute(s2);
                }
                catch(Exception)
                {

                }
            }

            throw new Exception();
        }


        private static string Remove(string s, int digit)
        {
            string d = digits[digit];
            for (int i = 0; i < d.Length; i++)
            {
                int c = s.IndexOf(d[i]);
                if (c == -1)
                    throw new Exception();

                s = s.Remove(c, 1);
            }

            return s;
        }
        
    }


    #region Commun

    public class Reader
    {
        string[] _content;
        int idx = 0;

        public Reader(string path)
        {
            string[] Separator = new string[] { " ", "\r\n", "\n" };
            string s = File.ReadAllText(path);
            _content = s.Split(Separator, StringSplitOptions.None);
        }

        public string Next()
        {
            return _content[idx++];
        }

        public int ReadInt()
        {
            return int.Parse(Next());
        }

        public int[] ReadInt(int N)
        {
            List<int> res = new List<int>();
            for (int i = 0; i < N; i++)
                res.Add(ReadInt());
            return res.ToArray();
        }
    }

    public static class Calc
    {

        public static long PPCM(long[] a)
        {
            return a.Aggregate(PPCM);
        }

        public static long PPCM(long a, long b)
        {
            return a * b / PGCD(a, b);
        }

        public static long PGCD(long[] a)
        {
            return a.Aggregate(PGCD);
        }

        public static long PGCD(long a, long b)
        {
            if (a < b)
                return PGCD(b, a);

            while (b != 0)
            {
                long r = a % b;
                a = b;
                b = r;
            }
            return a;
        }
    }

    #endregion
}
