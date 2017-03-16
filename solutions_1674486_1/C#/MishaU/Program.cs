using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Round1C.ProblemA
{
    public class Vertex
    {
        public Vertex(int number)
        {
            Number = number;
            Visited = 0;
            InheritedFrom = new HashSet<Vertex>();
        }

        public int Number { get; private set; }
        public int Visited { get; set; }
        public HashSet<Vertex> InheritedFrom { get; private set; }

        public override int  GetHashCode()
        {
            return Number;
        }

        public override bool Equals(object obj)
        {
            var other = obj as Vertex;
            if (other == null)
                return false;
            return other.Number == Number;
        }
    }

    public class Graph
    {
        public Graph()
        {
            Vertexies = new HashSet<Vertex>();
        }

        public Vertex GetByNumberOrCreate(int number)
        {
            foreach (var vertex in Vertexies)
            {
                if (vertex.Number == number)
                {
                    return vertex;
                }
            }
            var v = new Vertex(number);
            Vertexies.Add(v);
            return v;
        }

        public HashSet<Vertex> Vertexies { get; private set; }
    }

    class Program
    {
        private static string BuildOutFileName(string fileName)
        {
            var fileInfo = new FileInfo(fileName);
            return fileInfo.FullName.Replace(fileInfo.Extension, ".out");
        }

        private static bool BFS(Vertex vertex, int idBFS)
        {
            vertex.Visited = idBFS;
            foreach (var inh in vertex.InheritedFrom)
            {
                if ((inh.Visited == idBFS) || (BFS(inh, idBFS)))
                {
                    return true;
                }
            }
            return false;
        }

        private static bool Exists(Graph graph)
        {
            var idBFS = 1;
            foreach (var vertex in graph.Vertexies)
            {
                if (BFS(vertex, idBFS))
                {
                    return true;
                }
                idBFS++;
            }
            return false;
        }

        static void Main(string[] args)
        {
            var fileName = args[0];
            //var fileName = "d:\\1.in";
            var inputParser = new InputParser(fileName);
            var numberOfTestCase = 1;
            using (var streamWriter = new StreamWriter(BuildOutFileName(fileName)))
            {
                foreach (var inputLine in inputParser)
                {
                    var line = string.Format("Case #{0}: {1}", numberOfTestCase, Exists(inputLine) ? "Yes" : "No");
                    streamWriter.WriteLine(line);
                    //Console.WriteLine(line);
                    numberOfTestCase++;
                }
            }
        }
    }
}
