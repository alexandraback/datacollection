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
                    var hasDiamond = false;
                    for (var i = 0; i < classesCount; i++)
                    {
                        try
                        {
                            GetIndirectlyInheritedClasses(i, indirectlyInheritedClasses, directlyInheritedClasses);
                        }
                        catch (ApplicationException)
                        {
                            hasDiamond = true;
                        }
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

            var result = new HashSet<int>();
            foreach (var directlyInheritedClass in directlyInheritedClasses[current])
            {
                GetIndirectlyInheritedClasses(directlyInheritedClass, indirectlyInheritedClasses, directlyInheritedClasses);
                foreach (var inh in indirectlyInheritedClasses[directlyInheritedClass])
                {
                    if (result.Contains(inh))
                        throw new ApplicationException();
                    result.Add(inh);
                }
                result.Add(directlyInheritedClass);
            }
            indirectlyInheritedClasses[current] = result.ToArray();
        }
    }
}
