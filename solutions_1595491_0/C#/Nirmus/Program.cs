using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJamZad2
{
    class Program
    {
        static string pathIn = @"C:\Users\Admin\Downloads\B-small-attempt0.in";
        static string pathOut = @"C:\Users\Admin\Downloads\out.txt";

        static void Main(string[] args)
        {
            StringBuilder bui = new StringBuilder();
            string[] input = File.ReadAllLines(pathIn);

            int T = int.Parse(input[0]);

            for (int i = 1; i < input.Length; i++)
            {
                string[] dane = input[i].Split(' ');

                int N = int.Parse(dane[0]);
                int S = int.Parse(dane[1]);
                int P = int.Parse(dane[2]);

                int result = 0;

                for (int j = 3; j < dane.Length; ++j)
                {
                    int t = int.Parse(dane[j]);

                    if (t % 3 == 0)
                    {
                        if (t / 3 >= P)
                        {
                            ++result;
                        }
                        else if (t != 0 && t / 3 + 1 >= P && S > 0)
                        {
                            ++result;
                            --S;
                        }
                    }
                    else if (t % 3 == 1)
                    {
                        if (t / 3 + 1 >= P)
                        {
                            ++result;
                        }
                    }
                    else
                    {
                        if (t / 3 + 1>= P)
                        {
                            ++result;
                        }
                        else if (t != 29 && t / 3 + 2 >= P && S > 0)
                        {
                            ++result;
                            --S;
                        }

                    }
                }
                bui.Append(string.Format("Case #{0}: {1}{2}", i, result, Environment.NewLine));
            }

            File.WriteAllText(pathOut, bui.ToString());
        }
    }
}
