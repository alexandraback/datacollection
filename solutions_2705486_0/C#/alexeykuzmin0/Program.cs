using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
    class Program
    {
        static StreamReader sr = new StreamReader("input.txt");
        static StreamWriter sw = new StreamWriter("output.txt");

        static List<List<string>> tests = new List<List<string>>();
        static List<string>[] answers;
        static BOR root = new BOR();

        static List<string> ReadTest()
        {
            List<string> ans = new List<string>();
            ans.Add(sr.ReadLine());
            return ans;
        }

        static void Run(int p)
        {
            string our = tests[p][0];
            SortedDictionary<Position, int> dict = new SortedDictionary<Position, int>();
            List<string> w = new List<string>();
            w.Add("");
            dict[new Position() { age = 5, v = root, words = w}] = 0;
            for (int i = 0; i < our.Length; ++i)
            {
                SortedDictionary<Position, int> new_dict = new SortedDictionary<Position, int>();
                foreach (Position was in dict.Keys)
                {
                    Position new_pos;
                    if (was.v.children[our[i] - 'a'] != null)
                    {
                        new_pos = new Position() { v = was.v.children[our[i] - 'a'], age = was.age + 1, words = new List<string>(was.words)};
                        new_pos.words[new_pos.words.Count - 1] += our[i];
                        if (!new_dict.ContainsKey(new_pos))
                        {
                            new_dict[new_pos] = int.MaxValue;
                        }
                        new_dict[new_pos] = Math.Min(new_dict[new_pos], dict[was]);
                        if (new_pos.v.finish)
                        {
                            new_pos = new Position() { v = root, age = was.age + 1, words = new List<string>(was.words)};
                            new_pos.words[new_pos.words.Count - 1] += our[i]; 
                            new_pos.words.Add("");
                            if (!new_dict.ContainsKey(new_pos))
                            {
                                new_dict[new_pos] = int.MaxValue;
                            }
                            new_dict[new_pos] = Math.Min(new_dict[new_pos], dict[was]);
                        }
                    }
                    if (was.age >= 5)
                    {
                        for (char c = 'a'; c <= 'z'; ++c)
                        {
                            if (was.v.children[c - 'a'] != null)
                            {
                                new_pos = new Position() { v = was.v.children[c - 'a'], age = 1, words = new List<string>(was.words)};
                                new_pos.words[new_pos.words.Count - 1] += (char)(c + 'A' - 'a');
                                if (!new_dict.ContainsKey(new_pos))
                                {
                                    new_dict[new_pos] = int.MaxValue;
                                }
                                new_dict[new_pos] = Math.Min(new_dict[new_pos], dict[was] + 1);
                                if (new_pos.v.finish)
                                {
                                    new_pos = new Position() { v = root, age = 1, words = new List<string>(was.words)};
                                    new_pos.words[new_pos.words.Count - 1] += (char)(c + 'A' - 'a');
                                    new_pos.words.Add("");
                                    if (!new_dict.ContainsKey(new_pos))
                                    {
                                        new_dict[new_pos] = int.MaxValue;
                                    }
                                    new_dict[new_pos] = Math.Min(new_dict[new_pos], dict[was] + 1);
                                }
                            }
                        }
                    }
                }
                dict = new_dict;
            }
            int ans = int.MaxValue;
            foreach (Position pos in dict.Keys)
            {
                if (pos.v.finish)
                {
                    ans = Math.Min(ans, dict[pos]);
                }
            }
            answers[p] = new List<string>();
            answers[p].Add(ans.ToString());
        }

        static void Out(int p)
        {
            sw.WriteLine("Case #" + (p + 1).ToString() + ": " + answers[p][0]);
        }

        static void Main(string[] args)
        {
            sr.ReadLine();
            StreamReader sr2 = new StreamReader("garbled_email_dictionary.txt");
            while (!sr2.EndOfStream)
            {
                root.Add(sr2.ReadLine());
            }
            while (!sr.EndOfStream)
            {
                tests.Add(ReadTest());
            }
            answers = new List<string>[tests.Count];
            ParallelOptions po = new ParallelOptions() { MaxDegreeOfParallelism = 1 };
            Parallel.For(0, tests.Count, po, Run);
            for (int i = 0; i < answers.Count(); ++i)
            {
                Out(i);
            }
            sw.Flush();
            sw.Close();
        }
    }

    class BOR
    {
        public BOR[] children = new BOR[26];
        public bool finish = false;
        public int id;

        static int next_id = 0;

        public void Add(string line)
        {
            if (line == "")
            {
                finish = true;
                return;
            }
            if (children[line[0] - 'a'] == null)
            {
                children[line[0] - 'a'] = new BOR() { id = next_id++ };
            }
            children[line[0] - 'a'].Add(line.Substring(1));
        }
    }

    class Position : IComparable
    {
        public BOR v;
        public int age;
        public List<string> words = new List<string>();

        public int CompareTo(object obj)
        {
            Position rhs = obj as Position;
            if (v.id < rhs.v.id)
            {
                return -1;
            }
            if (v.id > rhs.v.id)
            {
                return 1;
            }
            if (age < rhs.age)
            {
                return -1;
            }
            if (age > rhs.age)
            {
                return 1;
            }
            return 0;
        }
    }
}
