using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2012QC {
    class Program {
        int start = 1111, end = 2222;
        int numdigits = 4;
        int recycle(int n) {
            int m = n % 10;
            for (int i = 1; i < numdigits; ++i) m *= 10;
            return m + n / 10;
        }
        List<Tuple<int, int>> cycles;
        void findCycles(int n) {
            int cur = n, count = 1;
            while(true) {
                cur = recycle(cur);
                if (cur == n) break;
                if (cur >= start && cur <= end) {
                    if (cur < n) return;    // must have been already covered
                    count++;
                }
            }
            if (count > 1) {
                lock (cycles) {
                    cycles.Add(new Tuple<int, int>(cur, count));
                }
            }
        }
        int nPairs() {
            int count = 0;
            foreach (var t in cycles) {
                int n = t.Item2;
                count += n * (n - 1) / 2;
            }
            return count;
        }
        int getResult(int start, int end) {
            this.start = start; this.end = end;
            numdigits = start.ToString().Length;
            cycles = new List<Tuple<int, int>>();
            Parallel.For(start, end, i => {
                findCycles(i);
            });
            return nPairs();
        }
        Program() {
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; ++i) {
                int[] inputs = Console.ReadLine().Split().Select(p => int.Parse(p)).ToArray();
                Console.WriteLine("Case #{0}: {1}", i+1, getResult(inputs[0], inputs[1]));
            }
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
