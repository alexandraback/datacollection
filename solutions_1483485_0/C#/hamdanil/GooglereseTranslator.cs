using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

namespace CodeJam
{
    class GooglereseTranslator
    {
        static void Main(string[] args)
        {
            new GooglereseTranslator().Solve();
        }

        void Solve()
        {
            using (StreamReader sc = new StreamReader("A-small-attempt0.in"))
            using (StreamWriter sout = new StreamWriter("A-small.out"))
            {
                int cas = sc.Next<int>();
                //sc.ReadLine();
                for (int zz = 1; zz <= cas; zz++)
                {
                    string input = sc.ReadLine();
                    string output = "";
                    IDictionary<char, char> dictionary = InitDictionary();
                    foreach (char i in input)
                    {
                        if (Char.IsWhiteSpace(i)) output += ' ';
                        else output += dictionary[i];
                    }
                    sout.WriteLine("Case #" + (zz) + ": " + output);
                }
            }
        }

        private IDictionary<char, char> InitDictionary()
        {
            IDictionary<char, char> dictionary = new Dictionary<char, char>{
                {'a','y'},
                {'b','h'},
                {'c','e'},
                {'d','s'},
                {'e','o'},
                {'f','c'},
                {'g','v'},
                {'h','x'},
                {'i','d'},
                {'j','u'},
                {'k','i'},
                {'l','g'},
                {'m','l'},
                {'n','b'},
                {'o','k'},
                {'p','r'},
                {'q','z'},
                {'r','t'},
                {'s','n'},
                {'t','w'},
                {'u','j'},
                {'v','p'},
                {'w','f'},
                {'x','m'},
                {'y','a'},
                {'z','q'},
            };

            return dictionary;

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
