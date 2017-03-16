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
            string file = "C-small-attempt0";
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
            int a = int.Parse(values[0]);
            int b = int.Parse(values[1]);
            int digits = a.ToString().Length;

            int cnt = 0;
            for (int m = a+1; m <= b; m++)
            {
                Dictionary<int, bool> alreadySeen = new Dictionary<int, bool>();
                for (int j = 1; j < digits; j++)
                {
                    int n = GetShiftedNumber(m, j);
                    if (n < m && n >= a && !alreadySeen.ContainsKey(n))
                    {
                        cnt++;
                        alreadySeen[n] = true;
                    }
                }
            }
            return cnt.ToString();
        }

        private static int GetShiftedNumber(int n, int shift) {
            string actualNumber = n.ToString();
            string shiftedNumber = actualNumber.Substring(actualNumber.Length - shift) +
                                    actualNumber.Substring(0, actualNumber.Length - shift);
            return int.Parse(shiftedNumber);
        }




    }
}
