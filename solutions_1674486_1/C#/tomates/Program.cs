using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Diagnostics;

namespace ConsoleApplication1
{
    class Program
    {
        static bool g_flag;

        static void Y(List<List<int>> l, int[] flag, int num)
        {
            if (num == -1 || g_flag)
            {
                return;
            }

            if (flag[num] == 1)
            {
                g_flag = true;
                return;
            }

            flag[num] = 1;

            for (int j = 0; j < l[num].Count; j++)
            {
                Y(l, flag, l[num][j]);
            }
        }

        static string X(string[] s)
        {
            List<List<int>> l = new List<List<int>>();

            for (int i = 0; i < s.Length; i++)
            {
                string[] tmp = s[i].Split(' ');

                List<int> a = new List<int>();
                for (int j = 1; j < tmp.Length; j++)
                {
                    a.Add(int.Parse(tmp[j])-1);
                }
                l.Add(a);
            }

            string o = "No";

            for (int i = 0; i < l.Count; i++)
            {
                if (l[i].Count >= 2)
                {
                    int[] flag = new int[l.Count];
                    g_flag = false;

                    for (int j = 0; j < l[i].Count; j++)
                    {
                        Y(l, flag, l[i][j]);
                    }

                    if (g_flag == true)
                    {
                        o = "Yes";
                        break;
                    }
                }
            }

            return o;
        }


        static void Main(string[] args)
        {
            string x = @"C:\Users\a\Desktop\google code jam\test.in";
            StreamReader sr = new StreamReader(x, Encoding.ASCII);

            string s;
            string output = "";

            int n = 0;

            while ((s = sr.ReadLine()) != null)
            {
                if (s == "") continue;

                if (n > 0)
                {
                    int a = int.Parse(s);

                    List<string> l = new List<string>();
                    for (int i = 0; i < a; i++)
                    {
                        s = sr.ReadLine();
                        l.Add(s);
                    }
                    string o = X(l.ToArray());
                    output += String.Format("Case #{0}: {1}\n", n, o);
                }

                n++;
            }

            sr.Close();

            StreamWriter writer = new StreamWriter(@"C:\Users\a\Desktop\google code jam\out.txt", false, Encoding.ASCII);
            writer.Write(output);
            writer.Close();
        }
    }
}
