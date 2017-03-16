using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemA
{
    class ProblemA
    {
        class ClassDefinition
        {
            public List<int> InheritedFrom { get; set; }
            public int References { get; set; }
            public int PathsHere { get; set; }

            public ClassDefinition()
            {
                InheritedFrom = new List<int>();
                References = 0;
            }

            public void Reset()
            {
                PathsHere = 0;
            }
        }

        static void Main(string[] args)
        {
            string inputFolder = @"c:\Devel\X\GoogleCodeJam2012_Round1C\Inputs";
            string inputFile = "A-large.in";

            string outputFile = Path.GetFileNameWithoutExtension(inputFile) + ".out";

            using (StreamReader sr = new StreamReader(Path.Combine(inputFolder, inputFile)))
            using (StreamWriter sw = new StreamWriter(Path.Combine(inputFolder, outputFile)))
            {
                string line;

                line = sr.ReadLine();
                int T = int.Parse(line);

                for (int testcase = 0; testcase < T; testcase++)
                {
                    // code thing here
                    line = sr.ReadLine();
                    int N = int.Parse(line);

                    ClassDefinition[] classes = new ClassDefinition[N];

                    for (int classIndex = 0; classIndex < N; classIndex++)
                    {
                        classes[classIndex] = new ClassDefinition();
                    }

                    for (int classIndex = 0; classIndex < N; classIndex++)
                    {
                        line = sr.ReadLine();
                        string[] parts = line.Split(' ');
                        int M = int.Parse(parts[0]);

                        for (int parentIndex = 0; parentIndex < M; parentIndex++)
                        {
                            int parentClass = int.Parse(parts[parentIndex + 1]) - 1;
                            classes[classIndex].InheritedFrom.Add(parentClass);
                            classes[parentClass].References++;
                        }
                    }

                    var solution = "No";

                    // find all bottom nodes
                    foreach (var c in classes)
                    {
                        for (int i = 0; i < N; i++)
                        {
                            classes[i].Reset();
                        }

                        Queue<ClassDefinition> queue = new Queue<ClassDefinition>();
                        queue.Enqueue(c);

                        while (queue.Count > 0)
                        {
                            ClassDefinition next = queue.Dequeue();

                            if (next.PathsHere >= 2)
                            {
                                solution = "Yes";
                                break;
                            }

                            foreach (var parentId in next.InheritedFrom)
                            {
                                classes[parentId].PathsHere++;
                                queue.Enqueue(classes[parentId]);
                            }
                        }

                        if (solution == "Yes") break;
                    }                    

                    // write solution here
                    sw.WriteLine("Case #{0}: {1}", testcase + 1, solution);
                }
            }
        }
    }
}
