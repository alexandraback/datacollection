using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GCJ2013
{
    public class Program
    {
        //private const string FILE_NAME = "../../test.txt";
        private const string FILE_NAME = "../../small.txt";
        //private const string FILE_NAME = "../../large.txt";

        private const string OUTPUT = "../../out1AC.txt";

        static void Main(string[] args)
        {
            var eval = new Eval();
            var res = "";

            // Test Case
            //if ((res = eval.eval(new[] { "2 3 4 4", "9 4 36 1", "1 1 1 1", "", }, 0)) != "") throw new Exception(res);
            //if ((res = eval.eval(new[] { "", "", "", "", }, 0)) != "") throw new Exception(res);
            //return;

            File.Delete(OUTPUT);
            var lines = File.ReadAllLines(FILE_NAME);
            var T = int.Parse(lines[0]);
            var l = 1; //行数

            for (int t = 0; t < T; t++)
            {
                res = eval.eval(lines, l);
                l += 1;

                File.AppendAllText(OUTPUT, string.Format("Case #{0}: {1}\n", t + 1, res));
                Console.Write(DateTime.Now.ToShortTimeString() + "." + DateTime.Now.Second + string.Format(" Case #{0}: {1}\n", t + 1, res));
            }
        }

        private class Eval
        {
            public int R; //テストケース数
            public int N; //ランダムに選んだ数値の数
            public int M; //最大値
            public int K; //積の数
            public int[] p; //積

            private string[] lines;
            private int l;

            public string eval(string[] lines, int l)
            {
                this.lines = lines;
                this.l = l;
                string sans = small();
                //string lans = large();
                //if (sans != lans) throw new Exception(sans + " != " + lans);
                return sans.ToString();
                //return lans.ToString();
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
                var res = new StringBuilder();

                for (int r = 0; r < R; r++)
                {
                    parse2(r);
                    res.AppendLine();

                    var s = solve();

                    res.Append(s);
                }

                return res.ToString();
            }

            private string solve()
            {
                // 答えのリスト
                var dic = new SortedDictionary<int, string>() {
                    { 125, "555" }, { 100, "554" }, { 75, "553" }, { 50, "552" },
                    { 80, "544" }, { 60, "543" }, { 40, "542" },
                    { 45, "533" }, { 30, "532" }, { 20, "522" },
                    { 64, "444" }, { 48, "443" }, { 32, "442" },
                    { 36, "433" }, { 24, "432" }, { 16, "422" },
                    { 27, "333" }, { 18, "332" }, { 12, "322" },
                    {1, "222"},
                };
                // 最大値は満たしておく
                var max = p.Max();
                var ans = "";

                if (dic.TryGetValue(max, out ans)) return ans;

                // まず因数分解
                var set = new SortedSet<string>();
                set.Add("2");

                for (int i = 0; i < p.Length; i++)
                {
                    for (int k = 3; k <= M && k <= p[i]; k++)
                    {
                        if (p[i] % k == 0) set.Add(k.ToString());
                    }
                }

                var list = new List<string>(set.Reverse());
                for (int i = list.Count; i < N; i++)
                {
                    list.Add("2");
                }
                
                return string.Join("", list.ToArray(), 0, N);
            }

            /// <summary>変数初期化</summary>
            private void parse2(int r)
            {
                p = new int[K];

                for (int k = 0; k < K; k++)
                {
                    p[k] = int.Parse(lines[l + r + 1].Split(' ')[k]);
                }
            }


            /// <summary>変数初期化</summary>
            private void parse()
            {
                R = int.Parse(lines[l].Split(' ')[0]);
                N = int.Parse(lines[l].Split(' ')[1]);
                M = int.Parse(lines[l].Split(' ')[2]);
                K = int.Parse(lines[l].Split(' ')[3]);
            }
        }
    }
}
