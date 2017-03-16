using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace CodeJamQualA
{
    class Program
    {
        static void Main(string[] args)
        {
            string countstr = System.Console.ReadLine();
            int count = int.Parse(countstr);

            string outputstr = "";
            for (int i = 0; i < count; i++)
            {
                outputstr += ("Case #"+(i+1)+": "+Process()+"\n");
            }

            System.Console.WriteLine(outputstr);


        }


        static string Process()
        {
            string instr = System.Console.ReadLine();
            string[] splstr = instr.Split(" ".ToCharArray());

            long A = long.Parse(splstr[0]);
            long B = long.Parse(splstr[1]);


            int count = 0;

            int c = 1+(int)Math.Log10((double)B);


            for (long i = A; i < B; i++)
            {

                List<long> hit = new List<long>();

                long tmp = i;
                for (int j = 0; j < c; j++)
                {
                    
                    tmp = (tmp % 10) * (long)Math.Pow(10,c-1) + tmp / 10;
 
                    if (tmp > i && tmp <= B && !hit.Contains(tmp))
                    {
                        hit.Add(tmp);
                        count++;
                    }
                }


            }
            return count + "";
        }
       
    }
}
