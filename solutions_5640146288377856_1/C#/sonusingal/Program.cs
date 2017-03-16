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
            var fr = new FileStream(@"C:\Users\Sonu\Desktop\GC\p-2\r3\\A-large.in", FileMode.Open);
            var fr2 = new FileStream(@"C:\Users\Sonu\Desktop\GC\p-2\r3\\A-large.out", FileMode.Create);
            var sr = new StreamReader(fr);
            var sw = new StreamWriter(fr2);
            var t = int.Parse(sr.ReadLine());
            for(var i=0;i<t;i++)
            {
                var line = sr.ReadLine().Split(' ');
                var r = int.Parse(line[0]);
                var c = int.Parse(line[1]);
                var w = int.Parse(line[2]);
                    sw.WriteLine("Case #{0}: {1}", i + 1, LeastAttempts(r,c,w));
            }
            sw.Flush();
            sw.Close();
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
