using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using (TextReader input = new StreamReader("input.txt"))
            using (TextWriter output = new StreamWriter("output.txt"))
            //using (TextReader input = new StreamReader(Console.OpenStandardInput()))
            //using (TextWriter output = new StreamWriter(Console.OpenStandardOutput()))
            {
                Process(input, output);
            }
        }

        private static void Process(TextReader input, TextWriter output)
        {
            int numberOfCases = int.Parse(input.ReadLine());
            for (int currentCase = 1; currentCase <= numberOfCases; currentCase++)
            {
                string[] split = input.ReadLine().Split(' ');
                int Googlers = int.Parse(split[0]);
                int surprising = int.Parse(split[1]);
                int minimumScore = int.Parse(split[2]);
                int total = 0;
                int lowScore = minimumScore * 3 - 4;
                int highScore = lowScore + 1;
                if (lowScore < 0)
                {
                    surprising = 0;
                }
                for (int position = 3; position < 3 + Googlers; position++)
                {
                    int score = int.Parse(split[position]);
                    if (score > highScore)
                    {
                        total++;
                    }
                    else
                    {
                        if ((score >= lowScore) && (surprising > 0))
                        {
                            surprising--;
                            total++;
                        }
                    }
                }
                output.WriteLine(string.Format("Case #{0}: {1}", currentCase, total));
            }
        }
    }
}
