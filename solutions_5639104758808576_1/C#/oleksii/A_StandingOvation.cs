using System.IO;
using System.Linq;
using System.Text;

namespace StudyingConsoleCSharp.CodeJam._2015Qualification
{
    public class StandingOvation
    {
        public void Process()
        {
            var result = new StringBuilder();
            using (var textReader = File.OpenText("D:\\in.txt"))
            {
                var testsCount = int.Parse(textReader.ReadLine());
                for (var t = 1; t <= testsCount; ++t)
                {
                    var ps = textReader.ReadLine().Split(' ').ToArray();
                    var arr = ps[1].Select(i => byte.Parse(i.ToString())).ToArray();

                    result.AppendLine(string.Format("Case #{0}: {1}", t, GetCount(arr)));
                }
            }
            using (var textWriter = File.CreateText("D:\\out.txt"))
            {
                textWriter.Write(result.ToString());
            }
        }

        private int GetCount(byte[] arr)
        {
            if (arr.Length < 1)
                return 0;

            var result = 0;
            int tmp = arr[0];
            for (var i = 1; i < arr.Length; ++i)
            {
                var diff = i - tmp;
                if (diff > 0)
                    result += diff;

                tmp += arr[i] + (diff > 0 ? diff : 0);
            }
            return result;
        }
    }
}