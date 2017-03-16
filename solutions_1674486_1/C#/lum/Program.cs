using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace R1Q1
{
    class Program
    {
        static Dictionary<int, int> occurences = new Dictionary<int, int>();

        static bool[,] graph;
        static int numClasses;


        static int[] getRoots()
        {
            List<int> roots = new List<int>();

            for (int i = 0; i < numClasses; i++)
            {
                bool isRoot = true;
                for (int j = 0; j < numClasses; j++)
                {
                    if (graph[i, j]) isRoot = false;
                }
                if (isRoot) roots.Add(i);
            }

            Debug.Assert(roots.Count > 0);
            return roots.ToArray();

        }

        static int[] getSubClasses(int superclass)
        {
            List<int> subs = new List<int>();

            for (int i = 0; i < numClasses; i++)
            { 
                if(graph[i, superclass])
                {
                    subs.Add(i);
                }
            }
            return subs.ToArray();
        }

        static void logSubClasses(int superC)
        {
            foreach (var sub in getSubClasses(superC))
            {
                occurences[sub] = occurences[sub] + 1;
                logSubClasses(sub);
            }
        }

        static bool doublePath(int root)
        {
            occurences.Clear();
            for (int i = 0; i < numClasses; i++)
            {
                occurences[i] = 0;
            }
            logSubClasses(root);
            foreach (int num in occurences.Values)
            {
                if (num > 1) return true;
            }
            return false;
        }

        static void logSupers(int node)
        {
            for (int i = 0; i < numClasses; i++)
            {
                if (graph[node, i])
                {
                    occurences[i] = occurences[i] + 1;
                    if (occurences[i] > 1)
                        return;
                    logSupers(i);
                }
            }
        }

        static bool dblPath2()
        {
            for (int i = 0; i < numClasses; i++)
            {
                occurences.Clear();
                for (int j = 0; j < numClasses; j++)
                {
                    occurences[j] = 0;
                }
                logSupers(i);
                foreach (int num in occurences.Values)
                {
                    if (num > 1) return true;
                }
            }
            return false;
        }


        static void Main(string[] args)
        {
            var instream = File.OpenRead("foo.in");
            var outstream = File.OpenWrite("foo.out");

            var reader = new StreamReader(instream);
            var writer = new StreamWriter(outstream);

            var num = int.Parse(reader.ReadLine());
            System.Console.WriteLine("Num of Cases {0}", num);
            var i = 1;

            while (!reader.EndOfStream)
            {
                var input_line = reader.ReadLine();


                numClasses = int.Parse(input_line);
                graph = new bool[numClasses, numClasses];

                for(int j = 0 ; j < numClasses; j++)
                {
                    int[] path = reader.ReadLine().Split(' ').Select(s=> int.Parse(s)).ToArray();

                    int numSuperclasses = path[0];
                    for(int k = 0; k < numSuperclasses ; k++)
                    {
                        graph[j, path[1 + k] - 1] = true;
                    }
                }

                

                
                writer.WriteLine("Case #{0}: {1}", i, dblPath2() ? "Yes" : "No");
                System.Console.WriteLine("Case #{0}: {1}", i, dblPath2() ? "Yes" : "No");
                i++;
            }
            writer.Close();
            reader.Close();
            System.Console.ReadKey();
        }
    }
}
