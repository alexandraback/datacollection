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



        static void ProblemC()
        {
            StreamReader reader = new StreamReader(@"C:\tmp\C.in", Encoding.ASCII);
            StreamWriter writer = new StreamWriter(@"C:\tmp\outC.txt");
            string s = reader.ReadLine();

            StreamReader reader2 = new StreamReader(@"C:\tmp\garbled_email_dictionary.txt", Encoding.ASCII);


            int m = int.Parse(s);
            for (int i = 0; i < m; i++)
            {
                string x = null;//ProblemC2(reader.ReadLine());
                x = "Case #" + (i + 1).ToString() + ":" + " " + x;
                writer.WriteLine(x);
            }
            reader.Close();
            writer.Close();
        }

        static int A2(string s, int n)
        {
            string t = "aeiou";
            int r = 0;
            for (int i = 0; i < s.Length; i++)
            {
                int c = 0;
                int max = 0;
                for (int j = i; j < s.Length; j++)
                {
                    string u = s.Substring(j, 1);
                    if (t.Contains(u))
                    {
                        c = 0;
                    }
                    else
                    {
                        c++;
                    }
                    if (c > max) max = c;
                    if (max >= n)
                    {
                        r++;
                    }
                }
            }
            return r;
        }


        static void A()
        {
            StreamReader reader = new StreamReader(@"C:\tmp\A.in", Encoding.ASCII);
            StreamWriter writer = new StreamWriter(@"C:\tmp\outA.txt");
            string s = reader.ReadLine();

            string r = "";
            int m = int.Parse(s);
            for (int i = 0; i < m; i++)
            {
                string[] c = reader.ReadLine().Split();
                int x = A2(c[0], int.Parse(c[1]));
                r = "Case #" + (i + 1).ToString() + ":" + " " + x.ToString();
                writer.WriteLine(r);
            }
            reader.Close();
            writer.Close();
        }

        static string B2(int X, int Y)
        {
            string r = "";
            string x = "W";
            if (X < 0)
            {
                x = "E";
                X = -X;
            }
            for (int i = 0; i < 2 * X; i++)
            {
                r = r + x;
                if (x == "E")
                {
                    x = "W";
                }
                else
                {
                    x = "E";
                }
            }

            string y = "S";
            if (Y < 0)
            {
                y = "N";
                Y = -Y;
            }
            for (int i = 0; i < 2 * Y; i++)
            {
                r = r + y;
                if (y == "N")
                {
                    y = "S";
                }
                else
                {
                    y = "N";
                }
            }

            return r;
        }


        static void B()
        {
            StreamReader reader = new StreamReader(@"C:\tmp\B.in", Encoding.ASCII);
            StreamWriter writer = new StreamWriter(@"C:\tmp\outB.txt");
            string s = reader.ReadLine();

            string r = "";
            int m = int.Parse(s);
            for (int i = 0; i < m; i++)
            {
                string[] c = reader.ReadLine().Split();
                string x = B2(int.Parse(c[0]), int.Parse(c[1]));
                r = "Case #" + (i + 1).ToString() + ":" + " " + x;
                writer.WriteLine(r);
            }
            reader.Close();
            writer.Close();
        }

        static void Main(string[] args)
        {
            // ProblemA();
            //  ProblemB();
            //ProblemC();
            //A();
            B();
        }
    }
}
