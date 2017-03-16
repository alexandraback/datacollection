using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GCJ2013
{
    class Program
    {
        //private const string FILE_NAME = "../../test.txt";
        private const string FILE_NAME = "../../small.txt";
        //private const string FILE_NAME = "../../large.txt";

        private const string OUTPUT = "../../outQB.txt";

        static void Main(string[] args)
        {
            var eval = new Eval();
            var res = "";

            // Test Case
            if ((res = eval.eval(new[] { "3 3", "2 1 2", "1 1 1", "2 1 2", "", "", "", }, 0)) != "YES") throw new Exception(res);
            if ((res = eval.eval(new[] { "5 5", "2 2 2 2 2", "2 1 1 1 2", "2 1 2 1 2", "2 1 1 1 2", "2 2 2 2 2", "", }, 0)) != "NO") throw new Exception(res);
            if ((res = eval.eval(new[] { "1 3", "1 2 1", "", "", "", "", "", }, 0)) != "YES") throw new Exception(res);
            //if ((res = eval.eval(new[] { "", "", "", "", }, 0)) != "") throw new Exception(res);
            //return;

            File.Delete(OUTPUT);
            var lines = File.ReadAllLines(FILE_NAME);
            var T = int.Parse(lines[0]);
            var l = 1;

            for (int t = 0; t < T; t++)
            {
                res = eval.eval(lines, l);
                l += eval.M + 1;

                File.AppendAllText(OUTPUT, string.Format("Case #{0}: {1}\n", t + 1, res));
                Console.Write(DateTime.Now.ToShortTimeString() + "." + DateTime.Now.Second + string.Format(" Case #{0}: {1}\n", t + 1, res));
            }
        }

        private class Eval
        {
            public int N;
            public int M;

            private int[][] a;

            public const string YES = "YES", NO = "NO";

            private string[] lines;
            private int l;

            public string eval(string[] lines, int l)
            {
                this.lines = lines;
                this.l = l;
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
                return judge();
            }

            /// <summary>判定</summary>
            private string judge()
            {
                if (M == 1 || N == 1) return YES;

                // 全てのマス
                for (int m = 0; m < M; m++)
                {
                    for (int n = 0; n < N; n++)
                    {
                        if (isLowest(m, n)) return NO;
                    }
                }

                return YES;
            }

            /// <summary>上下かつ左右に自分より高い草があるかどうか判定</summary>
            private bool isLowest(int mm, int nn)
            {
                // 判定対象の高さ
                var h = a[mm][nn];
                bool up = false, down = false, left = false, right = false;

                // 上方向
                for (int m = 0; m < mm; m++) { if (h < a[m][nn]) up = true; }
                // 下方向
                for (int m = mm; m < M; m++) { if (h < a[m][nn]) down = true; }
                // 左方向
                for (int n = 0; n < nn; n++) { if (h < a[mm][n]) left = true; }
                // 右方向
                for (int n = nn; n < N; n++) { if (h < a[mm][n]) right = true; }

                if ((up || down) && (left || right)) return true;
                return false;
            }

            /// <summary>変数初期化</summary>
            private void parse()
            {
                M = int.Parse(lines[l].Split(' ')[0]);
                N = int.Parse(lines[l].Split(' ')[1]);
                a = new int[M][];

                for (int m = 0; m < M; m++)
                {
                    var sa = lines[l + m + 1].Split(' ');
                    a[m] = new int[N];
                    for (int n = 0; n < N; n++)
                    {
                        a[m][n] = int.Parse(sa[n]);
                    }
                }
            }
        }
    }
}
