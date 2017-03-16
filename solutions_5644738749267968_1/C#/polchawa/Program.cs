using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

namespace DeceitfulWar
{
    class Program
    {
        private static class InputParser
        {
            private static string ReadLine()
            {
                var lineStr = Console.ReadLine();
                if (string.IsNullOrEmpty(lineStr))
                    throw new Exception("Missing line");
                return lineStr;
            }

            private static double ParseDoubleFromStr(string str)
            {
                double result;
                if (!double.TryParse(str, NumberStyles.Any, CultureInfo.InvariantCulture, out result))
                    throw new Exception(string.Format("Invalid string: {0}", str));
                return result;
            }

            private static IEnumerable<string> ReadLineFragments()
            {
                return ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            }

            public static IEnumerable<double> ReadLineDoubles()
            {
                return ReadLineFragments().Select(ParseDoubleFromStr);
            }

            private static int ParseIntFromStr(string str)
            {
                int result;
                if (!int.TryParse(str, out result))
                    throw new Exception(string.Format("Invalid string: {0}", str));
                return result;
            }

            public static int ReadLineInt()
            {
                var lineStr = ReadLine();

                return ParseIntFromStr(lineStr);
            }
        }


        static void Main(string[] args)
        {
            var testCases = InputParser.ReadLineInt();
            for (var test = 1; test <= testCases; ++test)
            {
                var n = InputParser.ReadLineInt();

                var naomi = ReadBlocks(n);
                var ken = ReadBlocks(n);

                var warScore = SolveWar(naomi, ken);
                var deceitfulWarScore = SolveDeceitfulWar(naomi, ken);

                Console.WriteLine("Case #{0}: {1} {2}", test, deceitfulWarScore, warScore);
            }
        }



        private static double[] ReadBlocks(int n)
        {
            var naomi = InputParser.ReadLineDoubles().OrderBy(x => x).ToArray();
            if (naomi.Length != n)
                throw new Exception("Invalid input");
            return naomi;
        }


        private static double GetReplyForMove(double candidate, double[] ken)
        {
            if (ken[ken.Length - 1] < candidate)
                return ken[0];
            return ken.FirstOrDefault(x => x > candidate);
        }

        private static int SolveWar(double[] naomi, double[] ken)
        {
            var score = 0;

            foreach (var move in naomi)
            {
                var reply = GetReplyForMove(move, ken);

                if (reply < move)
                    score++;

                ken = ken.Where(x => x != reply).ToArray();
            }
            return score;
        }


        private static int SolveDeceitfulWar(double[] naomi, double[] ken)
        {
            int kenStart = 0, score = 0;

            foreach (var move in naomi)
            {
                if (move > ken[kenStart])
                {
                    score++;
                    kenStart++;
                }
            }
            return score;
        }
    }
}
