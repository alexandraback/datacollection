using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ2012QB {
    class Program {
        int canBeatReqd(int total, int reqdPoints) {
            int result = 0;
            int max;
            // apart
            // 002,012,022
            if (total % 3 == 2) max = total / 3 + 2;
            else if (total % 3 == 0) max = total / 3 + 1;
            else max = total / 3 + 1;
            if (max >= reqdPoints) result += 2;
            // not apart
            // 000,001,011
            if (total % 3 == 0) max = total / 3;
            else if (total % 3 == 1) max = total / 3 + 1;
            else max = total / 3 + 1;
            // i.e. if mod 3 is 0 or 2, then max can be one more
            if (max >= reqdPoints) result += 1;
            // 0 - cannot beat score
            // 1 - can beat score if not surprising
            // 2 - can beat score only if surprising
            // 3 - will beat score either way
            return result;
        }
        void test() {
            for (int i = 0; i < 30; ++i) {
                Console.WriteLine("{0}: {1}", i, canBeatReqd(i,1));
            }
            Console.ReadLine();
            // form the above test, it was clear that for a given target, following is true -
            // a) total = (target-1)*3 or (target-1)*3-1 needs apart scores to beat
            // b) total < (target-1)*3-1 cannot beat
            // c) total > (target-1)*3 will beat anyway
        }
        Program() {
            //test(); return;
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; ++i) {
                var inputs = Console.ReadLine().Split().Select(kk => int.Parse(kk)).ToArray();
                int N = inputs[0], S=inputs[1], p=inputs[2];
                int beats = 0, beatsIfApart=0;
                for (int j = 3; j < 3 + N; ++j) {
                    int total = inputs[j];
                    // only total of 2 onwards can be apart
                    if (total > (p - 1) * 3) beats++;
                    else if (total>1 && total >= (p - 1) * 3 - 1) beatsIfApart++;
                }
                int totalBeats = beats + Math.Min(beatsIfApart, S);
                Console.WriteLine("Case #{0}: {1}", i + 1, totalBeats);
            }
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
