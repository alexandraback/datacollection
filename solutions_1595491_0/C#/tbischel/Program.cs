using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            const string inputFile = @"C:\Users\Tyler\Desktop\GoogleCodeJam2012\ProblemB\Input\B-small-attempt3.in";
            const string outputFile = @"C:\Users\Tyler\Desktop\GoogleCodeJam2012\ProblemB\Output\Small.txt";

            //const string inputFile = @"C:\Users\Tyler\Desktop\GoogleCodeJam2012\ProblemB\Input\Test.txt";
            //const string outputFile = @"C:\Users\Tyler\Desktop\GoogleCodeJam2012\ProblemB\Output\Test.txt";

            var sr = new StreamReader(inputFile);
            var sw = new StreamWriter(outputFile);

            int testCases = int.Parse(sr.ReadLine());
            for (int i = 1; i <= testCases; i++)
            {
                var testCase = DancingWiththeGooglers.ParseCase(sr);
                var result = "Case #" + i + ": " + testCase.SolveCase();
                sw.WriteLine(result);
            }
            sw.Flush();
            sw.Close();
        }
    }

    public class DancingWiththeGooglers
    {
        public static Dictionary<int, Tuple<int, int>> BestPossibleHighScores = BestPossibleHigh();

        public int NumGooglers { get; set; }
        public int Surprises { get; set; }
        public int MaxScore { get; set; }
        public List<int> Scores { get; set; }
 
        public static DancingWiththeGooglers ParseCase(StreamReader sr)
        {
            var parameters =
                sr.ReadLine()
                .Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                .Select(st => int.Parse(st))
                .ToList();

            var n = parameters[0];
            var s = parameters[1];
            var p = parameters[2];
            var t = parameters.Skip(3).OrderByDescending(i => i).ToList();

            return new DancingWiththeGooglers { NumGooglers  = n, Surprises = s, MaxScore = p, Scores = t };
        }

        public String SolveCase()
        {
            int ok = 0;
            int surprises = Surprises;

            foreach (int score in Scores)
            {
                if (NotSurprise(score) >= MaxScore)
                {
                    ok++;
                }
                else if (Surprise(score) >= MaxScore && surprises > 0)
                {
                    ok++;
                    surprises--;
                }
            }
            return ok.ToString();
        }

        public int NotSurprise(int ti)
        {
            return BestPossibleHighScores[ti].Item1;
        }

        public int Surprise(int ti)
        {
            return BestPossibleHighScores[ti].Item2;
        }

        public static Dictionary<int, Tuple<int, int>> BestPossibleHigh()
        {
            var result = new Dictionary<int, Tuple<int, int>>();
            for(int i=0; i<=30; i++)
            {
                result[i] = BestPossibleHigh(i);
            }
            return result;
        }

        public static Tuple<int, int> BestPossibleHigh(int ti)
        {
            var surprise = -1;
            var notsurprise = -1;
            var high = ti/3 + 1;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    var triple = new List<int> { high - i, high - j, ti - (2*high - i - j) };
                    var range = triple.Max() - triple.Min();
                    var max = triple.Max();
                    if(triple.All(n => n >= 0))
                    {
                        if (range < 2)
                            notsurprise = Math.Max(notsurprise, max);
                        else if (range == 2)
                            surprise = Math.Max(surprise, max);
                    }
                }
            }
            return new Tuple<int, int>(notsurprise, surprise);
        }
    }
}
