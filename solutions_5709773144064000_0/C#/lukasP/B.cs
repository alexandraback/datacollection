using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Globalization;
using System.Threading;

class Problem
{
    private static StreamReader reader;

    static string Solve()
    {
        string[] ss = reader.ReadLine().Split();
        double c = double.Parse(ss[0]);
        double f = double.Parse(ss[1]);
        double x = double.Parse(ss[2]);

        double sum = 0;
        double res = x / 2 + 47;
        foreach (int i in Enumerable.Range(0, (int)x))
        {
            double speed = 2 + f * i;
            res = Math.Min(res, sum + x / speed);
            sum += c / speed;
        }
        return string.Format("{0:0.############}", res);
    }

    public static void Main ()
    {
        Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;
        var bs = new BufferedStream(Console.OpenStandardInput());
        reader = new StreamReader(bs);

        foreach (int i in Enumerable.Range(1, int.Parse(reader.ReadLine())))
            Console.WriteLine("Case #{0}: {1}", i, Solve());
    }
}
