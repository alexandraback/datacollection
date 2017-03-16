using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Codejam
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("in.in");
            StreamWriter sw = new StreamWriter("out.out");
            var t = int.Parse(sr.ReadLine());
            for (int i = 1; i <= t; i++)
            {
                var a = sr.ReadLine().Split('/').Select(double.Parse).ToArray();
                double n = a[0] / a[1];
                int answer = Solve(n, 1);
                sw.WriteLine("Case #" + i + ": " + (answer == -1 ? "impossible" : answer.ToString()));
            }
            sw.Close();
        }
        static int Solve(double n, int count)
        {
            if (count > 40) return -1;
            if (n * 2 == 1) return count;
            if (n * 2 < 1) return Solve(n * 2, count + 1);
            if (Solve(n * 2 - 1, count + 1) != -1) return count;
            return -1;
        }
    }
}
