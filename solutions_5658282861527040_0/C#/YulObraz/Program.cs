using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1B_Second {
    class Program {
        static void Main(string[] args) {
            int testCount = Console.In.ReadLine().Split(' ').Select(it => Int32.Parse(it)).First();
            for(int i = 0; i < testCount; i++) {
                var test = new Test();
                test.Load();
                Console.Write("Case #{0}: ", i + 1);
                Console.Error.Write("Case #{0}: ", i + 1);
                Console.WriteLine(test.Solve());
                Console.Error.WriteLine(test.Solve());
            }
            //Console.ReadKey();
        }

    }
    public class Test {
        int A;
        int B;
        int K;
        string Ks;
        string As;
        string Bs;
        public void Load() {
            var p = Console.In.ReadLine().Split(' ').Select(it => Int32.Parse(it));
            A = p.First();
            B = p.Skip(1).First();
            K = p.Last();
            if(B > A) {
                int temp = B;
                B = A;
                A = temp;
            }
            As = Convert.ToString(A, 2);
            Bs = Convert.ToString(B, 2);
            Ks = Convert.ToString(K, 2);
        }
        
        /*long f(int as_length) {
            long n = 1;
            for(int i = As.Length; i >Ks.Length; i--) {
                long m = 1 << i;

                
            }
            return result;
        }*/
        long calc() {
            long sum = 0;
            for(int i = 0; i < A; i++) {
                for(int j = 0; j < B; j++) {
                    if((i & j) < K) {
                        sum++;
                    }
                }
            }
            return sum;
        }
        public string Solve() {
            return (calc()).ToString();
            //return ((long)A * (long)B - calc()).ToString();
        }

    }
}
