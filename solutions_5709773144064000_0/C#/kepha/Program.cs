using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codejam
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = Convert.ToInt32(Console.In.ReadLine());
            double C = 0, F = 0, X = 0;
            string[] rawtemp = new string[4];

            for (int t = 1; t <= T; t++)
            {
                rawtemp = Console.In.ReadLine().Split(' ');
                C = Convert.ToDouble(rawtemp[0].Replace('.',','));
                F = Convert.ToDouble(rawtemp[1].Replace('.', ','));
                X = Convert.ToDouble(rawtemp[2].Replace('.', ','));

                Console.Out.WriteLine(Solver.solve(t,C, F, X));
            }

        }
    }

    public class Solver
    {
        public static string solve(int number, double C, double F, double X)
        {
            double solution = X / 2;
            double denom = 2;
            double temp = (C-X)/denom;
            denom+=F;
            temp+=X/denom;

            while (temp < 0)
            {
                solution += temp;
                temp = (C - X) / denom;
                denom += F;
                temp += X / denom;
            }
            return "Case #" + number + ": "+ solution.ToString("F7").Replace(',','.');
        }
    }
}
