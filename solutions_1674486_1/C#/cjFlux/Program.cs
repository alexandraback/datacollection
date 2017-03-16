using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace TaskA
{
    class Program
    {
        class Node
        {
            public int Index { get; set; }
            public int ParentCount { get; set; }
            public HashSet<Node> Childs = new HashSet<Node>();
            public HashSet<Node> InheritsFrom = new HashSet<Node>();

            public bool Check(Node Ancestor)
            {
                if (this.InheritsFrom.Contains(Ancestor)) return true;
                this.InheritsFrom.Add(Ancestor);
                foreach (var node in Childs) if (node.Check(Ancestor)) return true;
                return false;
            }

        }
        static void Main(string[] args)
        {
            System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;
            StreamReader sr = new StreamReader(@"input.txt");
            StreamWriter sw = new StreamWriter(@"output.txt");
            int Count = int.Parse(sr.ReadLine());
            for (int t = 1; t <= Count; t++)
            {
                sw.Write("Case #{0}: ", t);

                int Cnt = int.Parse(sr.ReadLine());
                Node[] Nodes = new Node[Cnt];
                for (int i = 0; i < Cnt; i++) Nodes[i] = new Node { Index = i, ParentCount = 0 };
                for (int i = 0; i < Cnt; i++)
                {
                    int[] Arr = Array.ConvertAll(sr.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries).Skip(1).ToArray(), s => int.Parse(s) - 1);
                    foreach (int index in Arr)
                    {
                        Nodes[index].Childs.Add(Nodes[i]);
                        Nodes[i].ParentCount++;
                    }
                }
                foreach (var node in Nodes.Where(x => x.ParentCount == 0)) if (node.Check(node)) { sw.Write("Yes"); goto fin; }
                sw.Write("No");

            fin: ;
                if (t != Count) sw.WriteLine();
            }
            sr.Close(); sw.Close();
        }
    }
}
