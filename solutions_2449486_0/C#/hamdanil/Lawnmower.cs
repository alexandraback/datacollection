using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

namespace CodeJam
{
    class Lawnmower
    {
        static void Main(string[] args)
        {
            new Lawnmower().Solve();
        }

        void Solve()
        {
            using (StreamReader sc = new StreamReader("B-small-attempt0.in"))
            using (StreamWriter sout = new StreamWriter("B-small.out"))
            {
                int cas = sc.Next<int>();
                for (int zz = 1; zz <= cas; zz++)
                {
                    string ans = "";

                    int x = sc.Next<int>();
                    int y = sc.Next<int>();

                    int[][] lawn = new int[x][];
                    for (int i = 0; i < x; i++)
                    {
                        lawn[i] = new int[y];
                        for (int j = 0; j < y; j++)
                            lawn[i][j] = sc.Next<int>();
                    }



                    ans = IsValid(lawn) ? "YES" : "NO";


                    sout.WriteLine("Case #" + (zz) + ": " + ans);
                }
            }
        }

        private bool IsValid(int[][] lawn)
        {
            int x = lawn.Length;
            int y = lawn[0].Length;
            int[] xSetting = new int[x];
            int[] ySetting = new int[y];

            for (int i = 0; i < x; i++)
                xSetting[i] = lawn[i].Max();
            for (int j = 0; j < y; j++)
                ySetting[j] = lawn.Max(s => s[j]);

            for (int i = 0; i < x; i++)
                for (int j = 0; j < y; j++)
                    if (lawn[i][j] != Math.Min(xSetting[i], ySetting[j])) return false;

            return true;
        }
    }

    public static class Extensions
    {
        public static string Next(this StreamReader sr)
        {
            if (sr.EndOfStream) return null;
            StringBuilder sb = new StringBuilder();
            char ch;
            while (!Char.IsWhiteSpace(ch = (char)sr.Read()))
            {
                sb.Append(ch);
            }
            if (sb.Length == 0) return sr.Next();
            return sb.ToString();
        }

        public static T Next<T>(this StreamReader sr) where T : IConvertible
        {
            string s = sr.Next();
            if (s == null) throw new EndOfStreamException();
            return (T)Convert.ChangeType(s, typeof(T));
        }

        public static string[] nextStrings(this StreamReader sr)
        {
            return sr.ReadLine().Split();
        }

        public static List<T> NextList<T>(this StreamReader sr) where T : IConvertible
        {
            string[] st = sr.ReadLine().Split();
            List<T> ret = new List<T>();
            foreach (string s in st)
                ret.Add((T)Convert.ChangeType(s, typeof(T)));
            return ret;
        }
    }
}
