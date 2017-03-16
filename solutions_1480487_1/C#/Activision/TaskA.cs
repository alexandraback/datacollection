using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ_R1B
{
    public class TaskA
    {
        public static void Main(string[] args)
        {
            var reader = new StreamReader(@"..\..\ProblemA\small.in");
            var writer = new StreamWriter(@"..\..\ProblemA\small.out");
            var T = int.Parse(reader.ReadLine());
            for (int i = 0; i < T; i++)
            {
                var inp = reader.ReadLine().Split(' ').Select(int.Parse);
                var N = inp.First();
                var S = inp.Skip(1).ToArray();
                var sum = S.Sum();
                var max = (double)sum*2/N;
                var sum2 = 0;
                var N2 = 0;
                for (int j = 0; j < N; j++)
                    if (S[j] < max)
                    {
                        sum2 += S[j];
                        N2++;
                    }
                var max2 = (double) (sum + sum2)/N2;

                writer.Write(String.Format("Case #{0}:", i + 1));
                for (int j = 0; j < N; j++)
                {
                    var pnt = (double) (S[j] >= max ? 0 : (max2 - S[j])/sum*100);
                    writer.Write(String.Format(" {0:F5}", pnt));
                }
                writer.WriteLine();
            }
            reader.Close();
            writer.Close();
        }
    }
}
