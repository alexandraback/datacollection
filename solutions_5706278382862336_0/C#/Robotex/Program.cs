using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Globalization;

namespace Magic_Trick
{
    class Program
    {
        static Int64 gcd(Int64 a,Int64 b)
        {
            if (a == 0)
                return b;
            while (b != 0)
            {
                if (a > b)
                {
                    a = a - b;
                }
                else
                {
                    b = b - a;
                }
            }

            return a;
        }

        static void Main(string[] args)
        {
            string inputPath = @"input.txt";
            string outputPath = @"output.txt";
            if (!File.Exists(inputPath))
            {
                Console.WriteLine("Missing input file!");
                return;
            }
            if (File.Exists(outputPath))
                File.Delete(outputPath);
            using (StreamReader sr = File.OpenText(inputPath))
            {
                int T = int.Parse(sr.ReadLine());
                for (int testCase = 0; testCase < T; testCase++)
                {
                    string[] tokens = sr.ReadLine().Split('/');
                    int P = int.Parse(tokens[0]);
                    int Q = int.Parse(tokens[1]);

                    Int64 g = gcd(P, Q);
                    double p = P / g;
                    double q = Q / g;
                    double x = q / p;
                    double y = Math.Log(q) / Math.Log(2);

                    double temp = Math.Ceiling(y);

                    using (StreamWriter sw = File.AppendText(outputPath))
                    {
                        if (temp != y)
                            sw.WriteLine("Case #" + (testCase + 1) + ": impossible");
                        else
                        {
                            temp = Math.Ceiling(Math.Log(x) / Math.Log(2));
                            sw.WriteLine("Case #" + (testCase + 1) + ": " + temp.ToString());
                        }
                    }
                }
            }
        }
    }
}
