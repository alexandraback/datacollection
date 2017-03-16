using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace km.gcj.gcj2013.r1b
{
    class Program_A
    {
        static System.Diagnostics.Stopwatch sw;
        
        /// <summary> プログラムのスタートポイント </summary>
        /// <param name="args"> 第一引数に入力ファイルを指定 </param>
        static void Main(string[] args)
        {
            sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            Logic(args);

            sw.Stop();
            Console.WriteLine(sw.Elapsed);
            Console.ReadLine();
        }

        private static void Logic(string[] args)
        {
            Problem2 p = Problem2.createProblem(args);
            if (p==null) {
                return;
            }

            // 試行回数を取得し、ループする。
            long repeat = p.getNextInt64s().ToArray()[0];
            for (int i = 0; i<repeat; i++) {

                // MainLoop
                string[] xy = p.getNexts().ToArray();
                var    str  = xy[0].Replace('e','a').Replace('i','a').Replace('o','a').Replace('u','a');
                var    n  = Int32.Parse(xy[1]);

                var answer = calc(str, n);


                // ＼(・ω・＼)　　(／・ω・)／
                p.WriteAnswerFullLine(answer.ToString());
                if(i%10==0)Console.WriteLine("{0}\t->{1}", i, sw.Elapsed);

            }
        }

        private static long calc(string str,int n){
            long result = 0;
            for (int i = 0; i<str.Length-(n-1); i++) {
                for (int j = n; j<=str.Length-i; j++) {
                    if (!str.Substring(i+(j-n),n).Contains('a')) {
                        result+=str.Length-i-j+1;
                        break;
                    }
                }
            }
            
            return result;
        }

    }
}
