using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace ProblemB
{
    class ProblemBProgram
    {
        static void Main(string[] args) { (Activator.CreateInstance(MethodBase.GetCurrentMethod().DeclaringType) as dynamic).Run(); }
        void Run()
        {
            //using (TextReader tr = new StreamReader(@"c:\temp\testin.txt"))
            using (TextReader tr = new StreamReader(@"c:\temp\B-small-attempt0.in"))
            //using (TextReader tr = new StreamReader(@"c:\temp\b-large.in"))
            //using (TextReader tr = Console.In)

            using (TextWriter tw = new StreamWriter(@"c:\temp\out.txt"))
            //using (TextWriter tw = Console.Out)
            {
                var tCase = int.Parse(tr.ReadLine());

                for (var tiCase = 1; tiCase <= tCase; ++tiCase)
                {
                    tw.WriteLine("Case #{0}: {1}", tiCase, Solve(tr.ReadLine));
                }
            }
        }

        string Solve(Func<string> rline)
        {
            var inp = rline().Split().Select(int.Parse).ToArray();
            int K = inp[0], L = inp[1], S = inp[2];


            var keyboard = rline();
            var target = rline();

            long max = 0, sum = 0;
            rec(S, keyboard, target, new char[S], 0, ref max, ref sum);

            var testCases = Math.Pow(K, S);
            var avg = (double) sum/testCases;

            var result = (double) max - avg;
            return result.ToString("F7", CultureInfo.InvariantCulture);
        }

        void rec(int S, string kb, string tg, char[] res, int index, ref long max, ref long sum)
        {
            if (index == S)
            {
                int cnt = 0;
                for (int i = 0; i < S - tg.Length + 1; i++)
                {
                    bool same = true;
                    for (int j = 0; j < tg.Length; j++)
                    {
                        if (res[i + j] != tg[j])
                        {
                            same = false;
                            break;
                        }
                    }
                    cnt += same ? 1 : 0;
                }

                max = Math.Max(max, cnt);
                sum += cnt;
                return;
            }

            for (int i = 0; i < kb.Length; i++)
            {
                res[index] = kb[i];
                rec(S,kb,tg, res, index + 1, ref max, ref sum);
            }
        }


    }
}
