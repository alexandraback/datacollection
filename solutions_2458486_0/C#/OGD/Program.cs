using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading;

namespace goo2013 {
    class Program {
        static void Main(string[] args) {
            string path = @"C:\goo\D-small-attempt1.in";
            var reader = new StreamReader(path);
            var writer = new StreamWriter(@"C:\goo\out.txt");
            int N = int.Parse(reader.ReadLine());
            string s;
            int j = 0;
            int read = 0;
            var keys = new SortedDictionary<int, int>();
            var rooms = new SortedDictionary<int, Tuple<int, List<int>>>();
            int roomsn = 0;
            int roomcounter = 0;
            while ((s = reader.ReadLine()) != null) {
                if (read == 0) {
                    var split = s.Split(' ');
                    roomsn = int.Parse(split[1]);
                    roomcounter = 0;
                    rooms = new SortedDictionary<int, Tuple<int, List<int>>>();
                    read++;
                    continue;
                }
                if (read == 1) {
                    keys = new SortedDictionary<int, int>();
                    var keysstrings = s.Split(' ');
                    foreach (string keysstring in keysstrings) {
                        int kkk = int.Parse(keysstring);
                        if (!keys.ContainsKey(kkk)) {
                            keys[kkk] = 0;
                        }
                        keys[kkk] = keys[kkk] + 1;
                    }
                    read++;
                    continue;
                }
                if (read == 2) {
                    var split = s.Split(' ');
                    int key = int.Parse(split[0]);
                    int r = int.Parse(split[1]);
                    roomcounter++;
                    rooms[roomcounter] = new Tuple<int, List<int>>(key, new List<int>());
                    for (int i = 0; i < r; i++) {
                        rooms[roomcounter].Item2.Add(int.Parse(split[i + 2]));
                    }
                    roomsn--;
                    if (roomsn == 0) {
                        read = 0;
                        j++;
                        var stack = new Stack<int>();
                        var visiting = new HashSet<int>();
                        int v = 0;
                        bool q = Solve(keys, rooms, stack, visiting, ref v);
                        string outs = "IMPOSSIBLE";
                        if (q) {
                            outs = "";
                            var stack2 = new Stack<int>();
                            while (stack.Count != 0) {
                                stack2.Push(stack.Pop());
                            }
                            while (stack2.Count != 0) {
                                outs += stack2.Pop();
                                outs += " ";
                            }
                            outs.Remove(outs.Length - 2);
                        }
                        Console.WriteLine("Case #" + j + ": " + outs);
                        writer.WriteLine("Case #" + j + ": " + outs);
                    }
                }
            }
            writer.Close();
        }

        private static bool Solve(SortedDictionary<int, int> keys, SortedDictionary<int, Tuple<int, List<int>>> rooms, Stack<int> stack, HashSet<int> visiting, ref int v) {
            if (v > 1000000) {
                return false;
            }
            v++;
            if (keys.Count == 0) {
                return false;
            }
            //Console.WriteLine(stack.Count + " " + visiting.Count + " " + keys.Count);
            //Thread.Sleep(100);
            foreach (KeyValuePair<int, Tuple<int, List<int>>> keyValuePair in rooms) {
                int roomnumber = keyValuePair.Key;
                if (visiting.Contains(roomnumber)) {
                    continue;
                }
                var sroom = keyValuePair.Value;
                int kkey = sroom.Item1;
                List<int> room = sroom.Item2;
                if (keys.ContainsKey(kkey)) {
                    stack.Push(roomnumber);
                    visiting.Add(roomnumber);
                    if (stack.Count == rooms.Count) {
                        return true;
                    }
                    var newkeys = new SortedDictionary<int, int>(keys);
                    newkeys[kkey] = newkeys[kkey] - 1;
                    if (newkeys[kkey] == 0) {
                        newkeys.Remove(kkey);
                    }
                    foreach (int i in room) {
                        if (!newkeys.ContainsKey(i)) {
                            newkeys[i] = 0;
                        }
                        newkeys[i] = newkeys[i] + 1;
                    }
                    bool b = Solve(newkeys, rooms, stack, visiting, ref v);
                    if (b) {
                        return true;
                    }
                    stack.Pop();
                    visiting.Remove(roomnumber);
                }
            }
            return false;
        }
    }
}
