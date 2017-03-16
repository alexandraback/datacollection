using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream fs = new FileStream("B-small-attempt0.in", FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(fs, System.Text.Encoding.Default);
            sr.BaseStream.Position = 0;
            StreamWriter sw = new StreamWriter("B-small-attempt0.txt");

            int T = int.Parse(sr.ReadLine());
            for (int Ti = 0; Ti < T; Ti++)
            {
                string[] str = sr.ReadLine().Split(' ');
                int X = int.Parse(str[0]);
                int Y = int.Parse(str[1]);

                bool XT = isP(X);
                bool YT = isP(Y);

                string move = "";

                int ttt = 1;
                int pos = 0;
                while (pos != X)
                {
                    if (pos + ttt > X)
                    {
                        pos -= ttt;
                        move += 'W';
                    }
                    else
                    {
                        pos += ttt;
                        move += 'E';
                    }
                    ttt++;
                }
                while (pos != (X+Y))
                {
                    if (pos + ttt > (X + Y))
                    {
                        pos -= ttt;
                        move += 'S';
                    }
                    else
                    {
                        pos += ttt;
                        move += 'N';
                    }
                    ttt++;
                }
              
                sw.WriteLine("Case #" + (Ti + 1) + ": " + move);
            }
            sr.Dispose();
            sw.Dispose();
        }
        static bool isP(int n)
        {
            int t = 0;
            int i = 1;
            while (t <= n)
            {
                t += i;
                i++;
                if (t > n)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
