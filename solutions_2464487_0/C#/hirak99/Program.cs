using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1_1 {
    class Program {
        Program() {
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; ++i) {
                BigInteger[] inp = Console.ReadLine().Split().Select(t => new BigInteger(t,10)).ToArray();
                BigInteger N = 1 - 2 * inp[0];
                N = (N + (N*N+8*inp[1]).sqrt()) / 4;
                Console.Out.WriteLine("Case #{0}: {1}", i + 1, N.ToString());
            }
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
