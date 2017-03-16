using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CounterCulture
{
    class Program
    {
        static void Main(string[] args)
        {
            string inputFilePath = args[0];
            string outputFilePath = Path.GetFileNameWithoutExtension(inputFilePath) + ".out";
            using (StreamReader reader = new StreamReader(inputFilePath))
            {
                using (StreamWriter writer = new StreamWriter(outputFilePath))
                {
                    int T = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= T; i++)
                    {
                        int N = int.Parse(reader.ReadLine());

                        writer.WriteLine(string.Format("Case #{0}: {1}", i, GetCount(N)));
                    }
                }
            }
        }

        static int GetCount(int N)
        {
            int count = 0;

            HashSet<int> attempted = new HashSet<int>();

            HashSet<int> items0 = new HashSet<int>();
            items0.Add(1);

            while (true)
            {
                count++;

                HashSet<int> items1 = new HashSet<int>();
                foreach (int item0 in items0)
                {
                    if (item0 == N)
                    {
                        return count;
                    }
                    
                    attempted.Add(item0);

                    int items1a = item0 + 1;
                    if (!attempted.Contains(items1a))
                    {
                        items1.Add(items1a);
                    }

                    int items1b = int.Parse(new string(item0.ToString().Reverse().ToArray()));
                    if (!attempted.Contains(items1b))
                    {
                        items1.Add(items1b);
                    }
                }

                items0 = items1;
            }
        }
    }
}