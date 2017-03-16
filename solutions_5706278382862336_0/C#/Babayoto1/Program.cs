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

        private static ulong Solve(Problem inputDesck)
        {
            var gcd = GCD(inputDesck.A, inputDesck.B);
            inputDesck.A /= gcd;
            inputDesck.B /= gcd;

            if (!IsPowerOfTwo(inputDesck.B))
                return 0;
            if (inputDesck.B / 2 <= inputDesck.A)
            {
                return 1;
            }

            ulong count = 0;
            while (inputDesck.A!=1)
            {
                inputDesck.A /= 2;
                inputDesck.B /= 2;
                count++;
            }

            return (ulong)Math.Log(inputDesck.B, 2);
        }

        static ulong GCD(ulong a, ulong b)
        {
            return b == 0 ? a : GCD(b, a % b);
        }

        static bool IsPowerOfTwo(ulong x)
        {
            return (x & (x - 1)) == 0;
        }

        internal class Problem
        {
            public ulong A { get; set; }
            public ulong B { get; set; }
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

                problem.A = ulong.Parse(line.Split('/')[0]);
                problem.B = ulong.Parse(line.Split('/')[1]);

                return problem;
            }
        }
    }
}
