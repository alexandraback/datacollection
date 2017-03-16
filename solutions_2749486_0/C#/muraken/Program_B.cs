using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace km.gcj.gcj2013.r1b
{
    class Program_B
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
                long[] xy = p.getNextInt64s().ToArray();
                var    x  = xy[0];
                var    y  = xy[1];

                List<char> lcAnswer1 = calc(x, y);
                List<char> lcAnswer2 = calc(x, y);

                String answer = 
                    lcAnswer1.Count<lcAnswer2.Count?new String(lcAnswer1.ToArray()):new String(lcAnswer2.ToArray());


                // ＼(・ω・＼)　　(／・ω・)／
                p.WriteAnswerFullLine(answer.ToString());
                if(i%10==0)Console.WriteLine("{0}\t->{1}", i, sw.Elapsed);

            }
        }

        private static List<char> calc(long x,long y){
            List<char> lcAnswer = new List<char>();

            long step = 1;

            while (x!=0) {
                if (step <= x) {
                    lcAnswer.Add('E');
                    x-=step;
                    step++;
                }
                else if (step<=-x) {
                    lcAnswer.Add('W');
                    x+=step;
                    step++;
                }
                else if (0<x) {
                    lcAnswer.Add('W');
                    x+=step;
                    step++;
                    lcAnswer.Add('E');
                    x-=step;
                    step++;
                }
                else { // (0<-x)
                    lcAnswer.Add('E');
                    x-=step;
                    step++;
                    lcAnswer.Add('W');
                    x+=step;
                    step++;
                }
            }

            while (y!=0) {
                if (step<=y) {
                    lcAnswer.Add('N');
                    y-=step;
                    step++;
                }
                else if (step<=-y) {
                    lcAnswer.Add('S');
                    y+=step;
                    step++;
                }
                else if (0<y) {
                    lcAnswer.Add('S');
                    y+=step;
                    step++;
                    lcAnswer.Add('N');
                    y-=step;
                    step++;
                }
                else { // (0<-y)
                    lcAnswer.Add('N');
                    y-=step;
                    step++;
                    lcAnswer.Add('S');
                    y+=step;
                    step++;
                }
            }


            return lcAnswer;
        }

        private static List<char> calc2(long x, long y)
        {
            List<char> lcAnswer = new List<char>();

            long step = 1;

            while (y!=0) {
                if (step<=y) {
                    lcAnswer.Add('N');
                    y-=step;
                    step++;
                }
                else if (step<=-y) {
                    lcAnswer.Add('S');
                    y+=step;
                    step++;
                }
                else if (0<y) {
                    lcAnswer.Add('S');
                    y+=step;
                    step++;
                    lcAnswer.Add('N');
                    y-=step;
                    step++;
                }
                else { // (0<-x)
                    lcAnswer.Add('N');
                    x-=step;
                    step++;
                    lcAnswer.Add('S');
                    x+=step;
                    step++;
                }
            }

            while (x!=0) {
                if (step<=x) {
                    lcAnswer.Add('E');
                    x-=step;
                    step++;
                }
                else if (step<=-x) {
                    lcAnswer.Add('W');
                    x+=step;
                    step++;
                }
                else if (0<x) {
                    lcAnswer.Add('W');
                    x+=step;
                    step++;
                    lcAnswer.Add('E');
                    x-=step;
                    step++;
                }
                else { // (0<-x)
                    lcAnswer.Add('E');
                    x-=step;
                    step++;
                    lcAnswer.Add('W');
                    x+=step;
                    step++;
                }
            }

            return lcAnswer;
        }

    }
}
