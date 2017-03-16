using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam_2016_Q_1_C_Sharp
{
    class Program
    {
        static String Solve(String s)
        {
            Int32 n = Int32.Parse(s);

            Int32 currentValue = n;
            HashSet<Int32> digits = new HashSet<Int32>();
            for (Int32 i = 0; i < 2000; i++) {
                Int32 value = currentValue;
                while (value > 0)
                {
                    digits.Add(value % 10);
                    value /= 10;
                }
                if (digits.Count == 10) return currentValue.ToString();
                currentValue += n;
            }

            return "INSOMNIA";
        }

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"Z:\Projects\Соревнования\CodeJam 2016\Qualification\Task1_input\A-small-attempt0.in");
            Int32 count = Int32.Parse(lines[0].Trim());
            for (Int32 i = 0; i < count; i++)
            {
                String res = Solve(lines[i + 1]);
                Console.WriteLine("Case #{0}: {1}", i + 1, res);
            }
        }
    }
}
