using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _2013R1CP1
{
    class Program
    {
        static void Main(string[] args)
        {Console.WriteLine(DateTime.Now);

            String[] input = File.ReadAllText("..\\..\\input.txt").Split('\n');
            String ret = "";

            int l = 0;
            int T = int.Parse(input[l]);
            l++;
            for (int c = 0; c < T; c++)
            {
                string testCase = input[l].Split(' ')[0];
                int N = int.Parse(input[l].Split(' ')[1]);
                l++;

                decimal tot = 0;

                decimal lastpos = 0;

                decimal cons = 0;

                for (int i = 0; i < testCase.Length; i++)
                {
                    if ("aeiou".IndexOf(testCase[i]) >= 0)
                    {
                        cons = 0;
                    }
                    else
                    {
                        cons++;
                    }

                    if (cons == N)
                    {
                        decimal before = i - N + 2 - lastpos;
                        decimal after = testCase.Length - i;
                        //tot += testCase.Length - N - lastpos + 1;
                        tot += before * after;
                        lastpos = i - N + 2;
                        cons--;
                    }
                }


                ret += "Case #" + (c + 1).ToString() + ": " + tot.ToString() + "\n";
                Console.WriteLine("Case #" + (c + 1).ToString() + ": " + tot.ToString());
            }

            File.WriteAllText("..\\..\\output.txt", ret.Trim());
            Console.ReadLine();
        }
    }
}
