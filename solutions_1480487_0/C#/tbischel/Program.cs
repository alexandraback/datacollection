using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            const string inputFile = @"C:\Users\tbischel\Desktop\GoogleCodeJam2012\ProblemA\Input\A-small-attempt0.in";
            const string outputFile = @"C:\Users\tbischel\Desktop\GoogleCodeJam2012\ProblemA\Output\Small-1.txt";

            var sr = new StreamReader(inputFile);
            var sw = new StreamWriter(outputFile);

            int testCases = int.Parse(sr.ReadLine());
            for (int i = 1; i <= testCases; i++)
            {
                var testCase = SafetyInNumbers.ParseCase(sr);
                var result = "Case #" + i + ": " + testCase.SolveCase();
                sw.WriteLine(result);
            }
            sw.Flush();
            sw.Close();
        }
    }

    public class SafetyInNumbers
    {
        public int N { get; set; }
        public List<int> S { get; set; }

        public static SafetyInNumbers ParseCase(StreamReader sr)
        {
            var parameters =
                sr.ReadLine()
                .Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                .Select(s => int.Parse(s));

            var n = parameters.First();
            var si = parameters.Skip(1).ToList();

            return new SafetyInNumbers { S = si, N = n };
        }

        public String SolveCase()
        {
            double totalPoints = S.Sum();
            var currentFraction = S
                .Select((s, i) => new { indx = i, fract = s / totalPoints })
                .OrderBy(s => s.fract)
                .ToList();

            Dictionary<int, double> result = new Dictionary<int, double>();

            var remainingAudienceVote = 1.0;
            for (int i = 0; i < N - 1; i++)
            {
                var me = currentFraction[i];
                var next = currentFraction[i + 1];
                var diff = next.fract - me.fract;

                var myvote = Math.Min(diff, remainingAudienceVote/(i + 1));
                remainingAudienceVote -= myvote*(i + 1);
                result[me.indx] = myvote;
            }
            result[currentFraction.Last().indx] = remainingAudienceVote/N;
            for (int i = N - 2; i >= 0; i--)
            {
                var j1 = currentFraction[i].indx;
                var j2 = currentFraction[i + 1].indx;
                result[j1] += result[j2];
            }
            return String.Join(" ", Enumerable.Range(0, N).Select(i => (100*result[i]).ToString()));
        }
    }
}
