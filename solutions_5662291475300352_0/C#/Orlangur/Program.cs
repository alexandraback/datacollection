using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            var caseCount = int.Parse(Console.ReadLine());
            for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
            {
                var groupCount = int.Parse(Console.ReadLine());
                var groups = new List<HikerGroup>(groupCount);
                for (var groupIndex = 0; groupIndex < groupCount; groupIndex++)
                {
                    var line = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
                    groups.Add(new HikerGroup
                    {
                        StartingDegree = line[0],
                        HikerCount = line[1],
                        FastestHikerMinutesPerCircle = line[2]
                    });
                }

                var borderEncounterCount = groups.Sum(group => (long)group.HikerCount);
                var minEncounterCount = borderEncounterCount;

                foreach (var time in
                    groups
                        .SelectMany(group => group.GetFirstFinishingTimesInMinuteParts())
                        .OrderBy(timeInMinuteParts => timeInMinuteParts))
                {
                    var encounterCount = groups.Sum(group => group.GetEncounterCountAt(time));
                    if (encounterCount < minEncounterCount)
                        minEncounterCount = encounterCount;
                    if ((encounterCount > borderEncounterCount) || (minEncounterCount == 0))
                        break;
                }

                Console.WriteLine("Case #{0}: {1}", caseNumber, minEncounterCount);
            }
        }

        class HikerGroup
        {
            public int StartingDegree { get; set; }
            public int HikerCount { get; set; }
            public int FastestHikerMinutesPerCircle { get; set; }


            public long GetFastestFirstFinishingTimeInMinuteParts()
            {
                return (360 - StartingDegree) * FastestHikerMinutesPerCircle;
            }

            public long GetFirstFinishingTimeStepInMinuteParts()
            {
                return 360 - StartingDegree;
            }

            public long GetEncounterCountAt(long timeInMinuteParts)
            {
                var result = 0L;
                var x = FastestHikerMinutesPerCircle * timeInMinuteParts + StartingDegree;
                for (var hikerIndex = 0; hikerIndex < HikerCount; hikerIndex++)
                {
                    var circlesFinished = (timeInMinuteParts + StartingDegree * (FastestHikerMinutesPerCircle + hikerIndex)) /
                        (360 * (FastestHikerMinutesPerCircle + hikerIndex));
                    result += Math.Abs(circlesFinished - 1);
                }
                return result;
            }

            public IEnumerable<long> GetFirstFinishingTimesInMinuteParts()
            {
                var currentTimeInMinuteParts = GetFastestFirstFinishingTimeInMinuteParts();
                for (var hikerIndex = 0; hikerIndex < HikerCount; hikerIndex++)
                {
                    yield return currentTimeInMinuteParts;
                    currentTimeInMinuteParts += GetFirstFinishingTimeStepInMinuteParts();
                }
            }
        }
    }
}
