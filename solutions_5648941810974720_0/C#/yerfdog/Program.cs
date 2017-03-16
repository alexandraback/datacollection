using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj16r1b
{
    class Program
    {
        public static int largest = 0;
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\GCJ\A-small.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\A.out");
            for (int a = 0; a < t; a++)
            {
                string line = lines[idx++];
                tw.WriteLine("Case #{0}: {1}", a + 1, calca(line));
            }
            tw.Close();
        }

        private static string calca(string line)
        {
            string[] numbers = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
            string ans = "";
            string word;
            for (int c = 0; c < numbers.Length; c++)
            {
                ans = "";
                word = line;
                int a = 0;
                while (a < numbers.Length)
                {
                    int idx = (a + c) % numbers.Length;
                    bool found = true;
                    string toadd = "";
                    for (int b = 0; b < numbers[idx].Length; b++)
                    {
                        if (word.Contains(numbers[idx][b]))
                        {
                            word = word.Remove(word.IndexOf(numbers[idx][b]), 1);
                            toadd += numbers[idx][b];
                        }else
                        {
                            found = false;
                            break;
                        }
                    }
                    if (found)
                    {
                        ans += idx;
                    }
                    else
                    {
                        word += toadd;
                        a++;
                    }
                }
                if (word.Length == 0)
                {
                    char[] arr;
                    arr = ans.ToArray();
                    Array.Sort(arr);
                    return new string(arr);
                }
            }
            return ans;
        }
    }

}
