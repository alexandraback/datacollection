using System;
using System.Collections.Generic;
using System.IO;

namespace Round1C.ProblemA
{
    public class InputParser
    {
        private readonly Stream _input;

        public InputParser(string fileName)
        {
            _input = new FileStream(fileName, FileMode.Open);
        }

        private Graph ParseGraph(string[] lines)
        {
            var graph = new Graph();
            for (int i = 0; i < lines.Length; i++)
            {
                var vertex = graph.GetByNumberOrCreate(i + 1);
                var inheritedFrom = lines[i].Split(' ');
                var count = Int32.Parse(inheritedFrom[0]);
                for (int j = 1; j <= count; j++)
                {
                    var inh = graph.GetByNumberOrCreate(Int32.Parse(inheritedFrom[j]));
                    vertex.InheritedFrom.Add(inh);
                }
            }
            return graph;
        }

        public IEnumerator<Graph> GetEnumerator()
        {
            using (var reader = new StreamReader(_input))
            {
                var numberOfTest = Int32.Parse(reader.ReadLine().Trim());
                while (!reader.EndOfStream && numberOfTest > 0)
                {
                    int numberOfVertex = Int32.Parse(reader.ReadLine());
                    var lines = new string[numberOfVertex];
                    for (int i = 0; i < numberOfVertex; i++)
                    {
                        lines[i] = reader.ReadLine();
                    }
                    yield return ParseGraph(lines);
                    numberOfTest--;
                }
            }
        }

        public void Dispose()
        {
            _input.Dispose();
        }
    }
}