using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14.R1C
{
 using System;
 using System.Globalization;
 using System.Linq;
 using System.Xml.Serialization;

    public class A
    {
        public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];
            for (int i = 0; i < cases; i++)
            {
                int[] pars = lines[i + 1].Split(new char[1] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
                int R = pars[0], C = pars[1], W = pars[2];

                int x = C / W * R + (C % W == 0 ? W - 1 : W);



                Console.WriteLine("Case #{0}: {1}", (i+1), x);
                res[i] = string.Format("Case #{0}: {1}", (i+1), x);


            }
            return res;
        }

   
    }
}
