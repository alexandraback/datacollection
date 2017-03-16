using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace km.gcj.gcj2013.r1a
{
    class Program_B
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
                long[] ern = p.getNextInt64s().ToArray();
                var E = ern[0];
                var R = ern[1];
                var N = ern[2];
                long[] vi = p.getNextInt64s().ToArray();


                long[] spent = new long[N];
                long curEnergy;
                long limit = N - 1;
                for (long k = N-1; k >= 0; k--)
                {
                    if (k == 0)
	                {
                        curEnergy = E;
	                }
                    else{
                        curEnergy = R;
                    }
                    for (long m = limit; m > k; m--)
			        {
                        if (vi[k] <= vi[m])
                        {
                            var x = Math.Min(curEnergy, E - spent[m]);
                            spent[m] += x;
                            curEnergy -= x;
                            if (spent[m] == E)
                            {
                                limit = m - 1;
                            }
                        }
                        if (curEnergy == 0) break;
			        }
                    spent[k] = curEnergy;    
                }


                long answer = 0;
                for (int k = 0; k < N; k++)
                {
                    answer += vi[k] * spent[k];
                    Console.Write("{0},",spent[k]);
                }
                Console.WriteLine();

                // ＼(・ω・＼)　　(／・ω・)／
                p.WriteAnswerFullLine(answer.ToString());

            }
         }



    }
}
