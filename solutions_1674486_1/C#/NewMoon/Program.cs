using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Jam2A
{
    static class Program
    {
        static void Main()
        {
            const string exercise = "A";
            const bool isLarge = true;

            var input = File.ReadAllLines(GetFileName(exercise, isLarge, true));
            var numberOfCases = int.Parse(input[0]);
            
            var start = DateTime.Now;

            var output = HandleInput(input, numberOfCases);
            File.WriteAllLines(GetFileName(exercise, isLarge, false), output.ToArray());

            var end = DateTime.Now;
            var span = end - start;
            Console.WriteLine("Milliseconds spent = " + span.TotalMilliseconds);
            Console.ReadKey();
        }

        static List<string> HandleInput(string[] input, int numberOfCases)
        {
            var output = new List<string>();
            var i = 1;
            for (var cse = 1; cse <= numberOfCases; cse++)
            {
                var graph = new Dictionary<int, Node>();
                var n = int.Parse(input[i++]);

                for (int c = 1; c <= n; c++)
                    graph[c] = new Node();
                for (int current = 1; current <= n; current++)
                {
                    var cLine = input[i++];
                    var parts = cLine.Split(' ');
                    var m = int.Parse(parts[0]);
                    for (var superIndex = 0; superIndex < m; superIndex++)
                    {
                        var super = int.Parse(parts[superIndex + 1]);
                        graph[current].Supers.Add(super);
                        graph[super].Subs.Add(current);
                    }
                }


                output.Add(String.Format("Case #{0}: {1}", cse, SolveGraph(graph) ? "Yes" : "No"));
            }
            return output;
        }

        static bool SolveGraph(Dictionary<int, Node> graph)
        {
            while (true)
            {
                var unhandledNodes = graph.Select(p => p.Value).Where(p => !p.Handled).ToList();
                if (!unhandledNodes.Any())
                    return false;

                foreach (var unhandledNode in unhandledNodes)
                {
                    var allSupersHandled = unhandledNode.Supers.Select(i => graph[i]).All(n => n.Handled);
                    if (allSupersHandled)
                    {
                        foreach (var subNr in unhandledNode.Subs)
                        {
                            var sub = graph[subNr];
                            foreach (var extra in unhandledNode.Supers)
                                if (!sub.Supers.Add(extra))
                                    return true;
                        }
                        unhandledNode.Handled = true;
                    }
                }
            }
        }

        static string GetFileName(string exercise, bool isLarge, bool isInput)
        {
            //-attempt0
            return string.Format(@"C:\data\{0}-{1}.{2}", exercise, isLarge ? "large" : "small", isInput ? "in" : "out");
        }

        class Node
        {
            public HashSet<int> Supers = new HashSet<int>();
            public HashSet<int> Subs = new HashSet<int>(); 
            public bool Handled;
        }
    }
}
