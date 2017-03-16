using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace CodeJam
{
    class Node
    {
        public Node[] parents;
        internal int id;
        List<int> traversed = new List<int>();

        public Node(int id)
        {
            // TODO: Complete member initialization
            this.id = id;
        }

        internal void Print()
        {
            Console.WriteLine("{0} has {1} parents: ",id, parents.Length);
            foreach (Node n in parents)
            {
                Console.WriteLine("    {0}", n.id);
            }
        }

        bool hasCycle = false;
        internal bool hasCycles(Node p)
        {
            traversed.Add(p.id);
            foreach(Node n in p.parents) {
                bool b = traversed.Contains(n.id);
                if (!b)
                {
                    hasCycles(n);
                }
                else
                {
                    //Console.WriteLine("{0} has multiple {1}", id, n.id);
                    hasCycle = true;
                }

            }
            return hasCycle;
        }
    }

    class R1P7
    {
        private const string fileIn = @"C:\Users\aghaffar\Documents\Visual Studio 2010\Projects\Challenges\CodeJam\CodeJam\bin\Debug\input.in";
        private const string fileOut = @"C:\Users\aghaffar\Documents\Visual Studio 2010\Projects\Challenges\CodeJam\CodeJam\bin\Debug\output.txt";
        private static TextReader input = File.OpenText(fileIn);
        private static TextWriter console = File.CreateText(fileOut);
        //private static TextWriter console = Console.Out;

        public string solve()
        {
            bool debug = false;
            StringBuilder result = new StringBuilder(); ;

            int n = int.Parse(input.ReadLine());
            Node[] nodes = new Node[n];

            for (int i = 0; i < n; i++)
            {
                Node node = new Node(i + 1);
                //Console.WriteLine("creatin {0}", node.id);
                nodes[i] = node;
            }

            for (int i = 0; i < n; i++)
            {
                string[] ss = input.ReadLine().Split(' ');
                int parents = int.Parse(ss[0]);
                Node node = nodes[i];
                node.parents = new Node[parents];
                for (int j = 1; j < ss.Length; j++)
                {
                    node.parents[j - 1] = nodes[int.Parse(ss[j])-1];
                    //Console.WriteLine(" adding {0}", ss[j]);
                }
              }

            foreach (Node node in nodes)
            {
                bool b = node.hasCycles(node);
                if (b)
                    return "Yes";
            }
            return "No";
        }

        public static void Main()
        {
            int n = int.Parse(input.ReadLine());
            for (int i = 0; i < n; i++)
            {
                console.WriteLine("Case #{0}: {1}", i+1, new R1P7().solve());
            }
            console.Flush();
            //Console.ReadKey();
        }

    }
}
