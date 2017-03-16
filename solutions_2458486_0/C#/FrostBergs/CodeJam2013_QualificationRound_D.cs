using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using System.Linq;
using System.Windows.Forms;
using CodeJam.ExtentionMethods;

namespace CodeJam.Problems
{
    public class CodeJam2013_QualificationRound_D : BaseProblem
    {
        protected override object SolveCase(StreamReader reader)
        {
            int[] inputs = reader.ReadLine().ConvertInputToIntArray();
            
            int K = inputs[0];
            int N = inputs[1];

            Dictionary<int, int> keys = new Dictionary<int, int>();
            List<Chest> chests = new List<Chest>();

            Dictionary<int, int> totalRequiredKeys = new Dictionary<int, int>();
            Dictionary<int, int> totalAvailableKeys = new Dictionary<int, int>();

            inputs = reader.ReadLine().ConvertInputToIntArray();
            for (int k = 0; k < K; k++)
            {
                IncrementKeyDictionary(keys, inputs[k]);
                IncrementKeyDictionary(totalAvailableKeys, inputs[k]);
            }

            for (int n = 0; n < N; n++)
            {
                inputs = reader.ReadLine().ConvertInputToIntArray();
                List<int> chestKeys = new List<int>(inputs.Skip(2));
                chests.Add(new Chest(n + 1, inputs[0], chestKeys));

                IncrementKeyDictionary(totalRequiredKeys, inputs[0]);
                foreach (int key in chestKeys)
                    IncrementKeyDictionary(totalAvailableKeys, key);
            }

            foreach (KeyValuePair<int, int> item in totalRequiredKeys)
                if (!totalAvailableKeys.ContainsKey(item.Key) || totalAvailableKeys[item.Key] < totalRequiredKeys[item.Key])
                    return "IMPOSSIBLE";
            
            List<int> currentPath = new List<int>();

            if (FindPath(keys, chests, currentPath, false))
                return String.Join(" ", currentPath.ConvertAll<string>(x => x.ToString()).ToArray());
            else if (FindPath(keys, chests, currentPath, true))
                return String.Join(" ", currentPath.ConvertAll<string>(x => x.ToString()).ToArray());
            else
                return "IMPOSSIBLE";
        }

        private DateTime _startTime = DateTime.Now;

        private void IncrementKeyDictionary(Dictionary<int, int> dict, int key)
        {
            if (!dict.ContainsKey(key))
                dict.Add(key, 1);
            else
                dict[key]++;
        }

        private void DecrementKeyDictionary(Dictionary<int, int> dict, int key)
        {
            if (dict.ContainsKey(key))
            {
                if (dict[key] == 1)
                    dict.Remove(key);
                else
                    dict[key]--;
            }
            else
                throw new ArgumentException();
        }

        private class Chest
        {
            public int Index { get; private set; }
            public int RequiredKey { get; private set; }
            public List<int> Keys { get; private set; }

            public bool ReplacesUsedKey { get { return this.Keys.Contains(this.RequiredKey); } }

            public Chest(int index, int requiredKey, List<int> keys)
            {
                this.Index = index;
                this.RequiredKey = requiredKey;
                this.Keys = keys;
            }
        }

        private bool FindPath(Dictionary<int, int> keys, List<Chest> chests, List<int> currentPath, bool usePriority)
        {
            if (chests.Count == 0)
                return true;
            else if (keys.Count == 0)
                return false;

            if (!usePriority && (DateTime.Now - _startTime).TotalSeconds >= 1.0)
                return false;

            if (usePriority)
            {
                Chest rChest;
                while ((rChest = chests.Find(
                                                x => keys.ContainsKey(x.RequiredKey) &&
                                                (x.Keys.Contains(x.RequiredKey) || keys[x.RequiredKey] > 1 || chests.Count(y => y.RequiredKey == x.RequiredKey) == 1)
                                            )) != null)
                {
                    currentPath.Add(rChest.Index);
                    chests.Remove(rChest);
                    DecrementKeyDictionary(keys, rChest.RequiredKey);
                    foreach (int key in rChest.Keys)
                        IncrementKeyDictionary(keys, key);
                }
            }

            if (chests.Count == 0)
                return true;

            List<Chest> availableChests = chests.FindAll(x => keys.ContainsKey(x.RequiredKey));

            foreach (Chest availableChest in availableChests)
            {
                //if (FuckedIfOpen(availableChest, chests, keys))
                //    continue;

                List<int> newCurrentPath = new List<int>(currentPath);
                newCurrentPath.Add(availableChest.Index);
                
                List<Chest> newChestList = new List<Chest>(chests);
                newChestList.Remove(availableChest);

                Dictionary<int, int> newKeys = keys.ToDictionary(x => x.Key, x => x.Value);
                DecrementKeyDictionary(newKeys, availableChest.RequiredKey);
                foreach (int key in availableChest.Keys)
                    IncrementKeyDictionary(newKeys, key);

                if (FindPath(newKeys, newChestList, newCurrentPath, usePriority))
                {
                    currentPath.Clear();
                    currentPath.AddRange(newCurrentPath);
                    return true;
                }

                if (!usePriority && (DateTime.Now - _startTime).TotalSeconds >= 1.0)
                    return false;
            }

            return false;
        }
    }
}