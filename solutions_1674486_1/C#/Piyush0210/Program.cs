using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace DiamondInhertance
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("A-large.in");
            StreamWriter sw = new StreamWriter("A-large.out");

            int T = int.Parse(sr.ReadLine());
            for (int q = 0; q < T; q++)
            {
                String input = sr.ReadLine();
                int N = int.Parse(input);
                bool[,] graph = new bool[N, N];
                for (int i = 0; i < N; i++)
                {
                    input = sr.ReadLine();
                    String[] inputs = input.Split(' ');
                    int L = int.Parse(inputs[0]);
                    for (int j = 0; j < L; j++)
                    {
                        int endNode = int.Parse(inputs[j + 1]);
                        graph[i, endNode - 1] = true;
                    }
                }

                sw.WriteLine(string.Format("Case #{0}: {1}", (q + 1), doesCycleExists(graph, N) ? "Yes" : "No"));
            }
            sw.Close();
            sr.Close();
        }

        private static bool doesCycleExists(bool[,] graph, int N)
        {
            bool[] visisted = new bool[N];
            for (int i = 0; i < N; i++)
            {
                if (!visisted[i])
                {
                    if (doesCycleExists(graph, N, i, visisted))
                    {
                        return true;
                    }
                }                
            }

            return false;
        }

        private static bool doesCycleExists(bool[,] graph, int N, int startNode, bool[] visisted)
        {
            Queue<int> queue = new Queue<int>();
            queue.Enqueue(startNode);
            
            bool[] cycle = new bool[N];
            cycle[startNode] = true;

            while (queue.Count > 0)
            {
                int currentNode = queue.Dequeue();
                visisted[currentNode] = true;
                for (int i = 0; i < N; i++)
                {
                    if (graph[currentNode, i])
                    {
                        if (cycle[i])
                        {
                            return true;
                        }
                        else
                        {
                            queue.Enqueue(i);
                            cycle[i] = true;
                        }
                    }
                }
            }
            return false;
        }
    }
}
