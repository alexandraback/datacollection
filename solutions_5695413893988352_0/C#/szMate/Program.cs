using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace ProblemBBruteForce
{
    class Program
    {
        static string mindiff(string cj)
        {
            int pos = 0;
            while(pos < cj.Length && cj[pos] != '?')
            {
                pos++;
            }
            if (pos >= cj.Length)
            {
                return cj;
                /*string[] g = cj.Split();
                return (int)Math.Abs(Int32.Parse(g[0]) - Int32.Parse(g[1]));*/
            }
            int minfucker = int.MaxValue;
            string best = "";
            StringBuilder eee = new StringBuilder(cj);
            for (int i = 0; i < 10; i++)
            {
                eee[pos] = (char)('0' + i);
                string  st = mindiff(eee.ToString());
                string[] g = st.Split();
                int t = (int)Math.Abs(Int32.Parse(g[0]) - Int32.Parse(g[1]));
                if (t < minfucker)
                {
                    minfucker = t;
                    best = st.ToString();
                }
            }
            return best;
        }


        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("B-small-attempt3(2).in");
            StreamWriter sw = new StreamWriter("outs4.txt");
            long T = Int64.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string[] CJ = sr.ReadLine().Split();
                string C = CJ[0];
                string J = CJ[1];
                StringBuilder c = new StringBuilder(CJ[0]);
                StringBuilder j = new StringBuilder(CJ[1]); 

                // Instantiate the regular expression object.
               /* Regex rc = new Regex(C, RegexOptions.IgnoreCase);
                Regex rj = new Regex(J, RegexOptions.IgnoreCase);
                for (int j = 0; j < 10; j++)
                {
                    
                }*/

                //mindiff(C + " " + J);
                //sw.WriteLine(mindiff(C + " " + J));
                sw.WriteLine("Case #{0}: {1}", i + 1, mindiff(C + " " + J));
            }
            sw.Close();
            sr.Close();
        }
    }
}
