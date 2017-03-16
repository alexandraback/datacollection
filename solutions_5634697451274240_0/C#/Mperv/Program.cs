using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam_2016_Q_2_C_Sharp
{

    class Program
    {
        static String Solve(String s)
        {
            s = s + "+";           
            Char current = s[0];
            Int32 total = 0;

            for(Int32 i=1; i<s.Length; i++)
            {
                Char n = s[i];
                if (n != current)
                {
                    total++;
                    current = n;
                }
            }
            return total.ToString();
        }

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"Z:\Projects\Соревнования\CodeJam 2016\Qualification\Task2_input\B-small-attempt0.in");
            Int32 count = Int32.Parse(lines[0].Trim());
            for (Int32 i = 0; i < count; i++)
            {
                String res = Solve(lines[i + 1]);
                Console.WriteLine("Case #{0}: {1}", i + 1, res);
            }
        }
    }

}
