using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            using(var reader = new StreamReader("C:\\CodeJam\\1c\\b\\B-small-attempt0 (3).in"))
            {
                using (var writer = new StreamWriter("C:\\CodeJam\\1c\\b\\out.txt"))
                {
                    var numCases = int.Parse(reader.ReadLine());
                    for(int i = 1; i <= numCases; i++)
                    {
                        Console.Write("Case #{0}: ", i);
                        writer.Write("Case #{0}: ", i);
                        Solve(reader, writer);
                    }
                }
            }
            Console.ReadKey();
        }

        static void Solve(StreamReader reader, StreamWriter writer)
        {
            var line = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var B = line[0];
            var M = line[1];
            var maxM = (int)Math.Pow(2, B - 2);
            if (M > maxM)
            {
                Console.WriteLine("IMPOSSIBLE");
                writer.WriteLine("IMPOSSIBLE");
            }
            else
            {
                Console.WriteLine("POSSIBLE");
                writer.WriteLine("POSSIBLE");

                if(M == maxM)
                {
                    Console.Write('0');
                    writer.Write('0');
                    for (int i = 1; i < B; i++)
                    {
                        Console.Write('1');
                        writer.Write('1');
                    }
                    Console.WriteLine();
                    writer.WriteLine();
                }
                else
                {
                    var str = Convert.ToString(M, 2);
                    var str2 = str.PadLeft(B - 1, '0');
                    Console.Write(str2);
                    writer.Write(str2);
                    Console.WriteLine('0');
                    writer.WriteLine('0');
                }

                for(int i = 1; i < B; i++)
                {
                    for (int j = 0; j < B; j++)
                    {
                        if (j > i)
                        {
                            Console.Write('1');
                            writer.Write('1');
                        }
                        else
                        {
                            Console.Write('0');
                            writer.Write('0');
                        }
                    }
                    Console.WriteLine();
                    writer.WriteLine();
                }
            }
        }
    }
}
