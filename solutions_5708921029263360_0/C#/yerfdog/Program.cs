using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj16r1c
{
    class Program
    {
        char[][] ANSWER;
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\GCJ\C.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\C.out");
            for (int a = 0; a < t; a++)
            {
                string[] line = lines[idx++].Split(' ');
                int J = int.Parse(line[0]);
                int P = int.Parse(line[1]);
                int S = int.Parse(line[2]);
                int K = int.Parse(line[3]);
                long M = long.Parse(line[1]);
                List<string> ans;
                tw.WriteLine("Case #{0}: {1}", a + 1, calcc(J, P, S, K, out ans));
                for (int c = 0; c < ans.Count; c++)
                {
                    tw.WriteLine(ans[c]);
                }
            }
            tw.Close();
        }

        private static int calcc(int j, int p, int s, int k, out List<string> ans)
        {
            ans = new List<string>();
            Dictionary<int, int> jp = new Dictionary<int, int>();
            Dictionary<int, int> ps = new Dictionary<int, int>();
            Dictionary<int, int> js = new Dictionary<int, int>();
            for (int a = 0; a < j; a++)
            {
                for (int b = 0; b < p; b++)
                {
                    for (int c = 0; c < s; c++)
                    {
                        int jpi = a * 100 + b;
                        int psi = b * 100 + c;
                        int jsi = a * 100 + c;
                        if (!jp.ContainsKey(jpi))
                        {
                            jp.Add(jpi, 0);
                        }
                        if (!ps.ContainsKey(psi))
                        {
                            ps.Add(psi, 0);
                        }
                        if (!js.ContainsKey(jsi))
                        {
                            js.Add(jsi, 0);
                        }
                        if (jp[jpi] < k && ps[psi] < k && js[jsi] < k)
                        {
                            jp[jpi]++;
                            ps[psi]++;
                            js[jsi]++;
                            ans.Add((a + 1) + " " + (b + 1) + " " + (c + 1));
                        }
                    }
                }
            }
            return ans.Count;
        }

        private static char[][] calcb22(int b, long m, char[][] ans, int curRow)
        {
            for (int j = 0; j < Math.Pow(2, b - curRow - 1); j++)
            {
                int cop = j;
                for (int k = 0; k < b - curRow - 1; k++)
                {
                    if (cop % 2 == 1)
                    {
                        ans[curRow][curRow + k + 1] = '1';
                    }
                    else
                    {
                        ans[curRow][curRow + k + 1] = '0';
                    }
                    cop >>= 1;
                }
                if (curRow == b - 2)
                {
                    if (count(ans) == m)
                    {
                        return ans;
                    }
                }
                else
                {
                    return calcb22(b, m, ans, curRow + 1);
                }
            }
            return new char[0][];
        }

        private static long count(char[][] ans)
        {
            int b = ans.Length;
            long count = 0;
            long[] cnts = new long[b];
            for (int a = b - 2; a >= 0; a--)
            {
                if (ans[a][b - 1] == '1')
                {
                    count++;
                    cnts[a]++;
                }
                for (int c = a + 1; c < b - 1; c++)
                {
                    if (ans[a][c] == '1')
                    {
                        count += cnts[c];
                        cnts[a] += cnts[c];
                    }
                }
            }
            return count;
        }

        private static string calcb2(int b, long m, out char[][] ans)
        {
            char[][] ans2 = new char[b][];
            for (int i = 0; i < b; i++)
            {
                ans2[i] = new char[b];
                for (int j = 0; j < b; j++)
                {
                    ans2[i][j] = '0';
                }
            }
            ans = calcb22(b, m, ans2, 0);
            if (ans.Length == 0)
            {
                return "IMPOSSIBLE";
            }
            return "POSSIBLE";
        }
        private static string calcb(int b, long m, out char[][] ans)
        {
            long count = 0;
            for (int a = 2; a <= b; a++)
            {
                count = (((a - 2) * (a - 1)) / 2);
                long prevTotal = count;
                count++;
                if (count >= m)
                {
                    ans = construct(b, a, 0, count - m);
                    return "POSSIBLE";
                }

                for (int c = 1; c < b - a; c++)
                {
                    long cur = (a - 1) + prevTotal;
                    prevTotal += cur;
                    count += cur;
                    if (count >= m)
                    {
                        ans = construct(b, a, c, count - m);
                        return "POSSIBLE";
                    }
                }
            }
            ans = new char[0][];
            return "IMPOSSIBLE";
        }

        private static char[][] construct(int b, int a, int c, long v)
        {
            char[][] ans = new char[b][];
            for (int i = 0; i < b; i++)
            {
                ans[i] = new char[b];
                for (int j = 0; j < a - 1; j++)
                {
                    ans[i][j] = '0';
                }
            }
            for (int i = 1; i < a - 1; i++)
            {
                long count = 1 + (c) * (c + 1) / 2;
                if (count > v)
                {
                    ans[i][b - 1] = '1';
                }
            }

            return ans;
        }

        private static string calca(int n, int[] numSens)
        {
            string ans = "";
            while (true)
            {
                int max = -1;
                List<int> tops = new List<int>();
                for (int a = 0; a < n; a++)
                {
                    if (numSens[a] > max)
                    {
                        tops = new List<int>();
                        tops.Add(a);
                        max = numSens[a];
                    }
                    else if (numSens[a] == max)
                    {
                        tops.Add(a);
                    }
                }
                if (max == 0)
                {
                    break;
                }
                int take = 2;
                if (max == 1 && tops.Count == 3)
                {
                    take = 1;
                }
                ans += " ";
                for (int a = 0; a < tops.Count && a < take; a++)
                {
                    ans += (char)('A' + tops[a]);
                    numSens[tops[a]]--;
                }
            }
            return ans;
        }

    }
}