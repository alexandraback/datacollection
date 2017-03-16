using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace _1B_A
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
            if ((res = eval.eval(new[] { "2 20 10", "", "", "", }, 0)) != "33.3333333333333 66.6666666666667") throw new Exception(res);
            if ((res = eval.eval(new[] { "2 10 0", "", "", "", }, 0)) != "0 100") throw new Exception(res);
            if ((res = eval.eval(new[] { "4 25 25 25 25", "", "", "", }, 0)) != "25 25 25 25") throw new Exception(res);
            if ((res = eval.eval(new[] { "7 0 72 0 0 0 0 0", "", "", "", }, 0)) != "16.6666666666667 0 16.6666666666667 16.6666666666667 16.6666666666667 16.6666666666667 16.6666666666667") throw new Exception(res);
            if ((res = eval.eval(new[] { "3 24 30 21", "", "", "", }, 0)) != "34.6666666666667 26.6666666666667 38.6666666666667") throw new Exception(res);
            //return;

            File.Delete(OUTPUT);
            var lines = File.ReadAllLines(FILE_NAME);
            var T = int.Parse(lines[0]);
            var i = 1;

            for (int t = 0; t < T; t++)
            {
                res = eval.eval(lines, i);
                i += 1;

                File.AppendAllText(OUTPUT, string.Format("Case #{0}: {1}\n", t + 1, res));
                //Console.Write(string.Format("Case #{0}: {1}\n", t + 1, res));
            }
        }

        private class Eval
        {
            public int N;
            private List<int> si = new List<int>();

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
                var res = new StringBuilder();

                // 0があるときだけ特別
                if (si.Contains(0) && (si.FindAll(i => i != 0).Min() > si.Sum() * 1.0 / N))
                {
                    var c = si.Count(i => i == 0);
                    if (c == 1)
                    {
                        foreach (var s in si)
                        {
                            if (s == 0) res.Append(100).Append(' ');
                            else res.Append(0).Append(' ');
                        }
                        res.Remove(res.Length - 1, 1);
                        return res.ToString();
                    }
                    else
                    {
                        foreach (var s in si)
                        {
                            if (s == 0) res.Append(100.0 / c).Append(' ');
                            else res.Append(0).Append(' ');
                        }
                        res.Remove(res.Length - 1, 1);
                        return res.ToString();
                    }
                }

                double sum = si.Sum() * 2.0 / N;
                var sirev = new List<double>();

                foreach (var s in si)
                {
                    sirev.Add(sum - s);
                }
                sum = sirev.Sum();

                foreach (var s in sirev)
                {
                    if (s < 0)
                        res.Append(0).Append(' ');
                    else
                        res.Append(s / sum * 100).Append(' ');
                }

                res.Remove(res.Length - 1, 1);
                return res.ToString();
            }

            /// <summary>変数初期化</summary>
            private void parse()
            {
                this.si.Clear();
                var sa = lines[t].Split(' ');
                this.N = int.Parse(sa[0]);
                for (int i = 0; i < N; i++)
                {
                    si.Add(int.Parse(sa[i + 1]));
                }
            }
        }
    }
}
