using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
    class Program
    {
        static int maxVal;

        static void recur(List<int> circleList, List<int> bfList, List<bool> kidUsedList) 
        {   
            if (circleList.Count > bfList.Count)
                return;

            var curKid = circleList[circleList.Count - 1];
            var nextKid = bfList[curKid];

            if (circleList[0] == nextKid)
            {
                if (maxVal < circleList.Count)
                    maxVal = circleList.Count;
                return;
            }

            if ( circleList.Count >= 2 && circleList[circleList.Count - 2] == nextKid)
            {
                if ( maxVal < circleList.Count)
                    maxVal = circleList.Count;
            }

            if (!kidUsedList[nextKid])
            {
                circleList.Add(nextKid);
                kidUsedList[nextKid] = true;
                recur(circleList, bfList, kidUsedList);
            }
            else 
            {
                for (int i = 0; i < kidUsedList.Count; i++ )
                {
                    var restKid = i;
                    if (!kidUsedList[restKid] && bfList[restKid] == curKid)
                    {
                        if (maxVal < circleList.Count + 1)
                            maxVal = circleList.Count + 1;
                        break;
                    }   
                }
            }

        }

        static void Main(string[] args)
        {
            var sr = new StreamReader("C-small-attempt0.in");
            var sw = new StreamWriter("output.txt");

            int T = int.Parse(sr.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                int N = int.Parse(sr.ReadLine());
                maxVal = 0;

                var splits = sr.ReadLine().Split(' ');
                List<int> bfList = new List<int>();
                List<List<int>> refBFLIst = new List<List<int>>();

                for (int i = 0; i < splits.Length; i++)
                    bfList.Add(int.Parse(splits[i]) - 1);

                for (int i = 0; i < bfList.Count; i++) 
                {
                    List<int> circleList = new List<int>(); 
                    List<bool> kidUsedList = new List<bool>();
                    foreach (var kid in bfList)
                        kidUsedList.Add(false);

                    circleList.Add(i);
                    kidUsedList[i] = true;
                    recur(circleList, bfList,kidUsedList);

                    if (maxVal == bfList.Count) break;
                }

                sw.WriteLine("Case #" + t.ToString() + ": " + maxVal);
            }
            sr.Close();
            sw.Close();
        }
    }
}
