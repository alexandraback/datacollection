using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

namespace Pogo
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length > 0)
            {
                TextReader reader = File.OpenText(args[0]);
                Console.SetIn(reader);

                StreamWriter streamWriter = new StreamWriter(new FileStream(args[0] + ".out", FileMode.Create));
                streamWriter.AutoFlush = true;
                Console.SetOut(streamWriter);
            }

            int T = Int32.Parse(Console.ReadLine()); // number of test cases

            for (int i = 0; i < T; i++)
            {
                string[] line = Console.ReadLine().Split(' ');

                int X = Convert.ToInt32(line[0]);
                int Y = Convert.ToInt32(line[1]);

                Console.WriteLine("Case #{0}: {1}", i + 1, Solve(X, Y));
            }

            if (args.Length == 0)
                Console.ReadKey(false);
        }

        static private string Solve(int X, int Y)
        {
            StringBuilder solution = new StringBuilder();

            for (int i = 0; i < Math.Abs(X); i++)
            {
                if (X > 0)
                {
                    solution.Append("WE");
                }
                else if (X < 0)
                {
                    solution.Append("EW");
                }
            }

            for (int i = 0; i < Math.Abs(Y); i++)
            {
                if (Y > 0)
                {
                    solution.Append("SN");
                }
                else if (Y < 0)
                {
                    solution.Append("NS");
                }
            }

            if (solution.Length > 500)
                throw new Exception("Too many moves!");

            return solution.ToString();
        }
    }
}
