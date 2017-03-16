using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

namespace CodeJam
{
    class RecycledNumberCalculator
    {
        static void Main(string[] args)
        {
            new RecycledNumberCalculator().Solve();
        }

        void Solve()
        {
            using (StreamReader sc = new StreamReader("C-large.in"))
            using (StreamWriter sout = new StreamWriter("C-large.out"))
            {
                int cas = sc.Next<int>();
                for (int zz = 1; zz <= cas; zz++)
                {
                    int ans = 0;
                    int a = sc.Next<int>();
                    int b = sc.Next<int>();
                    for (int i = a; i < b; i++)
                    {
                        IList<int> recycledNumbers = GetRecycledNumbers(i);
                        foreach (int j in recycledNumbers)
                        {
                            if (j > i && j >= a && j <= b)
                            {

                                ans++;
                            } 
                        }
                    }



                    sout.WriteLine("Case #" + (zz) + ": " + ans);
                }
            }
        }

        private IList<int> GetRecycledNumbers(int originalNumber)
        {
            HashSet<int> recycledNumbers = new HashSet<int>();
            string originalNumberAsString = originalNumber.ToString();
            int length = originalNumberAsString.Length;
            for(int i =1; i<length; i++)
            {
                string newString = originalNumberAsString.Substring(i) + originalNumberAsString.Substring(0, i);
                if (newString[0] == '0') continue;
                recycledNumbers.Add(Int32.Parse(newString));
            }
            return recycledNumbers.ToList();
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
    }
}
