using System;
using System.Collections.Generic;
using System.IO;

namespace RecycledNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader input = new StreamReader(@"C:\Users\Montana\Desktop\C-large.in"))
            using (StreamWriter output = new StreamWriter(@"C:\Users\Montana\Desktop\out3.txt"))
            {
                int count = int.Parse(input.ReadLine());

                for (int i = 0; i < count; i++)
                {
                    output.WriteLine("Case #{0}: {1}", (i + 1), RecycleNumbers(input.ReadLine()));
                }
            }
        }

        private static int RecycleNumbers(string line)
        {
            string[] split = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            int a = int.Parse(split[0]);
            int b = int.Parse(split[1]);

            int count = 0;
            Dictionary<int, HashSet<int>> entries = new Dictionary<int, HashSet<int>>();

            if (b < 10) return 0;

            for (int shift = 1; shift < Math.Log10(b); shift++)
            {
                for (int j = a; j <= b; j++)
                {
                    int r = ShiftNumber(j, shift);
                    if (r < a || r > b || r == j || r < j) continue;
                    else
                    {
                        if (!entries.ContainsKey(j)) entries.Add(j, new HashSet<int>());
                        if (entries[j].Contains(r)) continue;
                        entries[j].Add(r);
                        count++;
                    }
                }
            }

            return count;
        }

        private static int ShiftNumber(int number, int shift)
        {
            string n = number.ToString();

            return int.Parse(n.Substring(shift) + n.Substring(0, shift));
        }

        private static bool IsPalindrome(int number)
        {
            string n = number.ToString();
            for (int i = 0; i < n.Length / 2; i++) if (n[i] != n[n.Length - i - 1]) return false;
            return true;
        }
    }
}
