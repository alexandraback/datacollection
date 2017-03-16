using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemB
{
    class Program
    {
        static string negate(string s)
        {
            string ret = "";
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == '-') ret += '+';
                else ret += '-';
            }
            return ret;
        }

        static long rekur(string s)
        {
            if (s.Equals("+")) return 0;
            else if (s.Equals("-")) return 1;
            else
            {
                if (s[s.Length - 1] == '+')
                {
                    return rekur(s.Substring(0, s.Length - 1));
                }
                else
                {
                    return rekur(negate(s.Substring(0, s.Length - 1))) + 1;
                }
                //return rekur(negate(s.Substring(0, s.Length - 1))) + rekur(s.Substring(s.Length - 1, 1));
            }
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("B-small-attempt0(2).in");
            StreamWriter sw = new StreamWriter("outsmall.txt");
            long T = Int64.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string s = sr.ReadLine();
                sw.WriteLine("Case #{0}: {1}", i + 1, rekur(s));
            }
            sw.Close();
        }
    }
}
