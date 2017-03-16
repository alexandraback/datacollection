using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static bool isPal(long n)
        {
            string s = n.ToString();
            for (int i = 0; i <= s.Length/2; i++)
                if (s[i] != s[s.Length - i-1]) return false;
            return true;
        }
        static void Main(string[] args)
        {
            using (StreamReader sr = File.OpenText(@"C:\Users\esedo_000\Desktop\in.txt"))
            {

                int T, r=0,ret;
                long A, B;
                int[] count = new int[10000003];
                for (long i = 1; i * i <= 1e14; i++)
                {
                        long z = i * i;
                        if (isPal(z) && isPal(i))
                            r++;
                        count[i] = r;
                }
                T = int.Parse(sr.ReadLine());
                for (int K = 1; K <= T; K++)
                {
                    string[] text = sr.ReadLine().Split(' ');
                    A = long.Parse(text[0]);
                    B = long.Parse(text[1]);
                    double a = Math.Sqrt(A);
                    double b = Math.Sqrt(B);
                    long low = (int)(a) - 1;
                    long up = (int)(b) + 1;
                    while ((long)(low) * low < A) low++;
                    low--;
                    while ((long)(up) * up > B) up--;
                    ret = count[up] - count[low];
                    using (System.IO.StreamWriter file = new System.IO.StreamWriter(@"C:\Users\esedo_000\Desktop\out2.txt", true))
                    {
                        file.WriteLine("Case #" + K + ": " + ret);
                    }

                }
            }
        }
    }
}
