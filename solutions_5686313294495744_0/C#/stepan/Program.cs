using System.Linq;
using System.IO;
using System;
using System.Collections;
using System.Collections.Generic;

namespace P1
{
    class Program
    {
        const string size = "small";

        static void Main()
        {
            using (var streamReader = new StreamReader($"C-{size}.in"))
            using (var streamWriter = new StreamWriter($"output-{size}.txt"))
            {
                int t = int.Parse(streamReader.ReadLine());

                for (int j = 0; j < t; j++)
                {
                    var dictFirst = new Dictionary<string, int>();
                    var dictSecond = new Dictionary<string, int>();

                    var dicts = new Dictionary<string, List<string>>();

                    int n = int.Parse(streamReader.ReadLine());

                    for(int k = 0; k < n; k++)
                    {
                        string[] theLine = streamReader.ReadLine().Split(' ');

                        string first = theLine[0];
                        string second = theLine[1];

                        if (!dicts.ContainsKey(first)) dicts[first] = new List<string>();
                        if (!dicts.ContainsKey(second)) dicts[second] = new List<string>();

                        dicts[first].Add(second);
                        dicts[second].Add(first);

                        if (!dictFirst.ContainsKey(first))
                        {
                            dictFirst.Add(first, 1);
                        }
                        else
                        {
                            dictFirst[first] = dictFirst[first] + 1;
                        }

                        if (!dictSecond.ContainsKey(second))
                        {
                            dictSecond.Add(second, 1);
                        }
                        else
                        {
                            dictSecond[second] = dictSecond[second] + 1;
                        }
                    }
                    
                    foreach (var f in dictFirst)
                    {
                        if(f.Value == 1)
                        {
                            if (dictSecond.ContainsKey(f.Key))
                            {
                                dictSecond[f.Key] = dictSecond[f.Key] - 1;
                            }
                        }
                    }
                    foreach (var f in dictSecond)
                    {
                        if (f.Value == 1)
                        {
                            if (dictFirst.ContainsKey(f.Key))
                            {
                                dictFirst[f.Key] = dictFirst[f.Key] - 1;
                            }
                        }
                    }

                    int maxFirst = Math.Max(0, dictFirst.Max(f => f.Value) - 1);
                    int maxSecond = Math.Max(0, dictSecond.Max(f => f.Value) - 1);

                    int nFakes = Math.Min(maxFirst, maxSecond);

                    streamWriter.WriteLine($"Case #{j + 1}: {nFakes}");
                }
            }
        }
    }
}
