using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace AcmSolution4
{
    class Program
    {
        static void Main()
        {
#if !ONLINE_JUDGE
            Console.SetIn(new StreamReader("../../../a.txt"));
            Console.SetOut(new StreamWriter("../../../a-large.txt"));
#endif         
          int tt = GetInt();

          for (int test = 1; test <= tt; ++test)
          {
              var a = GetInts().ToList();
              int n = a[0];
              a.RemoveAt(0);
              int sum = 0;
              int min = int.MaxValue;

              for (int i = 0; i < n; ++i)
              {
                  sum += a[i];
                  if (min > a[i])
                      min = a[i];
              }

              int[] b = (int[]) a.ToArray().Clone();
              Array.Sort(b);

              double res = b[0];
              int cnt = 1;
              double t = 0;

              for (int i = 0; i < n; i++)
              {
                 int next = i == n - 1  ? 10000000 : b[i + 1];
                 double r = (next - b[i]) / 1.0 / sum;

                 if (t + cnt * r > 1.00000000000001)
                 {
                     res += sum * (1 - t) / cnt;
                     break;
                 }
                 else
                 {
                     t += r * cnt;
                     res += r * sum;
                 }

                  cnt++;
              }



              Console.Write(string.Format("Case #{0}: ", test));
              for (int i = 0; i < n; i++)
              {
                  double ans = 0;
                  if (res < a[i])
                      ans = 0;
                  else 
                      ans = (res - a[i]) / sum * 100.0;

                  Console.Write(String.Format("{0:0.0000000}", ans).Replace(",", ".") + " ");
              }
              Console.WriteLine();
          }
          Console.Out.Close();
        }
    
        static int GetInt()
        {
            return int.Parse(GetStr());
        }

        static int GetInt(string s)
        {
            return int.Parse(s);
        }

        static int[] GetInts()
        {
            return Array.ConvertAll(GetStr().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
        }

        static long[] GetLongs()
        {
            return Array.ConvertAll(GetStr().Split(), long.Parse);
        }

        static string[] GetStrs()
        {
            return GetStr().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
        }

        static long GetLong()
        {
            return GetLong(GetStr());
        }

        static long GetLong(string s)
        {
            return long.Parse(s);
        }

        static string GetStr()
        {
            return Console.ReadLine();
        }

        static void WL<T>(T s)
        {
            Console.WriteLine(s);
        }

        static void W<T>(T s)
        {
            Console.Write(s);
        }

        static int nod(int a, int b)
        {
            while (a != 0 && b != 0)
            {
                if (a > b)
                    a = a % b;
                else if (b > a)
                    b = b % a;
            }
            return a + b;
        }
    }

    internal class Pair
    {
        public long X { get; set; }
        public long Y { get; set; }

        public Pair(long i, long j)
        {
            X = i;
            Y = j;
        }
    }
}