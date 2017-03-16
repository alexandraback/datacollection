using System;
using System.IO;
using System.Linq;

namespace Treasure
{
    public class Chest
    {
        public int ID;
        public int KeyType;
        public int[] Keys;

        public override string ToString()
        {
            return this.ID.ToString();
        }
    }

    public class Treasure
    {
        private static void Main(string[] args)
        {
            using (var reader = new StreamReader("in.txt"))
            using (var writer = new StreamWriter("out.txt"))
            {
                reader.ReadLine();

                int caseID = 1;
                while (!reader.EndOfStream)
                {
                    var counts = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                    var keyCount = counts[0];
                    var chestCount = counts[1];

                    var startingKeys = ReadKeys(reader);
                    var chests = new Chest[chestCount];
                    for (var i = 0; i < chestCount; i++)
                    {
                        chests[i] = ReadChest(reader, i + 1);
                    }

                    var solution = FindSolution(startingKeys, chests);

                    var result = solution != null ? string.Join(" ", solution.Select(c => c.ToString())) : "IMPOSSIBLE";
                    writer.WriteLine("Case #{0}: {1}", caseID, result);
                    caseID++;
                }
            }
        }

        private static Chest ReadChest(TextReader reader, int id)
        {
            var chest = new Chest();
            chest.ID = id;
            var line = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
            chest.KeyType = line[0];

            chest.Keys = line.Skip(2).OrderBy(x => x).ToArray();
            return chest;
        }

        private static int[] ReadKeys(TextReader reader)
        {
            return reader.ReadLine().Split(' ').Select(int.Parse).OrderBy(x => x).ToArray();
        }
        
        private static Chest[] FindSolution(int[] startingKeys, Chest[] chests)
        {
            var indexes = Enumerable.Range(0, chests.Length).ToArray();
            var keys = new int[201];
            foreach (var key in startingKeys) keys[key]++;

            var theoriticalTotalKeys = new int[201];
            foreach (var chest in chests)
            {
                foreach (var key in chest.Keys)
                {
                    theoriticalTotalKeys[key]++;
                }
                theoriticalTotalKeys[chest.KeyType]--;
            }
            
            if (!Sort(chests, indexes, 0, keys, theoriticalTotalKeys, startingKeys.Length)) return null;

            return indexes.Select(i => chests[i]).ToArray();
        }

        private static bool Sort(Chest[] chests, int[] indexes, int currentIndex, int[] keys, int[] remainingKeys, int totalKeys)
        {
            if (currentIndex == indexes.Length) return true;
            if (remainingKeys.Any(x => x < 0))
                return false;

            for (int index = 0; index < chests.Length; index++)
            {
                var chest = chests[index];
                if (Array.IndexOf(indexes, index, 0, currentIndex) != -1)
                    continue;  //already opened

                if (keys[chest.KeyType] > 0)
                {
                    var keysBefore = keys[chest.KeyType];

                    keys[chest.KeyType]--;
                    remainingKeys[chest.KeyType]++;
                    foreach (var key in chest.Keys)
                    {
                        keys[key]++;
                        remainingKeys[chest.KeyType]--;
                    }
                    totalKeys += chest.Keys.Length - 1;

                    indexes[currentIndex] = index;
                    if (Sort(chests, indexes, currentIndex + 1, keys, remainingKeys, totalKeys)) return true;
                    if (keysBefore <= keys[chest.KeyType]) return false;

                    keys[chest.KeyType]++;
                    remainingKeys[chest.KeyType]--;
                    foreach (var key in chest.Keys)
                    {
                        keys[key]--;
                        remainingKeys[chest.KeyType]++;
                    }
                    totalKeys -= (chest.Keys.Length - 1);
                }
            }

            return false;
        }
    }
}