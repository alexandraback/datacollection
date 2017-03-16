using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ {
    public class B {
        public static void Run() {
            var sr = new StreamReader(@"C:\gcj\b-small-attempt0.in");
            var sw = new StreamWriter(@"C:\gcj\b-small-attempt0.out");

            var numtestcases = Convert.ToInt64(sr.ReadLine());
            for(long i = 0; i < numtestcases; i++) {
                var line = sr.ReadLine();
                var lineSplit = line.Split(' ');

                long A = Convert.ToInt64(lineSplit[0]);
                long B = Convert.ToInt64(lineSplit[1]);
                long K = Convert.ToInt64(lineSplit[2]);

                long count = 0;
                for(long k = 0; k < K; k++) {
                    for(long a = 0; a < A; a++) {
                        for(long b = 0; b < B; b++) {
                            if((a & b) == k) {
                                count++;
                            }
                        }
                    }
                }
                var outputString = String.Format("Case #{0}: {1}", i + 1, count);
                sw.WriteLine(outputString);
            }
            sr.Close();
            sw.Close();
        }
    }
}
