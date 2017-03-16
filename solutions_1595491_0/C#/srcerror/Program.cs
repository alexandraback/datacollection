using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Dancing
{
    class Program
    {
        const string InputPath = @"d:\Work\Current\CodeJam\2012\Dancing\B-small-attempt0.in";
        const string OutputPath = @"d:\Work\Current\CodeJam\2012\Dancing\B-small-attempt0.out";


        static void Main(string[] args)
        {

            var sr = new StreamReader(InputPath);
            var sw = new StreamWriter(OutputPath);

            int N = Int32.Parse(sr.ReadLine());
            for (int n = 1; n <= N; n++)
            {
                var x = SolveNextInput(sr);

                sw.WriteLine(GetCaseSolutionString(x, n));

            }
            sr.Close();
            sw.Close();
        }

        private static string GetCaseSolutionString(int result, int n)
        {
            return string.Format("Case #{0}: {1}", n, result);
        }

        private static int SolveNextInput(StreamReader sr)
        {
            string phrase = sr.ReadLine();
            var nums = phrase.Split(' ').Select(x => Int32.Parse(x));
            int N = nums.First();
            int S = nums.Skip(1).First();
            int p = nums.Skip(2).First();
            var vals = nums.Skip(3).OrderBy(x => x).ToList();

            int boundaryS = p + 2*(Math.Max(p - 2, 0));
            int boundaryA = p + 2*(Math.Max(p - 1, 0));

            int result = 0;

            foreach (var val in vals)
            {
                if (val >= boundaryA)
                {
                    result++;
                }
                else if (val >= boundaryS && S > 0)
                {
                    S--;
                    result++;
                }
            }

            return result;
        }

    }
}
