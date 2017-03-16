using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam2012
{
    class Program
    {
        static void Main(string[] args)
        {
            int size = int.Parse(Console.ReadLine());

            for (int i = 0; i < size; i++)
            {
                Console.Write("Case #");
                Console.Write(i+1);
                Console.Write(": ");
                
                
                string inputs = Console.ReadLine();
                string[] ips = inputs.Split(' ');

                int N = int.Parse(ips[0]);
                int S = int.Parse(ips[1]);
                int p = int.Parse(ips[2]);

                int d1 = 1;
                int d2 = 2;
                if (p == 1)
                {
                    d2 = 1;
                }
                if (p == 0)
                {
                    d1 = d2 = 0;
                }

                int p1 = p * 3 - d1 * 2;
                if (p1 < 0) p1 = 0;
                int p2 = p * 3 - d2 * 2;
                if (p2 < 0) p2 = 0;

                int pt1 = 0;
                int pt2 = 0;

                for(int s=3;s<ips.Length ;s++)
                {
                    int x = int.Parse(ips[s]);

                    if (x >= p1)
                    {
                        pt1++;
                    }
                    else if(x >=p2)
                    {
                        pt2++;
                    }
                }

                if (pt2 > S)
                {
                    pt2 = S;
                }

                Console.Write(pt1 + pt2);
                Console.WriteLine();
            }
        }

    }
}
