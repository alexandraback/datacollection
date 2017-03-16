using System;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam2012
{
    class ProblemA
    {
        static void Main(string[] args)
        {
            StringBuilder output = new StringBuilder();

            string[] lines = File.ReadAllLines("A-small-attempt4.in");
            
            for (int i = 1; i < lines.Length; i++)
            {
                string result = "";

                string[] values = lines[i].Split(' ');
                int[] points = new int[values.Length - 1];
                for (int j = 1; j < values.Length; j++)
                {
                    points[j - 1] = Int32.Parse(values[j]);
                }

                int count = points.Length;
                int sum = points.Sum();

                double target = 2.0 / count * sum;
                
                int count2 = 0;
                double sum2 = 0;

                foreach (double p in points)
                {
                    if (p < target)
                    {
                        count2++;
                        sum2 += p;
                    }
                }
                
                if (count2 != count)
                    target = 1.0 / count2 * (sum + sum2);

                foreach (double p in points)
                {
                    double r = (target - p) / sum * 100;
                    result += (r < 0 ? 0 : r).ToString("0.000000") + " ";
                }
                
                output.AppendFormat("Case #{0}: {1}", i, result.TrimEnd(' '));
                output.AppendLine();
            }

            File.WriteAllText("A-small-attempt4.out", output.ToString());
        }
    }
}
