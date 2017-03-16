using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2
{
    class Program
    {
        static void Main(string[] args)
        {
            var lines = File.ReadAllLines(@"C:\Users\Viktor\Downloads\GCJ\1111111111111111111.in");

            StringBuilder result = GetValue(lines);

            var length = result.Length - 1;
            File.WriteAllText(@"E:\res.res", result.Remove(length, 1).ToString());
        }

        private static StringBuilder GetValue(string[] lines)
        {
            var result = new StringBuilder();
            int cases = int.Parse(lines[0]);

            for (int i = 1; i <= cases; i++)
            {
                var input = lines[i].Split(' ');

                var word = MakeBinary(input[0]);
                int n = int.Parse(input[1]);

                int res = 0;
                var length = word.Length;

                var all = new HashSet<Tuple<int, int>>();
                for (int j = 0; j < length - n + 1; j++)
                {
                    var part = word.Substring(j, n);
                    if (part.IndexOf('1') == -1)
                    {
                        for (int k = 0; k <= j; k++)
                        {
                            for (int l = j + n - 1; l < length; l++)
                            {
                                all.Add(new Tuple<int, int>(k, l));
                            }
                        }
                    }
                }

                res = all.Count;
                result.AppendFormat("Case #{0}: {1}\n", i, res);
            }

            return result;
        }

        private static string MakeBinary(string s)
        {
            string res = "";
            foreach (char c in s)
            {
                switch (c)
                {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                        res += 1;
                        break;

                    default:
                        res += 0;
                        break;

                }
            }

            return res;
        }
    }
}
