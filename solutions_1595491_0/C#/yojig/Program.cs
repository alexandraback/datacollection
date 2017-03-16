using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace _2012Qual_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputFileName = "B-small.in";

            if (args.Count() > 0)
                inputFileName = args[0];

            var sb = new StringBuilder();
            var input = new List<string>();

            using (var stream = new FileStream(inputFileName, FileMode.Open))
            {
                using (var reader = new StreamReader(stream))
                {
                    string line;
                    while ((line = reader.ReadLine()) != null)
                    {
                        input.Add(line);
                    }
                }
            }

            var caseCount = Convert.ToInt32(input[0]);

            for (int i = 0; i < caseCount; i++)
            {
                var vars = input[1 + i].Split(' ');

                var tripletsCount = Convert.ToInt32(vars[0]);
                var surpriseCount = Convert.ToInt32(vars[1]);
                var requiredPoints = Convert.ToInt32(vars[2]);

                var hitCount = 0;

                for (int j = 3; j < tripletsCount + 3; j++)
                {
                    var tripletScore = Convert.ToInt32(vars[j]);

                    var sc = tripletScore / 3;
                    var left = tripletScore % 3;

                    if (sc >= requiredPoints)
                    {
                        ++hitCount;
                        continue;
                    }

                    if (tripletScore == 0)
                        continue;

                    if (left > 0)
                    {
                        if (left <= 2 && sc + 1 >= requiredPoints)
                        {
                            ++hitCount;
                        }

                        else if (surpriseCount > 0 && sc + left >= requiredPoints)
                        {
                            ++hitCount;
                            --surpriseCount;
                        }
                    }
                    else if (surpriseCount > 0 && sc + 1 >= requiredPoints)
                    {
                        ++hitCount;
                        --surpriseCount;
                    }
                }

                sb.AppendFormat("Case #{0}: {1}", i + 1, hitCount);
                sb.AppendLine();
            }

            using (var stream = new FileStream(inputFileName + ".out", FileMode.Create))
            {
                using (var writer = new StreamWriter(stream))
                {
                    writer.Write(sb.ToString());
                }
            }
        }
    }
}
