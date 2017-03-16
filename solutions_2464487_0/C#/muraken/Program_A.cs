using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace km.gcj.gcj2013.r1a
{
    class Program_A
    {
        /// <summary> プログラムのスタートポイント </summary>
        /// <param name="args"> 第一引数に入力ファイルを指定 </param>
        static void Main(string[] args)
        {
            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            Logic(args);

            sw.Stop();
            Console.WriteLine(sw.Elapsed);
            Console.ReadLine();
        }

        private static void Logic(string[] args)
        {
            //throw new NotImplementedException();
            Problem2 p = Problem2.createProblem(args);
            if (p == null) {
                return;
            }


            // 試行回数を取得し、ループする。
            long repeat = p.getNextInt64s().ToArray()[0];
            for (int i = 0; i < repeat; i++)
            {

                // MainLoop
                long[] rt = p.getNextInt64s().ToArray();
                var r = rt[0];
                var t = rt[1];

                var tSqrt = (long)Math.Ceiling(Math.Sqrt(((double)t) / 2));

                long answer = 0;
                for (long k = tSqrt; k > 0; k--)
                {
                    //if (2 * k * k + (2 * r - 1) * k <= t)
                    if ((2 * k + 2 * r - 1) <= t / k)
                        {
                        answer = k;
                        break;
                    }
                    else
                    {
                    }
                }

                // ＼(・ω・＼)　　(／・ω・)／
                p.WriteAnswerFullLine(answer.ToString());

            }
         }



    }
}
