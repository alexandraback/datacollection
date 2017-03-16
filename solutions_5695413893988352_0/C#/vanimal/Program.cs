using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Jam
{
    class Program
    {
        static void Main(string[] args)
        {
            int cases = ReadInt();

            for (int i = 0; i < cases; i++)
            {
                Console.WriteLine("Case #{0}: {1}", i + 1, Solve());
            }
        }

        enum Result
        {
            Tied,
            CodersWinning,
            JammersWinning
        }
        
        static string Solve()
        {
            var scoreInputs = ReadList<string>();
            var scores = new List<string> { string.Empty, string.Empty };
            var result = Result.Tied;

            for (int i = 0; i < scoreInputs[0].Length; i++)
            {
                char coders = scoreInputs[0][i];
                char jammers = scoreInputs[1][i];

                if (coders == '?' && jammers == '?')
                {
                    switch (result)
                    {
                        case Result.Tied:
                            var cNextDigits = scoreInputs[0].Skip(i + 1);
                            var jNextDigits = scoreInputs[1].Skip(i + 1);

                            var cFixedDigits = cNextDigits.TakeWhile(c => c != '?');
                            var jFixedDigits = jNextDigits.TakeWhile(c => c != '?');
                            
                            bool oneForCoders = false;
                            bool oneForJammers = false;

                            var initialDiff = cFixedDigits.Zip(jFixedDigits, (c, j) => c - j).FirstOrDefault();

                            var digits = cNextDigits.Zip(jNextDigits, (c, j) => new { c, j }).TakeWhile(p => p.c != '?' || p.j != '?');

                            if (initialDiff > 5)
                            {
                                oneForJammers = true;
                            }
                            else if (initialDiff == 5)
                            {
                                var cMax = digits.Skip(1).Select(p => p.c == '?' ? '9' : p.c);
                                var jMin = digits.Skip(1).Select(p => p.j == '?' ? '0' : p.j);
                                oneForJammers = cMax.Zip(jMin, (c,j) => c - j).SkipWhile(d => d == 0).FirstOrDefault() > 0;
                            }
                            else if (initialDiff < -5)
                            {
                                oneForCoders = true;
                            }
                            else if (initialDiff == -5)
                            {
                                var cMin = digits.Skip(1).Select(p => p.c == '?' ? '0' : p.c);
                                var jMax = digits.Skip(1).Select(p => p.j == '?' ? '9' : p.j);
                                oneForCoders = cMin.Zip(jMax, (c, j) => c - j).SkipWhile(d => d == 0).FirstOrDefault() < 0;
                            }

                            scores[0] += oneForCoders ? '1' : '0';
                            scores[1] += oneForJammers ? '1' : '0';

                            if (oneForCoders)
                            {
                                result = Result.CodersWinning;
                            }

                            if (oneForJammers)
                            {
                                result = Result.JammersWinning;
                            }
                            break;
                        case Result.CodersWinning:
                            scores[0] += '0';
                            scores[1] += '9';
                            break;
                        case Result.JammersWinning:
                            scores[0] += '9';
                            scores[1] += '0';
                            break;
                    }
                }
                else if (coders == '?')
                {
                    switch (result)
                    {
                        case Result.Tied:
                            scores[0] += jammers;
                            scores[1] += jammers;
                            break;
                        case Result.CodersWinning:
                            scores[0] += '0';
                            scores[1] += jammers;
                            break;
                        case Result.JammersWinning:
                            scores[0] += '9';
                            scores[1] += jammers;
                            break;
                    }
                }
                else if (jammers == '?')
                {
                    switch (result)
                    {
                        case Result.Tied:
                            scores[0] += coders;
                            scores[1] += coders;
                            break;
                        case Result.CodersWinning:
                            scores[0] += coders;
                            scores[1] += '9';
                            break;
                        case Result.JammersWinning:
                            scores[0] += coders;
                            scores[1] += '0';
                            break;
                    }
                }
                else
                {
                    scores[0] += coders;
                    scores[1] += jammers;

                    if (result == Result.Tied && coders != jammers)
                    {
                        result = coders > jammers ? Result.CodersWinning : Result.JammersWinning;
                    }
                }
            }

            return scores[0] + " " + scores[1];
        }

        static int ReadInt()
        {
            return int.Parse(Console.ReadLine());
        }

        static string ReadString()
        {
            return Console.ReadLine();
        }

        static List<T> ReadList<T>()
        {
            return Console.ReadLine().Split(' ').Select(v => (T)Convert.ChangeType(v, typeof(T))).ToList();
        }
    }
}
