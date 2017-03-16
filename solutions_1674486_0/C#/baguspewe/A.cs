using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamPlayground
{
    class Tools
    {
        static public int[] getArrayIntFromLine(StreamReader sr)
        {
            string[] s = sr.ReadLine().Split();
            int[] i = new int[s.Length];

            for (int a = 0; a < s.Length; a++)
                i[a] = int.Parse(s[a]);

            return i;
        }

        static public List<int> getListIntFromString(string str)
        {
            string[] s = str.Split();
            List<int> i = new List<int>();

            if (str == "") return i;

            for (int a = 0; a < s.Length; a++)
                i.Add(int.Parse(s[a]));

            return i;
        }
    }

    class Node
    {
        public List<int> parentList;

        public Node()
        {
            parentList = new List<int>();
        }
    }

    class dataStructure
    {
        public List<Node> nodes;

        public dataStructure()
        {
            nodes = new List<Node>();
        }
    }

    class Solution
    {
        dataStructure ds;

        private bool checkDiamond(List<int> list)
        {
            list.Sort();
            for (int i = 0; i < list.Count - 1; i++)
            {
                if (list[i] == list[i + 1]) 
                    return true;
            }

            return false;
        }

        private string traceParent(int parent_id)
        {
            string ret = "";

            if (ds.nodes[parent_id].parentList.Count == 0)
                return (parent_id.ToString());

            for (int i = 0; i < ds.nodes[parent_id].parentList.Count; i++)
            {
                if (i != 0)
                    ret = ret + " ";
                ret = ret + traceParent(ds.nodes[parent_id].parentList[i]-1);
            }

            ret = ret + " " + parent_id.ToString();

            return ret;
        }

        public string solve(StreamReader sr)
        {
            int N = int.Parse(sr.ReadLine());
            ds = new dataStructure();

            for (int i = 0; i < N; i++)
            {
                Node cNode = new Node();
                int[] nodeList = Tools.getArrayIntFromLine(sr);

                int num_of_parents = nodeList[0];
                for (int j = 1; j <= num_of_parents; j++)
                {
                    cNode.parentList.Add(nodeList[j]);
                }
                ds.nodes.Add(cNode);
            }

            // in case no class with 2 parents, return NO
            bool multiParent = false;
            for (int i = 0; i < ds.nodes.Count; i++)
            {
                if (ds.nodes[i].parentList.Count >= 2)
                    multiParent = true;
            }
            if (!multiParent)
                return "No";

            // well, there are possibilities of diamond
            // do search for each class with multi parent

            for (int i = 0; i < ds.nodes.Count; i++)
            {
                string ret = "";
                if (ds.nodes[i].parentList.Count >= 2)
                {
                    //ret = traceParent(i);
                    for (int j = 0; j < ds.nodes[i].parentList.Count; j++)
                    {
                        if (j != 0)
                            ret = ret + " ";
                        ret = ret + traceParent(ds.nodes[i].parentList[j] - 1);
                    }
                }

                List<int> list = Tools.getListIntFromString(ret);
                if (checkDiamond(list)) return "Yes";
                
            }

            return "No";
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string input_id = "A-small-attempt1";
            StreamReader sr = new StreamReader(input_id + ".in");
            StreamWriter sw = new StreamWriter(input_id + ".out");

            int total_test_case = Int32.Parse(sr.ReadLine());
            Console.WriteLine("Total test case: " + total_test_case);

            Solution s = new Solution();

            for (int i = 1; i <= total_test_case; i++)
            {
                Console.WriteLine("==== Test case: " + i + " ====");
                string result = s.solve(sr);
                sw.WriteLine("Case #" + i + ": " + result);
                Console.WriteLine("Case #" + i + ": " + result);
            }

            sr.Close();
            sw.Close();

            Console.WriteLine("Press any key to continue...");
            Console.ReadKey();
        }
    }
}
