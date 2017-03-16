using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DancingWithTheGooglers
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\Users\wangran\Documents\visual studio 11\Projects\GoogleCodeJam\DancingWithTheGooglers\B-large.in.txt");
            for (int i = 1; i < lines.Length; i++)
            {
                int[] numbers = lines[i].Split(' ').Select(s => int.Parse(s)).ToArray();
                int num = numbers[0];
                int sup = numbers[1];
                int max = numbers[2];
                int oktotal = 0;
                int suptotal = 0;
                for (int j = 3; j < num+3; j++)
                {
                    if (numbers[j] < max)
                    {
                        continue;
                    }
                    int temp = ((int)((numbers[j] - max) / 2)) - max;
                    if (temp > -2)
                    {
                        oktotal++;
                    }
                    else if (temp == -2)
                    {
                        suptotal++;
                    }
                }
                int result = oktotal + Math.Min(suptotal, sup);

                var resultLine = string.Format("Case #{0}: {1}\n", i, result);
                Console.Write(resultLine);
                File.AppendAllText(@"C:\Users\wangran\Documents\visual studio 11\Projects\GoogleCodeJam\DancingWithTheGooglers\B-large.out.txt", resultLine);
            }

        }
    }
}
