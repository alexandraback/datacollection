namespace GoogleCodeJam
{
    using System;
    using System.Linq;

    internal static class Program
    {
        private static void Main(string[] args)
        {
            int t = int.Parse(Console.In.ReadLine());
            foreach (var caseNum in Enumerable.Range(0, t))
            {
                var solution = new Solver20141Ba(Console.In).Solve();
                Console.Out.WriteLine("Case #{0}:{1}", caseNum + 1, solution);
            }
        }
    }

    public interface ISolution
    {
    }
}