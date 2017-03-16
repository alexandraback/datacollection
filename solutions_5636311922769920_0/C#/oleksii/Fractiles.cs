using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StudyingConsoleCSharp.CodeJam._2016Qualification
{
    public class Fractiles
    {
        private const string Path = @"C:\_Development\Git\Study\StudyingConsole\StudyingConsoleCSharp\CodeJam\2016Qualification\";

        public void Process()
        {
            var result = new StringBuilder();
            using (var textReader = File.OpenText(Path + "in_D.txt"))
            {
                var testsCount = int.Parse(textReader.ReadLine());
                for (var t = 1; t <= testsCount; ++t)
                {
                    var ps = textReader.ReadLine().Split(' ').Select(int.Parse).ToArray();

                    result.AppendLine($"Case #{t}: {Solve(ps[0], ps[1], ps[2])}");
                }
            }
            using (var textWriter = File.CreateText(Path + "out_D.txt"))
            {
                textWriter.Write(result.ToString());
            }
        }

        private string Solve(int K, int C, int S)
        {
            return string.Join(" ", Enumerable.Range(1, S));
        }
    }
}
