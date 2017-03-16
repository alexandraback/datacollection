using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    public class Round1BProblemC : Problem
    {
        protected override string SolveCase()
        {
            int numberOfGroups = ReadNextLineAsInt32();
            List<int> hikerStartPositions = new List<int>();
            List<int> hikerRevTimes = new List<int>();
            for (int i = 0; i < numberOfGroups; i++)
            {
                int[] parameters = ReadNextLineAsInt32Array();
                int startPos = parameters[0];
                int numberOfHikers = parameters[1];
                int revTime = parameters[2];
                for (int j = 0; j < numberOfHikers; j++)
                {
                    hikerStartPositions.Add(startPos);
                    hikerRevTimes.Add(revTime);
                    revTime++;
                }
            }
            if (hikerStartPositions.Count <= 1)
            {
                return "0";
            }

            int fastestHiker = hikerRevTimes[0] > hikerRevTimes[1] ? 1 : 0;

            int fastestHikerRevTime = hikerRevTimes[fastestHiker];
            int slowestHikerRevTime = hikerRevTimes[1 - fastestHiker];
            int fastestHikerStartPosition = hikerStartPositions[fastestHiker];
            int slowestHikerStartPosition = hikerStartPositions[1 - fastestHiker];

            double timeForSlowestHikerToCompleteLap = 1.0 * (360 - slowestHikerStartPosition) / 360 * slowestHikerRevTime;
            double timeForFastestHikerToCompleteNextLap = (1.0 * (360 - fastestHikerStartPosition) / 360 + 1) * fastestHikerRevTime;

            if (timeForFastestHikerToCompleteNextLap > timeForSlowestHikerToCompleteLap)
            {
                return "0";
            }
            return "1";
        }
    }
}
