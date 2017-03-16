using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.ExceptionServices;
using System.Runtime.Remoting.Channels;
using System.Text;


namespace carrots
{
    class Program
    {
        private static void Main(string[] args)
        {

            StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
            string input = reader.ReadToEnd();

            var lines = input.Split(new[] {"\r\n", "\n"}, StringSplitOptions.None);
            var validLines = lines.Take(lines.Count() - 1).ToArray();


            int linecount = 0;
            int testcases = int.Parse(validLines[linecount++]);


            foreach (var zzz in Enumerable.Range(1, testcases))
            {
                var testinput =
                    validLines[linecount++].Split(new[] {" "}, StringSplitOptions.RemoveEmptyEntries)
                        .Select(x => Int64.Parse(x));

                Int64 B = testinput.First();
                Int64 M = testinput.Last();


                var maxc = MaxCombinations(B);

                if (maxc < M)
                {
                    Console.WriteLine("Case #" + zzz + ": " + "IMPOSSIBLE");
                    continue;
                }

                bool[][] slides = new bool[B][];
                for (Int64 b = 0; b <= B - 1; b++)
                {
                    slides[b] = new bool[B];
                    for (Int64 bb = b + 1; bb <= B - 1; bb++)
                    {
                        if (b == B - 1)
                        {
                            continue;
                        }
                            slides[b][bb] = true;

                    }
                }


                Int64 currentComb = maxc;

                for (Int64 bebe = B - 1; bebe >= 0; bebe--)
                {
                    Int64 value = 1;
                    if (bebe > 1)
                    {
                        value = Convert.ToInt64(Math.Pow(2, bebe - 2));
                    }

                    if (currentComb - M >= value)
                    {
                        currentComb -= value;
                        slides[bebe-1][B - 1] = false;
                    }
                    
                }



                Console.WriteLine("Case #" + zzz + ": " + "POSSIBLE");

                foreach (bool[] slide in slides)
                {
                    foreach (bool b in slide)
                    {
                        if (b)
                        {
                            Console.Write("1");
                        }
                        else
                        {
                            Console.Write("0");
                        }
                    }
                    Console.WriteLine();
                }


            }
        }

        private static Int64 MaxCombinations(Int64 B)
        {
            if (B == 1 || B ==2)
            {
                return 1;
            }

            return Convert.ToInt64(Math.Pow(2, B - 2));

        }
    }
}

