using System.Globalization;
using System.IO;
using System.Linq;

namespace GoogleCodeJam2014
{
    public class CookieClickerAlpha
    {
        //private const string filename = "B-sample";
        private const string filename = "B-small";
        //private const string filename = "B-large";

        public static void Run()
        {
            var lines = File.ReadAllLines(filename+".in");
            var file = new StreamWriter(filename + ".out");
            var T = int.Parse(lines[0]);

            for (int i = 0; i < T; i++)
            {
                var values = lines[1 + i].Split(' ').Select(s => double.Parse(s, CultureInfo.InvariantCulture.NumberFormat)).ToArray(); 
                double C = values[0];
                double F = values[1];
                double X = values[2];
                var resd = Result(C,F,X);
                var res = resd.ToString("#.0000000", CultureInfo.InvariantCulture.NumberFormat);
                file.WriteLine("Case #" + (i + 1) + ": " + res);
            }

            file.Close();
        }

        public static double Result(double c,double f,double x)
        {
            int maxK = GetK(c,f,x);
            double t = 0.0;

            for (int k = 0; k < maxK; k++)
            {
                t += 1/(2 + (k*f));
            }
            t *= c;

            t += x / (2 + (maxK * f));
            return t;
        }

        public static int GetK(double c, double f, double x)
        {
            if (x <= c) return 0;
            int k = 0;
            double xc = x - c;
            

            double current = 1;
            double next = 0;

            while (next < current)
            {
                double kf2 = 2 + k++ * f;
                current = xc/kf2;
                next = x/(kf2 + f);
            }

            return k-1;
        }

    }
}
