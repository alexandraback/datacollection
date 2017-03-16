using System;
using System.IO;
using System.Collections.Generic;

namespace GoogleCodeJam2012
{
    class Node
    {
        public List<Node> parents { get; set; }
        public bool visited { get; set; }
        public int ID;

        public Node(int i) { visited = false; parents = new List<Node>(); ID = i; }
    }

    class A
    {
        static void Main(string[] args)
        {
            // Open Reader/Writer
            TextReader fileIn = new StreamReader("a.in");
            TextWriter fileOut = new StreamWriter("a.out");


            int countNum = Int32.Parse(fileIn.ReadLine());

            for (int caseCount = 0; caseCount < countNum; caseCount++)
            {
                int classCount = Int32.Parse(fileIn.ReadLine());
                List<Node> root = new List<Node>();
                for (int i = 0; i < classCount; i++)
                {
                    root.Add(new Node(i));
                }

                for (int i = 0; i < classCount; i++)
                {
                    string[] info = fileIn.ReadLine().Split(' ');
                    int parentCount = Int32.Parse(info[0]);
                    for (int j = 0; j < parentCount; j++)
                    {
                        root[i].parents.Add(root[Int32.Parse(info[j + 1]) - 1]);
                    }
                }

                bool acyclic = true;
                for (int i = 0; i < root.Count; i++)
                {
                    if (Rec(root[i]) == false)
                    {
                        acyclic = false;
                        break;
                    }

                    // Reset for next check
                    foreach (Node n in root)
                    {
                        n.visited = false;
                    }
                }


                fileOut.WriteLine("Case #" + (caseCount + 1) + ": " + (acyclic ? "No" : "Yes"));

                Console.WriteLine("Case #" + (caseCount + 1) + " completed!");
            }

            // Close Reader/Writer
            fileIn.Close();
            fileOut.Close();
        }

        public static bool Rec(Node node)
        {
            if (node.visited)
            {
                return false;
            }

            node.visited = true;
            bool retVal = true;

            for (int i = 0; i < node.parents.Count; i++)
            {
                if (Rec(node.parents[i]) == false)
                {
                    retVal = false;
                    break;
                }
            }

            return retVal;

        }
    }

}
