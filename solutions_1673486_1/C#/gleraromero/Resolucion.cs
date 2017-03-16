using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Codejam2012._1A
{
    class Resolucion
    {
        public static void Resolver(string path)
        {
            StreamWriter escritor = new StreamWriter(string.Concat(path, "/", "current.out"));
            StreamReader lector = new StreamReader(string.Concat(path, "/", "current.in"));
            int T = int.Parse(lector.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                string[] data = lector.ReadLine().Split(' ');
                int alreadyTyped = int.Parse(data[0]);
                int totalChars = int.Parse(data[1]);
                int cantUntyped = totalChars - alreadyTyped;

                data = lector.ReadLine().Split(' ');
                double[] rightProbs = data.Select(p => Convert.ToDouble(p.Replace(".",","))).ToArray();
                double[] probaFirstNRight = new double[alreadyTyped+1];
                probaFirstNRight[0] = 1;
                probaFirstNRight[1] = rightProbs[0];

                for (int n = 2; n < alreadyTyped+1; n++)
                {
                    probaFirstNRight[n] = probaFirstNRight[n - 1] * rightProbs[n - 1];
                }

                double[] averages = new double[alreadyTyped+1];
                for (int bs = 0; bs < alreadyTyped+1; bs++)
                {
                    averages[bs] = probaFirstNRight[alreadyTyped - bs] * (bs * 2 + cantUntyped + 1) + (1 - probaFirstNRight[alreadyTyped - bs]) * (bs * 2 + cantUntyped + 1 + totalChars + 1);
                }
                double averageOnGiveUp = 1 + totalChars + 1;
                escritor.WriteLine(string.Format("Case #{0}: {1}", i + 1, Math.Min(averageOnGiveUp, averages.Min()).ToString("N6").Replace(".","").Replace(",",".")));
            }
            lector.Close();
            escritor.Close();
        }

        public static double ProbaUnion(List<double> numeros)
        {
            if (numeros.Count == 2)
            {
                return numeros[0] + numeros[1] - numeros[0] * numeros[1];
            }
            else
            {
                double probaUltimos = ProbaUnion(new List<double>() { numeros[numeros.Count - 1], numeros[numeros.Count - 2]});
                numeros.RemoveAt(numeros.Count - 1);
                numeros[numeros.Count - 1] = probaUltimos;
                return ProbaUnion(numeros);
            }
        }
    }
}
