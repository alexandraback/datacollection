using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace Codejam
{
    class A
    {
        static void Main(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine());
            LinkedList<char> resultBuilder;
            for (int current = 1; current <= t; current++)
            {
                string line = Console.ReadLine();
                resultBuilder = new LinkedList<char>();
                foreach (char c in line)
                {
                    if (resultBuilder.Count == 0)
                    {
                        resultBuilder.AddFirst(c);
                    }
                    else
                    {
                        if (resultBuilder.First.Value > c)
                        {
                            resultBuilder.AddLast(c);
                        }
                        else
                        {
                            resultBuilder.AddFirst(c);
                        }
                    }
                }
                Console.WriteLine(string.Format("Case #{0}: {1}",current,string.Join("", resultBuilder.ToArray())));
            }
        }
    }
}
