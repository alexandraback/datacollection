using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GoogleCodeJamSolutions
{
    class InfiniteHouseOfPanckacakes
    {
        public void Solve(string fileName)
        {
            var data = LoadData(fileName);
            var solution = SolveInternally(data);
            WriteSolution(solution, fileName);
        }

        private int[] SolveInternally(List<int[]> data)
        {
            var result = new int[data.Count];

            for(int i = 0; i < data.Count; ++i)
            {
                result[i] = SolveConcrete(data[i]);
            }
            return result;
        }

        private class Data
        {
            public readonly int[] Pancakes;
            public readonly int SpecialMinutes;
            public readonly int SpentMinutes;

            public Data(int[] pancakes, int specialMinutes, int spentMinutes)
            {
                Pancakes = pancakes;
                SpecialMinutes = specialMinutes;
                SpentMinutes = spentMinutes;
            }
        }

        private int SolveConcrete(int[] d)
        {
            var queue = new Queue<Data>();
            queue.Enqueue(new Data(d, 0, 0));

            var bestTime = d.Max();

            while(queue.Count > 0)
            {
                var currentData = queue.Dequeue();
                var max = currentData.Pancakes.Max();
                
                if(max <= 2)
                {
                    bestTime = Math.Min(2 + currentData.SpecialMinutes + currentData.SpentMinutes, bestTime);
                    continue;
                }

                //do nothing
                var newList = currentData.Pancakes.Select(x => x - 1).Where(x => x > 0).ToArray();
                queue.Enqueue(new Data(newList, currentData.SpecialMinutes, currentData.SpentMinutes + 1));

                //take special minute
                var list = currentData.Pancakes;
                var maxItem = list[0];
                var newsplist = new int[list.Length + 1];

                var index = 0;
                for(int i = 0; i < list.Length; ++i)
                {
                    if(list[i] > maxItem)
                    {
                        maxItem = list[i];
                        index = i;
                    }

                    newsplist[i] = list[i];
                }

                newsplist[index] = newsplist[index] / 2;
                newsplist[list.Length] = maxItem - newsplist[index];
                queue.Enqueue(new Data(newsplist, currentData.SpecialMinutes, currentData.SpentMinutes + 1));
            }

            return bestTime;
        }

        private List<int[]> LoadData(string fileName)
        {
            var res = new List<int[]>();
            using (var f = new StreamReader(fileName))
            {
                var testCases = int.Parse(f.ReadLine());
                for (int i = 0; i < testCases; ++i)
                {
                    var curLine = f.ReadLine();
                    
                    var pancakesStr = f.ReadLine().Split(' ');
                    var pancakes = pancakesStr.Select(x => int.Parse(x)).ToArray();
                    res.Add(pancakes);
                }
            }

            return res;
        }

        private void WriteSolution(int[] result, string fileName)
        {
            fileName = fileName.Replace(".in", ".out");
            using (var o = new StreamWriter(fileName))
            {
                for (int i = 0; i < result.Length; ++i)
                {
                    if (i < result.Length - 1)
                        o.WriteLine("Case #{0}: {1}", i + 1, result[i]);
                    else
                        o.Write("Case #{0}: {1}", i + 1, result[i]);
                }
                
            }
        }
    }
}
