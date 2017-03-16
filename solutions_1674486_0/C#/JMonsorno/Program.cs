using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace cjr1ca1
{
    class Program
    {
        static void Main(string[] args)
        {
            string inputText = File.ReadAllText(args[0]).Replace("\r\n", "\n").Replace("\r", "\n");
            string inputFilename = Path.GetFileNameWithoutExtension(args[0]);
            string[] input = inputText.Split('\n');
            StreamWriter output = new StreamWriter(String.Format("{0}.out", inputFilename));

            int T = Int32.Parse(input[0]);
            int index = 1;
            for (int t = 1; t <= T; ++t)
            {
                int N = Int32.Parse(input[index++]);
                string[] testCase = new string[N];
                for (int i = 0; i < N; ++i)
                    testCase[i] = input[index++];
                output.WriteLine(ProcessTest(t, N, testCase));
                output.Flush();
            }

            output.Close();
        }

        private static string ProcessTest(int t, int N, string[] testCase)
        {
            Node[] nodes = new Node[N];
            //Create
            int index = 0;
            foreach (string line in testCase)
            {
                Node node = new Node(index);

                nodes[index++] = node;
            }
            //Setup associated linked nodes
            index = 0;
            foreach (string line in testCase)
            {
                List<int> numbers = line
                    .Split(' ')
                    .Select(s => Int32.Parse(s))
                    .ToList();
                if (numbers[0] + 1 != numbers.Count)
                    throw new ApplicationException();
                numbers.RemoveAt(0);
                List<Node> neighbors = new List<Node>();
                foreach (int nodeIndex in numbers)
                    neighbors.Add(nodes[nodeIndex - 1]);
                nodes[index++].inheritFrom = neighbors;
            }

            //Step through nodes
            foreach (Node node in nodes)
            {
                if (node.visited)
                    continue;

                node.visit();

                if (nodes.Any(n => n.diamondFound))
                    return String.Format("Case #{0}: Yes", t);
            }
            return String.Format("Case #{0}: No", t);
        }



        class Node
        {
            public int index { get; set; }
            public List<Node> inheritFrom { get; set; }
            public List<int> visitedNeighbors { get; set; }
            public bool visited { get; set; }
            public bool diamondFound { get; set; }

            public Node(int index)
            {
                this.index = index;
                visitedNeighbors = new List<int>();
                visited = false;
                diamondFound = false;
            }

            public List<int> visit()
            {
                if (visited)
                    return visitedNeighbors;

                List<int> result = new List<int>();
                foreach (Node neighbor in inheritFrom)
                {
                    if (result.Contains(neighbor.index))
                    {
                        diamondFound = true;
                        break;
                    }
                    result.Add(neighbor.index);
                    List<int> localResult = neighbor.visit();
                    if (localResult.Intersect(result).Any())
                    {
                        diamondFound = true;
                        break;
                    }
                    result.AddRange(localResult);
                }
                visited = true;
                visitedNeighbors = result;
                return result;
            }
        }
    }
}
