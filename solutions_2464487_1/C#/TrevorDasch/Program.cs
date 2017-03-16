using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamRound1A
{
    class Program
    {


        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"C:\Users\Trevor\Downloads\input.txt");
            StreamWriter sw = new StreamWriter(@"C:\Users\Trevor\Downloads\output.txt");



            int count = int.Parse(sr.ReadLine());

            for (int x = 0; x < count; x++)
            {
                sw.Write("Case #" + (x + 1) + ": ");

                Do(sr, sw);
            }
            sw.Flush();
        }

        public static void Do(StreamReader sr, StreamWriter sw)
        {
            string s = sr.ReadLine();
            string[] splits = s.Split(' ');
            ulong r = ulong.Parse(splits[0]);
            ulong t = ulong.Parse(splits[1]);

            //Total = number of rings 

            // 3 + 7 + 11 + ... (2*(r + (N -1) * 2 )) +1 )
            // ( 2* r ) + ( 2 * (r+2) ) ... ( 2 * (r + ((N * 2) -2 )) + {CONST} (N )  

            // ( N * ( 2* r) ) 

            //  0 + 4 + ... + ( 2 * ( N * 2) - 2) +  {CONST} N * (2 * r ) + (N) = t

            // 0 + 4 + ... + ( N * 4 ) +  {CONST} ( -4 * N + N * 2 *r + N)

            // .... + ( N * 4) +   {CONST} (N * (2 * r - 5) )

            // {CONST} 2 * (N ) * (N + 1)  + (N * ( 2 * r - 3) )

            // N * (2 * N + 2 + 2 * r - 3)
            // N * ( 2 * (N + r) - 1)

            // t 

            // N = t / ( 2 * N + 2 * r - 1)

            // 2 * N * N + N * (2 * r - 1) = t
            

            // t = x * N

            // 2 * N + 2 * r - 1 = x

            // x <= t
            // 2 * r - 1 + 2 * N <= t

            // N <= ( t - 2* r + 1 ) / 2

            //approx = sqrt(t);

            ulong approx = (ulong)Math.Sqrt((double)t) + 1;

            if (approx > 1+(t / (2 * r - 1)))
            {
                approx = 1+(t / (2 * r - 1));
            }

            ulong sum = 0;


            ulong min = 0;
            ulong max = approx;

            approx = (max + min) / 2;

            ulong final = 0;
            while (true)
            {


                if ((approx * (2 * approx + 2 * r - 1)) > t)
                {
                    if (min +1 >= max )
                    {
                        final = min;
                        break;
                    }

                    max = approx;
                    approx = (max + min) / 2;

                    //sum += (2 * (approx ) - 1 + r) * (2 * (approx ) - 1+ r) - (2 * (approx) - 2 + r) * (2 * (approx) - 2 + r);
                }
                else
                {
                    if (min +1 >= max )
                    {
                        final = min;
                        break;
                    }

                    min = approx;
                    approx = (max + min) / 2;

                }
            }

            sw.WriteLine(final);

        }

    }
}
