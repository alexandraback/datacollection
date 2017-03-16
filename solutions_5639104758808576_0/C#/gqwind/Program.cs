using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        
        static void Main(string[] args)
        {
            string fin = "A-small-attempt0.in";
            string fout = "output.txt";
            StreamReader sr = new StreamReader(fin);
            StreamWriter sw = new StreamWriter(fout);
            int T = Int32.Parse(sr.ReadLine());
            int n, ans;
            string str;
            string text;
            for (int i = 1; i <= T; i++)
            {
                text = sr.ReadLine();
                n = Int32.Parse(text.Split(' ')[0]);
                str = text.Split(' ')[1];
                int cur = 0;
                ans = 0;
                for (int j = 0; j <= n; j++)
                {
                    int num = (int)(str[j] - '0');
                    if (num == 0) continue;
                    if (cur < j)
                    {
                        ans = ans + j - cur;
                        cur = j;
                    }
                    cur += num;
                }
                sw.WriteLine(string.Format("Case #{0}: {1}", i, ans));
            }
            sr.Close();
            sw.Close();
        }
    }
}
