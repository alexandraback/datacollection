using System;
using System.Collections.Generic;


namespace Diamon_Inheritance
{
    class ClassNode
    {
        //public int No;
        public List<ClassNode> children;
        public int flag;
        public ClassNode()
        {
            flag = 0;
            children = new List<ClassNode>();
        }
    }
    class Graph
    {
        public List<ClassNode> Bases;
        public ClassNode[] nodes;
        public int noclasses;

        public Graph(int noClasses)
        {
            noclasses = noClasses;
            Bases = new List<ClassNode>();
            nodes = new ClassNode[noClasses];
            for (int i = 0; i < noClasses; i++)
                nodes[i] = new ClassNode();
        }

    }
    class Program
    {
        static int flagno = 1;
        static Graph proGraph;
        static void print_GCJ(int Case, string s)
        {
            Console.WriteLine("Case #" + Case.ToString() + ": " + s);
        }
        static void Main(string[] args)
        {
            #region inputandoutput
            int T = Int32.Parse(Console.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                int n = Int32.Parse(Console.ReadLine());
                proGraph = new Graph(n);
                for (int count = 0; count < n; count++)
                {
                    string[] inp = Console.ReadLine().Split(' ');
                    if (inp[0] == "0")
                    {
                        proGraph.Bases.Add(proGraph.nodes[count]);
                    }
                    else
                    {
                        int num = Int32.Parse(inp[0]);
                        for (int count1 = 1; count1 <= num; count1++)
                        {
                            int num1 = Int32.Parse(inp[count1]);
                            proGraph.nodes[num1-1].children.Add(proGraph.nodes[count]);
                        }
                    }
                }
                print_GCJ(i, process());
            }

            #endregion


        }
        static string process()
        {
            Queue<ClassNode> cnq = new Queue<ClassNode>();
            foreach(ClassNode baseC in proGraph.Bases)
            {
                cnq.Enqueue(baseC);
                while (cnq.Count != 0)
                {
                    ClassNode now = cnq.Dequeue();
                    if (now.flag == flagno) return "Yes";
                    now.flag = flagno;
                    foreach (ClassNode ch in now.children)
                    {
                        if (ch.flag == flagno)
                        {                            
                            return "Yes";
                        }
                        cnq.Enqueue(ch);
                    }
                }                
                flagno++;
            }
            return "No";
        }
    }
}
