using System;
using System.Collections.Generic;
using System.IO;

namespace Qual1A
{
    internal class ProgramA
    {
        private static bool Local = true;

        private static void Main()
        {
            var stream = Local ? new StreamReader("in.txt") : new StreamReader(Console.OpenStandardInput());

            var T = Convert.ToInt32(stream.ReadLine());

            for (var tt = 0; tt < T; tt++)
            {
                Console.Write("Case #{0}: ", tt + 1);

                var line = stream.ReadLine().Trim();
                var lines = line.Split();
                var name = lines[0];
                var n = int.Parse(lines[1]);
                var l = name.Length;

                Int64 res = 0;
                int last = -1;
                int acc = 0;
                for (var i = 0; i < l; i++)
                {
                    if (!IsVowel(name[i]))
                    {
                        acc++;
                        if (acc >= n)
                        {
                            res += ((Int64)(i - n + 1 - last)) * ((Int64)(l - i));
                            last = i - n + 1;
                        }
                    }
                    else
                    {
                        acc = 0;
                    }
                }

                Console.WriteLine(res);

            }
        }
        public static bool IsVowel(char a)
        {
            return a == 'u' || a == 'e' || a == 'i' || a == 'a' || a == 'o';
        }
    }

}