using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        private static string rotate(string s)
        {
            string ans = s.Clone().ToString();
            string ch = ans.Substring(0,1);
            ans = ans.Remove(0, 1);
            ans = ans.Insert(ans.Length, ch);
            return ans;
        }
        static void Main(string[] args)
        {
            int T, tc, a, b, c, d, pos, mod, temp, skor;
            string tmp;
            HashSet<int> s = new HashSet<int>();
            T = Convert.ToInt32(Console.ReadLine());
            for (tc = 1; tc <= T; tc++)
            {
                tmp = Console.ReadLine();
                pos = tmp.IndexOf(' ');
                a = Convert.ToInt32(tmp.Substring(0, pos));
                b = Convert.ToInt32(tmp.Substring(pos + 1, tmp.Length - pos - 1));
                if (a > b)
                {
                    temp = a;
                    a = b;
                    b = temp;
                }
                s.Clear();
                for (c = a; c <= b; c++) s.Add(c);
                temp = b;
                mod = 0;
                while (temp != 0)
                {
                    mod++;
                    temp /= 10;
                }
                skor = 0;
                for (c = a; c <= b; c++)
                {
                    temp = 0;
                    tmp = c.ToString();
                    for (d = 0; d < mod; d++)
                    {
                        if (s.Contains(Convert.ToInt32(tmp)))
                        {
                            s.Remove(Convert.ToInt32(tmp));
                            temp++;
                        }
                        tmp = rotate(tmp);
                    }
                    skor += temp * (temp - 1) / 2;
                }
                Console.WriteLine("Case #" + tc.ToString() + ": " + skor.ToString());
            }
        }
    }
}
