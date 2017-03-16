using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1C
{
    class Program
    {
        static int ReadInt(System.IO.StreamReader reader)
        {
            return int.Parse(reader.ReadLine());
        }

        static List<int> ReadIntList(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => int.Parse(x)).ToList();
        }

        static int[] ReadIntArray(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => int.Parse(x)).ToArray();
        }

        static int[] ReadCharArray(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            int[] dataInt = new int[data.Length];
            for (int i = 0; i < data.Length; i++)
                dataInt[i] = data[i] == '.' ? -1 : 1;

            return dataInt;
        }

        static int[] ReadIntData(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => int.Parse(x)).ToArray();
        }

        static Int64[] ReadInt64Array(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => Int64.Parse(x)).ToArray();
        }

        static List<string> ReadStringList(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').ToList();
        }

        public class Node
        {
            //public int index;
            public List<int> parent;
        }

        static List<int> parents;
        static Dictionary<int, bool> results;
        static void Main(string[] args)
        {
            System.IO.StreamReader reader = System.IO.File.OpenText("input.in");
            System.IO.StreamWriter writer = System.IO.File.CreateText("output.out");

            int T = ReadInt(reader);
            for (int i = 1; i <= T; i++)
            {
                results = new Dictionary<int, bool>();
                string result = "";
                List<Node> nodes = new List<Node>();
                List<int> multiNodes = new List<int>();
                
                int N = ReadInt(reader);
                for (int j = 0; j < N; j++)
                {
                    Node node = new Node();
                    //node.index = j + 1;
                    
                    List<int> data = ReadIntList(reader);
                    if (data[0] == 0)
                        node.parent = null;
                    else
                    {
                        data.RemoveAt(0);
                        if (data.Count > 1)
                            multiNodes.Add(j + 1);
                        node.parent = data;
                    }

                    nodes.Add(node);
                }


                if (multiNodes.Count > 0)
                {
                    bool found = false;
                    for (int n = 0; n < multiNodes.Count; n++)
                    {
                        parents = new List<int>();
                        for (int p = 0; p < nodes[multiNodes[n] - 1].parent.Count; p++)
                        {
                            if (parents.Contains(nodes[multiNodes[n] - 1].parent[p]))
                            {
                                found = true;
                                break;
                            }
                            parents.Add(nodes[multiNodes[n] - 1].parent[p]);
                            if (HasSameParents(nodes[multiNodes[n] - 1].parent[p], nodes))
                            {
                                found = true;
                                break;
                            }
                        }
                    }
                    if (found)
                        result = "Yes";
                    else
                        result = "No";
                }
                else
                    result = "No";

                Console.WriteLine("Case #" + i + ": " + result);
                writer.WriteLine("Case #" + i + ": " + result);
            }

            reader.Dispose();
            writer.Dispose();
        }

        static bool HasSameParents(int index, List<Node> nodes)
        {
            if (results.ContainsKey(index))
                return results[index];

            if (nodes[index - 1].parent == null)
            {
                results[index] = false;
                return false;
            }

            for (int i = 0; i < nodes[index - 1].parent.Count; i++)
            {
                if (parents.Contains(nodes[index - 1].parent[i]))
                {
                    results[index] = true;
                    return true;
                }
                parents.Add(nodes[index - 1].parent[i]);
                if (HasSameParents(nodes[index - 1].parent[i], nodes))
                {
                    results[index] = true;
                    return true;
                }
            }
            results[index] = false;
            return false;
        }
    }
}
