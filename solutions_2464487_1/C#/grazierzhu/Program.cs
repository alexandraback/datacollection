using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Numerics;

namespace CodeJam
{
    class Program
    {
        static string[] data;
        static int index = 0;
        static string Next()
        {
            return data[index++];
        }

        static int NextInt()
        {
            return int.Parse(Next());
        }

        static void Main(string[] args)
        {
            string fn = args.Length > 0 ? args[0] : "C:\\temp\\unittest.in";
            data = File.ReadAllText(fn).Replace('\r', ' ').Replace('\n', ' ').Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            StringBuilder output = new StringBuilder(5000);

            int caseCount = NextInt();
            for (int cas = 0; cas < caseCount; cas++)
            {
                //set up test case
                double r = double.Parse(Next());
                double t = double.Parse(Next());
                //output
				Console.WriteLine("Done case #" + (cas + 1));
                output.AppendLine(string.Format("Case #{0}: {1}", cas + 1, Solve(r, t)));
            }

            File.WriteAllText(fn + ".out", output.ToString());
        }

        static int Solve(double r, double t)
        {
            double r2 = (2 * r - 1);
            return (int)((Math.Sqrt(r2 * r2 + 8 * t) - r2) / 4);
        }
    }
}
