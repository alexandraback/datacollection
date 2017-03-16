using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace codejam_1b_3
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
                int n = int.Parse(sr.ReadLine());
                int[] d = new int[n];
                int[] h = new int[n];
                int[] m = new int[n];
                for (int i = 0; i < n; i++)
                {
                    string[] data = sr.ReadLine().Split(' ');
                    d[i] = int.Parse(data[0]);
                    h[i] = int.Parse(data[1]);
                    m[i] = int.Parse(data[2]);
                }

                if (n > 1)
                {
                    //hiker1 start at d[0], speed m[0]
                    //hiker2 start at d[1], speed m[1]
                    float t1 = (360.0f - d[0]) / m[0];
                    float t2 = (360.0f - d[1]) / m[1];

                    if (Math.Max(t1, t2) / Math.Min(t1, t2) > 1)
                    {
                        sw.WriteLine("1"); continue;
                    }

                    if (t1 > t2 && d[0] > d[1])
                    {
                        sw.WriteLine("1"); continue;
                    }
                    if (t1 < t2 && d[0] < d[1])
                    {
                        sw.WriteLine("1"); continue;
                    }
                    sw.WriteLine("0");
                }
                else
                {
                    sw.WriteLine("0");
                    //hiker1 start at d[0], speed m[0]
                    //hiker2 start at d[0], speed m[0] + 1
                }

                //if (true)
                //    sw.WriteLine("0");
                //else
                //    sw.WriteLine("1");
            }
            fsOut.Close();
        }
    }
}
