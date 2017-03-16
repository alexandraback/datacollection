using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace CodeJam2012
{
    class Program
    {
        private const string INPUT = "C-large.in";
        private const string OUTPUT = "C-large.out";

        static void Main(string[] args)
        {

            
            string[] input = File.ReadAllLines("d:/code/codejam_dotnet/data/" + INPUT);
            var output = new List<string>();
            for (int i = 1; i < input.Length; i++)
            {
                string[] splitInput = input[i].Split();
                output.Add("Case #" + i + ": " + GetResult(Convert.ToInt32(splitInput[0]), Convert.ToInt32(splitInput[1])).ToString());
                Console.WriteLine(i + " of " + input.Length);
            }
            File.WriteAllLines("d:/code/codejam_dotnet/data/" + OUTPUT, output);

        }

        private static int GetResult(int a, int b)
        {
            int numDigits = a.ToString().Length;
            checked
            {
                if (a == b) return 0;

                int counter = 0;
                for (; a < b; a++)
                {
                    var rotationSet = new HashSet<int>();
                    for (int i = 1; i < numDigits; i++)
                    {
                        int end = a % (int)Math.Pow(10, i);
                        int begin = a / (int)Math.Pow(10, i);
                        rotationSet.Add(begin + end * (int)Math.Pow(10, numDigits - i));
                    }
                    foreach (var rotation in rotationSet)
                    {
                        if (rotation > a && rotation <= b)
                        {
                            counter++;
                        }
                    }
                }
                return counter;
            }
        }
    }
}
