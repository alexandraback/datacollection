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
            string file = "B-large";
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
            int s = int.Parse(values[1]);
            int p = int.Parse(values[2]);
            List<int> scores = new List<int>();
            for (int i = 3; i < values.Length; i++)
            {
                scores.Add(int.Parse(values[i]));
            }

            int min = (p * 3) - 2;
            int max = 0;
            //scores.Sort();
            for (int i = scores.Count -1; i>=0; i--) {
                if (scores[i] >= min)
                {
                    max++;
                    continue;
                }
                if (s > 0 && scores[i] >= Math.Max(min-2,p)) {
                    max++;
                    s--;
                }
            }

            return max.ToString();
        }




    }
}
