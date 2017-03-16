using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    public class Program
    {
        // TODO set properties for your challenge
        private const bool ShowResultInOneLine = true;
        public const bool EachCaseHasSameLineCount = true;

        public static void Main(string[] args)
        {
            // search and read ijnputfile
            var file = Directory.GetFiles("../../../WorkingDir", "*.in").FirstOrDefault();
            if (string.IsNullOrEmpty(file)) throw new FileNotFoundException("No Inputfile found");

            var lines = File.ReadAllLines(file);

            var result = ProcessAll(lines);

            File.WriteAllText(file + ".result", result);
            new FileInfo(file).MoveTo(file + ".processed");
        }

        /// <summary>
        /// Processes a inputfile and generates the output for all the cases
        /// </summary>
        /// <param name="lines"></param>
        /// <returns></returns>
        public static string ProcessAll(string[] lines)
        {
            // Anzahl der Tests steht immer in der ersten Zeile
            var caseCount = int.Parse(lines[0]);

            // Testfälle splitten
            var cases = CreateCases(lines, caseCount);

            var sbResult = new StringBuilder();

            var counter = 1;
            foreach (var job in cases)
            {
                var result = ExcecuteSingleCase(job);

                sbResult.Append("Case #" + counter++ + ":");

                if (ShowResultInOneLine)
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
            return sbResult.ToString();
        }

        /// <summary>
        /// Runs one input case to get the correct output for it
        /// </summary>
        public static string ExcecuteSingleCase(string input)
        {
            var number = long.Parse(input);

            var result = CalcSteps(1, number) + 1;

            return result.ToString();
        }

        private static long CalcSteps(long cur, long number)
        {
            if (cur == number) return 0;
            if (cur + 1 == number) return 1;
            if (cur + 2 == number) return 2;
            if (cur + 3 == number) return 3;
            if (cur + 4 == number) return 4;
            if (cur + 5 == number) return 5;
            if (cur + 6 == number) return 6;
            if (cur + 7 == number) return 7;
            if (cur + 8 == number) return 8;
            if (cur + 9 == number) return 9;
            if (cur + 10 == number) return 10;

            var swap = Swap(cur);
            if (swap > number || swap <= cur)
            {
                return CalcSteps(cur + 1, number) + 1L;
            }

            long counter = cur + 1L;
            var nextSwap = Swap(counter);

            while (nextSwap > swap && nextSwap < number && nextSwap > cur)
            {
                swap = nextSwap;
                nextSwap = Swap(++counter);
            }

            return CalcSteps(swap, number) + (counter - cur);
        }

        public static long Swap(long number)
        {
            var result = 0L;

            while (number > 0)
            {
                var r = number % 10;
                result = result * 10 + r;
                number = number / 10;  //left = Math.floor(left / 10); 
            }

            return result;
        }

        public static IEnumerable<String> CreateCases(string[] caseLines, int caseCount)
        {
            if (EachCaseHasSameLineCount)
            {
                var linesPerCase = (caseLines.Length - 1) / caseCount;
                return CreateCases(caseLines, (x) => linesPerCase, caseCount);
            }

            /* First Line determines linecount for each case
             * -> This line isn't included in the resulting cases
             * Example: First line contains Linecount  */
            return CreateCases(caseLines, (x) => int.Parse(x) + 1, caseCount);

            /* Second or the combination of the first two lines determines the linecount for each case
             * -> the two lines are included in the resulting cases
             * Example: second line contains following linecount + the first and second line itself */
            return CreateCases(caseLines, (fst, snd) => int.Parse(snd) + 2, caseCount);
        }

        /// <summary>
        /// First Line determines linecount for each case
        /// </summary>
        public delegate int DetermineCaseLineLength(string firstCaseLine);

        /// <summary>
        /// Second or the combination of the first two lines determines the linecount for each case
        /// Example here: https://code.google.com/codejam/contest/32016/dashboard#s=p1
        /// </summary>
        public delegate int DetermineCaseLineLengthFromSndLine(string fstLine, string sndLine);

        /// <summary>
        /// splitts the input into single cases
        /// the first line doesn't belong to the input for a case
        /// </summary>
        public static IEnumerable<String> CreateCases(string[] caseLines, DetermineCaseLineLength detLength, int caseCount)
        {
            var curLine = 1; // 1 wegen der Zeile mit der Anzahl der Tests

            for (var i = 0; i < caseCount; i++)
            {
                var curSb = new StringBuilder();

                var lineCount = detLength(caseLines[curLine]);
                var count = 0;

                do
                {
                    curSb.Append(caseLines[curLine++]);
                    if (++count < lineCount)
                    {
                        curSb.AppendLine();
                    }
                }
                while (count < lineCount);

                yield return curSb.ToString();
            }
        }

        /// <summary>
        /// splitts the input into single cases
        /// the first and second line belong to the input for a case
        /// </summary>
        public static IEnumerable<String> CreateCases(string[] caseLines, DetermineCaseLineLengthFromSndLine detLength, int caseCount)
        {
            var curLine = 1; //1 => Skip the line with the Testcaseammount

            for (var i = 0; i < caseCount; i++)
            {
                var curSb = new StringBuilder();

                var lineCount = detLength(caseLines[curLine++], caseLines[curLine++]);

                curLine -= 2; // Both lines need to be included

                var count = 0;

                do
                {
                    curSb.Append(caseLines[curLine++]);
                    if (++count < lineCount)
                    {
                        curSb.AppendLine();
                    }
                }
                while (count < lineCount);

                yield return curSb.ToString();
            }
        }
    }
}
