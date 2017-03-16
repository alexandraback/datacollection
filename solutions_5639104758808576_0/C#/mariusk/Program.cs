using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Marius.CodeJam
{
    public class Program
    {
        public static void Main(string[] args)
        {
            using (var input = new StreamReader("input.txt"))
            using (var output = new StreamWriter("output.txt"))
            {
                var caseCount = int.Parse(input.ReadLine());
                for (var currentCase = 1; currentCase <= caseCount; currentCase++)
                {
                    var line = input.ReadLine();
                    var parts = line.Split().Select(s => s.Trim()).ToArray();
                    var missing = 0;
                    var current = 0;
                    var data = parts[1];
                    for (var i = 0; i < data.Length; i++)
                    {
                        if (current < i)
                        {
                            missing += (i - current);
                            current = i;
                        }
                        current += ToNumber(data[i]);
                    }

                    output.WriteLine("Case #{0}: {1}", currentCase, missing);
                }
            }
        }

        private static int ToNumber(char c)
        {
            if (c < '0' || c > '9')
                throw new ArgumentOutOfRangeException("c");
            return c - '0';
        }
    }
}
