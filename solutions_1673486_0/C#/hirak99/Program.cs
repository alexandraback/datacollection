using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJR1AA {
    class Program {
        float solve(int[] ab, float[] probs) {
            float minexp = 1 + ab[1] + 1;
            for (int i = 0; i <= ab[0]; ++i) {
                // i is keys to leave
                float probcorrect = 1;
                for (int j = 0; j < i; ++j)
                    probcorrect *= probs[j];
                int corr, incorr;
                if (i == ab[1]) corr = 1; else corr = (ab[0] - i) * 2 + (ab[1]-ab[0]) + 1;
                incorr = (ab[0] - i) * 2 + (ab[1] - ab[0]) + 1 + ab[1] + 1;
                float exp = probcorrect * corr + (1 - probcorrect) * incorr;
                if (exp < minexp) minexp = exp;
            }
            return minexp;
        }
        Program() {
            int n = int.Parse(Console.ReadLine());
            for (int dd = 0; dd < n; ++dd) {
                int[] ab = Console.ReadLine().Split().Select(a => int.Parse(a)).ToArray();
                float[] probs = Console.ReadLine().Split().Select(a => float.Parse(a)).ToArray();
                Console.WriteLine("Case #{0}: {1}", dd + 1, solve(ab, probs));
            }
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
