using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace codejam01
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("in.txt");
            FileStream fsOut = new FileStream("out.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fsOut);
            sw.AutoFlush = true;
            int testCount = int.Parse(sr.ReadLine());
            for (int i = 0; i < testCount; i++)
            {
                sw.Write(string.Format("Case #{0}: ", i + 1));

                string[] data = sr.ReadLine().Split(' ');
                int sm = int.Parse(data[0]);

                int res = 0;
                int s = 0;
                for (int j = 0; j <= sm; j++)
                {
                    byte t = Byte.Parse(data[1][j].ToString());
                    if (t > 0)
                    {
                        if (j > s)
                        {
                            res += j - s;
                            s = j;
                        }
                    }
                    s += t;
                }
                sw.WriteLine(res);
            }
            fsOut.Close();
            
        }
    }
}
