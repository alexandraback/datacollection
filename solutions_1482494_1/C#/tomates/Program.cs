using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Diagnostics;

namespace ConsoleApplication1
{
    class Program
    {


        static string M(List<string> l, ref int level)
        {
            string r = "";

            for (int i = 0; i < l.Count; i++)
            {
                string t = l[i];

                string[] a = t.Split(' ');

                int x = Int32.Parse(a[0]);
                int y = Int32.Parse(a[1]);

                if (y <= level)
                {
                    if (x != -1)
                    {
                        level = level + 2;
                    }
                    else
                    {
                        level++;
                    }
                    l.Remove(t);
                    return t;
                }

                if (x <= level && x != -1)
                {
                    if (r == "")
                    {
                        r = t;
                    }
                    else
                    {
                        string[] b = r.Split(' ');
                        int z = Int32.Parse(b[1]);
                        if (y > z)
                        {
                            r = t;
                        }

                    }
                }

            }

            if (r == "")
            {
                return r;
            }

            level++;
            l.Remove(r);
            string[] c = r.Split(' ');
            l.Add("-1 " + c[1]);

            return r;
        }

        static string X(List<string> l)
        {
            int level = 0;
            int step = 0;

            // List<string> l = new List<string>();
            int[] b = new int[l.Count];

            while (l.Count > 0)
            {

                string t = M(l, ref level);

                if (t == "")
                {
                    return "Too Bad";
                }

              //  l.Remove(t);
                step++;
            }




            return step.ToString();
        }


        static void Main(string[] args)
        {
            string x = @"C:\Users\a\Desktop\test.txt";
            //string x = @"C:\Users\a\Desktop\B-small-practice.in";
            //string x = @"C:\Users\a\Desktop\B-large-practice.in";
            //string x = @"C:\Users\a\Desktop\A-large-practice.in";
            StreamReader sr = new StreamReader(x, Encoding.ASCII);

            string s;
            string output = "";

            int n = 0;

            string[] t = new string[2];

            while ((s = sr.ReadLine()) != null)
            {
                if (s == "") continue;

                if (n > 0)
                {
                    int m = int.Parse(s);

                    List<string> l = new List<string>();
                    for (int i = 0; i < m; i++)
                    {
                        l.Add(sr.ReadLine());
                    }

                    string o = X(l);
                    output += String.Format("Case #{0}: {1}\n", n, o);
                }

                n++;
            }

            sr.Close();

            StreamWriter writer = new StreamWriter(@"C:\Users\a\Desktop\output.txt", false, Encoding.ASCII);
            writer.Write(output);
            writer.Close();
        }
    }
}
