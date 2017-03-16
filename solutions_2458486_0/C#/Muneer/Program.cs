using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace Treasure
{
    class Program
    {
        struct Chest
        {
            public int id;
            public int keyToOpen;
            public List<int> keysInside;

            public bool HasMoreKeysThan(Chest c)
            {
                if (keysInside.Count > c.keysInside.Count) return true;
                else if (keysInside.Count < c.keysInside.Count) return false;
                else if (id < c.id) return true;
                else return false;
            }
        }

        static Chest[] chests;

        static void Main(string[] args)
        {

            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            StreamReader sr = new StreamReader("D:\\D-small-attempt3.in");
            StreamWriter sw = new StreamWriter("D:\\D-small-attempt3.out");

            //StreamReader sr = new StreamReader("D:\\B-large.in");
            //StreamWriter sw = new StreamWriter("D:\\B-large.out");

            int numTestCases = Convert.ToInt32(sr.ReadLine());


            for (int i = 0; i < numTestCases; i++)
            {
                Console.WriteLine(i);

                string[] str = sr.ReadLine().Split(' ');

                int numKeys = Convert.ToInt32(str[0]);
                int numChests = Convert.ToInt32(str[1]);

                Dictionary<int, int> dictKeysAtEnd = new Dictionary<int, int>();

                List<int> initialKeys = new List<int>();

                str = sr.ReadLine().Split(' ');
                for (int j = 0; j < numKeys; j++)
                {
                    int key = Convert.ToInt32(str[j]);
                    initialKeys.Add(key);

                    if (dictKeysAtEnd.ContainsKey(key) == false)
                    {
                        dictKeysAtEnd[key] = 0;
                    }
                    dictKeysAtEnd[key]++;
                }

                chests = new Chest[numChests];

                for (int j = 0; j < numChests; j++)
                {
                    str=sr.ReadLine().Split(' ');

                    chests[j].keyToOpen = Convert.ToInt32(str[0]);

                    if (dictKeysAtEnd.ContainsKey(chests[j].keyToOpen) == false)
                    {
                        dictKeysAtEnd[chests[j].keyToOpen] = 0;
                    }
                    dictKeysAtEnd[chests[j].keyToOpen]--;


                    int numKeysInChest = Convert.ToInt32(str[1]);

                    chests[j].id = j;
                    chests[j].keysInside = new List<int>();

                    for (int k = 0; k < numKeysInChest; k++)
                    {
                        int key = Convert.ToInt32(str[2 + k]);
                        chests[j].keysInside.Add(key);

                        if (dictKeysAtEnd.ContainsKey(key) == false)
                        {
                            dictKeysAtEnd[key] = 0;
                        }
                        dictKeysAtEnd[key]++;
                    }

                }


                List<int> selectedSequence = new List<int>();
                bool found = true;

                for (int sequenceSize = 1; sequenceSize <= numChests; sequenceSize++)
                {
                        
                    for (int j = chests.Length - 1; j >= 0; j--)
                    {
                        
                        if (selectedSequence.Contains(j) == true)
                        {
                            continue;
                        }

                        for (int k = 0; k <= selectedSequence.Count; k++)
                        {

                            List<int> tempSequence = new List<int>(selectedSequence);

                            tempSequence.Insert(k, j);

                            if (IsValidSequenceFromEnd(tempSequence.ToArray(), dictKeysAtEnd) == true)
                            {
                                selectedSequence = tempSequence;
                                break;
                            }
                        }

                        if (selectedSequence.Count == sequenceSize)
                        {
                            break;
                        }
                    }

                    if (selectedSequence.Count != sequenceSize)
                    {
                        found = false;
                        break;
                    }
                }

                sw.Write("Case #{0}: ", i + 1);
                if (found == true)
                {
                    for (int j = 0; j < selectedSequence.Count; j++)
                    {
                        sw.Write(selectedSequence[j] + 1);
                        sw.Write(" ");
                    }
                }
                else
                {
                    sw.Write("IMPOSSIBLE");
                }
                sw.WriteLine();

            }
            sw.Close();
        }

        static bool IsValidSequenceFromEnd(int[] testSequence, Dictionary<int, int> dictKeysAtEnd)
        {
            Dictionary<int, int> dictCopy = new Dictionary<int, int>();
            foreach (KeyValuePair<int, int> kv in dictKeysAtEnd)
            {
                dictCopy[kv.Key] = kv.Value;
            }


            for (int j = testSequence.Length - 1; j >= 0; j--)
            {
                Chest testChest = chests[testSequence[j]];

                for (int k = 0; k < testChest.keysInside.Count; k++)
                {
                    int keyType = testChest.keysInside[k];

                    if (dictCopy.ContainsKey(keyType) == true && dictCopy[keyType] > 0)
                    {
                        dictCopy[keyType]--;
                    }
                    else
                    {
                        return false;
                    }
                }

                if (dictCopy.ContainsKey(testChest.keyToOpen) == false)
                {
                    dictCopy[testChest.keyToOpen] = 0;
                }
                dictCopy[testChest.keyToOpen]++;
            }

            return true;
        }
    }
}
