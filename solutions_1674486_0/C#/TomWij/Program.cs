using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GCJ.DI
{
    class Program
    {
        static int C (string s)
        {
            return Convert.ToInt32(s);
        }

        static bool Check(int emptyOne, ref List<List<int>> reversedClasses)
        {
            var visit = new List<int> {emptyOne};
            var current = 0;

            while (current < visit.Count())
            {
                foreach (var currentClassInheritance in reversedClasses[visit[current]])
                {
                    if (visit.Contains(currentClassInheritance))
                        return true;
                    
                    visit.Add(currentClassInheritance);
                }

                ++current;
            }

            return false;
        }

        static void Main()
        {
            using (var sr = new StreamReader(new FileStream("file.in", FileMode.Open)))
            {
                var testCases = Convert.ToInt32(sr.ReadLine());
                var output = new List<String>();

                // Read each test case.
                var i = 0;
                while (i < testCases)
                {
                    var classesCount = C(sr.ReadLine());
                    var classes = new List<List<int>>();
                    var emptyOnes = new List<int>();
                    var reversedClasses = new List<List<int>>();

                    // Read each class.
                    var j = 0;
                    while (j < classesCount)
                    {
                        var myClass = sr.ReadLine().Split(' ').Select(x => C(x) - 1).Skip(1).ToList();
                        classes.Add(myClass);

                        if (!myClass.Any())
                            emptyOnes.Add(j);

                        ++j;

                        // Create empty lists in advance for the next task.
                        reversedClasses.Add(new List<int>());
                    }

                    // Reverse the classes, such that everything points from the 0 classes instead of to the 0 class:
                    j = 0;
                    foreach (var myClass in classes)
                    {
                        foreach (var k in myClass)
                            reversedClasses[k].Add(j);

                        ++j;
                    }

                    // Enumerate each class, see if we come across the same class twice.
                    var check = (from emptyOne in emptyOnes
                                 where Check(emptyOne, ref reversedClasses)
                                 select emptyOne).Any();

                    output.Add("Case #" + ++i + ": " + (check ? "Yes" : "No"));
                }

                File.WriteAllLines("file.out", output);
            }
        }
    }
}
