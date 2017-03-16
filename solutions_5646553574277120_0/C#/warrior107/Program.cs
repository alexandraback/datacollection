using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Q2CS
{
    class Program
    {
        static void Main(string[] args)
        {
            int t;
            int c, d, v;
            int ans;
            int sum;
            int x;
            string input;

            input = Console.ReadLine();
            t = Int32.Parse(input);

            for (int i = 1; i <= t; i++)
            {
                input = Console.ReadLine();
                string[] inputs = input.Split(' ');
                c = Int32.Parse(inputs[0]);
                d = Int32.Parse(inputs[1]);
                v = Int32.Parse(inputs[2]);

                List<int> denom = new List<int>();
                input = Console.ReadLine();
                string[] dens = input.Split(' ');

                for (int j = 0; j < d; j++)
                {
                    x = Int32.Parse(dens[j]);
                    denom.Add(x);
                }

                ans = 0;

                for (int j = 1; j <= v; j++)
                {
                    var a = from e in denom
                            where e <= j
                            select e;

                    sum = 0;
                    foreach (int q in a)
                    {
                        sum = sum + q;
                    }

                    if(sum<j)
                    {
                        ans++;
                        denom.Add(j);
                    }
                }

                Console.WriteLine("Case #{0}: {1}\n", i, ans);
            }
        }
    }
}
