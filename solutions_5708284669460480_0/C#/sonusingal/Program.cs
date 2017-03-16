using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleContest
{
    class Program
    {
        static void Main(string[] args)
        {
            var fr = new FileStream(@"C:\Users\Sonu\Desktop\GC\p-2\r3\\B-small-attempt1 (2).in", FileMode.Open);
            var fr2 = new FileStream(@"C:\Users\Sonu\Desktop\GC\p-2\r3\\B-small-attempt1 (2).out", FileMode.Create);
            var sr = new StreamReader(fr);
            var sw = new StreamWriter(fr2);
            var t = int.Parse(sr.ReadLine());
            for(var i=0;i<t;i++)
            {
                var line = sr.ReadLine().Split(' ');
                var k = int.Parse(line[0]);
                var l = int.Parse(line[1]);
                var s = int.Parse(line[2]);
                var ks = sr.ReadLine();
                var ls = sr.ReadLine();
                var s2 = BananasLeft(k,l,s,ks,ls);
                s2 = string.Format("{0:G29}", decimal.Parse(s2));
                if (!s2.Contains(".")) s2 += ".0";
                    sw.WriteLine("Case #{0}: {1}", i + 1, s2);
            }
            sw.Flush();
            sw.Close();
        }

        private static string BananasLeft(int k, int l, int s, string ks, string ls)
        {
            var chars = ks.ToList();
            var targets = ls.ToList();
            if (targets.Any(x => !chars.Contains(x)) || l > s) return "0.0";
            var ccc =0;
            var i= 1;
            while(true)
            {
            i = ls.IndexOf(ls[0],i);
                if(i<=0) break;
                if( ls.IndexOf(ls.Substring(i)) < i) 
                {ccc = l-i; break;
                }
                i++;
            }

            var tc = 1 + (s - l) / (l - ccc);
            var pnm = 1;
            var pdn = Math.Pow(k,l);
            Dictionary<char, int> pd = new Dictionary<char, int>();

            foreach(var lc in ls)
            {
                if(!pd.ContainsKey(lc))
                {
                   pd.Add(lc,chars.Count(x => x == lc));
                }

                pnm *= pd[lc];
            }

            var fp = (double)pnm / (double)pdn;
            if (fp < 0.000001) fp = 0;
                return string.Format("{0:N7}", tc* (1-fp));
        }

        private static int LeastAttempts(int r, int c, int w)
        {
            if (w == 1) return r * c;
            if(r==1 && w >= c-1) return c;
            var dcc = w > c / 2 ? 1 : c/w;
            var count = (r - 1) * dcc;
            var lrc = (int)Math.Ceiling((double)c/(double)w) + w - 1;
            return count + lrc;
        }
    }
}
