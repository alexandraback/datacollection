using System.Collections.Generic;
using System.IO;
using System.Text;

namespace StudyingConsoleCSharp.CodeJam._2016Qualification
{
    /// <summary>
    /// Problem A. Counting Sheep
    /// </summary>
    public class CountingSheep
    {
        private const string Path = @"C:\_Development\Git\Study\StudyingConsole\StudyingConsoleCSharp\CodeJam\2016Qualification\";

        public void Process()
        {
            var result = new StringBuilder();
            using (var textReader = File.OpenText(Path + "in_A.txt"))
            {
                var testsCount = int.Parse(textReader.ReadLine());
                for (var t = 1; t <= testsCount; ++t)
                {
                    var number = int.Parse(textReader.ReadLine());

                    result.AppendLine($"Case #{t}: {Solve(number)}");
                }
            }
            using (var textWriter = File.CreateText(Path + "out_A.txt"))
            {
                textWriter.Write(result.ToString());
            }
        }

        private static string Solve(int n)
        {
            if (n == 0)
                return "INSOMNIA";

            var observed = new HashSet<byte>();
            long current = 0;
            while (observed.Count < 10)
            {
                current += n;
                long t = current;
                while (t/10 > 0)
                {
                    observed.Add((byte)(t%10));
                    t /= 10;
                }
                observed.Add((byte)t);
            }
            return current.ToString();
        }
    }
}
