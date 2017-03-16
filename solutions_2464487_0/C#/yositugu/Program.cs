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

        private const string OUTPUT = "../../out1AA.txt";

        static void Main(string[] args)
        {
            var eval = new Eval();
            var res = "";

            // Test Case
            if ((res = eval.eval(new[] { "1 9", "", "", "", }, 0)) != "1") throw new Exception(res);
            if ((res = eval.eval(new[] { "1 10", "", "", "", }, 0)) != "2") throw new Exception(res);
            if ((res = eval.eval(new[] { "3 40", "", "", "", }, 0)) != "3") throw new Exception(res);
            if ((res = eval.eval(new[] { "1 1000000000000000000", "", "", "", }, 0)) != "707106780") throw new Exception(res);
            if ((res = eval.eval(new[] { "10000000000000000 1000000000000000000", "", "", "", }, 0)) != "49") throw new Exception(res);
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
            public long r; //初期値
            public long t; //インク残量

            private string[] lines;
            private int l;

            public string eval(string[] lines, int l)
            {
                this.lines = lines;
                this.l = l;
                string sans = small();
                //string lans = large();
                //if (sans != lans) throw new Exception(sans + " != " + lans);
                //return sans.ToString();
                return sans.ToString();
            }

            /// <summary>工夫する</summary>
            private string large()
            {
                parse();
                int res = -1;
                return res.ToString();
            }

            /// <summary>まともにやる</summary>
            private string small()
            {
                parse();
                int res = -1;

                for (long i = r; 0 <= t; i += 2)
                {
                    //t -= (i + 1) * (i + 1) - i * i;
                    t -= i * 2 + 1;
                    res++;
                }

                return res.ToString();
            }


            /// <summary>変数初期化</summary>
            private void parse()
            {
                r = long.Parse(lines[l].Split(' ')[0]);
                t = long.Parse(lines[l].Split(' ')[1]);
            }
        }
    }
}
