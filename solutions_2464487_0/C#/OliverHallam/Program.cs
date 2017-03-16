using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bullseye
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader("c:\\temp\\in.txt"))
            using (var writer = new StreamWriter("c:\\temp\\out.txt"))
            {
                var count = int.Parse(reader.ReadLine());
                for (var caseID = 1; caseID <= count; caseID++)
                {
                    var row = reader.ReadLine().Split(' ').Select(long.Parse).ToArray();
                    var innerSize = row[0];
                    var paint = row[1];

                    var rings = CountRings(innerSize, paint);

                    writer.WriteLine("Case #{0}: {1}", caseID, rings);
                    writer.Flush();
                }
            }
        }

        private static long CountRings(long startRadius, long paint)
        {
            long rings = -1;
            long radius = startRadius;
            while (paint >= 0)
            {
                rings++;
                paint -= 2 * radius + 1;
                radius += 2;
            }
            return rings;
        }
    }
}
