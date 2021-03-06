﻿using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace pc
{
    class Env
    {
        static public string[] delim = { " ", "\t" };
        public StreamReader srd;
        public StreamWriter swr;
    }
    //struct subset {
    //    public int size;
    //    public bool[] used = new bool[500];
    //    public subset(int size)
    //    {
    //        this.size =size;
    //        for (int i = 0; i < size; i++)
    //        {
    //            used[i] = false;
    //        }
    //    }
    //}
    class Program
    {
        static void probCore(long T, Env env)
        {
            string line = env.srd.ReadLine();
            string[] parts = line.Split(Env.delim, StringSplitOptions.None);
            int A = Int32.Parse(parts[0]);
            int[] n = new int[A];

            for (int i = 0; i < A; i++)
            {
                n[i] = Int32.Parse(parts[i+1]);
            }

            //subset current = new subset(A);
            bool[] current = new bool[A];

            current[0] = true;
            for (int i = 1; i < A; i++)
            {
                current[i] = false;
            }
            Dictionary<int, bool[]> dict = new Dictionary<int, bool[]>();
            while (true)
            {
                //subsetのsumを出す。
                int subsum = 0;
                for (int i = 0; i < A; i++)
                {
                    if (current[i])
                    {
                        subsum = subsum + n[i];
                    }
                }
                if (dict.ContainsKey(subsum))
                {
                    //見つかった
                    env.swr.WriteLine("Case #{0}:", T);
                    {
                        bool flag = false;
                        for (int i = 0; i < A; i++)
                        {
                            if (current[i])
                            {
                                if (flag)
                                {
                                    env.swr.Write(" {0}", n[i]);
                                }
                                else
                                {
                                    env.swr.Write("{0}", n[i]);
                                    flag = true;
                                }
                            }
                        }
                    }
                    env.swr.WriteLine();
                    current = dict[subsum];
                    {
                        bool flag = false;
                        for (int i = 0; i < A; i++)
                        {
                            if (current[i])
                            {
                                if (flag)
                                {
                                    env.swr.Write(" {0}", n[i]);
                                }
                                else
                                {
                                    env.swr.Write("{0}", n[i]);
                                    flag = true;
                                }
                            }
                        }
                    }
                    env.swr.WriteLine();
                    return;
                }
                else
                {
                    bool[] current2 = new bool[A];
                    current.CopyTo(current2, 0);
                    dict.Add(subsum, current2);
                    bool carry = true;
                    for (int i = 0; i < A; i++)
                    {
                        if (carry)
                        {
                            carry = current[i];
                            current[i] = !current[i];
                        }
                    }
                    if (carry)
                    {
                        env.swr.WriteLine("Case #{0}: Impossible", T);
                    }

                }
                


            }


//                  double[] p = new double[A];
//                  {
//                      p[i] = Double.Parse(parts[i]);
//                      if (i == 0)
//                      {
//                          q[i] = p[0];
//                      }
//                      else
//                      {
//                          q[i] = q[i - 1] * p[i];
//                      }
//                  }
//              }
//              //戦略
//              //スルーするX
//              //  success (B-A)+1
//              //  fail    (B-A)+1 + B+1
//              //戻るY
//              //  success (A-i)*2 + (B-A)+1
//              //  fail    (A-i)*2 + (B-A)+1 + B+1
//              //捨てるZ
//              //  success B+2
//
//              int x_success = (B - A + 1);
//              int x_fail    = (B - A + 1) + B + 1;
//              double xExp = q[A - 1] * x_success + (1 - q[A - 1]) * x_fail;
//              Console.WriteLine("{0} x:{1} (s:{2} f:{3} p[a-1]:{4})", T, xExp, x_success, x_fail, q[A - 1]);
//              double yExp = 1000 * 1000; // 十分に大きい数
//              for (int i = 1; i < A; i++)
//              {
//                  int y_success = (A - i) * 2 + (B - A) + 1;
//                  int y_fail    = (A - i) * 2 + (B - A) + 1 + B + 1;
//                  double y_exp = q[i - 1] * y_success + (1 - q[i - 1]) * y_fail;
//                  if (y_exp < yExp)
//                  {
//                      yExp = y_exp;
//                  }
//              }
//              double zExp = B + 2;
//              Console.WriteLine("{0} y:{1}", T, yExp);
//              Console.WriteLine("{0} z:{1}", T, zExp);
//              double xyExp = xExp < yExp ? xExp : yExp;
//
//              double xyzExp = xyExp < zExp ? xyExp : zExp;
//
//              //for (int i = 0; i < A; i++)
//              //{
//              //    p[i] = Double.Parse(parts[i]);
//              //}
//
//
//
//              
//              //    string S = parts[1];
//          //    int N = S.Length;
//
//          //    List<uint> list = new List<uint>();
//          //    list.Sort();
//          //    bool flag = false;
//          //    uint lastPrint = 0;
//              env.swr.WriteLine("Case #{0}: {1}", T, xyzExp);
//          //    for (int i = 1; i < (list.Count); i++)
//          //    {
//          //        if ((lastPrint != list[i])
//          //            && (list[i - 1] == list[i]))
//          //        {
//          //            flag = true;
//          //            lastPrint = list[i];
//          //            env.swr.Write(" {0}", lastPrint);
//          //        }
//          //    }
//          //    if (!flag)
//          //    {
//          //        env.swr.Write(" NONE", T);
//          //    }
//                  //env.swr.WriteLine();
        }

        static void probLoop(Env env)
        {
            string line = env.srd.ReadLine();
            Stopwatch sw = new Stopwatch();
            sw.Start();
            long t = Int64.Parse(line);
            for (long i = 1; i <= t; i++)
            {
                probCore(i, env);
            }
            sw.Stop();
            long millisec = sw.ElapsedMilliseconds;
            Console.WriteLine("used:{0}[ms]", millisec);
        }

        static void Main(string[] args)
        {
            StreamReader srd = null;
            StreamWriter swr = null;
            Env env = new Env();

            try
            {
                srd = new StreamReader(
                    args[0], Encoding.GetEncoding("Shift_JIS"));
                env.srd = srd;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            try
            {
                swr = new StreamWriter(
                    args[1], false, Encoding.GetEncoding("Shift_JIS"));
                env.swr = swr;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            probLoop(env);

            swr.Close();
        }
    }
}
