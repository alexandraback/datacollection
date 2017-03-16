using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace codejam_1c_1
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
            for (int ii = 0; ii < testCount; ii++)
            {
                sw.Write(string.Format("Case #{0}: ", ii + 1));
                string[] data = sr.ReadLine().Split(' ');
                int r = int.Parse(data[0]);
                int c = int.Parse(data[1]);
                int w = int.Parse(data[2]);

                if (w == 1) { sw.WriteLine(r * c); continue; }
                if (c == w) { sw.WriteLine(c + r - 1); continue; }

                int rem;
                int res = Math.DivRem(r * c, w, out rem);
                //if(tmp > 0) res
                sw.WriteLine(r * res + w + (rem == 0 ? - 1 : 0));
            }
            fsOut.Close();
        }
    }
}
