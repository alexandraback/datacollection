using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace R1B
{
    class Program
    {
        static void Main()
        {
            int T = int.Parse(Console.ReadLine());
            for (int t = 0; t < T; t++)
            {
                string result = "";
                int N = int.Parse(Console.ReadLine());
                List<List<int>> rows = new List<List<int>>();
                List<int> sortedList = new List<int>();
                for (int i = 0; i < 2 * N - 1; i++)
                {
                    List<int> row = new List<int>();
                    String line = Console.ReadLine();
                    var sts = line.Split(' ');
                    for (int j = 0; j < sts.Length; j++)
                    {
                        int k = int.Parse(sts[j]);
                        row.Add(k);
                        int l = 0;
                        for (; l < sortedList.Count; l++)
                        {
                            if (sortedList[l] > k)
                                break;
                        }
                        sortedList.Insert(l, k);
                    }
                    rows.Add(row);
                }

                List<int> res = findMissedNumbers(sortedList);
                for (int i = 0; i < res.Count; i++)
                {
                    result += " " + res[i];
                }
                Console.WriteLine("Case #" + (t + 1) + ":" + result);
            }
        }

        private static List<int> findMissedNumbers(List<int> sortedList)
        {
            List<int> result = new List<int>();
            for (int idx = 0; idx < sortedList.Count;)
            {
                int num = sortedList[idx];

                int cnt = 0;
                for (int i = idx; i < sortedList.Count; i++)
                {
                    if (sortedList[i] == num)
                        cnt++;
                    else
                    {
                        break;
                    }
                }
                if (cnt % 2 == 1)
                    result.Add(num);
                while (idx < sortedList.Count && num == sortedList[idx]) idx++;
            }
            return result;
        }
    }
}
