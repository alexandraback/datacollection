using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace codejam_1b_1
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(args.Length > 0 ? args[0] : "in");
            FileStream fsOut = new FileStream("out.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fsOut);
            sw.AutoFlush = true;
            int testCount = int.Parse(sr.ReadLine());
            for (int i = 0; i < testCount; i++)
            {
                sw.Write(string.Format("Case #{0}: ", i + 1));
                long n = long.Parse(sr.ReadLine());
                long res = 0;
                long cur = 0;
                while (cur < n)
                {
                    string s = cur.ToString();
                    long curx = long.Parse(String.Join("", s.Reverse()));
                    if (curx - cur > 1 && curx <= n)
                        cur = curx;
                    else
                        cur++;
                    res++;
                }
                sw.WriteLine(res);
            }
            fsOut.Close();
        }
    }
}
