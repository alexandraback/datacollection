using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = "../../B-Large.in";

            using (TextReader tr = new StreamReader(input))
            using (TextWriter tw = new StreamWriter(input.Replace(".in", ".out.txt")))
            {
                int T = int.Parse(tr.ReadLine());
                for (int c = 1; c <= T; c++)
                {
                    int ans = 0;

                    var pancakes = tr.ReadLine().ToCharArray().ToList();

                    while(!pancakes.All(x => x == '+'))
                    {
                        int last = pancakes.Count - 1;
                        while(pancakes[last] == '+') { last--; }

                        if (pancakes[0] == '+')
                        {
                            int first = 0;
                            while (pancakes[first] == '+') { first++; }

                            var temp = pancakes.GetRange(0, first).Select(x => x == '+' ? '-' : '+').Reverse().ToList();
                            temp.AddRange(pancakes.GetRange(first, pancakes.Count - first));
                            pancakes = temp;
                        }
                        else
                        {
                            pancakes = pancakes.GetRange(0, last + 1).Select(x => x == '+' ? '-' : '+').Reverse().ToList();
                        }

                        ans++;
                    }

                    Console.WriteLine($"Case #{c}: {ans}");
                    tw.WriteLine($"Case #{c}: {ans}");
                }
            }
        }
    }
}
