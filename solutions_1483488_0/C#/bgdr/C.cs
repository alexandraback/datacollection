using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;
namespace GoogleCodeJam
{
    class C
    {
        static int solve(int A, int B, bool outp)
        {
            Hashtable ht = new Hashtable();
            int ret = 0;
            for (int k = A; k <= B; ++k)
            {
                string n = k.ToString();
                for (int j = 1; j < n.Length; j++)
                {
                    string start = n.Substring(0, n.Length - j);
                    string end = n.Substring(n.Length - j);
                    string m = end + start;
                    if (m.StartsWith("0")) continue;
                    int mi = Int32.Parse(m);
                    if (mi <= k || mi > B) continue;
//                    if (outp) Console.WriteLine(n + " " + m);
                    string key = n + " " + m;
                    if (ht.ContainsKey(key)) continue;
                    ht.Add(key, true);
                    ret++;
                }
            }
            return ret;
        }
        public static void Main(String[] args)
        {
            StreamReader sr = new StreamReader("C.in");
            StreamWriter sw = new StreamWriter("C.out");
            int T;
            int A, B;
            T = Int32.Parse(sr.ReadLine());
            for (int i = 1; i <= T; ++i)
            {
                string[] toks = sr.ReadLine().Split(' ');
                A = Int32.Parse(toks[0]);
                B = Int32.Parse(toks[1]);
                sw.WriteLine("Case #" + i + ": " + solve(A, B, i == 2));
            }
            sw.Close();
        }
    }
}
