using System;
using System.IO;
using System.Linq;
using System.Text;

namespace Qualification
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("Problems\\A-small-attempt1.in");

            var sb = new StringBuilder();

            int testCaseCount = Int32.Parse(input[0]);
            for (int i = 1; i <= testCaseCount; i++)
            {
                string[] target = input[i].Split(' ');
                string output = "Case #" + i + ": " + ProblemC.Solve(target[0], Int32.Parse(target[1]));
                sb.AppendLine(output);
                Console.WriteLine(output);
            }

            File.WriteAllText("ouput.txt", sb.ToString().Trim());
            Console.WriteLine(DateTime.Now);
            Console.ReadLine();
        }

        private class ProblemC
        {
            private static readonly char[] vowels = new[] {'a', 'e', 'i', 'o', 'u'};

            public static int Solve(string name, int n)
            {
                name = String.Concat(name.Select(x => vowels.Contains(x) ? 'v' : 'c'));

                int nValue = 0;

                for (int s = 0; s < name.Length; s++)
                {
                    for (int e = name.Length - 1; e >= s + n - 1; e--)
                    {
                        int count = 0;
                        //Console.WriteLine(s + " - " + e);

                        for (int x = s; x <= e; x++)
                        {
                            if (name[x] == 'c')
                            {
                                count++;
                                if (count == n)
                                {
                                    nValue++;
                                    break;
                                }
                            }
                            else
                                count = 0;
                        }
                    }
                }

                return nValue;
            }
        }
    }
}