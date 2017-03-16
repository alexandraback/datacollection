using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace km.gcj.gcj2014
{
    class Program
    {
        static System.Diagnostics.Stopwatch sw;

        /// <summary> プログラムのスタートポイント </summary>
        /// <param name="args"> 第一引数に入力ファイルを指定 </param>
        static void Main(string[] args)
        {
            sw=new System.Diagnostics.Stopwatch();
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
                var target_cnt = p.getNextInt64s().ToArray()[0];
                var list = new List<string>();
                for (int j = 0; j<target_cnt; j++) {
                    list.Add(p.getNext());
                }
                var list_cnt = new List<List<int>>();
                var list_rep = new List<string>();
                foreach (var s in list) {
                    var cnt = new List<int>();
                    var sb = new StringBuilder();
                    var c_cnt = 0;
                    var bufChr = ' ';
                    for (int k = 0; k<s.Length; k++) {
                        if (k==0)
	                    {
		                    c_cnt++;
                            bufChr = s[k];
	                    }
                        else if (s[k] == bufChr) {
                            c_cnt++;
                        }
                        else {
                            sb.Append(bufChr);
                            cnt.Add(c_cnt);
                            bufChr=s[k];
                            c_cnt=1;
                        }
                    }
                    sb.Append(bufChr);
                    cnt.Add(c_cnt);

                    list_rep.Add(sb.ToString());
                    list_cnt.Add(cnt);
                }
//                foreach (var s in list_rep) {
  //                  Console.WriteLine(s);
//                }

                bool flg = true;
                for (int j = 1; j<list_rep.Count; j++) {
                    if (list_rep[j-1] != list_rep[j]) {
                        flg=false;
                        break;
                    }
                }
                if (flg) {
                    var answer = 0;
                    for (int j = 0; j<list_cnt[0].Count; j++) {
                        var bufList = new List<int>();
                        for (int k = 0; k<list_cnt.Count; k++) {
                            bufList.Add(list_cnt[k][j]);
//                            Console.WriteLine("bufList.Add  "+list_cnt[k][j]);

                        }
                        bufList.Sort();
                        int bufTarget = bufList[bufList.Count/2];
                        int answer_buffer = 0;
                        foreach (var num in bufList) {
                            answer_buffer+=Math.Abs(num-bufTarget);
                        }
//                        Console.WriteLine("answer_buffer = "+answer_buffer);
                        if (bufList.Count%2==0) {
                            int bufTarget2 = bufList[(bufList.Count/2)-1];
                            int answer_buffer2 = 0;
                            foreach (var num in bufList) {
                                answer_buffer2+=Math.Abs(num-bufTarget2);
                            }
//                            Console.WriteLine("answer_buffer2 = "+answer_buffer2);
                            answer_buffer=Math.Min(answer_buffer, answer_buffer2);
                        }
                        answer+=answer_buffer;
                    }
                    // ＼(・ω・＼)　　(／・ω・)／
                    p.WriteAnswerFullLine(answer.ToString());
                }
                else {
                    var answer = "Fegla Won";
                    // ＼(・ω・＼)　　(／・ω・)／
                    p.WriteAnswerFullLine(answer);
                }

//                // ＼(・ω・＼)　　(／・ω・)／
//                p.WriteAnswerFullLine(answer);

                if (i%10==0) Console.WriteLine("{0}\t->{1}", i, sw.Elapsed);
            }
        }
    }
}
