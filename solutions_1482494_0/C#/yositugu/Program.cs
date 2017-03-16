using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace _1A_B
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
            if ((res = eval.eval(new[] { "2", "0 1", "0 2", "", }, 0)) != "3") throw new Exception(res);
            if ((res = eval.eval(new[] { "3", "2 2", "0 0", "4 4", }, 0)) != "3") throw new Exception(res);
            if ((res = eval.eval(new[] { "1", "1 1", "", "", }, 0)) != "Too Bad") throw new Exception(res);
            if ((res = eval.eval(new[] { "5", "0 5", "0 1", "1 1", "4 7", "5 6", }, 0)) != "6") throw new Exception(res);
            //return;

            File.Delete(OUTPUT);
            var lines = File.ReadAllLines(FILE_NAME);
            var T = int.Parse(lines[0]);
            var i = 1;

            for (int t = 0; t < T; t++)
            {
                res = eval.eval(lines, i);
                i += eval.N + 1;

                File.AppendAllText(OUTPUT, string.Format("Case #{0}: {1}\n", t + 1, res));
                //Console.Write(string.Format("Case #{0}: {1}\n", t + 1, res));
            }
        }

        private class Eval
        {
            public int N;
            private List<ab> abi = new List<ab>();

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
                var res = 0;
                var star = 0;
                while (abi.Count > 0)
                {
                    abi.Sort((x, y) => (x.b - y.b));
                    while (abi.Count > 0)
                    {
                        if (star < abi[0].b) break;
                        star += abi[0].star;
                        res += 1;
                        abi.RemoveAt(0);
                    }
                    abi.Sort((x, y) => (x.a - y.a));
                    if (abi.Count > 0)
                    {
                        if (abi[0].star < 2 || star < abi[0].a) break;
                        star += 1;
                        res += 1;
                        abi[0].star = 1;
                    }
                }
                if (abi.Count == 0) return res.ToString();
                else return "Too Bad";
            }

            /// <summary>変数初期化</summary>
            private void parse()
            {
                this.abi.Clear();
                var sa = lines[t].Split(' ');
                this.N = int.Parse(sa[0]);
                for (int i = 0; i < N; i++)
                {
                    sa = lines[t + 1 + i].Split(' ');
                    abi.Add(new ab(int.Parse(sa[0]), int.Parse(sa[1])));
                }
            }

            private class ab
            {
                public int a { get; private set; }
                public int b { get; private set; }
                public int star = 2;
                public ab(int a, int b)
                {
                    this.a = a;
                    this.b = b;
                }
            }
        }
    }
}
