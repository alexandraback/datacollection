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
            Console.SetIn(new StreamReader("../../../c-small.txt"));
            Console.SetOut(new StreamWriter("../../../c-SMALLLLL.txt"));
#endif         
          int tt = GetInt();

          for (int test = 1; test <= tt; ++test)
          {
              var a = GetInts().ToList();
              int n = a[0];
              a.RemoveAt(0);

              int max = 1 << n;

              Console.WriteLine(string.Format("Case #{0}: ", test));

              Dictionary<int, int> dic = new Dictionary<int, int>();
              bool find = false;
              for (int i = 1; !find && i < max; ++i)
              {
                  int sum = 0;
                  int t = i;
                  int s = 0;
                  while (t > 0)
                  {
                      if (t % 2 == 1)
                          sum += a[s];
                      ++s;
                      t = t / 2;
                  }

                  if (!dic.ContainsKey(sum))
                      dic[sum] = i;
                  else
                  {
                      find = true;
                      s = 0;
                      t = i;
                      while (t > 0)
                      {
                          if (t % 2 == 1)
                              Console.Write(a[s] + " "); ;
                          ++s;
                          t = t / 2;
                      }

                      Console.WriteLine();

                      s = 0;
                      t = dic[sum];
                      while (t > 0)
                      {
                          if (t % 2 == 1)
                              Console.Write(a[s] + " "); ;
                          ++s;
                          t = t / 2;
                      }
                      Console.WriteLine();
                  }
              }


              if (!find)
                  Console.WriteLine("Impossible");
         
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