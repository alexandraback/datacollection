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

        static int E(List<UInt64> l, UInt64 a, UInt64 b)
        {
            int c = 0;
            for (int i = 0; i < l.Count; i++)
            {
                if (l[i] >= a && l[i] <= b) c++;
            }
            return c;
        }

        static string J(int[] key, int[] c, List<int>[] l)
        {
            string r = "";
            for (int i = 1; i < c.Length; i++)
            {
                if (c[i] < 0) continue;
                if (l[i].Count == 0) continue;
                int t = c[i];
                if (key[t] > 0)
                {
                    List<int> x = l[i];
                    if (x.Contains(t))
                    {
                        key[t]--;
                        c[i] = -1;
                        for (int j = 0; j < x.Count; j++) key[x[j]]++;
                        r = r + " " + i.ToString();
                        i = 0;
                    }
                }
            }
            return r;
        }

        static string K(int[] key, int[] c, List<int>[] l, string o)
        {
            for (int i = 1; i < c.Length; i++)
            {
                if (c[i] < 0) continue;
                if (l[i].Count == 0) continue;
                int t = c[i];
                if (key[t] > 0)
                {
                    c[i] = -1;
                    key[t]--;
                    List<int> x = l[i];
                    for (int j = 0; j < x.Count; j++) key[x[j]]++;
                    string r = K(key, c, l, i.ToString());
                    if (r != "IMPOSSIBLE") return o + " " + r;
                    c[i] = t;
                    key[t]++;
                    for (int j = 0; j < x.Count; j++) key[x[j]]--;
                }
            }

            for (int i = 1; i < c.Length; i++)
            {
                if (!(c[i] < 0 || l[i].Count == 0)) return "IMPOSSIBLE";
            }
            return o;
        }

        static string I(int[] key, int[] c, List<int>[] l)
        {
            string r = J(key, c, l);
            string p = K(key, c, l, "");
            if (p == "IMPOSSIBLE") return p;

            for (int i = 1; i < c.Length; i++)
            {
                if (c[i] < 0) continue;
                int t = c[i];
                if (key[t] > 0)
                {
                    key[t]--;
                    p = p + " " + i.ToString();
                }
                else
                {
                    return "IMPOSSIBLE";
                }
            }

            return r + p;
        }

        static string H(int[] key, int[] c, List<int>[] l, string o, List<int>[] ex, int[] sum)
        {
            int count = 0;
            for (int i = 1; i < c.Length; i++)
            {
                if (c[i] < 0)
                {
                    count++;
                    continue;
                }

                int t = c[i];
                if (key[t] > 0)
                {
                    List<int> x = l[i];
                    bool f = false;
                    for (int k = 1; k < i; k++)
                    {
                        if (c[k] < 0) continue;
                        if (ex[i].Contains(k)) f = true;
                    }
                    if (f) continue;
                    f = false;
                    if (key[t] >= sum[t]) f = true;
                    if (l[i].Contains(t)) f = true;
                    c[i] = -1;
                    key[t]--;
                    sum[t]--;
                    for (int j = 0; j < x.Count; j++) key[x[j]]++;
                    string r = H(key, c, l, i.ToString(), ex, sum);
                    if (r != "IMPOSSIBLE") return o + " " + r;
                    c[i] = t;
                    key[t]++;
                    sum[t]++;
                    for (int j = 0; j < x.Count; j++) key[x[j]]--;
                    if (f) return "IMPOSSIBLE";
                }
            }

            if (count == c.Length - 1) return o;
            return "IMPOSSIBLE";
        }

        static List<int>[] L(List<int>[] l)
        {
            List<int>[] r = new List<int>[l.Length];
            for (int i = 1; i < l.Length; i++)
            {
                r[i] = new List<int>();
                List<int> x = l[i];
                for (int j = 1; j < i; j++)
                {
                    List<int> y = l[j];
                    if (y.Count < x.Count) continue;
                    bool f = true;
                    for (int k = 0; k < x.Count; k++)
                    {
                        if (!y.Contains(x[k]))
                        {
                            f = false;
                            break;
                        }
                        if (f) r[i].Add(j);
                    }
                }
            }
            return r;
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"C:\tmp\test.in", Encoding.ASCII);
            string s = sr.ReadLine();
            string output = "";

            int n = int.Parse(s);
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine(i + 1);
                s = sr.ReadLine();
                string[] a = s.Split(' ');
                int m = int.Parse(a[1]);
                s = sr.ReadLine();
                a = s.Split(' ');

                int[] key = new int[201];

                for (int j = 0; j < a.Length; j++)
                {
                    key[int.Parse(a[j])]++;
                }

                int[] c = new int[m + 1];
                List<int>[] l = new List<int>[m + 1];
                for (int j = 1; j < m + 1; j++)
                {
                    s = sr.ReadLine();
                    a = s.Split(' ');
                    c[j] = int.Parse(a[0]);
                    l[j] = new List<int>();
                    for (int k = 2; k < a.Length; k++)
                    {
                        l[j].Add(int.Parse(a[k]));
                    }
                }
                int[] sum = new int[key.Length];
                for (int j = 1; j < c.Length; j++)
                {
                    sum[c[j]]++;
                }
                int[] sum_key = new int[key.Length];
                Array.Copy(key, sum_key, key.Length);
                for (int j = 1; j < l.Length; j++)
                {
                    foreach (int x in l[j])
                    {
                        sum_key[x]++;
                    }
                }
                bool f = false;
                for (int j = 1; j < sum.Length; j++)
                {
                    if (sum[j] > sum_key[j]) f = true;
                }

                //if (c.Length > 18) continue;
                List<int>[] ex = L(l);
                string r = "IMPOSSIBLE";
                //if (!f)
                //{
                //    int[] tmp = (int[])key.Clone();
                //    int[] tmp2 = (int[])c.Clone();
                //   // r = I(key, c, l);
                //    if(r!="IMPOSSIBLE")
                //    {
                //        //r = H(tmp, tmp2, l, "", ex, sum);
                //    }
                //}
                if (!f)
                {
                    r = H(key, c, l, "", ex, sum);
                }
                output += "Case #" + (i + 1).ToString() + ":" + " " + r + "\r\n";
            }
            output = output.Replace("  ", " ");
            StreamWriter writer = new StreamWriter(@"C:\tmp\out.txt", false, Encoding.ASCII);
            writer.Write(output);
            writer.Close();
        }
    }
}
