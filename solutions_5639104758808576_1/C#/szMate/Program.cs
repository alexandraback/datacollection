using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace StandingOvation
{
    class Program
    {
        static int howmany(string s, int smax)
        {
            int standing = 0;
            int bring = 0;
            int i=0;
            while (standing<smax){
                standing += Int32.Parse(s[i].ToString());
                if (standing < i + 1)
                {
                    bring += i + 1 - standing;
                    standing = i + 1;
                }
                i++;
            }
            return bring;
        }

        static void Main(string[] args)
        {
            StreamWriter sw = new StreamWriter("A-large.out.txt");
            StreamReader sr = new StreamReader("A-large.in");
            int T = Int32.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string[] line = sr.ReadLine().Split(' ');
                int smax =  Int32.Parse(line[0]);
                int bring = howmany(line[1], smax);
                sw.WriteLine("Case #{0}: {1}", i + 1, bring);
            }
            sr.Close();
            sw.Flush();
            sw.Close();
        }
    }
}
