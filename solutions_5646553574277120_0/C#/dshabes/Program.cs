using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2015_1C_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var parts = Console.ReadLine().Split().Select(int.Parse).ToArray();
                var C = parts[0];
                var D = parts[1];
                var V = parts[2];
                var existingSet = Console.ReadLine().Split().Select(long.Parse).ToArray();

                var possibles = new int[V + 1];
                possibles[0] = 1;
                for (int i = 0; i < D; i++)
                {
                    for (int j = 0; j <= V; j++)
                    {
                        if (possibles[j] == 1)
                        {
                            var newValue = j + existingSet[i];
                            if (newValue <= V && possibles[newValue] == 0)
                                possibles[newValue] = -1;
                        }
                    }
                    for (int j = 0; j <= V; j++)
                        if (possibles[j] == -1)
                        {
                            possibles[j] = 1;
                        }
                }

                var required = 0;

                while (true)
                {
                    var nextD = -1;
                    for (int i = 0; i <= V; i++)
                    {
                        if (possibles[i] == 0)
                        {
                            nextD = i;
                            break;
                        }
                    }
                    if (nextD == -1)
                        break;
                    required++;
                    for (int j = 0; j <= V; j++)
                    {
                        if (possibles[j] == 1)
                        {
                            var newValue = j + nextD;
                            if (newValue <= V && possibles[newValue] == 0)
                                possibles[newValue] = -1;
                        }
                    }
                    for (int j = 0; j <= V; j++)
                        if (possibles[j] == -1)
                        {
                            possibles[j] = 1;
                        }
                }

                Console.WriteLine("Case #{0}: {1}", testN, required);
            }
        }
    }
}
