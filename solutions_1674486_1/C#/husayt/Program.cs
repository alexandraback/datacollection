using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;

namespace tmplate
{
    public class Node
    {
        public int x;

        public List<int> nodes;
        public bool beenHere;
    }

    internal class Program
    {
        private const string locationDir = @"c:\_code\c#\codejam\b\in\";

        private static Node[] cur;

        private static bool startwalk(int k)
        {
            var c = cur[k];
            if (c.beenHere)
                return true;
            c.beenHere = true;
            foreach (int node in c.nodes)
            {
                if (startwalk(node))
                    return true;
            }
            return false;
        }

        private static bool check(Node[] nodes)
        {
            int n = nodes.Length;

            cur = nodes;
            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < n; j++)
                {
                    nodes[j].beenHere = false;
                }

                if (startwalk(i)) return true;
            }
            return false;
        }

        private static void Main(string[] args)
        {
            List<Node[]> cases = ReadFile();
            //------------------  start

            StringBuilder sb = new StringBuilder();
            for (int i = 1; i < cases.Count(); i++)
            {
                var cs = cases[i];

                bool res = check(cs);
                string strOut = string.Format(@"Case #{0}: {1}", i, res ? "Yes" : "No");
                sb.AppendLine(strOut);
            }

            //----------------   end

            WriteFile(sb.ToString());
            //  Console.WriteLine("Hello World");
        }

        private static List<Node[]> ReadFile()
        {
            List<Node[]> cases = new List<Node[]>();
            // Read the file and display it line by line.
            using (var file = new StreamReader(locationDir + @"input.in"))
            {
                string line;
                //    string myString = file.ReadToEnd();
                line = file.ReadLine();
                var n = Convert.ToInt32(line);
                cases.Add(null);
                for (int i = 1; i <= n; i++)
                {
                    line = file.ReadLine();
                    var nodeCount = Convert.ToInt32(line);
                    Node[] nodes = new Node[nodeCount + 1];
                    cases.Add(nodes);
                    for (int j = 1; j <= nodeCount; j++)
                    {
                        var cs = new Node()
                            {
                                x = j
                            };
                        nodes[j] = cs;

                        line = file.ReadLine();
                        var a = line.Split(' ');
                        cs.nodes = a.Skip(1).Select(x => Convert.ToInt32(x)).ToList();
                    }
                }

                file.Close();
                return cases;
            }
        }

        private static void WriteFile(string outputText)
        {
            // Read the file and display it line by line.
            using (var file = new StreamWriter(locationDir + @"output.in"))
            {
                //string myString = file.ReadToEnd();
                file.WriteLine(outputText);

                file.Close();
            }
        }
    }
}