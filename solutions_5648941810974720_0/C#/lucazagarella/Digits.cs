using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace GoogleCoceJam2016
{
    public class Digits
    {
        public const string ProblemCode = "A";

        public static void Solve(string file)
        {
            using (var sr = new StreamReader(file + ".in"))
            {
                using (var sw = new StreamWriter(file + ".out"))
                {
                    string line = sr.ReadLine();
                    var cases = int.Parse(line);

                    for (int i = 1; i <= cases; i++)
                    {
                        line = sr.ReadLine();

                        var res = SolveInput(line);
                        var restText = res;
                        Console.WriteLine("Case #{0}: {1}", i, restText);
                        sw.WriteLine("Case #{0}: {1}", i, restText);
                    }

                }
            }

            Console.WriteLine();
            Console.WriteLine("FINITO");
            Console.WriteLine();
            Console.ReadKey();
        }


        public static string SolveInput(string input)
        {
            var res = new List<int>();
            var chars = input.GroupBy(x => x).ToDictionary(x => x.Key, y => y.Count()); ;
            if (chars.ContainsKey('Z'))
            {
                int cnt = chars['Z'];
                for (int i = 0; i < cnt; i++)
                {
                    res.Add(0);
                    
                }
                chars['O'] -= cnt;
                chars['R'] -= cnt;
                chars['E'] -= cnt;
                chars['Z'] -= cnt;
            }
            chars=chars.Where(x => x.Value > 0).ToDictionary(x => x.Key, y => y.Value);

            if (chars.ContainsKey('G'))
            {
                int cnt = chars['G'];
                for (int i = 0; i < cnt; i++)
                {
                    res.Add(8);

                }
                chars['E'] -= cnt;
                chars['I'] -= cnt;
                chars['G'] -= cnt;
                chars['H'] -= cnt;
                chars['T'] -= cnt;
            }
            chars = chars.Where(x => x.Value > 0).ToDictionary(x => x.Key, y => y.Value);

            if (chars.ContainsKey('X'))
            {
                int cnt = chars['X'];
                for (int i = 0; i < cnt; i++)
                {
                    res.Add(6);

                }
                chars['S'] -= cnt;
                chars['I'] -= cnt;
                chars['X'] -= cnt;
            }
            chars = chars.Where(x => x.Value > 0).ToDictionary(x => x.Key, y => y.Value);

            if (chars.ContainsKey('U'))
            {
                int cnt = chars['U'];
                for (int i = 0; i < cnt; i++)
                {
                    res.Add(4);

                }
                chars['F'] -= cnt;
                chars['O'] -= cnt;
                chars['U'] -= cnt;
                chars['R'] -= cnt;
            }
            chars = chars.Where(x => x.Value > 0).ToDictionary(x => x.Key, y => y.Value);

            if (chars.ContainsKey('W'))
            {
                int cnt = chars['W'];
                for (int i = 0; i < cnt; i++)
                {
                    res.Add(2);

                }
                chars['T'] -= cnt;
                chars['W'] -= cnt;
                chars['O'] -= cnt;
            }
            chars = chars.Where(x => x.Value > 0).ToDictionary(x => x.Key, y => y.Value);

            if (chars.ContainsKey('O'))
            {
                int cnt = chars['O'];
                for (int i = 0; i < cnt; i++)
                {
                    res.Add(1);

                }
                chars['O'] -= cnt;
                chars['N'] -= cnt;
                chars['E'] -= cnt;
            }
            chars = chars.Where(x => x.Value > 0).ToDictionary(x => x.Key, y => y.Value);

            if (chars.ContainsKey('H'))
            {
                int cnt = chars['H'];
                for (int i = 0; i < cnt; i++)
                {
                    res.Add(3);
                }
                chars['T'] -= cnt;
                chars['H'] -= cnt;
                chars['R'] -= cnt;
                chars['E'] -= cnt;
                chars['E'] -= cnt;
            }
            chars = chars.Where(x => x.Value > 0).ToDictionary(x => x.Key, y => y.Value);

            if (chars.ContainsKey('F'))
            {
                int cnt = chars['F'];
                for (int i = 0; i < cnt; i++)
                {
                    res.Add(5);
                }
                chars['F'] -= cnt;
                chars['I'] -= cnt;
                chars['V'] -= cnt;
                chars['E'] -= cnt;
            }
            chars = chars.Where(x => x.Value > 0).ToDictionary(x => x.Key, y => y.Value);

            if (chars.ContainsKey('S'))
            {
                int cnt = chars['S'];
                for (int i = 0; i < cnt; i++)
                {
                    res.Add(7);
                }
                chars['S'] -= cnt;
                chars['E'] -= cnt;
                chars['V'] -= cnt;
                chars['E'] -= cnt;
                chars['N'] -= cnt;
            }
            chars = chars.Where(x => x.Value > 0).ToDictionary(x => x.Key, y => y.Value);

            if (chars.ContainsKey('I'))
            {
                int cnt = chars['I'];
                for (int i = 0; i < cnt; i++)
                {
                    res.Add(9);
                }
                chars['N'] -= cnt;
                chars['I'] -= cnt;
                chars['N'] -= cnt;
                chars['E'] -= cnt;
            }
            chars = chars.Where(x => x.Value > 0).ToDictionary(x => x.Key, y => y.Value);

            if (chars.Any())
            {
                throw new Exception();
            }

            return string.Join("",res.OrderBy(x=> x));
        }

        public static void SolveLarge()
        {
            Solve(ProblemCode + "-large");
        }

        public static void SolveSample()
        {
            Solve(ProblemCode + "-sample");
        }


        public static void SolveSmall()
        {
            Solve(ProblemCode + "-small");
        }


    }
}
