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

        private const string OUTPUT = "../../out1CB.txt";

        static void Main(string[] args)
        {
            var eval = new Eval();
            var res = "";

            // Test Case
            if((res = eval.eval(new[] { "1", "a", "", "", "", }, 0)) != "1") throw new Exception(res);
            if((res = eval.eval(new[] { "3", "ab bbbc cd", "", "", "", }, 0)) != "1") throw new Exception(res);
            if((res = eval.eval(new[] { "4", "aa aa bc c", "", "", "", }, 0)) != "4") throw new Exception(res);
            if((res = eval.eval(new[] { "2", "abc bcd", "", "", "", }, 0)) != "0") throw new Exception(res);
            //if ((res = eval.eval(new[] { "", "", "", "", }, 0)) != "") throw new Exception(res);
            //return;

            File.Delete(OUTPUT);
            var lines = File.ReadAllLines(FILE_NAME);
            var T = int.Parse(lines[0]);
            var l = 1;

            for(int t = 0; t < T; t++)
            {
                res = eval.eval(lines, l);
                l += 2; //1Caseの行数

                File.AppendAllText(OUTPUT, string.Format("Case #{0}: {1}\n", t + 1, res));
                Console.Write(DateTime.Now.ToShortTimeString() + "." + DateTime.Now.Second + string.Format(" Case #{0}: {1}\n", t + 1, res));
            }
        }

        private class Eval
        {
            public int N;
            public string[] cars;
            private const long MOD = 1000000007;

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

                if(N == 1) return "1";

                var res = 0;
                foreach(var pat in allPattern(cars))
                {
                    res++;
                    // 最初
                    if(pat[0].Last() != pat[1].First())
                    {
                        res--; continue;
                    }
                    // 最後
                    if(pat[pat.Count - 2].Last() != pat[pat.Count - 1].First())
                    {
                        res--; continue;
                    }
                    // 中
                    for(int i = 1; i < pat.Count - 1; i++)
                    {
                        if((pat[i - 1].Last() != pat[i].First()) && (pat[i].Last() != pat[i + 1].First()))
                        {
                            res--;
                            break;
                        }
                    }
                }

                return res.ToString();
            }

            private IEnumerable<IList<string>> allPattern(IList<string> src)
            {
                if(src.Count == 1) yield return new List<string>(src);
                for(int i = 0; i < src.Count; i++)
                {
                    var copy = new List<string>(src);
                    copy.RemoveAt(i);
                    foreach(var r in allPattern(copy))
                    {
                        r.Add(src.ElementAt(i));
                        yield return r;
                    }
                }
            }

            /// <summary>変数初期化</summary>
            private void parse()
            {
                cars = lines[l + 1].Split(' ');
                N = cars.Length;
            }
        }
    }
}
