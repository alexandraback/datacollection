using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class A
    {
        static void Main(string[] args)
        {
            var inputfile = new FileStream("A.in", FileMode.Open);
            var input = new StreamReader(inputfile);
            var outputFile = new FileStream("A.out", FileMode.Create);
            var output = new StreamWriter(outputFile);

            char[] sep = { ' ' };
            int T = 0;
            var str = input.ReadLine();
            string[] temp = str.Split(sep);

            T = int.Parse(temp[0]);
            for (int i = 1; i <= T; i++)
            {
                str = input.ReadLine();
                temp = str.Split(sep);
                var you = int.Parse(temp[0]);
                var n = int.Parse(temp[1]);
                
                var bubbles = new List<int>();
                str = input.ReadLine();
                temp = str.Split(sep);
                for (int j = 0; j < n; j++)
                {
                    bubbles.Add(int.Parse(temp[j]));
                }
                bubbles.Sort();

                if (you == 1)
                {
                    output.WriteLine("Case #{0}: {1}", i, n);
                    continue;
                }

                var move = play(bubbles, you);
                var sum = new int[n];
                sum[0] = move[0];
                for (int j = 1; j < n; j++)
                {
                    sum[j] = move[j] + sum[j - 1];
                }

                var aisa = new List<int>();
                for (int j = 0; j < n; j++)
                {
                    aisa.Add(sum[j] + n - j - 1);
                }
                aisa.Sort();

                output.WriteLine("Case #{0}: {1}", i, Math.Min(n, aisa.First()));


            }

            output.Close();
            input.Close();
            outputFile.Close();
            inputfile.Close();
        }

        private static int[] play(List<int> bubbles, int you)
        {
            var move = new int[bubbles.Count];
            for (int i = 0; i < bubbles.Count; i++)
            {
                if (you > bubbles[i])
                {
                    move[i]=0;
                    you += bubbles[i];
                }
                else
                {
                    while (you <= bubbles[i])
                    {
                        you += you - 1;
                        move[i]++;
                    }
                    you += bubbles[i];
                }
            }
            return move;
        }
    }
}
