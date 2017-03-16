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
            const string inputFile = @"E:\Visual Studio Projects\Google Code Jam\cj2013\GoogleCodeJam1B\ProblemA\Input\A-small-attempt0.in";
            const string outputFile = @"E:\Visual Studio Projects\Google Code Jam\cj2013\GoogleCodeJam1B\ProblemA\Output\small.out";

            var sr = new StreamReader(inputFile);
            var sw = new StreamWriter(outputFile);

            int testCases = int.Parse(sr.ReadLine());
            for (int i = 1; i <= testCases; i++)
            {
                var testCase = Osmos.ParseCase(sr);
                var result = "Case #" + i + ": " + testCase.SolveCase();
                sw.WriteLine(result);
            }
            sw.Flush();
            sw.Close();
        }
    }

    public class Osmos
    {
        public int A { get; set; }
        public int N { get; set; }
        public List<int> Motes { get; set; }

        public static Osmos ParseCase(StreamReader sr)
        {
            var parameters = sr.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                .Select(s => int.Parse(s)).ToList();

            var a = parameters.First();
            var n = parameters.Last();
            var motes = sr.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                .Select(s => int.Parse(s)).OrderBy(s => s).ToList();

            return new Osmos { A = a, N = n, Motes = motes };
        }

        public String SolveCase()
        {
            int result = Absorb(A, Motes);
            return result.ToString();
        }

        public int Absorb(int size, List<int> remaining)
        {
            if (remaining.Count == 0)
                return 0;

            if (size > remaining[0])
                return Absorb(size + remaining[0], remaining.Skip(1).ToList());

            if (size <= 1)
                return remaining.Count;

            return Math.Min(remaining.Count, 1 + Absorb(size + size - 1, remaining));
        }
    }
}
