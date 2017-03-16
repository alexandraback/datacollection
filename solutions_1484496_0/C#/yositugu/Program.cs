using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace _1B_C
{
    class Program
    {
        //private const string FILE_NAME = "../../test.txt";
        private const string FILE_NAME = "../../small.txt";
        //private const string FILE_NAME = "../../large.txt";

        private const string OUTPUT = "../../out.txt";

        static void Main(string[] args)
        {
            var eval = new Eval();
            var res = "";

            // Test Case
            if ((res = eval.eval(new[] { "20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20", }, 0)) != "\n1 2\n3") throw new Exception(res);
            if ((res = eval.eval(new[] { "4 0 1 4 5", }, 0)) != "\n1 4\n5") throw new Exception(res);
            if ((res = eval.eval(new[] { "3 1 3 5", }, 0)) != "Impossible") throw new Exception(res);
            //if ((res = eval.eval(new[] { "20 120 266 858 1243 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600", }, 0)) != "\n3117 4210 4943\n2328 2894 7048") throw new Exception(res);
            //return;

            File.Delete(OUTPUT);
            var lines = File.ReadAllLines(FILE_NAME);
            var T = int.Parse(lines[0]);
            var i = 1;

            for (int t = 0; t < T; t++)
            {
                res = eval.eval(lines, i);
                i += 1;

                File.AppendAllText(OUTPUT, string.Format("Case #{0}:{1}\n", t + 1, res));
                //Console.Write(string.Format("Case #{0}: {1}\n", t + 1, res));
            }
        }

        private class Eval
        {
            public int N;
            private List<long> si = new List<long>();

            private string[] lines;
            private int t;

            public string eval(string[] lines, int t)
            {
                this.lines = lines;
                this.t = t;
                string s = small();
                //string l = large();
                //if (s != l) throw new Exception(s + " != " + l);
                return s.ToString();
            }

            /// <summary>工夫する</summary>
            private string large()
            {
                parse();
                return "";
            }

            /// <summary>まともにやる</summary>
            private string small()
            {
                parse();
                var res1 = new List<long>();
                var res2 = new List<long>();

                var sumlist = new List<List<long>>();
                long sum = 0;

                // ビット
                for (long b = 1; b < (1 << N); b++)
                {
                    res1 = new List<long>();
                    sum = getSum(b, res1);
                    if (isContains(sumlist, sum, res1, out res2)) break;
                    sumlist.Add(res1);
                }

                if (res2.Count == 0) return "Impossible";
                return "\n" + res2.Aggregate("", (s, l) => (s + " " + l)).Remove(0, 1) + "\n" + res1.Aggregate("", (s, l) => (s + " " + l)).Remove(0, 1);
            }

            private bool isContains(List<List<long>> sumlist, long sum, List<long> res1, out List<long> res2)
            {
                foreach (var list in sumlist)
                {
                    if (list.Sum() != sum) continue;
                    if (res1.Union(list).Count() != (res1.Count + list.Count)) continue;
                    res2 = list;
                    return true;
                }
                res2 = new List<long>();
                return false;
            }

            private long getSum(long b, List<long> res1)
            {
                long sum = 0;

                for (int i = 0; i < N; i++)
                {
                    if ((b & (1 << i)) == 0) continue;
                    sum += si[i];
                    res1.Add(si[i]);
                }
                return sum;
            }

            /// <summary>変数初期化</summary>
            private void parse()
            {
                this.si.Clear();
                var sa = lines[t].Split(' ');
                this.N = int.Parse(sa[0]);
                for (int i = 0; i < N; i++)
                {
                    si.Add(long.Parse(sa[i + 1]));
                }
            }
        }
    }
}
