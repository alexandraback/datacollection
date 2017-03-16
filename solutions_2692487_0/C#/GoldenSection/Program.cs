using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            string line;

            StreamReader reader = new StreamReader("a-small-1.in");
            StreamWriter writer = new StreamWriter("a-small-1.out");

            int cc = int.Parse(reader.ReadLine());
            for (int T = 1; T <= cc; T++)
            {
                line = reader.ReadLine();
                string[] tokens = line.Split();
                long R = long.Parse(tokens[0]);
                int n = int.Parse(tokens[1]);

                line = reader.ReadLine();
                tokens = line.Split();
                List<long> list = new List<long>();
                foreach (string str in tokens)
                {
                    list.Add(long.Parse(str));
                }
                list.Sort();

                int tmp = 0;
                int ans = n;
                for (int i = 0; R > 1 && i < n; i++)
                {
                    while (R <= list[i])
                    {
                        R = R * 2 - 1;
                        tmp++;
                    }
                    R += list[i];

                    if (tmp + n - 1 - i < ans)
                    {
                        ans = tmp + n - 1 - i;
                    }
                }
                writer.WriteLine("Case #{0}: {1}", T, ans);
            }

            reader.Close();
            writer.Close();
        }
    }
}
