using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _14_2B
{
    class Program
    {
        static void Main(string[] args)
        {
            int T;

            string str;
            string[] strs;
            str = Console.ReadLine();
            T = int.Parse(str);

            for (int caseNumber = 1; caseNumber <= T; caseNumber++)
            {
                long P, Q;
                str = Console.ReadLine();
                strs = str.Split('/');
                P = long.Parse(strs[0]);
                Q = long.Parse(strs[1]);


                int Qpow = 0;
                long Qamari = 0;
                int Ppow = 0;
                const long mask = 1;
                for (int i = 0; i < 50; i++)
                {
                    if ((Q & (mask << i)) != 0)
                    {
                        Qpow = i;
                        Qamari = Q / (mask << i);
                        break;
                    }
                }

                if (P % Qamari != 0)
                {

                    Console.WriteLine("Case #" + caseNumber + ": impossible");
                    goto next;
                }

                long Pnew = P / Qamari;

                for (int i = 0; i < 50; i++)
                {
                    if ((Pnew & (mask << i)) != 0)
                    {
                        Ppow = i;
                    }
                }



                Console.WriteLine("Case #" + caseNumber + ": " + (Qpow - Ppow));
            next:
                continue;

            }

            Console.Error.WriteLine("fin");

            Console.ReadLine();

        }
    }
}
