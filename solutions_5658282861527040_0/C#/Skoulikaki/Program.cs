using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TheNewLottey
{
    class Program
    {
        const string filename = "B-small-attempt0 (1).in";
        const int linesForCaseNumber = 1;

        const string notPossible = "Fegla Won";

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(filename);
            int T_cases = int.Parse(sr.ReadLine());

            Debug.Assert(T_cases >= 1, "Input cases not correct");

            for (int currentCase = 1; currentCase <= T_cases; currentCase++)
            {
                string caseLine = sr.ReadLine();
                var splitCase = caseLine.Split(' ');
                Debug.Assert(splitCase.Length == 3, string.Format("Case {0} not corrent in input", currentCase));

                long A_machineA = long.Parse(splitCase[0]);
                long B_machineB = long.Parse(splitCase[1]);
                long K_catalina = long.Parse(splitCase[2]);

                Debug.Assert(splitCase.Length == 3, string.Format("Case {0} not corrent in input", currentCase));
                string resultForCase = SolveTheNewLotteryForLines(A_machineA, B_machineB, K_catalina);

                Console.WriteLine("Case #{0}: {1}", currentCase, resultForCase);
            }
        }

        private static string SolveTheNewLotteryForLines(long A_machineA, long B_machineB, long K_catalina)
        {
            long winningCases = 0;

            for (long machineA = 0; machineA < A_machineA; machineA++)
            {
                for (long machineB = 0; machineB < B_machineB; machineB++)
                {
                    long winningNumber = machineA & machineB;
                    if (K_catalina > winningNumber)
                        winningCases++;
                }
            }

            return winningCases.ToString();
        }
    }
}
