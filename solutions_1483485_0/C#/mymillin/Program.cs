using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Q1
{
    class Program
    {
        static void Main(string[] args)
        {
            new Program();
        }

        Program()
        {

            StreamReader input = new StreamReader("sample.txt");
            StreamWriter output = new StreamWriter("solution.txt");

            int caseTotal = int.Parse(input.ReadLine());
            string line;

            for (int count = 0; count < caseTotal; count++)
            {
                line = input.ReadLine();
                string solution = Solve(line);

                Console.WriteLine(solution);
                output.WriteLine("Case #" + (count + 1) + ": " + solution);
            }
            output.Close();

            Console.ReadLine();

        }


        static char[] trans = new char[] { 'y', 'h', 'e' ,'s', 'o',
                                           'c', 'v', 'x' ,'d', 'u',
                                           'i', 'g', 'l' ,'b', 'k',
                                           'r', 'z', 't' ,'n', 'w',
                                           'j', 'p', 'f' ,'m', 'a', 'q'
                                            };

        private static string Solve(string line)
        {
            StringBuilder sb = new StringBuilder();
            foreach (char c in line.ToCharArray())
            {
                if (c == ' ')
                    sb.Append(' ');
                else
                {
                    sb.Append(trans[c - 'a']);
                }
            }
            return sb.ToString();
        }
    }
}
