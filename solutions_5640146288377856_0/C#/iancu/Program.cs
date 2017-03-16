using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoundC_ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine(GetMoves(1, 7, 2));

            //Console.ReadKey();
            //return;

            using (var sr = File.OpenText("input.txt"))
            {
                var num_tests = Convert.ToInt32(sr.ReadLine());

                using (var sw = new StreamWriter(File.OpenWrite("output.txt")))
                {

                    for (int i = 0; i < num_tests; ++i)
                    {
                        var nums = sr.ReadLine().Split(' ').Select(k => Convert.ToInt32(k.Trim())).ToArray();

                        sw.WriteLine(String.Format("Case #{0}: {1}", i + 1, GetMoves(nums[0], nums[1], nums[2])));
                    }

                    sw.Flush();
                    sw.Close();
                }

            }

        }

        private static long GetMoves(int rows, int cols, int width)
        {
            long pinDown = rows * (cols / width);

            return pinDown + width - (cols % width == 0 ? 1 : 0);
        }
    }

}
