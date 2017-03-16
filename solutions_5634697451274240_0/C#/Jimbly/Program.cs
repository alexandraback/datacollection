using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpProbB
{
  class Program
  {
    static void Main(string[] args)
    {
      int num_tests = int.Parse(Console.ReadLine());
      for (int i = 1; i <= num_tests; i++)
      {
        string S = Console.ReadLine();
        int N = S.Length;
        int tail = N-1;
        bool[] b = new bool[N];
        int ret = 0;
        for (int ii = 0; ii < N; ++ii) {
          b[ii] = (S[ii] == '+') ? true : false;
        }
        while (true) {
          while (tail >= 0 && b[tail]) {
            --tail;
          }
          if (tail == -1) {
            Console.WriteLine("Case #{0}: {1}", i, ret);
            break;
          }
          // b[tail] is bad
          if (!b[0]) {
            int count = tail + 1;
            ++ret;
            for (int ii = 0; ii < count / 2.0; ++ii) {
              bool t = b[ii];
              b[ii] = !b[count - ii - 1];
              b[count - ii - 1] = !t;
            }
          } else {
            int count = 0;
            while (b[count]) {
              ++count;
            }
            ++ret;
            for (int ii = 0; ii < count / 2.0; ++ii)
            {
              bool t = b[ii];
              b[ii] = !b[count - ii - 1];
              b[count - ii - 1] = !t;
            }
          }
//           for (var ii = 0; ii < N; ++ii)
//           {
//               Console.Write("{0}", b[ii] ? "+" : "-");
//           }
//           Console.WriteLine("");
        }
      }
    }
  }
}
