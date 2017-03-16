using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace google_code_jam
{
    class Program
    {
        static void B(string[] s, int i, int j, ref int x, ref int o, ref int d)
        {
            string t = s[i].Substring(j, 1);
            if (t == "T")
            {
                x++;
                o++;
            }
            else if (t == "X")
            {
                x++;
            }
            else if (t == "O")
            {
                o++;
            }
            else
            {
                d = 1;
            }
        }

        static string C(int x, int o)
        {
            if (x == 4) return "X won";
            if (o == 4) return "O won";
            return null;
        }

        static string A(string[] s)
        {
            int m = s.Length;
            int d = 0;
            string r = "";

            int x, o;
            for (int i = 0; i < m; i++)
            {
                x = 0;
                o = 0;
                for (int j = 0; j < m; j++)
                {
                    B(s, i, j, ref x, ref o, ref  d);
                }
                r = C(x, o);
                if (r != null) return r;
            }

            for (int i = 0; i < m; i++)
            {
                x = 0;
                o = 0;
                for (int j = 0; j < m; j++)
                {
                    B(s, j, i, ref x, ref o, ref  d);
                }
                r = C(x, o);
                if (r != null) return r;
            }

            x = 0;
            o = 0;
            for (int i = 0; i < m; i++)
            {
                B(s, i, i, ref x, ref o, ref  d);
            }
            r = C(x, o);
            if (r != null) return r;

            x = 0;
            o = 0;
            for (int i = 0; i < m; i++)
            {
                B(s, m - i - 1, i, ref x, ref o, ref  d);
            }
            r = C(x, o);
            if (r != null) return r;

            if (d > 0) return "Game has not completed";
            return "Draw";
        }


        static string D(string[] s)
        {
            int n = s.Length;
            string[] t = s[0].Split(' ');
            int m = t.Length;
            int[,] a = new int[n, m];
            for (int i = 0; i < n; i++)
            {
                t = s[i].Split(' ');
                for (int j = 0; j < m; j++)
                {
                    a[i, j] = int.Parse(t[j]);
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int u = a[i, j];
                    bool f = true;
                    for (int k = 0; k < m; k++)
                    {
                        if (a[i, k] > u)
                        {
                            f = false;
                            break;
                        }
                    }
                    if (f) continue;
                    for (int k = 0; k < n; k++)
                    {
                        if (a[k, j] > u) return "NO";
                    }
                }
            }
            return "YES";
        }

        static bool F(string s)
        {
            string t = "";
            for (int i = 0; i < s.Length; i++)
            {
                t = s.Substring(i, 1) + t;
            }
            if (s == t) return true;
            return false;
        }

        static List<UInt64> G()
        {
            List<UInt64> l = new List<UInt64>();
            List<UInt64> z = new List<UInt64>();
            l.Add(1);
            l.Add(4);
            l.Add(9);
            z.Add(1);
            z.Add(2);
            z.Add(3);

            UInt64 max = ((UInt64)Math.Pow(10, 7)) + 1;
            for (UInt64 i = 10; i <= max; i++)
            {
                if (F(i.ToString()))
                {
                    UInt64 t = i * i;
                    if (F(t.ToString()))
                    {
                        l.Add(t);
                        z.Add(i);
                    }
                }
            }
            return l;
        }

        static int E(List<UInt64> l,UInt64 a, UInt64 b)
        {
            int c = 0;
            for (int i = 0; i < l.Count;i++ )
            {
                if(l[i]>=a && l[i]<=b)c++;
            }
            return c;
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"C:\tmp\test.in", Encoding.ASCII);
            string s = sr.ReadLine();
            string output = "";

            int n = int.Parse(s);
            for (int i = 0; i < n; i++)
            {
                s = sr.ReadLine();
                string[] a = s.Split(' ');
                int r = E(G(),UInt64.Parse(a[0]), UInt64.Parse(a[1]));
                output += "Case #" + (i + 1).ToString() + ":" + " " + r + "\r\n";
            }

            StreamWriter writer = new StreamWriter(@"C:\tmp\out.txt", false, Encoding.ASCII);
            writer.Write(output);
            writer.Close();
        }
    }
}
