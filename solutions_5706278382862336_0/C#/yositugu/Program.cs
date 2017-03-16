using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GCJ2014
{
    public class Program
    {
        //private const string FILE_NAME = "../../test.txt";
        private const string FILE_NAME = "../../small.txt";
        //private const string FILE_NAME = "../../large.txt";

        private const string OUTPUT = "../../out1CA.txt";

        static void Main(string[] args)
        {
            var eval = new Eval();
            var res = "";

            // Test Case
            if((res = eval.eval(new[] { "1/2", "", "", "", }, 0)) != "1") throw new Exception(res);
            if((res = eval.eval(new[] { "3/4", "", "", "", }, 0)) != "1") throw new Exception(res);
            if((res = eval.eval(new[] { "1/4", "", "", "", }, 0)) != "2") throw new Exception(res);
            if((res = eval.eval(new[] { "1/1024", "", "", "", }, 0)) != "10") throw new Exception(res);
            if((res = eval.eval(new[] { "2/23", "", "", "", }, 0)) != "impossible") throw new Exception(res);
            if((res = eval.eval(new[] { "123/31488", "", "", "", }, 0)) != "8") throw new Exception(res);
            //if ((res = eval.eval(new[] { "", "", "", "", }, 0)) != "") throw new Exception(res);
            //return;

            File.Delete(OUTPUT);
            var lines = File.ReadAllLines(FILE_NAME);
            var T = int.Parse(lines[0]);
            var l = 1;

            for(int t = 0; t < T; t++)
            {
                res = eval.eval(lines, l);
                l += 1; //1Caseの行数

                File.AppendAllText(OUTPUT, string.Format("Case #{0}: {1}\n", t + 1, res));
                Console.Write(DateTime.Now.ToShortTimeString() + "." + DateTime.Now.Second + string.Format(" Case #{0}: {1}\n", t + 1, res));
            }
        }

        private class Eval
        {
            public long P; //分子
            public long Q; //分母

            private const string IMPOSSIBLE = "impossible";
            private readonly long[] BI = { 1L, 2L, 4L, 8L, 16L, 32L, 64L, 128L, 256L, 512L, 1024L, 2048L, 4096L, 8192L, 16384L, 32768L, 65536L, 131072L, 262144L, 524288L, 1048576L, 2097152L, 4194304L, 8388608L, 16777216L, 33554432L, 67108864L, 134217728L, 268435456L, 536870912L, 1073741824L, 2147483648L, 4294967296L, 8589934592L, 17179869184L, 34359738368L, 68719476736L, 137438953472L, 274877906944L, 549755813888L, 1099511627776L, };

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
                var res = new StringBuilder();

                return res.ToString();
            }

            /// <summary>まともにやる</summary>
            private string small()
            {
                parse();
                var gcd = Gcd(P, Q);
                var p = P / gcd;
                var q = Q / gcd;

                if(!BI.Contains(q)) return IMPOSSIBLE;

                var pp = p * (BI.Last() / q);
                for(int i = 0; i < BI.Length; i++)
                {
                    if(BI[BI.Length - 1 - i] <= pp) return i.ToString();
                }
                return IMPOSSIBLE;
            }

            private static long Gcd(long p, long q)
            {
                long temp = 0;
                while(true)
                {
                    temp = q % p;
                    if(temp == 0) return p;
                    q = p;
                    p = temp;
                }
            }

            /// <summary>変数初期化</summary>
            private void parse()
            {
                P = int.Parse(lines[l].Split('/')[0]);
                Q = int.Parse(lines[l].Split('/')[1]);
            }
        }
    }
}
