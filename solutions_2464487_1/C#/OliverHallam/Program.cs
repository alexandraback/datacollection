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
            var min = 0l;
            var max = 20000000000l;

            while (max > min)
            {
                var mid = (min + max + 1) / 2;

                var paintForMid = PaintForRings(startRadius, mid);

                if (paintForMid > paint)
                    max = mid - 1;
                else if (paintForMid < paint)
                    min = mid;
                else
                    return mid;
            }
            return min;
        }

        private static long PaintForRings(long startRadius, long ringCount)
        {
            try
            {
                return checked(ringCount * (2 * startRadius + 2 * ringCount - 1));
            }
            catch (OverflowException)
            {
                return long.MaxValue;
            }
        }
    }
}
