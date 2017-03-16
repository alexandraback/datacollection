using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2014_1b_B
{
    class Program
    {
        const string root = @"B:\Users\Justin\Desktop\Temp\Google Code\2014_1b_B\";
        static void Main(string[] args)
        {
            var reader = new StreamReader(root + "in.txt");
            var writer = new StreamWriter(root + "out.txt", false);

            int numCases = int.Parse(reader.ReadLine());

            for (int cc = 1; cc <= numCases; cc++)
            {
                int[] inputs = reader.ReadLine().Split(' ').Select(p => int.Parse(p)).ToArray();
                int a = inputs[0];
                int b = inputs[1];
                int k = inputs[2];
                int num = Step(a, b, k);

                writer.WriteLine("Case #{0}: {1}", cc, num);

            }
            writer.Close();
        }

        public static int Step(int a, int b, int k)
        {
            int comb = 0;
            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    if ((i & j) < k)
                        comb++;
                }
            }
            return comb;
        }
    }
}
