using System.IO;
using System.Linq;
using System.Text;

namespace StudyingConsoleCSharp.CodeJam._2015Qualification
{
    public class OminousOmino
    {
        public void Process()
        {
            var result = new StringBuilder();
            using (var textReader = File.OpenText("..\\..\\CodeJam\\2015Qualification\\inD.txt"))
            {
                var testsCount = int.Parse(textReader.ReadLine());
                for (var t = 1; t <= testsCount; ++t)
                {
                    var number = 0;
                    var ps = textReader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                    var X = ps[0];
                    var R = ps[1];
                    var C = ps[2];

                    result.AppendLine(string.Format("Case #{0}: {1}", t, CanFill(X, R, C) ? "GABRIEL" : "RICHARD"));
                }
            }
            using (var textWriter = File.CreateText("..\\..\\CodeJam\\2015Qualification\\outD.txt"))
            {
                textWriter.Write(result.ToString());
            }
        }

        private bool CanFill(int X, int R, int C)
        {
            if (X == 1)
                return true;

            if (X == 2)
                return R%2 == 0 || C%2 == 0;

            if (X == 3)
                return R%3 == 0 && C > 1 || C%3 == 0 && R > 1;

            if (X == 4)
                return R%4 == 0 && C > 2 || C%4 == 0 && R > 2;

            return false;
        }
    }
}