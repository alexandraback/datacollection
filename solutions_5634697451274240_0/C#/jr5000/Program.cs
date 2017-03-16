using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Codejam2
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader("C:\\Users\\Jon\\Desktop\\CodeJam\\Qualification\\ProblemB\\B-small-attempt3.in"))
            {
                using (var writer = new StreamWriter("C:\\Users\\Jon\\Desktop\\CodeJam\\Qualification\\ProblemB\\B-small.out"))
                {
                    int testCases = int.Parse(reader.ReadLine());
                    for (int tc = 0; tc < testCases; tc++)
                    {
                        Solve(tc + 1, reader, writer);
                    }
                }
            }
            Console.ReadKey();
        }

        static void Solve(int caseNumber, StreamReader reader, StreamWriter file)
        {
            var stack = reader.ReadLine().ToArray().Select(a=>a == '+').ToList();
            stack.Add(true);
            int ret = Recurse(stack.ToArray(), stack.Count);
            file.WriteLine("Case #{0}: {1}", caseNumber, ret);
            Console.WriteLine("Case #{0}: {1}", caseNumber, ret);
        }

        static int Recurse(bool[] stack, int range, bool justFlipped=false)
        {
            var start = stack[range - 1];
            for(int i = range - 2; i >= 0; i--)
            {
                if(stack[i] != start)
                {
                    if (true || stack[0] != start)
                    {
                        int min = 1 + Recurse(stack, i + 1);
                        if (!justFlipped || i != range - 2)
                        {
                            for (int j = 0; j <= i / 2; j++)
                            {
                                var temp = stack[j];
                                stack[j] = !stack[i - j];
                                stack[i - j] = !temp;
                            }

                            min = Math.Min(min, 1 + Recurse(stack, i + 2, true));

                            for (int j = 0; j <= i / 2; j++)
                            {
                                var temp = stack[j];
                                stack[j] = !stack[i - j];
                                stack[i - j] = !temp;
                            }
                        }
                        return min;
                    }
                    else
                    {
                        return 1 + Recurse(stack, i + 1);
                    }
                }
            }
            return 0;
        }
    }
}