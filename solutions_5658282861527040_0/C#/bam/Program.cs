using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1B_2
{
    class Program
    {
        static void Main(string[] args)
        {
             var file = new StreamReader(@"C:\Users\Administrator\Documents\CodeJam\r1_2_2.txt");
            var outFile = new StreamWriter(@"C:\Users\Administrator\Documents\CodeJam\r1_2_2Out.txt");
            var total = long.Parse(file.ReadLine());

            for (long i = 1; i <= total; i++)
            {
                var lineSplit = file.ReadLine().Split(' ');

                var A = long.Parse(lineSplit[0]);
                var B = long.Parse(lineSplit[1]);
                var K = long.Parse(lineSplit[2]);
                long nPos = 0;
                for (long a = 0; a < A; a++)
                {
                    for (long b = 0; b < B; b++)
                    {
                        if ((a & b) < K)
                            nPos++;
                    }
                }

                outFile.WriteLine(string.Format("Case #{0}: {1}", i, nPos));

            }

            file.Close();
            outFile.Close();
        }
    }
}
