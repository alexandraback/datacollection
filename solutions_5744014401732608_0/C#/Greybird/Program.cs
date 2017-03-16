using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var dir = new DirectoryInfo(@"C:\Users\Arnau\Downloads");
            var file = dir.EnumerateFiles("*.in").OrderByDescending(f => f.LastWriteTime).First();
            Console.WriteLine(file.Name);
            Console.ReadLine();
            var lines = File.ReadAllLines(file.FullName);
            var count = int.Parse(lines[0]);
            var results = new List<string>();
            for (var t = 0; t < count; t++)
            {
                Console.WriteLine("Test {0}/{1}", t + 1, count);
                var B = int.Parse(lines[t + 1].Split(' ')[0]);
                var M = int.Parse(lines[t + 1].Split(' ')[1]);

                var connections = new Slide[B, B];
                for (var from = 0; from < B; from++)
                {
                    for (var to = 0; to < B; to++)
                    {
                        connections[from, to] = Slide.Present;
                    }
                }
                var steps = new List<Step>();
                var paths = CountPaths(connections, B);
                if (paths >= M)
                {
                    connections = new Slide[B, B];
                    for (var i = 0; i < B; i++)
                    {
                        connections[i, i] = Slide.Forbidden;
                    }
                    steps.Add(CreateStep(connections));
                    while (AddASlideWherePossible(B, M, steps))
                    {
                        ;
                    }
                }

                if (steps.Count == 0)
                {
                    results.Add($"Case #{t + 1}: IMPOSSIBLE");
                }
                else
                {
                    results.Add($"Case #{t + 1}: POSSIBLE");
                    for (var from = 0; @from < B; @from++)
                    {
                        var c = steps.Last().Connections;
                        var sb = new StringBuilder();
                        for (var to = 0; to < B; to++)
                        {
                            var s = c[@from, to];
                            sb.Append(s == Slide.Present ? "1" : "0");
                        }
                        results.Add(sb.ToString());
                    }
                }
            }
            File.WriteAllLines(@"output.txt", results);
        }

        private static Step CreateStep(Slide[,] connections, Point? point = null)
        {
            return new Step
            {
                Connections = (Slide[,]) connections.Clone(),
                Added = point
            };
        }

        private static int CountPaths(Slide[,] connections, int B)
        {
            var paths = new int[B, B];
            return GetNumberOfPaths(0, B - 1, B, connections, paths);
        }

        private static int GetNumberOfPaths(int from, int to, int B, Slide[,] connections, int[,] paths)
        {
            if (paths[from, to] != 0)
            {
                return paths[from, to];
            }
            if (from == to)
            {
                paths[from, to] = 1;
                return 1;
            }
            var sum = 0;
            for (var i = from + 1; i < B; i++)
            {
                if (connections[from, i] == Slide.Present)
                {
                    sum += GetNumberOfPaths(i, to, B, connections, paths);
                }
            }
            paths[from, to] = sum;
            return sum;
        }

        public class Step
        {
            public Slide[,] Connections;
            public List<Point> ForbiddenAtStep = new List<Point>();
            public Point? Added { get; set; }
        }

        private static bool AddASlideWherePossible(int B, int M, List<Step> steps)
        {
            if (steps.Count == 0)
            {
                return false;
            }
            var lastStep = steps.Last();
            for (var from = 0; from < B; from++)
            {
                for (var to = from + 1; to < B; to++)
                {
                    if (lastStep.Connections[from, to] == Slide.None)
                    {
                        if (!lastStep.ForbiddenAtStep.Any(p => p.X == from && p.Y == to))
                        {
                            var step = CreateStep(lastStep.Connections, new Point(from, to));
                            step.Connections[from, to] = Slide.Present;
                            var number = CountPaths(step.Connections, B);
                            if (number > M)
                            {
                                lastStep.ForbiddenAtStep.Add(new Point(from, to));
                            }
                            else
                            {
                                steps.Add(step);
                                if (number == M)
                                {
                                    return false;
                                }
                                return true;
                            }
                        }
                    }
                }
            }
            var addedPoint = lastStep.Added;
            steps.RemoveAt(steps.Count - 1);
            if (addedPoint != null)
            {
                steps.Last().ForbiddenAtStep.Add(addedPoint.Value);
            }
            return true;
        }

        public enum Slide
        {
            None,
            Forbidden,
            Present
        }
    }
}