using System;
using System.Diagnostics;

namespace GoogleCodeJam
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var sw = Stopwatch.StartNew();

            var problem = new ProblemD(@"..\..\_data\D-large.in");
            problem.Solve();

            sw.Stop();
            Console.WriteLine("Done in {0}", sw.Elapsed);
            Console.ReadKey();
        }
    }
}
