using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace FirstRound
{
    class Program
    {
        private static StreamReader reader = null;
        private static StreamWriter writer = null;

        static void Main()
        {
            //reader = new StreamReader("A-small-attempt2.in");
            //writer = new StreamWriter("A-small.out");
            reader = new StreamReader("A-large.in");
            writer = new StreamWriter("A-large.out");

            using (reader)
            {
                using (writer)
                {
                    int tests = int.Parse(reader.ReadLine());
                    int nodes = 0;
                    string line = null;
                    string[] parameters = null;
                    int[] dParam = null;
                    for (int test = 0; test < tests; test++)
                    {
                        nodes = int.Parse(reader.ReadLine());
                        List<int>[] graph = new List<int>[nodes];

                        for (int i = 0; i < graph.Length; i++)
                        {
                            graph[i] = new List<int>();
                        }
                        for (int node = 0; node < nodes; node++)
                        {
                            line = reader.ReadLine();
                            parameters = line.Split(' ');
                            dParam = new int[parameters.Length];
                            int count = int.Parse(parameters[0]);
                            for (int sNode = 1; sNode < parameters.Length; sNode++)
                            {
                                graph[node].Add(int.Parse(parameters[sNode]) - 1);
                            }
                        }
                        bool isDiamond = false;
                        for (int j = 0; j < nodes; j++)
                        {
                            int[] used = new int[nodes];

                            isDiamond = TraverseDFS(graph, j, used);

                            if (isDiamond)
                            {
                                break;
                            }
                        }

                        writer.Write("Case #{0}: ", test+1);
                        if (isDiamond)
                        {
                            writer.WriteLine("Yes");
                        }
                        else
                        {
                            writer.WriteLine("No");
                        }
                    }
                }
            }
        }

        private static bool TraverseDFS(List<int>[] graph, int curVert, int[] used)
        {
            Stack<int> s = new Stack<int>();
            s.Push(curVert);
            int curNode = curVert;

            while(s.Count!=0)
            {
                curNode = s.Pop();
                for (int edge = 0; edge < graph[curNode].Count; edge++)
                {
                    if (used[graph[curNode][edge]] >= 1)
                    {
                        return true;
                    }
                    used[graph[curNode][edge]]++;
                    s.Push(graph[curNode][edge]);
                }
            }
            return false;
        }

        private static bool Check(int[] used)
        {
            for (int i = 0; i < used.Length; i++)
            {
                if (used[i] > 1)
                {
                    return true;
                }
            }

            return false;
        }
    }
}
