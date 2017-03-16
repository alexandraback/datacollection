using System;
using System.IO;
using System.Linq;

namespace Treasure
{
    class Program
    {
        static void Main(string[] args)
        {
            int testsCount;
            var treasureSeekers = FileReader.GetLimits(args[0], out testsCount);
            var resultString = string.Empty;
            for (int index = 0; index < testsCount; index++)
            {
                var treasureSeeker = treasureSeekers[index];
                var isImposible = false;

                while (treasureSeeker.Keys.Any() && treasureSeeker.Chests.Any(c => !c.IsOpened) && !isImposible)
                {
                    var requiredKeys = treasureSeeker.Chests.Where(c=>!c.IsOpened).GroupBy(c => c.KeyType).Select(g => new {KeyType = g.Key, Count = g.Count()});
                   
                    var mostRequiredKey = requiredKeys.Max(k => k.Count - treasureSeeker.Keys.Count(tk => tk == k.KeyType));
                    Chest chestToOpen;
                    if (treasureSeeker.Keys.Contains(mostRequiredKey)
                        && requiredKeys.Where(k => k.KeyType == mostRequiredKey).Select(k=>k.Count).FirstOrDefault() == treasureSeeker.Keys.Count(k => k == mostRequiredKey))
                        chestToOpen = treasureSeeker.Chests.First(c => !c.IsOpened);
                    else
                        chestToOpen = treasureSeeker.Chests.FirstOrDefault(c => c.Keys.Contains(mostRequiredKey) && treasureSeeker.Keys.Contains(c.KeyType) && !c.IsOpened);
                    if (chestToOpen == null)
                        chestToOpen = treasureSeeker.Chests.FirstOrDefault(c => c.Keys.Count == treasureSeeker.Chests.Where(tsc=>!tsc.IsOpened).Max(tsc => tsc.Keys.Count) && !c.IsOpened);

                    if (chestToOpen == null)
                        isImposible = true;
                    else
                    {
                        if (treasureSeeker.Keys.Contains(chestToOpen.KeyType))
                            treasureSeeker.OpenChest(chestToOpen);
                        else
                            isImposible = true;
                    }
                }

                if (treasureSeeker.Chests.Any(c => !c.IsOpened))
                    isImposible = true;

                var currentResultString = string.Empty;

                if (isImposible)
                    currentResultString = string.Format("Case #{0}: IMPOSSIBLE", index + 1);
                else
                {
                    currentResultString += string.Format("Case #{0}:", index + 1);
                    while (treasureSeeker.ChestsOpenQueue.Any())
                    {
                        var id = treasureSeeker.ChestsOpenQueue.Dequeue();
                        currentResultString += ' ';
                        currentResultString += id;
                    }
                }
                currentResultString += "\r\n";
                resultString += currentResultString;
                File.WriteAllText(args[1], resultString);
                Console.WriteLine(currentResultString);
            }

            Console.ReadKey();
        }
    }
}
