using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Studio.Algorithm.GoogleCodeJamTemplate
{
    public class Program
    {

        public static string FILE_PERFIX = "A-";
        // public static string FILE_PERFIX = "B-";
        public static bool IS_FILE_OUT = true;
        public static bool IS_FILE_IN = true;
        public static bool IS_SMALL = false;

        public static char[] SPLITERS = new char[] { ' ', '\t' };


        public static void Main(string[] args)
        {
            GoogleCodeJam();
            Console.ReadKey();
        }

        /// <summary>
        /// Algorithm should be writen here for each test case
        /// </summary>
        public static void TestCase(int Index, TextReader reader)
        {
            string CaseNo = string.Format("Case #{0}: ", Index);
            string Result = CaseNo;

            IList<Node> g = new List<Node>();

            int N = int.Parse(reader.ReadLine());
            for (int i = 0; i < N; i++)
            {
                Node n = new Node();
                n.children = new List<Node>();
                n.parents = new List<Node>();
                n.id = i + 1;
                g.Add(n);
            }
            for (int i = 0; i < N; i++)
            {
                string[] splits = reader.ReadLine().Split(SPLITERS);
                int M = int.Parse(splits[0]);
                Node node = (from n in g where n.id == i + 1 select n).First();
                for (int x = 0; x < M; x++)
                {
                    int id = int.Parse(splits[x + 1]);
                    Node parent = (from n in g where n.id == id select n).First();
                    parent.children.Add(node);
                    node.parents.Add(parent);
                }
            }

            IList<Node> del = new List<Node>();
            do
            {
                del = g.Where(n => n.children.Count + n.parents.Count <= 1).ToList();

                foreach (var node in del)
                {
                    var x = (from n in g where n.id == node.id select n).First();
                    g.Remove(x);
                    bool b = false;
                    foreach (var n in node.parents)
                    {
                        x = (from m in g where m.id == n.id select m).First();
                        x.children.Remove(node);
                        b = true;
                    }
                    foreach (var n in node.children)
                    {
                        if (b == true)
                            throw new Exception();
                        x = (from m in g where m.id == n.id select m).First();
                        x.parents.Remove(node);
                    }
                }

            } while (del.Count > 0);

            bool found = false;
            while(g.Count > 0)
            {
                var node = g.Where(n => n.children.Count == 0).First();
                bool more = false;
                IList<Node> all = new List<Node>();
                IList<Node> parents = node.parents;
                foreach (var parent in parents)
                    all.Add(parent);
                do
                {
                    parents = parents.SelectMany(n => n.parents).ToList();
                    foreach (var parent in parents)
                    {
                        if(all.Contains(parent))
                        {
                            found = true;
                            break;
                        }
                        else
                        {
                            all.Add(parent);
                        }
                    }
                    if(found)
                        break;
                } while (parents.Count > 0);
                
                if(found)
                    break;

                g.Remove(node);
                foreach (var n in node.parents)
                    n.children.Remove(node);
                foreach (var n in node.children)
                    n.parents.Remove(node);
            }


            O(Result + (g.Any() ? "Yes" : "No"));
        }

       

        public static void GoogleCodeJam()
        {
            FileStream fs = null;
            TextReader sr = null;
            if (true == Program.IS_FILE_IN)
            {
                // open file
                string fn = FILE_PERFIX + "large.in";
                if (IS_SMALL) fn = FILE_PERFIX + "small.in";
                fs = File.Open(fn, FileMode.Open);
                sr = new StreamReader(fs);
            }
            else
            {
                sr = Console.In;
            }
            // read test case count
            string line = sr.ReadLine();
            int n = int.Parse(line);
            // for each test case
            for (int cs = 1; cs <= n; cs++)
            {
                TestCase(cs, sr);
            }
            if (true == IS_FILE_IN)
            {
                // close file
                if (null != sr) sr.Close();
                if (null != fs) fs.Close();
            }
        }

        /// <summary>
        /// Short for OutputLine
        /// </summary>
        /// <param name="s"></param>
        public static void O(string format, params object[] args)
        {
            Program.OutputLine(string.Format(format, args));
        }

        public static void O(string s)
        {
            Program.OutputLine(s);
        }

        static bool IS_FIRST_RUN = true;

        public static void OutputLine(string s)
        {
            System.Console.WriteLine(s);
            // write to file ?
            if (true == IS_FILE_OUT)
            {
                string fn = FILE_PERFIX + "large.out";
                if (IS_SMALL) fn = FILE_PERFIX + "small.out";
                FileStream fs = null;
                StreamWriter sw = null;
                try
                {
                    if (true == IS_FIRST_RUN)
                    {
                        IS_FIRST_RUN = false;
                        fs = File.Open(fn, FileMode.Create);
                    }
                    else
                    {
                        fs = File.Open(fn, FileMode.Append);
                    }
                    sw = new StreamWriter(fs);
                    sw.WriteLine(s);
                }
                catch (Exception e)
                {
                    System.Console.WriteLine(e.StackTrace);
                }
                finally
                {
                    // close file
                    if (null != sw) sw.Close();
                    if (null != fs) fs.Close();
                }
            }
        }

        private class Node
        {
            public int id;
            public IList<Node> parents { get; set; }
            public IList<Node> children { get; set; }
        }

    }
}
