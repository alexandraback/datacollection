using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamWriter writer = new StreamWriter(@"D:\output.txt"))
            {
                using (StreamReader reader = new StreamReader(File.OpenRead(@"D:\B-small-attempt2.in")))
                {
                    int cases = int.Parse(reader.ReadLine());
                    for (int i = 0; i < cases; i++)
                    {
                        Process(i, reader, writer);
                    }
                }
            }
        }

        public class Item
        {
            public int level1;
            public int level2;
            public bool done1;
            public bool done2;
            public Item(int a, int b)
            {
                level1 = a;
                level2 = b;
                done1 = false;
                done2 = false;
            }
            public override string ToString()
            {
                return level1.ToString() + "," + level2.ToString();
            }
        }

        private static void Process(int num, StreamReader reader, StreamWriter writer)
        {
            int caseId = num + 1;
            int NLevels = int.Parse(reader.ReadLine());

            List<Item> cost = new List<Item>();

            for (int i = 0; i < NLevels; i++)
            {
                var row = reader.ReadLine().Split(' ');
                cost.Add(new Item(int.Parse(row[0]), int.Parse(row[1])));
            }

            int total = NLevels * 2;
            int stars = 0;
            int steps = 0;
            bool fail = false;
            while (stars < total)
            {
                var flag = false;
                // complete the 2 starts
                foreach (var item in cost.Where(x => x.done2 == false && x.level2 <= stars))
                {
                    stars += 2;
                    item.done2 = true;
                    item.done1 = true;
                    flag = true;
                    steps++;
                }

                if (flag)
                    continue;

                foreach (var top in cost.Where(x => x.done1 == false && x.level1 <= stars).OrderByDescending(x => x.level2))
                {
                    stars++;
                    steps++;
                    top.done1 = true;
                    flag = true;
                    break;
                }

                if (!flag)
                {
                    fail = true;
                    break;
                }
            }

            writer.WriteLine("Case #{0}: {1}", caseId, fail ? "Too Bad" : steps.ToString());
        }
    }
}
