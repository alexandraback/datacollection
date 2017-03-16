using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemC
{
    using System.IO;

    class ProblemC
    {
        static void Main(string[] args)
        {
            //var inputFile = new System.IO.StreamReader("C-test.in");
            var inputFile = new System.IO.StreamReader("C-small-attempt0.in");

            var outputFile = new System.IO.StreamWriter("C-small.out");
            // var outputFile = new System.IO.StreamWriter("C-large.out");

            var T = Convert.ToInt32(inputFile.ReadLine());

            for (var k = 0; k < T; k++)
            {
                var line = inputFile.ReadLine();
                var data = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                var C = Convert.ToInt32(data[0]);
                var D = Convert.ToInt32(data[1]);
                var V = Convert.ToInt32(data[2]);

                line = inputFile.ReadLine();

                data = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                var max = 0;

                var A = new int[D];
                var B = new int[V+1];

                B[0] = 1;
                var i = 0;
                for (i = 1; i <= V; i++)
                {
                    B[i] = 0;
                }

                i = 0;
                foreach (var amount in data.Select(t => Convert.ToInt32(t)))
                {
                    A[i] = amount;
                    i++;

                    for (var j = 1; j <= V-amount; j++)
                    {
                        if (B[j] == 1)
                        {
                            B[j + amount] = 1;
                        }
                    }

                    if (amount <= V)
                    {
                        B[amount] = 1;
                    }
                }

                var count = 0;

                i = 1;
                while (i <= V)
                {
                    if (B[i] == 0)
                    {
                        count++;

                        for (var j = 1; j < V-i; j++)
                        {
                            if (B[j + i] == 0)
                            {
                                B[j + i] = 1;
                            }
                        }

                        B[i] = 1;
                    }

                    i++;
                }

                outputFile.Write("Case #" + (k + 1) + ": " + count + "\n");
            }

            inputFile.Close();

            outputFile.Flush();
            outputFile.Close();
        }
    }
}
