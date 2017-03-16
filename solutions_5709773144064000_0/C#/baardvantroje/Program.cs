using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CookieClickerAlpha
{
    class Params
    {
        public double Rate { get; set; }
        public double C { get; set; }
        public double F { get; set; }
        public double X { get; set; }
    }

    class Program
    {
        string inFilePath, outFilePath;
        
        static void Main(string[] args)
        {
            Program p;
            DateTime begin;

            p = new Program("C:\\gcj\\B-small-attempt0.in", "C:\\gcj\\B-small-attempt0.out");
            begin = DateTime.Now;
            p.Solve();
            Console.WriteLine("Solved sample input in {0:F4} seconds.", (DateTime.Now - begin).TotalSeconds);

            Console.WriteLine("{0}Press any key to exit.", Environment.NewLine);
            Console.ReadLine();
        }

        public Program (string inFilePath, string outFilePath)
        {
            this.inFilePath = inFilePath;
            this.outFilePath = outFilePath;
        }

        public void Solve()
        {
            using (StreamReader inStream = new StreamReader(inFilePath))
            using (StreamWriter outStream = new StreamWriter(outFilePath))
            {
                int numProblems = int.Parse(inStream.ReadLine());

                for (int i = 0; i < numProblems; i++)
                {
                    string[] paramStrings = inStream.ReadLine().Split(' ');

                    Params problem = new Params();
                    problem.Rate = 2;
                    problem.C = double.Parse(paramStrings[0]);
                    problem.F = double.Parse(paramStrings[1]);
                    problem.X = double.Parse(paramStrings[2]);

                    outStream.WriteLine("Case #{0}: {1}", (i + 1), solveParams(problem));
                }
            }
        }

        private double solveParams(Params problem)
        {
            double tFarm = timeToFarm(problem);
            double tGoal = timeToGoal(problem);
            double tGoalFarm = timeToGoalWithFarm(problem);

            if (tFarm + tGoalFarm < tGoal)
            {
                problem.Rate += problem.F;
                return tFarm + solveParams(problem);
            }
            else
            {
                return tGoal;
            }
        }

        private double timeToFarm(Params problem)
        {
            return problem.C / problem.Rate;
        }

        private double timeToGoal(Params problem)
        {
            return problem.X / problem.Rate;
        }

        private double timeToGoalWithFarm(Params problem)
        {
            return problem.X / (problem.Rate + problem.F);
        }
    }
}
