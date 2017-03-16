using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

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

            int googlers = int.Parse(splstr[0]);
            int surprises = int.Parse(splstr[1]);
            int p = int.Parse(splstr[2]);

            if (p == 0)
                return googlers+"";
            int count = 0;

            for (int i = 3; i < splstr.Length; i++)
            {
                int goog = int.Parse(splstr[i]);

                if (goog == 0 || goog < (p * 3 - 4))
                    continue;
                if (goog < p * 3 - 2)
                {
                    if (surprises > 0)
                    {
                        surprises--;
                        count++;
                    }
                    continue;
                }
                count++;
            }
            return "" + count;
        }

    }
}
