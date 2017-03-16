using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace Pogo
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader inp = new StreamReader(Console.ReadLine());
            StreamWriter outp = new StreamWriter(Console.ReadLine());
            int t = Convert.ToInt32(inp.ReadLine());
            for (int i = 0; i < t; i++)
            {
                if (i == 49)
                    Console.WriteLine();
                int[] d = inp.ReadLine().Split(new char[] { ' ' }).Select<string, int>(x => int.Parse(x)).ToArray();
                int c = 1; // Current move
                int cX = 0;
                int cY = 0;
                bool nx = d[0] < 0;
                bool ny = d[1] < 0;
                string e = "";

                if (nx) d[0] = -d[0];
                if (ny) d[1] = -d[1];

                while (Math.Abs(d[0] - cX - c) < Math.Abs(d[0] - cX))
                {
                    e += "E";
                    cX += c;
                    c++;
                }

                while (cX != d[0])
                {
                    if (d[0] - cX < 0)
                    {
                        e += "EW";
                        c += 2;
                        cX -= 1;
                    }
                    else
                    {
                        e += "WE";
                        c += 2;
                        cX += 1;
                    }
                }

                while (Math.Abs(d[1] - cY - c) < Math.Abs(d[1] - cY))
                {
                    e += "N";
                    cY += c;
                    c++;
                }

                while(cY != d[1])
                {
                    if (d[1] - cY < 0)
                    {
                        e += "NS";
                        c += 2;
                        cY -= 1;
                    }
                    else
                    {
                        e += "SN";
                        c += 2;
                        cY += 1;
                    }
                }

                char[] fe = e.ToCharArray();

                if (nx)
                {
                    foreach (int q in Enumerable.Range(0, e.Length).Where(f => e[f] == 'E'))
                    {
                        fe[q] = 'W';
                    }
                    foreach (int q in Enumerable.Range(0, e.Length).Where(f => e[f] == 'W'))
                    {
                        fe[q] = 'E';
                    }
                }

                if (ny)
                {
                    foreach (int q in Enumerable.Range(0, e.Length).Where(f => e[f] == 'N'))
                    {
                        fe[q] = 'S';
                    }
                    foreach (int q in Enumerable.Range(0, e.Length).Where(f => e[f] == 'S'))
                    {
                        fe[q] = 'N';
                    }
                }

                outp.WriteLine(String.Format("Case #{0}: {1}", i + 1, new string(fe)));
                Console.WriteLine(String.Format("Case #{0}: {1}", i + 1, new string(fe)));
            }
            inp.Close();
            outp.Close();
            Console.ReadLine();
        }
    }
}
