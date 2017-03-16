using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace PartElf
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args[0] == null)
            {
                Console.WriteLine("Input file path");
                return;
            }

            int testsCount;
            var problems = FileReader.GetProblems(args[0], out testsCount);
            var resultString = string.Empty;
            for (var index = 0; index < problems.Count; index++)
            {
                var problem = problems[index];
                var result = Solve(problem);

                if (!string.IsNullOrEmpty(resultString))
                    resultString += "\r\n";
                if (result > 0)
                {
                    resultString += string.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}", index + 1, result);
                }
                else
                {
                    resultString += string.Format(CultureInfo.InvariantCulture, "Case #{0}: impossible", index + 1);
                }

            }
            Console.WriteLine(resultString);
            File.WriteAllText(args[1], resultString);
            Console.ReadKey();
        }

        private static int Solve(Problem inputDesck)
        {
            if (inputDesck.K <= 4)
                return inputDesck.K;

            var x = (int)Math.Ceiling((-5 + Math.Sqrt(17 + 4*inputDesck.K)*1.0)/2);

            

            var result = 4*x + x*x;
            if (result >= inputDesck.K)
            {
                if (x > inputDesck.M || x > inputDesck.N)
                {
                    var y = Math.Min(inputDesck.M, inputDesck.N);
                    x += x - y;
                    return 2 * x + 2 * y;
                }
                return 4*x;
            }

            else
            {
                if (x +1 > inputDesck.M || x+1 > inputDesck.N)
                {
                    var y = Math.Min(inputDesck.M, inputDesck.N);
                    x += x + 1 - y;
                    return 2 * x + 2 * y;
                }
                return 4 * x + 2;
            }
                

        }

        internal class Problem
        {
            public int N { get; set; }
            public int M { get; set; }
            public int K { get; set; }
        }

        internal class FileReader
        {
            public static List<Problem> GetProblems(string filename, out int desckCount)
            {
                var file = new StreamReader(filename);
                var line = file.ReadLine();
                int.TryParse(line, out desckCount);

                var result = new List<Problem>();

                Problem currentDesck;
                while ((currentDesck = GetProblem(file)) != null)
                {
                    result.Add(currentDesck);
                }

                file.Close();
                return result;
            }

            private static Problem GetProblem(StreamReader file)
            {
                var problem = new Problem();

                var line = file.ReadLine();
                if (string.IsNullOrEmpty(line))
                    return null;

                problem.N = int.Parse(line.Split(' ')[0]);
                problem.M = int.Parse(line.Split(' ')[1]);
                problem.K = int.Parse(line.Split(' ')[2]);

                return problem;
            }
        }
    }
}
