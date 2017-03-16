using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class ProblemA
    {
        static void Main(string[] args)
        {
            var stream = new FileStream(args[0], FileMode.Open, FileAccess.Read);
            var reader = new StreamReader(stream);

            var writeStream = new FileStream(args[1], FileMode.Create, FileAccess.Write);
            var writer = new StreamWriter(writeStream);

            var cases = Convert.ToInt32(reader.ReadLine());

            for (var i = 0; i < cases; i++)
            {
                var hasDiam = false;

                var classes = Convert.ToInt32(reader.ReadLine());
                var graph = new bool[classes, classes];

                for (var j = 0; j < classes; j++)
                {
                    var line = reader.ReadLine().Split(' ');
                    var joins = Convert.ToInt32(line[0]);
                    for (var k = 1; k <= joins; k++)
                        graph[j, Convert.ToInt32(line[k]) - 1] = true;
                }

                for (var j = 0; j < classes; j++)
                {
                    var inherits = new Dictionary<int, int>();
                    if (GetInherits(j, graph, inherits, classes))
                    {
                        hasDiam = true;
                        break;
                    }
                }

                
                writer.WriteLine(string.Format("Case #{0}: {1}", i + 1, hasDiam ? "Yes" : "No"));
            }

            writer.Flush();
            writer.Close();
        }


        private static bool HasDiamond(Dictionary<int, int> inherits)
        {
            foreach (var k in inherits.Values)
                if (k > 1)
                    return true;

            return false;
        }

        private static bool GetInherits(int klass, bool[,] graph, Dictionary<int, int> inherits, int classes)
        {
            for (var i = 0; i < classes; i++)
            {
                if (graph[klass, i])
                {
                    if (inherits.ContainsKey(i))
                        return true;
                    else
                        inherits.Add(i, 1);

                    if (GetInherits(i, graph, inherits, classes))
                        return true;
                }
            }

            return false;
        }
    }
}
