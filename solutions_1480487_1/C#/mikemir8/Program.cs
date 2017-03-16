using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            ProcessFile();
        }

        public static void ProcessFile()
        {
            string file = "A-large";
            string path = @"C:\Users\Mike\Desktop\GoogleOutput\";
            StreamReader sr = new StreamReader(path + file + ".in");
            StreamWriter sw = new StreamWriter(path + file + ".out");

            int cases = int.Parse(sr.ReadLine());
            for (int i = 0; i < cases; i++)
            {
                string res = ProcessCase(sr);
                sw.WriteLine(string.Format("Case #{0}: {1}", i + 1, res));
            }
            sw.Flush();
            sw.Close();
        }


        private static string ProcessCase(StreamReader sr)
        {
            string[] values = sr.ReadLine().Split(' ');
            int n = int.Parse(values[0]);
            List<int> scores = new List<int>();
            int total = 0;
            for (int i = 0; i < n; i++)
            {
                scores.Add(int.Parse(values[i + 1]));
                total += scores[i];
            }

            double min = ((double)total * 2) / n;

            int n2 = 0;
            int total2 = 0;
            List<string> results = new List<string>();
            for (int i = 0; i < n; i++)
            {
                double pct = (min - scores[i]) * 100 / total;
                if (scores[i] <= min) {
                    n2++;
                    total2 += scores[i];
                }
            }

            double min2 = ((double)total2 + (double)total) / n2;
            for (int i = 0; i < n; i++)
            {
                double pct = 0;
                if (scores[i] > min2)
                    pct = 0;
                else
                    pct = (min2 - scores[i]) * 100 / total;
                results.Add(pct.ToString());
            }
            return string.Join(" ", results.ToArray());
            //int length = int.Parse(values[1]);

        }




    }
}
