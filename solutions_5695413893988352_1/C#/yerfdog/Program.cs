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
            string[] lines = File.ReadAllLines(@"C:\GCJ\B-large.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\B.out");
            for (int a = 0; a < t; a++)
            {
                string[] line = lines[idx++].Split(' ');
                tw.WriteLine("Case #{0}: {1}", a + 1, calcb(line[0], line[1]));
            }
            tw.Close();
        }
        private static string calcb2(string s1, string s2)
        {
            List<int> ones = new List<int>();
            List<int> twos = new List<int>();
            build(ones, s1, "");
            build(twos, s2, "");
            int min = int.MaxValue;
            int ans1 = 0;
            int ans2 = 0;
            for(int a = 0; a< ones.Count; a++)
            {
                for (int b = 0; b < twos.Count; b++)
                {
                    if(Math.Abs(ones[a] - twos[b]) < min)
                    {
                        min = Math.Abs(ones[a] - twos[b]);
                        ans1 = ones[a];
                        ans2 = twos[b];
                    }else if (Math.Abs(ones[a] - twos[b]) == min)
                    {
                        if(ones[a] < ans1)
                        {
                            ans1 = ones[a];
                            ans2 = twos[b];
                        }else if(ones[a] == ans1 && twos[b] < ans2)
                        {
                            ans1 = ones[a];
                            ans2 = twos[b];
                        }
                    }

                }

            }
            string pad = "";
            for (int a = 0; a < s1.Length; a++)
            {
                pad += "0";
            }
            return string.Format("{0:" + pad + "} {1:" + pad + "}", ans1, ans2);
        }

        private static void build(List<int> ones, string s1, string b)
        {
            if (b.Length == s1.Length)
            {
                ones.Add(int.Parse(b));
                return;
            }
            if (s1[b.Length] == '?')
            {
                for (int c = 0; c <= 9; c++)
                {
                    build(ones, s1, b + c);
                }
            }
            else
            {
                build(ones, s1, b + s1[b.Length]);
            }
        }

        private static string calcb(string s1, string s2)
        {
            long[] ans = find(s1, s2);
            long[] ans2 = find(s2, s1);
            string pad = "";
            for (int a = 0; a < s1.Length; a++)
            {
                pad += "0";
            }
            bool first = true;
            if (lookahead(s2, s1, -1, false) && !lookahead(s1, s2, -1, false))
            {
                first = false;
            }
            else if (!lookahead(s2, s1, -1, false) && lookahead(s1, s2, -1, false))
            {
                first = true;
            }
            else if (ans[0] - ans[1] < ans2[0] - ans2[1])
            {
                first = true;
            }
            else if (ans[0] - ans[1] > ans2[0] - ans2[1])
            {
                first = false;
            }
            else if (ans[0] < ans2[1])
            {
                first = true;
            }
            else if (ans[0] > ans2[1])
            {
                first = false;
            }
            else if (ans[1] < ans2[0])
            {
                first = true;
            }
            else if (ans[1] > ans2[0])
            {
                first = false;
            }
            if (first)
            {
                return string.Format("{0:" + pad + "} {1:" + pad + "}", ans[0], ans[1]);
            }
            else
            {
                return string.Format("{0:" + pad + "} {1:" + pad + "}", ans2[1], ans2[0]);
            }
        }

        private static long[] find(string s1, string s2)
        {
            string one = "";
            string two = "";
            bool balanced = true;
            for (int a = 0; a < s1.Length; a++)
            {
                if (s1[a] == '?')
                {
                    if (s2[a] == '?')
                    {
                        if (balanced)
                        {
                            if (lookahead(s1, s2, a, false))
                            {
                                one += "0";
                                two += "0";
                            }
                            else
                            {
                                balanced = false;
                                one += "1";
                                two += "0";
                            }
                        }
                        else
                        {
                            one += "0";
                            two += "9";
                        }

                    }
                    else if (balanced)
                    {
                        if (lookahead(s1, s2, a, false))
                        {
                            one += s2[a];
                            two += s2[a];
                        }
                        else
                        {
                            balanced = false;
                            one += (s2[a] - '0') + 1;
                            two += s2[a];
                        }
                    }
                    else
                    {
                        one += "0";
                        two += s2[a];
                    }
                }
                else if (s2[a] == '?')
                {
                    if (balanced)
                    {
                        if (lookahead(s1, s2, a, true))
                        {
                            one += s1[a];
                            two += s1[a];
                        }
                        else
                        {
                            balanced = false;
                            one += s1[a];
                            two += (s1[a] - '0') - 1;
                        }
                    }
                    else
                    {
                        one += s1[a];
                        two += "9";
                    }
                }
                else
                {
                    one += s1[a];
                    two += s2[a];
                    if (s1[a] > s2[a])
                    {
                        balanced = false;
                    }
                }
            }
            return new long[] { long.Parse(one), long.Parse(two) };
        }

        private static bool lookahead(string s1, string s2, int a, bool check)
        {
            for (int b = a + 1; b < s1.Length; b++)
            {
                if (s1[b] == '?')
                {
                    if (s2[b] != '9' && (!check || s2[b] != '?'))
                    {
                        return true;
                    }
                }
                else if (s2[b] == '?')
                {
                    if (s1[b] != '0')
                    {

                        return true;
                    }
                }
                else
                {
                    if (s1[b] > s2[b])
                    {
                        return true;
                    }
                    else if (s2[b] > s1[b])
                    {
                        return false;
                    }
                }
            }
            return true;
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
                        }
                        else
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
