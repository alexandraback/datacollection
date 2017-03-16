using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam_2016_R1A_1
{
    class Program
    {
        static String Solve(String s)
        {
            String nw = "";
            for (int i=0;i<s.Length; i++)
            {
                char c = s[i];
                String first = nw + c;
                String second = c + nw;
                if (StringComparer.InvariantCulture.Compare(first, second) > 0)
                {
                    nw = first;
                }
                else nw = second;

            }

            return nw;
        }

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"Z:\Projects\Соревнования\CodeJam 2016\Round1A\Task1_input\A-small-attempt0.in");
            Int32 count = Int32.Parse(lines[0].Trim());
            for (Int32 i = 0; i < count; i++)
            {
                String res = Solve(lines[i + 1]);
                Console.WriteLine("Case #{0}: {1}", i + 1, res);
            }
        }
    }
}
