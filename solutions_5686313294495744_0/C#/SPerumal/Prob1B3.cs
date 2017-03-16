using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Prob1B3
    {
        int i;
        internal void Run()
        {
            var lines = File.ReadAllLines("C-small-attempt1.in");

            var n = int.Parse(lines[0]);

            i = 1;
            using (var sw = File.CreateText("C.out"))
            {
                int index = 1;
                while (index < lines.Length)
                {
                    var count = int.Parse(lines[index++]);
                    var dictL = new Dictionary<string, Node>();
                    var dictR = new Dictionary<string, Node>();

                    for (int j = 0; j < count; j++, index++)
                    {
                        var line = lines[index];
                        var words = line.Split(' ');
                        if (!dictL.ContainsKey(words[0]))
                            dictL[words[0]] = new Node { Key = words[0] };

                        dictL[words[0]].Links.Add(words[1]);

                        if (!dictR.ContainsKey(words[1]))
                            dictR[words[1]] = new Node { Key = words[1] };

                        dictR[words[1]].Links.Add(words[0]);
                    }

                    duplicateCount = 0;
                    Process(dictL, dictR);

                    sw.WriteLine("Case #{0}: {1}", i++, duplicateCount);
                }
            }
        }

        int duplicateCount = 0;
        private void Process(Dictionary<string, Node> dictL, Dictionary<string, Node> dictR)
        {
            foreach (var lnode in dictL.Values.OrderByDescending(n => n.Links.Count))
            {
                while (true)
                {
                    var links = lnode.Links.Select(rn => dictR[rn]).OrderByDescending(n => n.Links.Count).ToList();
                    Node duplicate = null;
                    foreach (var link in links)
                        foreach (var lnode2 in link.Links.Select(l => dictL[l]).OrderByDescending(n => n.Links.Count))
                            foreach (var rnode in lnode2.Links.Select(l => dictR[l]).OrderByDescending(n => n.Links.Count))
                            if (lnode2.Key != lnode.Key && link.Key != rnode.Key)
                            {
                                duplicate = link;
                                break;
                            }

                    if (duplicate != null)
                    {
                        lnode.Links.Remove(duplicate.Key);
                        duplicate.Links.Remove(lnode.Key);
                        duplicateCount++;
                    }
                    else break;
                }
            }
        }

        class Node
        {
            public string Key;
            public List<string> Links = new List<string>();
        }
    }
}
