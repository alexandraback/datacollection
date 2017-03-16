using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace GCJ
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"D:\input.txt");
            StreamWriter sw = new StreamWriter(@"D:\output.txt");

            int t = int.Parse(sr.ReadLine());

            for (int i = 0; i < t; i++)
            {
                int n = int.Parse(sr.ReadLine());
                string[] inputs;
                List<int>[] graph = new List<int>[n + 1];
                bool result = false;

                for (int j = 1; j <= n; j++)
                {
                    inputs = sr.ReadLine().Split(' ');
                    graph[j] = new List<int>();

                    for (int k = 1; k < inputs.Length; k++)
                    {
                        graph[j].Add(int.Parse(inputs[k]));
                    }
                }

                for (int j = 1; j <= n && result == false; j++)
                {
                    bool[] isVisited = new bool[n + 1];
                    Queue<int> queue = new Queue<int>();
                    int nownode;

                    queue.Enqueue(j);

                    while (queue.Count != 0)
                    {
                        nownode = queue.Dequeue();

                        if (isVisited[nownode] == true)
                        {
                            result = true;
                            break;
                        }

                        isVisited[nownode] = true;

                        for (int k = 0; k < graph[nownode].Count; k++)
                        {
                            queue.Enqueue(graph[nownode][k]);
                        }
                    }
                }

                sw.Write("Case #{0}: ", (i + 1));

                if (result == true)
                {
                    sw.WriteLine("Yes");
                }
                else
                {
                    sw.WriteLine("No");
                }
            }

            sr.Close();
            sw.Close();
        }
    }
}
