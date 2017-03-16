using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Consonants
{
    class Program
    {
        static void Main(string[] args)
        {
            System.IO.StreamReader sr = new System.IO.StreamReader("A-small-attempt0.in");
            System.IO.StreamWriter sw = new System.IO.StreamWriter("output.out");
            int T = Convert.ToInt32(sr.ReadLine());
            string s, pattern;
            string[] buf;
            int n, i, b, count;

            for (int t = 1; t<=T; t++)
            {
                count = 0;
                buf = sr.ReadLine().Split();
                s = buf[0];
                n = Convert.ToInt32(buf[1]);
                pattern = "[^aeiou]{" + n.ToString() + "}";
                while (System.Text.RegularExpressions.Regex.Match(s, pattern).Success)
                {
                    i = System.Text.RegularExpressions.Regex.Match(s, pattern).Index;
                    b = s.Length - i - n;
                    count += (i + 1) * (b + 1);
                    s = s.Substring(i + 1);
                }
                sw.WriteLine("Case #" + t.ToString() + ": " + count.ToString());
            }
            sw.Close();
        }
    }
}
