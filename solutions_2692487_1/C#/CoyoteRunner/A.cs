using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
//using System.Math.*;

namespace google_code_jam
{
    class Program
    {
        static string ProblemA2(UInt64 A, UInt64[] b)
        {
            if (A == 1) return b.Length.ToString();
            Array.Sort(b);
            UInt64 n = 0;
            UInt64 m = 0;
            UInt64[] g = new UInt64[b.Length];
            while (true)
            {
                if (b[n] < A)
                {
                    A += b[n];
                    g[n] = m;
                    m = 0;
                    n++;
                    if (n == (UInt64)b.Length) break;
                }
                else
                {
                    A += A - 1;
                    m++;
                }
            }

            UInt64 r = 0;
            m = 0;
            n = 0;
            for (int i = b.Length - 1; i >= 0; i--)
            {
                n++;
                m += g[i];
                if (m > n)
                {
                    r += n;
                    n = 0;
                    m = 0;
                }
            }
            r += m;
            return r.ToString();
        }

        static void ProblemA()
        {
            StreamReader reader = new StreamReader(@"C:\tmp\A.in", Encoding.ASCII);
            StreamWriter writer = new StreamWriter(@"C:\tmp\outA.txt");
            string s = reader.ReadLine();

            int m = int.Parse(s);
            for (int i = 0; i < m; i++)
            {
                string[] c = reader.ReadLine().Split();
                UInt64 A = UInt64.Parse(c[0]);
                string[] t = reader.ReadLine().Split();
                UInt64[] b = new UInt64[t.Length];
                for (int j = 0; j < t.Length; j++)
                {
                    b[j] = UInt64.Parse(t[j]);
                }

                string x = ProblemA2(A, b);
                x = "Case #" + (i + 1).ToString() + ":" + " " + x;
                writer.WriteLine(x);
            }
            reader.Close();
            writer.Close();
        }

        static void Main(string[] args)
        {
            ProblemA();
        }
    }
}
