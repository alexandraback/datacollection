using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ1CA
{
    class Program
    {
        bool[] b;

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("A-small-attempt0.in");
            StreamWriter sw = new StreamWriter("out.txt");

            int T, N;
            T = Int32.Parse(sr.ReadLine());
            List<List<int>> lls;
            for (int i = 0; i < T; i++)
            {
                lls = new List<List<int>>();
                N = Int32.Parse(sr.ReadLine());
                for (int j = 0; j < N; j++)
                {
                    string[] str = (sr.ReadLine()).Split(' ');
                    List<int> ls = new List<int>();
                    int m = Int32.Parse(str[0]);
                    for (int k = 0; k < m; k++)
                        ls.Add(Int32.Parse(str[k + 1]));
                    lls.Add(ls);
                }
                bool ans = true;
                for (int j = 0; j < N; j++)
                {
                    if (work(j+1, lls) == false)
                        ans = false;
                }
                if (ans == true)
                    sw.WriteLine("Case #{0}: No\n", i+1);
                else sw.WriteLine("Case #{0}: Yes\n", i+1);
            }

            sr.Close();
            sw.Close();
        }
        static bool work(int x, List<List<int>>lls)
        {
            List<int> stack = new List<int>();
            bool[] b = new bool[1000];
            for (int i = 0; i < 1000; i++) b[i] = false;
            stack.Add(x);
            bool ret = true;
            int p = 0;
            int temp;
            while (stack.Count > p)
            {
                temp = stack[p];
                if (b[temp-1] == true)
                {
                    ret = false;
                    break;
                }
                else {
                    b[temp-1] = true;
                    for (int k = 0; k < lls[temp-1].Count; k++)
                        stack.Add(lls[temp-1][k]);
                }
                p++;
            }
            return ret;
        }
    }

}
