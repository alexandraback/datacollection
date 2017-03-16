using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Treasure
{
    class Program
    {
        static int[] Parse(String[] nums)
        {
            int[] ret = new int[nums.Length];
            for (int i = 0; i < nums.Length; ++i)
            {
                ret[i] = int.Parse(nums[i]);
            }
            return ret;
        }

        struct Chest
        {
            public bool fOpened;
            public List<int> keys;
            public int key;
            public UInt16 equivalenceClass;
            public bool fAutomatic;
            public bool fReachable;
        }

        static void FloodFill(ref Chest[] chests, int key)
        {
            bool fRecurs = false;
            SortedSet<int> pendingRecursions = new SortedSet<int>();
            for (int i = 0; i < chests.Length; ++i)
            {
                if (chests[i].fOpened)
                {
                    chests[i].fReachable = true;
                    continue;
                }
                if (chests[i].fReachable && key == chests[i].key)
                    return;
                if (!chests[i].fReachable && key == chests[i].key)
                {
                    fRecurs = true;
                    chests[i].fReachable = true;
                    for (int j = 0; j < chests[i].keys.Count; ++j)
                    {
                        pendingRecursions.Add(chests[i].keys[j]);
                    }
                }
            }
            if (fRecurs)
            {
                foreach (int a in pendingRecursions)
                {
                    FloodFill(ref chests, a);
                }
            }
        }

        static bool FastImpossibilityCheck(ref Chest[] chests, ref int[] keysInitial)
        {
            // todo: keep this live somehow/updated as I go to make performance better
            // two strategies - flood fill to check that all chests can be reached and count the number of each type of key
            int[] keysTotal = new int[500];
            for (int i = 0; i < 500; ++i)
            {
                keysTotal[i] = 0;
            }
            for (int i = 0; i < keysInitial.Length; ++i)
            {
                keysTotal[i] += keysInitial[i];
            }
            for (int i = 0; i < chests.Length; ++i)
            {
                if (!chests[i].fOpened)
                {
                    chests[i].fReachable = false;
                    keysTotal[chests[i].key]--;
                    for (int j = 0; j < chests[i].keys.Count; ++j)
                    {
                        keysTotal[chests[i].keys[j]]++;
                    }
                }
            }
            for (int i = 0; i < 500; ++i)
            {
                if (keysTotal[i] < 0)
                    return false;
            }

            // now floodfill
            for (int i = 0; i < keysInitial.Length; ++i)
            {
                if (keysInitial[i] > 0)
                {
                    FloodFill(ref chests, i);
                }
            }

            // check if everything is reachable
            for (int i = 0; i < chests.Length; ++i)
            {
                if (!chests[i].fReachable)
                {
                    return false;
                }
            }
            return true;
        }

        static bool Solve(ref Chest[] chests, ref int[] keys, ref List<int> answer, ref SortedSet<BigInteger> cachedFailues, BigInteger currentState, ref EquivalenceClass[] CountPerEqClass)
        {
            if (answer.Count == chests.Length) return true;
            if (cachedFailues.Contains(currentState)) return false;
            if (!FastImpossibilityCheck(ref chests, ref keys)) return false;
            // consider faster solve that just checks whether solving is even feasible

            for (int i = 0; i < chests.Length; ++i)
            {
                if (!chests[i].fOpened && keys[chests[i].key] > 0)
                {
                    if (chests[i].fAutomatic)
                    {
                        // if we can't succeed with this one, then we can't succeed without it
                        answer.Add(i);
                        chests[i].fOpened = true;
                        currentState = AddFromEqClass(currentState, chests[i].equivalenceClass, ref CountPerEqClass);
                        // no changes to keys
                        if (!Solve(ref chests, ref keys, ref answer, ref cachedFailues, currentState, ref CountPerEqClass))
                        {
                            currentState = RemoveFromEqClass(currentState, chests[i].equivalenceClass, ref CountPerEqClass);
                            chests[i].fOpened = false;
                            answer.RemoveAt(answer.Count - 1);
                            return false;
                        }
                        else
                        {
                            return true;
                        }
                    }
                    else
                    {
                        // open this chest, recurse in, close this chest if we didn't find the answer
                        answer.Add(i);
                        chests[i].fOpened = true;
                        keys[chests[i].key]--;
                        for (int j = 0; j < chests[i].keys.Count; ++j)
                        {
                            keys[chests[i].keys[j]]++;
                        }
                        //currentState |= (2u << chests[i].equivalenceClass);
                        currentState = AddFromEqClass(currentState, chests[i].equivalenceClass, ref CountPerEqClass);
                        if (!Solve(ref chests, ref keys, ref answer, ref cachedFailues, currentState, ref CountPerEqClass))
                        {
                            cachedFailues.Add(currentState);
                            // currentState ^= (2u << chests[i].equivalenceClass);
                            currentState = RemoveFromEqClass(currentState, chests[i].equivalenceClass, ref CountPerEqClass);
                            answer.RemoveAt(answer.Count - 1);
                            chests[i].fOpened = false;
                            for (int j = 0; j < chests[i].keys.Count; ++j)
                            {
                                keys[chests[i].keys[j]]--;
                            }
                            keys[chests[i].key]++;
                        }
                        else
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        struct EquivalenceClass
        {
            public UInt16 offset; // how many bits to shift to get to this class?
            public UInt16 bitCount; // how many bits does this class take? (enough to represent count)
            public UInt16 count; // how many in this equivalence class?
        }

        static BigInteger AddFromEqClass(BigInteger currentState, UInt16 eqClass, ref EquivalenceClass[] CountPerEqClass)
        {
            UInt32 mask = (1u<<(CountPerEqClass[eqClass].bitCount)) - 1;
            mask = mask << CountPerEqClass[eqClass].offset;
            BigInteger count = (currentState & mask) >> CountPerEqClass[eqClass].offset;
            count++;
            currentState = (currentState & ~mask) | (count << CountPerEqClass[eqClass].offset);
            return currentState;
        }

        static BigInteger RemoveFromEqClass(BigInteger currentState, UInt16 eqClass, ref EquivalenceClass[] CountPerEqClass)
        {
            BigInteger mask = (1u << (CountPerEqClass[eqClass].bitCount)) - 1;
            mask = mask << CountPerEqClass[eqClass].offset;
            BigInteger count = (currentState & mask) >> CountPerEqClass[eqClass].offset;
            count--;
            currentState = (currentState & ~mask) | (count << CountPerEqClass[eqClass].offset);
            return currentState;
        }

        static UInt16 bitsNeeded(UInt16 num)
        {
            // how many bits needed for num?
            for (UInt16 i = 0; i < 15; ++i)
            {
                if (num < 2 << i)
                {
                    return (UInt16)(1+i);
                }
            }
            return 0;
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                String[] nums = Console.ReadLine().Split(' ');
                int K = int.Parse(nums[0]);
                int N = int.Parse(nums[1]);
                int[] keysInit = Parse(Console.ReadLine().Split(' '));
                Chest[] chests = new Chest[N];
                UInt16 nexteq = 1; // also a count of how many equivalence classes there are
                // equivalence class 0 is reserved for automatic items
                EquivalenceClass[] CountPerEqClass = new EquivalenceClass[400];
                for (int j = 0; j < 400; ++j)
                {
                    CountPerEqClass[j].count = 0;
                }
                for (int j = 0; j < N; ++j)
                {
                    int[] temp = Parse(Console.ReadLine().Split(' '));
                    chests[j].key = temp[0];
                    chests[j].keys = new List<int>(temp.Skip(2));
                    chests[j].keys.Sort();
                    chests[j].fOpened = false;
                    chests[j].fAutomatic = (chests[j].keys.Count == 1 && chests[j].keys[0] == chests[j].key);
                    chests[j].equivalenceClass = 0;
                    if (!chests[j].fAutomatic)
                    {
                        bool fFoundEq = false;
                        for (int k = 0; k < j; ++k)
                        {
                            if (chests[j].key == chests[k].key && chests[j].keys.Count == chests[k].keys.Count)
                            {
                                fFoundEq = true;
                                for (int l = 0; l < chests[j].keys.Count; ++l)
                                {
                                    if (chests[j].keys[l] != chests[k].keys[l])
                                    {
                                        fFoundEq = false;
                                        break;
                                    }
                                }
                                if (fFoundEq)
                                {
                                    chests[j].equivalenceClass = chests[k].equivalenceClass;
                                    break;
                                }
                            }
                        }
                        if (!fFoundEq)
                        {
                            chests[j].equivalenceClass = nexteq;
                            nexteq++;
                        }
                    }
                    CountPerEqClass[chests[j].equivalenceClass].count++;
                }

                // now optimize the equivalence classes
                UInt16 offset = 0;
                for (int j = 0; j < 400; ++j)
                {
                    CountPerEqClass[j].bitCount = bitsNeeded(CountPerEqClass[j].count);
                    CountPerEqClass[j].offset = offset;
                    offset += CountPerEqClass[j].bitCount;
                }
                
                // now try to solve the problem
                List<int> keys = new List<int>(keysInit);
                int[] keysBucket = new int[500];
                for (int j = 0; j < 500; ++j)
                {
                    keysBucket[j] = 0;
                }
                foreach (int key in keys)
                {
                    keysBucket[key]++;
                }
                List<int> answer = new List<int>();
                
                //List<UInt32> cacheFailures = new List<UInt32>();
                SortedSet<BigInteger> cacheFailures = new SortedSet<BigInteger>();
                if (Solve(ref chests, ref keysBucket, ref answer, ref cacheFailures, BigInteger.Zero, ref CountPerEqClass))
                {
                    Console.Write("Case #{0}: ", 1 + i);
                    foreach (int n in answer)
                    {
                        Console.Write("{0} ", 1+n);
                    }
                    Console.WriteLine();
                }
                else
                {
                    Console.WriteLine("Case #{0}: IMPOSSIBLE", 1 + i);
                }
            }
        }
    }
}
