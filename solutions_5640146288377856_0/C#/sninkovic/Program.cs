using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace codejam
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());

            for (int t=0;t<T;t++)
            {
                string[] tok = Console.ReadLine().Split(new char[] { ' ' });
                int R = int.Parse(tok[0]);
                int C = int.Parse(tok[1]);
                int W = int.Parse(tok[2]);


                int cnt = 0;
                if (W==1)
                {
                    Console.WriteLine("Case #{0}: {1}", (t+1), R * C);
                    continue;
                }
                int i = W;
                bool hitWall = false;
                for (; i <= R * C; i += (W))
                {
                    cnt++;
                    if (i == R * C)
                        hitWall = true;
                }
                if (hitWall)
                    cnt += (W - 1);
                else
                cnt += W;
                Console.WriteLine("Case #{0}: {1}", (t+1), cnt);

            }
        }
    }
}
