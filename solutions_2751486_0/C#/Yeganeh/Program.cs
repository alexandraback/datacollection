using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace CodeJamCS
{
    class Program
    {
        static void solve(string[] inputLines)
        {
            int T = int.Parse(inputLines[0].Trim()) + 1;

            for (int tc = 1; tc < T; tc++)
            {
                string[] Ln = inputLines[tc].Trim().Split(' ');
                string L = Ln[0];
                int n = int.Parse(Ln[1]);

                //MatchCollection matchs = Regex.Matches(L, @"[qwrtypsdfghjklzxcvbnm]{"+n+"}",RegexOptions.IgnoreCase);

                //string[] cc = matchs.Cast<Match>().Select(v=>v.ToString()).ToArray();

                int nValue = 0;
                for (int i = 0; i < L.Length; i++)
                {
                    for (int j = i + 1; j < L.Length+1; j++)
                    {
                        string sub = L.Substring(i, j - i);
                        MatchCollection matchs = Regex.Matches(sub, @"[qwrtypsdfghjklzxcvbnm]{" + n + "}", RegexOptions.IgnoreCase);
                        if (matchs.Count > 0)
                            nValue++;
                    }
                }

                Console.WriteLine("Case #" + tc + ": " + nValue.ToString());
            }
        }
        static void Main(string[] args)
        {
            string[] inputLines = Console.In.ReadToEnd().Split('\n');
            //string[] inputLines = System.IO.File.ReadAllText("test.txt").Split('\n');

            solve(inputLines);
        }
    }
}
