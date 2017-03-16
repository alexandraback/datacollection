using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace TaskA
{
    internal class Program
    {
        private const string TaskName = "A";

        private static void Main(string[] args)
        {
            var reader = new StreamReader(string.Format("{0}.in", TaskName));
            var writer = new StreamWriter(string.Format("{0}.out", TaskName));

            var taskCount = Int32.Parse(reader.ReadLine());

            for (var taskIndex = 0; taskIndex < taskCount; taskIndex++)
            {
                var n = Int32.Parse(reader.ReadLine());

                var map = new bool[n,n];

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        map[i, j] = false;
                    }
                }

                for (var i = 0; i < n; i++)
                {
                    var mi = reader.ReadLine().Split(' ').Skip(1).Select(j => Int32.Parse(j) - 1);

                    foreach (var i1 in mi)
                    {
                        map[i, i1] = true;
                    }
                }


                var flag = false;

                for (var k = 0; k < n; k++)
                    for (var i = 0; i < n; i++)
                        for (var j = 0; j < n; j++)
                        {
                            if (map[i, j] && map[i, k] && map[k, j])
                            {
                                flag = true;
                            }
                            map[i, j] = map[i, j] || (map[i, k] && map[k, j]);
                        }

                writer.WriteLine(string.Format("Case #{0}: {1}", taskIndex + 1, flag ? "Yes" : "No"));
            }
            writer.Close();
            reader.Close();
        }
    }
}