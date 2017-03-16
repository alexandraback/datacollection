using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace gcj2012 {
    public static class QRC {
        public const string Round = "QR";
        public const string Problem = "C";
        //public const string Type = "sample";
        public const string Type = "small";
        //public const string Type = "large";

        public static void Solve() {
            const string inputFile = Round + Problem + "-" + Type + ".in";
            const string outputFile = Round + Problem + "-" + Type + ".out";

            var reader = new StreamReader(inputFile);
            TextWriter tw = new StreamWriter(outputFile);

            string line = reader.ReadLine();
            int N=int.Parse(line);
            for (int i = 0; i < N; i++) {
                line = reader.ReadLine();
                var valoriInput = line.Split(' ');
                int A = int.Parse(valoriInput[0]);
                int B = int.Parse(valoriInput[1]);
                long res = Calc(A, B);

                String outq = res+"";
                String Case="Case #" + (i+1).ToString() + ": ";
                String output = Case + outq;
                tw.WriteLine(output);
            }

            tw.Close();
            reader.Close();

        }


        public static int Calc(int A, int B)
        {
            int res = 0;
            
            for (int j = A; j <= B; j++)
            {
                string s = j.ToString();
                var dict = new HashSet<int>();

                for (int i = 1; i < s.Length; i++)
                {
                    var sa = s.Substring(i) + s.Substring(0, i);
                    int k = int.Parse(sa);
                    if (k<=j) continue;
                    if (k>B) continue;
                    dict.Add(k);
                }
                res += dict.Count;
            }

            return res;
        }


    }
}
