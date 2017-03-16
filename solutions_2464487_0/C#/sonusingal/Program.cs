using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleContest1
{
    class Program
    {
        static void Main(string[] args)
        {
            var sr = new StreamReader(@"C:\Users\Sonu\Desktop\Contest\Google\1\A-small-attempt1.in");
            var sw = new StreamWriter(@"C:\Users\Sonu\Desktop\Contest\Google\1\A-small-attempt1_output1.in", true);
            sw.AutoFlush = true;
            var count = int.Parse(sr.ReadLine().Trim());
            for (var i = 0; i < count; i++)
            {
                    var line = sr.ReadLine().Split(' ');
                    sw.WriteLine(string.Format("Case #{0}: {1}", i + 1, NoOfRings(int.Parse(line[0]), int.Parse(line[1]))));                
            }
        }

        private static int NoOfRings(int r, int t)
        {
            var n = 0;
            while (t > 0)
            {
                var p = 2 * r + 1;
                if (p > t) break;
                t -= p;
                n++;
                r += 2;
            }
            return n;
        }
    }
}
