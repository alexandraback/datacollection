using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam
{
    class Program
    {
        
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader("a.in");
            using (StreamWriter w = new StreamWriter("a.out"))
            {
                int t = int.Parse(reader.ReadLine());
                long R, C, W;

                for (int i = 0; i < t; i++)
                {
                    string[] numeros = reader.ReadLine().Split(' ');
                    R = long.Parse(numeros[0]);
                    C = long.Parse(numeros[1]);
                    W = long.Parse(numeros[2]);

                    w.WriteLine("Case #" + (i + 1) + ": " + solucion(R, C, W));
                }
            }
            
        }

        static long solucion(long R, long C, long W)
        {
            long total = (C / W) * R;

            if(C % W == 0)
            {
                total += W - 1;
            }
            else
            {
                total += W;
            }

            return total;
        }
            
    }
}
