using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace taskC
{
    class Program
    {

        static List<int> trans(int a)
        {
            List<int> res = new List<int>();
            while (a>0) {
                res.Add(a % 10);
                a /= 10;
            }
            return res;
        }

        static int toInt(List<int> a , int shift)
        {
            int res = 0;
            int n = a.Count;
            for (int i = a.Count - 1; i > -1; i--)
            {
                res = res * 10 + a[(i+shift)%n];
            }
            return res;
        }

        static bool more(List<int> current, int shift)
        {
            int n = current.Count;
            for (int i = n-1; i >-1; i--)
            {
                if (current[(i + shift) % n] < current[i]) return false;
                if (current[(i + shift) % n] > current[i]) return true;
            }
            return false;
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("c:/temp/input_c_large.txt");
            StreamWriter sw = new StreamWriter("c:/temp/output_c_large.txt");
            int[] previous = new int[100];
            int cntPrev;
            int T = int.Parse(sr.ReadLine());
            int a, b, res;
            int[] max, min;
            List<int> cur;
            for (int test = 0; test < T; test++)
            {
                res = 0;
                string[] token = sr.ReadLine().Split();
                a = int.Parse(token[0]);
                b = int.Parse(token[1]);
                max = new int[token[1].Length];
                min = new int[token[0].Length];
                int tempB = b;
                int tempA = a;
                int index;
                for (index = 0; index<min.Length; index++) {
                    min[index] = tempA%10;
                    tempA/=10;
                }
                for (index = 0; index<max.Length; index++) {
                    max[index] = tempB%10;
                    tempB/=10;
                }

                for (int current = a; current <= b; current++)
                {
                    cur = trans(current);
                    cntPrev = 0;
                    for (int i = 1; i < cur.Count; i++)
                    {
                        if (more(cur, i))
                        {
                            bool lessMax = true;
                            if (cur.Count == max.Length)
                            {
                                for (int i1 = cur.Count-1; i1 >-1; i1--)
                                {
                                    if (cur[(i1+i)%cur.Count] > max[i1])
                                    {
                                        lessMax = false;
                                        break;
                                    }
                                    if (cur[(i1 + i) % cur.Count] < max[i1])
                                        break;
                                }
                            }

                            bool noBefore = true;
                            int curInt = toInt(cur,i);
                            for (int i2 = 0; i2 < cntPrev; i2++)
                            {
                                if (previous[i2] == curInt)
                                {
                                    noBefore = false;
                                    break;
                                }
                            }

                            if (lessMax && noBefore)
                            {
                                res++;
                                //if (current == 1212)
                                //{
                                  //  for (int ind = cur.Count - 1; ind > -1; ind--) Console.Write(cur[ind]);
                                   // Console.WriteLine(" shift={0}", i);
                                   // for (int i3 = 0; i3 < cntPrev; i3++)
                                  //  {
                                  //      Console.Write("{0} ", previous[i3]);
                                   // }
                                 //   Console.WriteLine();
                                //}
                                 previous[cntPrev++] = curInt;
                            }
                        }
                       
                    }
                }

                sw.WriteLine("Case #{0}: {1}", test + 1, res);
            }

            sr.Close();
            sw.Close();
        }
    }
}
