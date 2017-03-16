using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace GCJR1BA {
    class Program {
        string Solve(int[] vals1) {
            double[] vals = new double[vals1.Length - 1];
            double tot = 0;
            for (int i = 0; i < vals1.Length - 1; ++i) {
                vals[i] = vals1[i + 1];
                tot += vals[i];
            }
            double[] vals2 = new double[vals.Length];
            for (int i = 0; i < vals1.Length - 1; ++i) {
                vals[i] /= tot;
                vals2[i]=vals[i];
            }
            Array.Sort(vals2);
            double sumsofar = 0;
            int n;
            for (n=0; n<vals.Length-1; ++n) {
                sumsofar += vals2[n];
                if (vals2[n + 1] > (sumsofar+1) / (n + 1)) break;
            }
            n++;
            if (n == vals.Length) sumsofar = 1;
            string result = "";
            for (int i = 0; i < vals.Length; ++i) {
                if (vals[i] > (sumsofar + 1) / n) result += " 0.0";
                else result += " " + ((sumsofar + 1) / n - vals[i]) * 100;
            }
            return result.Trim();
        }
        Program() {
            int T = int.Parse(Console.ReadLine());
            for (int dd = 0; dd < T; ++dd) {
                int[] values = Console.ReadLine().Split().Select(p => int.Parse(p)).ToArray();
                Console.WriteLine("Case #{0}: {1}", dd + 1, Solve(values));
            }
            //Console.ReadLine();
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
