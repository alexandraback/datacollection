using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace _1A_A
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
            if ((res = eval.eval(new[] { "2 5", "0.6 0.6", }, 0)) != "7") throw new Exception(res);
            if ((res = eval.eval(new[] { "1 20", "1", }, 0)) != "20") throw new Exception(res);
            if ((res = eval.eval(new[] { "3 4", "1 0.9 0.1", }, 0)) != "4.5") throw new Exception(res);
            //return;

            File.Delete(OUTPUT);
            var lines = File.ReadAllLines(FILE_NAME);
            var T = int.Parse(lines[0]);
            var i = 1;

            for (int t = 0; t < T; t++)
            {
                res = eval.eval(lines, i);
                i += 2;

                File.AppendAllText(OUTPUT, string.Format("Case #{0}: {1}\n", t + 1, res));
                Console.Write(DateTime.Now.ToShortTimeString() + string.Format(" Case #{0}: {1}\n", t + 1, res));
            }
        }

        private class Eval
        {
            private int A;
            private int B;
            private List<double> pi = new List<double>();

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
                var res = double.MaxValue;
                var list = new List<double>(A);
                var prob = 1.0;
                for (int i = 0; i < A; i++)
                {
                    prob *= pi[i];
                    list.Add(prob);
                }
                // 間違っていなければそのまま行くのがいい
                if (prob >= 0.99999999) return (B - A + 1).ToString();

                // Backspaceを0～A-1回押す場合
                for (int i = 0; i < A; i++)
                {
                    var once = (B - A + (i * 2) + 1);
                    var p = list[A - i - 1];
                    res = calcExp(once, p, res);
                }

                // すぐにEnterを押す場合
                res = calcExp(1, 0, res);

                return res.ToString();
            }

            private double calcExp(int once, double p, double res)
            {
                // 正解時
                var exp = p * once;
                // 不正解時
                exp += (1 - p) * (once + B + 1);
                return (exp < res) ? exp : res;
            }

            /// <summary>変数初期化</summary>
            private void parse()
            {
                pi.Clear();
                var sa = lines[t].Split(' ');
                this.A = int.Parse(sa[0]);
                this.B = int.Parse(sa[1]);

                sa = lines[t + 1].Split(' ');
                for (int i = 0; i < A; i++)
                {
                    pi.Add(double.Parse(sa[i]));
                }
            }
        }
    }
}
