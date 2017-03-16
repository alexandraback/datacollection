using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

namespace CodeJam
{
    class Dancer
    {
        static void Main(string[] args)
        {
            new Dancer().Solve();
        }

        void Solve()
        {
            using (StreamReader sc = new StreamReader("B-small-attempt0.in"))
            using (StreamWriter sout = new StreamWriter("B-small.out"))
            {
                int cas = sc.Next<int>();
                for (int zz = 1; zz <= cas; zz++)
                {
                    int ans = 0;
                    int n = sc.Next<int>();
                    int noOfSurprising = sc.Next<int>();
                    int p = sc.Next<int>();

                    var scores = sc.NextList<int>();

                    var minNormal = p * 3 - 2; //eg. 7,7,8 for 8
                    var minSurprising = Math.Max(p * 3 - 4, p); //e.g. 6,6,8 for 8 or 0,0,1 for 1

                    int certainCount = 0;
                    int onlyPossibleIfSurprisingCount = 0;

                    foreach (int score in scores)
                    {
                        if (score >= minNormal) certainCount++;
                        else if (score >= minSurprising) onlyPossibleIfSurprisingCount++;

                    }

                    ans = Math.Min(noOfSurprising, onlyPossibleIfSurprisingCount) + certainCount;

                    sout.WriteLine("Case #" + (zz) + ": " + ans);
                }
            }
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
