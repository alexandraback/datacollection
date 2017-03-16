using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{


    class Program
    {

        static void Main(string[] args)
        {
            
            int T = int.Parse(Console.ReadLine());
            
            for(int t = 0; t < T; t++)
            {
                string[] s = Console.ReadLine().Split(' ');
                int R = int.Parse(s[0]);
                int C = int.Parse(s[1]);
                int W = int.Parse(s[2]);

                int p = 0;
                for(int i = 0; i < R; i++)
                {
                    p += C / W;
                }
                int odd = C % W;
                if(odd == 0)
                {
                    p += W - 1;
                }
                else
                {
                    p += W;
                }
                Console.WriteLine("Case #{0}: {1}", t + 1, p);
            }

        }

    }
}
