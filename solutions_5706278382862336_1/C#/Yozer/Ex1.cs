using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Code_Jam_2014
{
    class Ex1
    {
        static void Main(string[] args)
        {
            using (StreamWriter writer = new StreamWriter("A-large.out"))
            {
                using (StreamReader sw = new StreamReader("A-large.in"))
                {
                    int num = int.Parse(sw.ReadLine());

                    for (int i = 1; i <= num; i++)
                    {
                        string[] line = sw.ReadLine().Split('/');
                        long P = long.Parse(line[0]);
                        long Q = long.Parse(line[1]);
                        writer.WriteLine("Case #" + i + ": " + Solve(P, Q));
                    }
                }
            }
           
        }

        static string Solve(long P, long Q)
        {
            int pokolenie = 0;

            long gcde = GCD(P, Q);
            P /= gcde;
            Q /= gcde;

            if ((Q & (Q - 1)) != 0)
                return "impossible";


            while (P < Q)
            {
                Q /= 2;
                pokolenie++;
            }

            if (pokolenie > 40)
                return "impossible";

            return pokolenie.ToString();
        }

        public static long GCD(long a, long b)
       {
           while (b != 0)
           {
               long tmp = b;
               b = a % b;
               a = tmp;
           }
 
           return a;
       }
    }
}
