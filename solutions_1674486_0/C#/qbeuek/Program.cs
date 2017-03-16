using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

//rachu ciachu pierwsze!

namespace inheritance
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader("..\\..\\input.txt"))
            using (var outputStream = new StreamWriter("..\\..\\output.txt.", false))
            {
                var totalCases = int.Parse(inputStream.ReadLine());

                for (var currentCase = 1; currentCase <= totalCases; currentCase++)
                {
                    var classesCount = int.Parse(inputStream.ReadLine());
                    var directlyInheritedClasses = new int[classesCount][];
                    for (var i = 0; i < classesCount; i++)
                    {
                        directlyInheritedClasses[i] = inputStream.ReadLine().Split().Select(s => int.Parse(s) - 1).Skip(1).ToArray();
                    }

                    var indirectlyInheritedClasses = new int[classesCount][];
                    for (var i = 0; i < classesCount; i++)
                    {
                        GetIndirectlyInheritedClasses(i, indirectlyInheritedClasses, directlyInheritedClasses);
                    }

                    var hasDiamond = false;
                    for (var i = 0; i < classesCount; i++)
                    {
                        hasDiamond = indirectlyInheritedClasses[i].GroupBy(c => c).Where(g => g.Count() > 1).Any();
                        if (hasDiamond)
                            break;
                    }
                    outputStream.WriteLine("Case #{0}: {1}", currentCase, hasDiamond ? "Yes" : "No");
                }
            }
        }

        static void GetIndirectlyInheritedClasses(int current, int[][] indirectlyInheritedClasses, int[][] directlyInheritedClasses)
        {
            if (indirectlyInheritedClasses[current] != null)
                return;

            var result = new List<int>();
            foreach (var directlyInheritedClass in directlyInheritedClasses[current])
            {
                GetIndirectlyInheritedClasses(directlyInheritedClass, indirectlyInheritedClasses, directlyInheritedClasses);
                result.AddRange(indirectlyInheritedClasses[directlyInheritedClass]);
                result.Add(directlyInheritedClass);
            }
            indirectlyInheritedClasses[current] = result.ToArray();
        }
    }
}
