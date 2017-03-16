using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace d_Treasure
{
    class Program
    {
        class Chest
        {
            public int Number;
            public int KeyNeeded;
            public int[] KeysInside;

            public bool ItsFree
            {
                get
                {
                    return KeysInside[KeyNeeded] > 0;
                }
            }

        }

        static int[] MakeKeys(Dictionary<int, int> dictionary)
        {
            var result = new int[201];
            for (var i = 0; i <= 200; i++)
                if (dictionary.ContainsKey(i))
                    result[i] = dictionary[i];
            return result;
        }

        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader("..\\..\\input.txt"))
            using (var outputStream = new StreamWriter("..\\..\\output.txt.", false))
            {
                var totalCases = int.Parse(inputStream.ReadLine());

                for (var currentCase = 1; currentCase <= totalCases; currentCase++)
                {
                    var inputValues = inputStream.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                    var inputKeys = inputValues[0];
                    var inputChests = inputValues[1];

                    var startKeys = MakeKeys(inputStream.ReadLine().Split(' ').Select(s => int.Parse(s)).GroupBy(k => k).ToDictionary(k => k.Key, k => k.Count()));

                    var chests = new List<Chest>();

                    for (var i = 0; i < inputChests; i++)
                    {
                        var chestValues = inputStream.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                        chests.Add(new Chest()
                        {
                            Number = chests.Count + 1,
                            KeyNeeded = chestValues[0],
                            KeysInside = MakeKeys(chestValues.Skip(1).GroupBy(k => k).ToDictionary(k => k.Key, k => k.Count())),
                        });
                    }

                    var currentOrder = new List<int>();
                    //var openedChests = new HashSet<int>();

                    if (OpenNextChest(chests, startKeys, currentOrder))
                    {
                        outputStream.WriteLine("Case #{0}: {1}", currentCase, string.Join(" ", currentOrder.ToArray()));
                    }
                    else
                    {
                        outputStream.WriteLine("Case #{0}: IMPOSSIBLE", currentCase);
                    }
                }
            }
        }

        static bool OpenNextChest(List<Chest> chests, int[] keys, List<int> order)
        {
            if (chests.Count == 0)
                return true;

            for (var i = 0; i < chests.Count; i++)
            {
                var chest = chests[i];
                if (keys[chest.KeyNeeded] > 0)
                {
                    order.Add(chest.Number);
                    chests.RemoveAt(i);
                    keys[chest.KeyNeeded] -= 1;
                    for (var j = 0; j < chest.KeysInside.Length; j++)
                        keys[j] += chest.KeysInside[j];

                    if (!OpenNextChest(chests, keys, order))
                    {
                        chests.Insert(i, chest);
                        order.RemoveAt(order.Count - 1);
                        keys[chest.KeyNeeded] += 1;
                        for (var j = 0; j < chest.KeysInside.Length; j++)
                            keys[j] -= chest.KeysInside[j];

                        if (chest.ItsFree)
                            return false;
                    }
                    else
                        return true;
                }
            }

            return false;
        }
    }
}
