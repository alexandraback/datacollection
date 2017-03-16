using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2012QualificationProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            using (TextReader reader = File.OpenText(@"a.in"))
            using (TextWriter writer = File.CreateText(@"a.out"))
            {
                var cases = Convert.ToInt32(reader.ReadLine());
                for (int c = 1; c <= cases; c++)
                {
                    var line = reader.ReadLine();
                    var split = line.Split(' ');
                    var A = Convert.ToInt32(split[0]);
                    var B = Convert.ToInt32(split[1]);

                    var result = B + 2.0;

                    line = reader.ReadLine();
                    split = line.Split(' ');
                    var pTotal = 1.0;
                    for (int a = 0; a < A; a++)
                    {
                        pTotal *= Convert.ToDouble(split[a]);
                        var correct = ((A - a - 1) * 2.0 + B - A + 1) * pTotal;
                        var incorrect = ((A - a - 1) * 2.0 + B - A + 1 + B + 1) * (1.0 - pTotal);
                        if (correct + incorrect <= result)
                            result = correct + incorrect;
                    }

                    var correct1 = (B - A + 1) * pTotal;
                    var incorrect1 = (B - A + 1 + B + 1) * (1.0 - pTotal);
                    if (correct1 + incorrect1 <= result)
                        result = correct1 + incorrect1;


                    writer.WriteLine("Case #{0}: {1}", c, result);
                }
            }
        }
    }
}
