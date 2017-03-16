using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Cookie
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            int T = Convert.ToInt32(Console.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                var line = Console.ReadLine().Split(' ').Select(token => Convert.ToDouble(token)).ToList();
                double C = line[0], F = line[1], X = line[2], Q = 0, R = 2, S = X / R, min = S;
                for (int n = 1; n <= X && min > Q; ++n)
                {
                    Q += C / R;
                    R += F;
                    S = Q + X / R;
                    min = Math.Min(min, S);
                }
                Console.WriteLine("Case #{0}: {1}", t, min);
            }
        }
    }
}
