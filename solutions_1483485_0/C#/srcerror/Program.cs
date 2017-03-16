using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Tongues
{
    class Program
    {
        const string InputPath = @"d:\Work\Current\CodeJam\Practice\T9Typing\T9Typing\A-small-attempt0.in";
        const string OutputPath = @"d:\Work\Current\CodeJam\Practice\T9Typing\T9Typing\resultA.out";

        static Dictionary<char, string> _alphabetT9 = new Dictionary<char, string>()
            {
                {'a', "y"},
                {'b', "h"},
                {'c', "e"},
                {'d', "s"},
                {'e', "o"},
                {'f', "c"},
                {'g', "v"},
                {'h', "x"},
                {'i', "d"},
                {'j', "u"},
                {'k', "i"},
                {'l', "g"},
                {'m', "l"},
                {'n', "b"},
                {'o', "k"},
                {'p', "r"},
                {'q', "z"},
                {'r', "t"},
                {'s', "n"},
                {'t', "w"},
                {'u', "j"},
                {'v', "p"},
                {'w', "f"},
                {'x', "m"},
                {'y', "a"},
                {'z', "q"},
                {' ', " "},
            };

        static void Main(string[] args)
        {

            var sr = new StreamReader(InputPath);
            var sw = new StreamWriter(OutputPath);

            int N = Int32.Parse(sr.ReadLine());
            for (int n = 1; n <= N; n++)
            {
                var x = SolveNextInput(sr);

                sw.WriteLine(GetCaseSolutionString(x, n));

            }
            sr.Close();
            sw.Close();
        }

        private static string GetCaseSolutionString(string phrase, int n)
        {
            return string.Format("Case #{0}: {1}", n, phrase);
        }

        private static string SolveNextInput(StreamReader sr)
        {
            string phrase = sr.ReadLine();
            var result = new StringBuilder();
            foreach (var c in phrase)
            {
                var nstr = _alphabetT9[c];
                result.Append(nstr);
            }

            return result.ToString();
        }

    }
}
