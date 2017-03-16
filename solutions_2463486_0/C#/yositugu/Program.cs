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
        //private const string FILE_NAME = "../../large1.txt";
        //private const string FILE_NAME = "../../large2.txt";

        private const string OUTPUT = "../../outQC.txt";

        static void Main(string[] args)
        {
            var eval = new Eval();
            var res = "";

            // Test Case
            if ((res = eval.eval(new[] { "1 4", "", "", "", "", "", "", }, 0)) != "2") throw new Exception(res);
            if ((res = eval.eval(new[] { "10 120", "", "", "", "", "", "", }, 0)) != "0") throw new Exception(res);
            if ((res = eval.eval(new[] { "100 1000", "", "", "", "", "", "", }, 0)) != "2") throw new Exception(res);
            if ((res = eval.eval(new[] { "1 100000000000000", "", "", "", "", "", "", }, 0)) != "39") throw new Exception(res);
            if ((res = eval.eval(new[] { "3 6", "", "", "", "", "", "", }, 0)) != "1") throw new Exception(res);
            //if ((res = eval.eval(new[] { "", "", "", "", }, 0)) != "") throw new Exception(res);
            //return;

            File.Delete(OUTPUT);
            var lines = File.ReadAllLines(FILE_NAME);
            var T = int.Parse(lines[0]);
            var l = 1;

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
            public long A;
            public long B;

            private long[] ans = { 1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002, };

            private string[] lines;
            private int l;

            public string eval(string[] lines, int l)
            {
                this.lines = lines;
                this.l = l;
                //string sans = small();
                string lans = large();
                //if (sans != lans) throw new Exception(sans + " != " + lans);
                //return sans.ToString();
                return lans.ToString();
            }

            /// <summary>工夫する</summary>
            private string large()
            {
                parse();
                var res = 0;
                long sqA = (long)Math.Sqrt(A);
                long sqB = (long)Math.Sqrt(B);

                for (; sqA <= sqB; sqA++)
                {
                    var square = sqA * sqA;
                    if (A <= square) break;
                }

                for (int i = 0; i < ans.Length; i++)
                {
                    if (sqA <= ans[i] && ans[i] <= sqB) res++;
                }
                return res.ToString();
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
                var res = 0;
                long sqA = (long)Math.Sqrt(A);
                long sqB = (long)Math.Sqrt(B);

                for (long i = sqA; i <= sqB; i++)
                {
                    var square = i * i;
                    if (square < A) continue;
                    if (!palindromes(i.ToString())) continue;
                    if (!palindromes(square.ToString())) continue;
                    res++;
                    System.Diagnostics.Debug.WriteLine("{0} * {0} = {1}", i, square);
                }
                return res.ToString();
            }

            /// <summary>回分判定</summary>
            private bool palindromes(string s)
            {
                var len = s.Length;
                for (int i = 0; i < len / 2; i++)
                {
                    if (s[i] != s[len - i - 1]) return false;
                }
                return true;
            }


            /// <summary>変数初期化</summary>
            private void parse()
            {
                A = long.Parse(lines[l].Split(' ')[0]);
                B = long.Parse(lines[l].Split(' ')[1]);
            }
        }
    }
}
