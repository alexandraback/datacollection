using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam1b
{
    class Problem3
    {
        public static void Main()
        {
            new Problem3().Start();
        }

        void Start()
        {
            var fileName = "C-small-1-attempt4";
            using (var input = new System.IO.StreamReader("../../IO/" + fileName + ".in"))
            using (var output = new System.IO.StreamWriter("../../IO/" + fileName + ".out"))
            {
                var TC = int.Parse(input.ReadLine());
                for (var testCase = 1; testCase <= TC; testCase++)
                {
                    Console.WriteLine("Case #" + testCase);

                    var N = int.Parse(input.ReadLine());
                    var hikers = new List<Tuple<uint, uint>>();
                    var minHiker = -1;
                    var minTime = uint.MaxValue;
                    for(var n = 0; n < N; n++)
                    {
                        var line = input.ReadLine().Split(' ').Select(uint.Parse).ToArray();
                        var pos = line[0];
                        var numHikers = line[1];
                        var period = line[2];
                        for (uint i = 0; i < numHikers; i++)
                        {
                            var timeToGoAround = (period + i) * (720 - pos);
                            if(timeToGoAround < minTime)
                            {
                                minHiker = hikers.Count;
                                minTime = timeToGoAround;
                            }
                            hikers.Add(new Tuple<uint, uint>(pos, period + i));
                        }
                    }
                    var totalIntersect = 0;
                    for (int i = 0; i < hikers.Count; i++)
                    {
                        if(i != minHiker)
                        {
                            var pos = hikers[i].Item1;
                            var period = hikers[i].Item2;
                            //TODO: EPSILON
                            if ((360 - pos) * period >= hikers[minHiker].Item2 * (720 - hikers[minHiker].Item1))
                                totalIntersect++;
                        }
                    }
                    Console.WriteLine("Case #" + testCase + ": " + totalIntersect);
                    output.WriteLine("Case #" + testCase + ": " + totalIntersect);
                }
            }
        }
    }
}
