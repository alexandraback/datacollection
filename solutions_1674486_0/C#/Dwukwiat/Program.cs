using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJAm.Round1C.A
{
    class Program
    {
        class Graph
        {
            public Boolean CheckTwoPaths()
            {
                for (int i = 1; i <= _numberOfVertices; i++)
                {
                    currentlyVisited = new List<int>();
                    AllPaths = new Dictionary<Tuple<int, int>, List<int>>();
                    if (DepthFirstSearch(i))
                        return true;
                    
                }
                return false;
            }

            private Dictionary<Tuple<int, int>, List<int>> AllPaths;

            public Graph(int vertices)
            {
                _numberOfVertices = vertices;
                InitializeGraph();
            }
            private Boolean[][] _graph;
            private int _numberOfVertices;
            List<int> currentlyVisited = new List<int>();

            private void InitializeGraph()
            {
                _graph = new Boolean[_numberOfVertices + 1][];
                for (int i = 1; i <= _numberOfVertices; i++)
                {
                    _graph[i] = new Boolean[_numberOfVertices+1];
                }
            }

            public void AddEdge(int start, int end)
            {
                _graph[start][end] = true;
            }

            private Boolean DepthFirstSearch(int vertex)
            {
                currentlyVisited.Add(vertex);
                if (AllPaths.ContainsKey(new Tuple<int, int>(currentlyVisited.First(), currentlyVisited.Last())))
                {
                    return true;
                    //var other =
                    //    AllPaths[new Tuple<int, int>(currentlyVisited.First(), currentlyVisited.Last())];

                    //if (other.Count == currentlyVisited.Count)
                    //{
                    //    if (other.All(x => currentlyVisited.Count(z => z == x) == 1))
                    //        return true;
                    //}
                    //else
                    //{
                    //    return true;
                    //}
                }
                else
                {
                    AllPaths[new Tuple<int, int>(currentlyVisited.First(), currentlyVisited.Last())] =
                        currentlyVisited;
                }
                for (int y = 1; y <= _numberOfVertices; y++)
                {
                    if (_graph[vertex][y] == true)
                    {
                            if(DepthFirstSearch(y) == true)
                                return true;
                            currentlyVisited = currentlyVisited.Take(currentlyVisited.Count - 1).ToList();
                    }
                }
                
                return false;
            }
        }

        class TestCase
        {
            public int ClassesCount { get; set; }
            public Graph graph { get; set; }

            public void Solve()
            {
                if(graph.CheckTwoPaths() == true)
                {
                    _result = "Yes";
                }
                else
                {
                    _result = "No";
                }
            }

            public void Parse(StreamReader sr)
            {
                ClassesCount = Int32.Parse(sr.ReadLine());
                graph = new Graph(ClassesCount);

                for (int i = 1; i <= ClassesCount; i++)
                {
                    var c = sr.ReadLine().Split(' ');
                    for (int j = 1; j < c.Length; j++)
                    {
                        graph.AddEdge(i, Int32.Parse(c[j]));
                    }
                }
            }

            internal void Output(StreamWriter sw)
            {
                //output
                sw.WriteLine("Case #" + TestCaseNumber + ": " + _result);
            }

            #region Hidden

            private string _result;

            public TestCase(int testCaseNumber)
            {
                TestCaseNumber = testCaseNumber;
            }

            public int TestCaseNumber { get; private set; }

            #endregion
        }

        #region Main

        private static void Main()
        {
            var testCases = new List<TestCase>();
            using (var sr = new StreamReader("input.txt"))
            {
                int testCasesNumber = Int32.Parse(sr.ReadLine());
                for (int i = 0; i < testCasesNumber; i++)
                {
                    var testCase = new TestCase(i + 1);
                    testCase.Parse(sr);
                    testCases.Add(testCase);
                }
            }

            using (var sw = new StreamWriter("output.txt"))
            {
                foreach (var testCase in testCases.OrderBy(x => x.TestCaseNumber))
                {
                    testCase.Solve();
                    testCase.Output(sw);
                }
            }
        }

        #endregion
    }
}
