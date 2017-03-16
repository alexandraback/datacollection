using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.IO;

namespace FairAndSquare2
{
    class Solver
    {
        public bool isPalin(String input)
        {
            for (int i = 0, j = input.Length - 1; i < input.Length / 2; i++, j--)
            {
                if (input[i] != input[j])
                    return false;
            }
            return true;
        }

        public List<long> solution;

        public void preCalc()
        {
            long start = 1, res;
            string input;

            solution = new List<long>();

            while (start <= 10000000)
            {
                if (isPalin(Convert.ToString(start)))
                {
                    res = start * start;
                    input = Convert.ToString(res);
                    if (isPalin(input))
                        solution.Add(res);
                }
                start++;
            }
        }

        public void Run()
        {
            preCalc();
            int cases, numCase, index, result;
            long A, B;

            StreamReader sr = new StreamReader("input.txt");
            StreamWriter sw = new StreamWriter("output.txt");

            string input;
            string[] values;

            input = sr.ReadLine();
            cases = Int32.Parse(input);

            for (numCase = 1; numCase <= cases; numCase++)
            {
                input = sr.ReadLine();
                values = input.Split(' ');

                A = long.Parse(values[0]);
                B = long.Parse(values[1]);

                index = 0;
                while (solution[index] < A)
                    index++;

                result = 0;
                while (index < solution.Count && solution[index] <= B)
                {
                    result++;
                    index++;
                }

                sw.WriteLine("Case #{0}: {1}", numCase, result);
            }

            sr.Close();
            sw.Close();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Solver solver = new Solver();
            solver.Run();
        }
    }
}
