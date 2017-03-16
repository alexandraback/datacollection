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
                        .Select(x => int.Parse(x));

                int B = testinput.First();
                int M = testinput.Last();


                var maxc = MaxCombinations(B);

                if (maxc < M)
                {
                    Console.WriteLine("Case #" + zzz + ": " + "IMPOSSIBLE");
                    continue;
                }

                bool[][] slides = new bool[B][];
                for (int b = 0; b <= B - 1; b++)
                {
                    slides[b] = new bool[B];
                    for (int bb = b+1; bb <= B - 1; bb++)
                    {
                        if (b == B - 1)
                        {
                            continue;
                        }
                            slides[b][bb] = true;

                    }
                }


                var currentComb = maxc;

                for (int bebe = B-1; bebe >= 0; bebe--)
                {
                    int value = 1;
                    if (bebe > 1)
                    {
                        value = Convert.ToInt32(Math.Pow(2, bebe - 2));
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

        private static int MaxCombinations(int B)
        {
            if (B == 1 || B ==2)
            {
                return 1;
            }

            return Convert.ToInt32(Math.Pow(2, B - 2));

        }
    }
}

