using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace codejam04
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("in");
            FileStream fsOut = new FileStream("out", FileMode.Create);
            StreamWriter sw = new StreamWriter(fsOut);
            sw.AutoFlush = true;
            int testCount = int.Parse(sr.ReadLine());
            for (int i = 0; i < testCount; i++)
            {
                sw.Write(string.Format("Case #{0}: ", i + 1));
                string[] data1 = sr.ReadLine().Split(' ');

                byte x = byte.Parse(data1[0]);
                byte r = byte.Parse(data1[1]);
                byte c = byte.Parse(data1[2]);

                if (SolveTest(x, r, c))
                    sw.WriteLine("RICHARD");
                else
                    sw.WriteLine("GABRIEL");

            }
            fsOut.Close();
        }

        private static bool SolveTest(byte x, byte r, byte c)
        {
            if (x >= 7)
                return true;
            if ((r * c) % x != 0)
                return true;
            if (Math.Min(r, c) < (x + 1) / 2)
                return true;

            return false;
        }
    }
}
