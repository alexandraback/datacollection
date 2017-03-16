using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;


namespace GCJ2012 {
    internal class R1Aa {
        public static void Main() {
            string filePath = @"C:\Users\shawn.mcclelland\Downloads\A-small-attempt0.in";
            var fileIn = new StreamReader(filePath);
            filePath = filePath.Remove(filePath.Length - 2) + "out";
            var fileOut = new StreamWriter(filePath);

            int totalCase = Convert.ToInt32(fileIn.ReadLine());
            for (int curCase = 0; curCase < totalCase; ++curCase) {
                string[] str = fileIn.ReadLine().Split(new[] {' '}, StringSplitOptions.RemoveEmptyEntries);
                string[] str2 = fileIn.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                fileOut.WriteLine("Case #{0}: {1}", curCase + 1, _Solve(str, str2));
            }
            fileIn.Close();
            fileOut.Close();
            //Console.ReadLine();
        }

        private static string _Solve(string[] str, string[] str2) {
            int A = Convert.ToInt32(str[0]);
            int B = Convert.ToInt32(str[1]);
            var ps = new List<double>();
            double result = 2 + B;
            if (result > A + B + 1) {
                result = A + B + 1;
            }
            int count = 1;
            foreach(string p in str2) {
                ps.Add(Convert.ToDouble(p));
                double tmp = _ExpectedKeystrokes(ps, count, B) + A - count;
                count++;
                if (result > tmp) {
                    result = tmp;
                }
                
            }
            return result.ToString("0.000000");

        }

        private static double _ExpectedKeystrokes(List<double> ps, int A, int B) {
            double psum = 1;
            foreach(double p in ps) {
                psum *= (p);
            }
            //Console.WriteLine(psum.ToString());
            double firstHalf = psum*(B - A + 1);
            double secondHalf = (1 - psum)*(B - A + B + 2);
            //Console.WriteLine(firstHalf.ToString());
            //Console.WriteLine(secondHalf.ToString());
            return psum*(B - A+1) + (1 - psum)*(B - A + B + 2);
        }
    }
}