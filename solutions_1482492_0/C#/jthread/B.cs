using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class B
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);

            string[] p = Console.ReadLine().Split();
            double D = double.Parse(p[0]);
            int N = int.Parse(p[1]);
            int A = int.Parse(p[2]);
            double[] t = new double[N];
            double[] x = new double[N];
            for (int i = 0; i < N; i++)
            {
                p = Console.ReadLine().Split();
                t[i] = double.Parse(p[0]);
                x[i] = double.Parse(p[1]);
            }

            Console.WriteLine("Case #" + CASE + ":");
            p = Console.ReadLine().Split();
            for (int i = 0; i < A; i++)
            {
                if (N > 2)
                {
                    Console.WriteLine("TODO");
                    continue;
                }
                double a = double.Parse(p[i]);
                double mytime = Math.Sqrt(2.0 * D / a);
                double histime = x[0] >= D ? 0 : t[1] * (D / x[1]);
                double ret = Math.Max(histime, mytime);
                Console.WriteLine(ret);
            }
        }
    }
}
