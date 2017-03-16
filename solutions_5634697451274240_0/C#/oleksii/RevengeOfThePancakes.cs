using System.IO;
using System.Linq;
using System.Text;

namespace StudyingConsoleCSharp.CodeJam._2016Qualification
{
    public class RevengeOfThePancakes
    {
        private const string Path = @"C:\_Development\Git\Study\StudyingConsole\StudyingConsoleCSharp\CodeJam\2016Qualification\";

        public void Process()
        {
            var result = new StringBuilder();
            using (var textReader = File.OpenText(Path + "in_B.txt"))
            {
                var testsCount = int.Parse(textReader.ReadLine());
                for (var t = 1; t <= testsCount; ++t)
                {
                    var cakes = textReader.ReadLine().Select(i => i == '+').ToArray();

                    result.AppendLine($"Case #{t}: {Solve(cakes, cakes.Length - 1, 0, true)}");
                }
            }

            using (var textWriter = File.CreateText(Path + "out_B.txt"))
                textWriter.Write(result.ToString());
        }

        private static int Solve(bool[] cakes, int end, int sum, bool desiredState)
        {
            while (end >= 0)
            {
                var current = cakes[end];
                while (end >= 0 && cakes[end] == current)
                    --end;

                if (current == desiredState)
                    continue;
                sum = sum + 1;
                desiredState = !desiredState;
            }
            return sum;
        }
    }
}
