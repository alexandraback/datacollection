using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam_Test
{
    public class Program
    {
        public static void Main(string[] args)
        {
            // Einstellungen für kontkretes Problem
            var showResultInOneLine = true; // TODO Je Aufgabe anpassen

            // Inputfile suchen
            var file = Directory.GetFiles("../../../WorkingDir", "*.in").FirstOrDefault();
            if (string.IsNullOrEmpty(file)) throw new FileNotFoundException("No Inputfile found");

            var lines = File.ReadAllLines(file);

            // Anzahl der Tests steht immer in der ersten Zeile
            var caseCount = int.Parse(lines[0]);

            // Aufbau eines Tests hat immer gleichviele Inputzeilen (bisher^^)
            var linesPerCase = (lines.Length - 1) / caseCount;

            // Testfälle splitten
            var cases = CreateCases(lines, linesPerCase, caseCount);

            var sbResult = new StringBuilder();

            var counter = 1;
            foreach (var job in cases)
            {
                var result = ExcecuteSingleCase(job);

                sbResult.Append("Case #" + counter++ + ":");

                if (showResultInOneLine)
                {
                    sbResult.Append(" " + result);
                }
                else
                {
                    sbResult.AppendLine();
                    sbResult.Append(result);
                }
                sbResult.AppendLine();
            }

            File.WriteAllText(file + ".result", sbResult.ToString());
            new FileInfo(file).MoveTo(file + ".processed");
        }

        public static string ExcecuteSingleCase(string input)
        {
            var splitts = input.Split(' ');

            var A = int.Parse(splitts[0]);
            var B = int.Parse(splitts[1]);
            var K = int.Parse(splitts[2]);

            return DetermineWinningNumbersBruteForce(A, B, K).ToString();
        }

        private static int DetermineWinningNumbersBruteForce(int A, int B, int K)
        {
            var hits = 0;

            for (var a = 0; a < A; a++)
            {
                for (var b = 0; b < B; b++)
                {
                    if ((a & b) < K)
                    {
                        hits++;
                    }
                }
            }

            return hits;
        }

        private static IEnumerable<String> CreateCases(string[] caseLines, int linesPerCase, int caseCount)
        {
            var curLine = 1; // 1 wegen der Zeile mit der Anzahl der Tests

            for (var i = 0; i < caseCount; i++)
            {
                var curSb = new StringBuilder();

                var proceed = true;
                do
                {
                    curSb.Append(caseLines[curLine++]);
                    if (proceed = (curLine - 1 /*wegen der 1ten Zeile*/) % linesPerCase != 0)
                    {
                        curSb.AppendLine();
                    }
                }
                while (proceed);

                yield return curSb.ToString();
            }
        }
    }
}
