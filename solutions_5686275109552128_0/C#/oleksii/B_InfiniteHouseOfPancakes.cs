using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace StudyingConsoleCSharp.CodeJam._2015Qualification
{
    public class InfiniteHouseOfPancakes
    {
        public void Process()
        {
            var result = new StringBuilder();
            using (var textReader = File.OpenText("..\\..\\CodeJam\\2015Qualification\\in.txt"))
            {
                var testsCount = int.Parse(textReader.ReadLine());
                for (int t = 1; t <= testsCount; ++t)
                {
                    textReader.ReadLine();
                    var arr = textReader.ReadLine().Split(' ').Select(int.Parse).ToList();
                    arr.Sort();

                    result.AppendLine(string.Format("Case #{0}: {1}", t, GetTime(arr)));
                }
            }
            using (var textWriter = File.CreateText("..\\..\\CodeJam\\2015Qualification\\out.txt"))
            {
                textWriter.Write(result.ToString());
            }
        }

        private int GetTime(List<int> arr)
        {
            if (arr.Count < 1)
                return 0;

            var result = arr.Last();
            var spent = 0;
            while (arr.Last() > 1)
            {
                spent++;
                var max = SplitAndGetMax(arr);

                if (max + spent < result)
                    result = max + spent;
            }
            return result;
        }

        private int SplitAndGetMax(List<int> arr)
        {
            var max = arr.Last();
            var x = max / 2;
            var y = (max % 2 == 0) ? x : x + 1;
            
            arr.RemoveAt(arr.Count - 1);
            Insert(arr, x);
            Insert(arr, y);

            return arr.Last(); 
        }

        private void Insert(List<int> arr, int val)
        {
            int i = 0;
            while (i < arr.Count && arr[i] < val)
            {
                ++i;
            }
            arr.Insert(i, val);
        }
    }
}
