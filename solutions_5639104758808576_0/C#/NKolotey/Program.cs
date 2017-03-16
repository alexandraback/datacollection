using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split( new char[] {' ', '\t'}, StringSplitOptions.RemoveEmptyEntries);
                int max = int.Parse(line[0]);
                string s = line[1];

                int total = 0;
                int added = 0;

                for (int i = 0; i <= max; i++)
                {
                    int c = s[i] - '0';

                    if(c != 0)
                    {
                        if(total < i)
                        {
                            added += i - total;
                            total = i;
                        }

                        total += c;
                    }
                }

                Console.WriteLine("Case #{0}: {1}", t, added);
            }
        }
    }
}
