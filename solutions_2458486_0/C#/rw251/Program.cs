using System;
using System.Collections;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Collections.Generic;

namespace CodeChefNet
{

    class Program
    {
        private static bool fromFile = true;
        private static TextReader tmpReader;
        private static TextWriter tmpWriter;

        private static Dictionary<int, Dictionary<int, List<int>>> chests;
        private static Dictionary<int, Tuple<int, List<int>>> chestsIdFirst;

        static bool isPossible(List<int> localKeysHolding, Dictionary<int, Dictionary<int, List<int>>> localChests, Dictionary<int, Tuple<int, List<int>>> localChestsIdFirst, out string s)
        {
            var keysholding = localKeysHolding.ToList();
            s = "";
            int skip = 0;
            while(localChestsIdFirst.Keys.Count>0)
            {//do chest
                var chesties = localChests.Where(x => keysholding.Contains(x.Key)).SelectMany(x => x.Value).Select(x => x.Key);
                if (chesties.Count() <= skip) return false;
                var firstPossibleChest =chesties.Skip(skip).Min();
                var y = localChestsIdFirst[firstPossibleChest];

                if (y.Item2.Contains(y.Item1) || keysholding.Count(x => x == y.Item1) > 1
                    || keysholding.Count(x => x == y.Item1) >= localChests[y.Item1].Count)
                {
                    keysholding.Remove(y.Item1);
                    keysholding.AddRange(y.Item2);
                    localChestsIdFirst.Remove(firstPossibleChest);
                    localChests[y.Item1].Remove(firstPossibleChest);
                    s += firstPossibleChest + " ";
                }

                //Contains its own key
                else if (keysholding.Count == 1 && y.Item2.Count == 0)
                {
                    //last key and none in chest so skit
                    skip++;
                    continue;
                }
                //About to lose our last key - can we get it back?
                else
                {
                    //quick check

                    var wouldNeed =
                        localChestsIdFirst.Where(x => x.Value.Item1 != y.Item1 && x.Value.Item2.Contains(y.Item1)).
                            Select(x => x.Value.Item1).ToList();

                    if (wouldNeed.Count() == 0)
                    {
                        skip++;
                        continue;
                    }
                    var tempKeys = keysholding.ToList();
                    tempKeys.Remove(y.Item1);
                    tempKeys.AddRange(y.Item2);
                    var tempC1 = localChests.ToDictionary(x => x.Key, x => x.Value.ToDictionary(yy => yy.Key, yy => yy.Value.ToList()));
                    var tempC2 = localChestsIdFirst.ToDictionary(x => x.Key, x => new Tuple<int, List<int>>(x.Value.Item1, x.Value.Item2.ToList()));
                    tempC2.Remove(firstPossibleChest);
                    tempC1[y.Item1].Remove(firstPossibleChest);
                    string t;
                    if (isPossible(tempKeys, tempC1, tempC2, out t))
                    {
                        //doit
                        keysholding.Remove(y.Item1);
                        keysholding.AddRange(y.Item2);
                        localChestsIdFirst.Remove(firstPossibleChest);
                        localChests[y.Item1].Remove(firstPossibleChest);
                        s += firstPossibleChest + " " + t;
                        return true;
                    }
                    else
                    {
                        skip++;
                        continue;
                    }
                }
                skip = 0;
            }

            return true;
        }
        
        static void Main(string[] args)
        {
            if (fromFile)
            {
                tmpWriter = Console.Out;
                tmpReader = Console.In;
                Console.SetIn(new StreamReader(@"in.txt"));
                Console.SetOut(new StreamWriter(@"out.txt"));
            }

            var T = GetInt();
            for(var i = 0; i < T; i++)
            {
                Console.Write(string.Format(@"Case #{0}: ",i+1));
                var ab = GetInts();
                var K = ab[0];
                var N = ab[1];
                var keysholding = GetInts();
                var totalKeys = keysholding.ToList();
                chests = new Dictionary<int, Dictionary<int, List<int>>>();
                chestsIdFirst = new Dictionary<int, Tuple<int, List<int>>>();
                for(var j=0;j<N;j++)
                {
                    var chest = GetInts();
                    var x = new List<int>();
                    if (chest[1] > 0)
                    {
                        x = chest.Skip(2).ToList();
                    }
                    if(!chests.ContainsKey(chest[0]))
                    {
                        chests.Add(chest[0],new Dictionary<int, List<int>>{ {j+1,x}});
                    }
                    else
                    {
                        chests[chest[0]].Add(j+1,x);
                    }
                    //idfirst
                    chestsIdFirst.Add(j+1,new Tuple<int, List<int>> (chest[0],x));
                    totalKeys.AddRange(x);
                }

                var distinctKeys = totalKeys.Distinct().ToList();

                var chestKeys = chests.ToDictionary(x => x.Key, x => x.Value.Count);

                var isPoss = true;
                foreach (var chestKey in chestKeys)
                {
                    if(!distinctKeys.Contains(chestKey.Key))
                    {
                        isPoss = false;
                        break;
                    }
                    if(totalKeys.Count(x=>x==chestKey.Key)<chestKey.Value)
                    {
                        isPoss = false;
                        break;
                    }
                }
                if(keysholding.Intersect(chestKeys.Keys).Count()==0) isPoss = false;
                string output = "";

                if (!isPoss) Console.WriteLine("IMPOSSIBLE");
                else
                {

                    int skip = 0;
                    while (N > 0)
                    {
                        //do chest
                        var chesties = chests.Where(x => keysholding.Contains(x.Key))
                            .SelectMany(x => x.Value)
                            .Select(x => x.Key).OrderBy(x=>x);
                        if (chesties.Count() <= skip)
                        {
                            isPoss = false;
                            Console.WriteLine("IMPOSSIBLE");
                            break;
                        }
                        var firstPossibleChest = chesties.Skip(skip).Min();

                        var y = chestsIdFirst[firstPossibleChest];

                        //Contains its own key
                        if (y.Item2.Contains(y.Item1))
                        {
                            keysholding.Remove(y.Item1);
                            keysholding.AddRange(y.Item2);
                            chestsIdFirst.Remove(firstPossibleChest);
                            chests[y.Item1].Remove(firstPossibleChest);
                            output += firstPossibleChest + " ";
                        }
                            //Have more than 1 of that key
                        else if (keysholding.Count(x => x == y.Item1) > 1)
                        {
                            keysholding.Remove(y.Item1);
                            keysholding.AddRange(y.Item2);
                            chestsIdFirst.Remove(firstPossibleChest);
                            chests[y.Item1].Remove(firstPossibleChest);
                            output += firstPossibleChest + " ";
                        }
                        else if (keysholding.Count(x => x == y.Item1) >= chests[y.Item1].Count)
                        {
                            keysholding.Remove(y.Item1);
                            keysholding.AddRange(y.Item2);
                            chestsIdFirst.Remove(firstPossibleChest);
                            chests[y.Item1].Remove(firstPossibleChest);
                            output += firstPossibleChest + " ";
                        }
                        else if (keysholding.Count == 1 && y.Item2.Count == 0)
                        {
                            //last key and none in chest so skip
                            skip++;
                            continue;
                        }
                            //About to lose our last key - can we get it back?
                        else
                        {
                            //quick check
                            var wouldNeed =
                                chestsIdFirst.Where(x => x.Value.Item1 != y.Item1 && x.Value.Item2.Contains(y.Item1)).
                                    Select(x => x.Value.Item1).ToList();

                            if(wouldNeed.Count()==0)
                            {
                                skip++;
                                continue;
                            }


                            var tempKeys = keysholding.ToList();
                            tempKeys.Remove(y.Item1);
                            tempKeys.AddRange(y.Item2);
                            var tempC1 = chests.ToDictionary(x => x.Key,
                                                             x =>
                                                             x.Value.ToDictionary(yy => yy.Key, yy => yy.Value.ToList()));
                            var tempC2 = chestsIdFirst.ToDictionary(x => x.Key,
                                                                    x =>
                                                                    new Tuple<int, List<int>>(x.Value.Item1,
                                                                                              x.Value.Item2.ToList()));
                            tempC2.Remove(firstPossibleChest);
                            tempC1[y.Item1].Remove(firstPossibleChest);
                            string t = "";
                            if (isPossible(tempKeys, tempC1, tempC2, out t))
                            {
                                //doit
                                keysholding.Remove(y.Item1);
                                keysholding.AddRange(y.Item2);
                                chestsIdFirst.Remove(firstPossibleChest);
                                chests[y.Item1].Remove(firstPossibleChest);
                                output += firstPossibleChest + " " + t;
                                break;
                            }
                            else
                            {
                                skip++;
                                continue;
                            }
                        }

                        //remove chest
                        N--;
                        skip = 0;
                    }
                }
                if(isPoss) Console.WriteLine(output.Trim());

            }

            if (fromFile)
            {
                Console.Out.Flush();
                Console.Out.Close();
                Console.SetOut(tmpWriter);
                Console.SetIn(tmpReader);

                //Console.WriteLine("TIME: " + DateTime.Now.Subtract(st).TotalMilliseconds);
                //Console.ReadKey();
            }
        }

        #region Getting stuff from console

        static string GetLine()
        {
            var line = Console.ReadLine();
            while (string.IsNullOrEmpty(line))
            {
                line = Console.ReadLine();
            }
            return line;
        }

        static int GetInt()
        {
            return int.Parse(GetLine());
        }

        static List<int> GetInts()
        {
            return GetLine().Split(' ').Select(x => int.Parse(x)).ToList();
        }

        static long GetLong()
        {
            return long.Parse(GetLine());
        }

        static List<long> GetLongs()
        {
            return GetLine().Split(' ').Select(x => long.Parse(x)).ToList();
        }

        static string GetString()
        {
            return GetLine();
        }

        static string[] GetStrings()
        {
            return GetLine().Split(' ').ToArray();
        }

        #endregion
    }
}
