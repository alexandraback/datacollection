using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LotteryGame {
    class Program {
        static void Main(string[] args) {
            using (var reader = new StreamReader("B-small-attempt0.in"))
            using (var writer = new StreamWriter("B-small-attempt0.out")) {
                int tests = int.Parse(reader.ReadLine());
                for (int test = 1; test <= tests; test++) {
                    SolveTest(reader, writer, test);
                }
            }
        }

        private static void SolveTest(StreamReader reader, StreamWriter writer, int test) {
            var input = reader.ReadLine().Split().Select(int.Parse).ToArray();
            int A = input[0], B = input[1], K = input[2];
            int ans = 0;
            for (int i = 0; i < A; ++i)
                for (int j = 0; j < B; ++j)
                    if ((i & j) < K)
                        ++ans;
            writer.WriteLine("Case #{0}: {1}", test, ans);
        }
    }
}
