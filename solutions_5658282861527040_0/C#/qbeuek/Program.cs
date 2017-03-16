using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lottery
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader(@"..\..\input.txt"))
            using (var outputStream = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(inputStream.ReadLine());
                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    var inputs = inputStream.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                    var A = inputs[0];
                    var B = inputs[1];
                    var K = inputs[2];

                    var result = 0L;
                    for (var a = 0; a < A; a++)
                        for (var b = 0; b < B; b++)
                            if ((a & b) < K)
                                result++;

                    outputStream.WriteLine("Case #{0}: {1}", caseNumber, result);
                }
            }
        }
    }
}
