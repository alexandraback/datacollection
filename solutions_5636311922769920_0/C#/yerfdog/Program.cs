using System;
using System.IO;

namespace gcj16q
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\GCJ\D.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\D.out");
            for (int a = 0; a < t; a++)
            {
                string[] line = lines[idx++].Split(' ');
                int K = int.Parse(line[0]);
                int C = int.Parse(line[1]);
                int S = int.Parse(line[2]);
                tw.WriteLine("Case #{0}: {1}", a + 1, calcd(K, C, S));
            }
            tw.Close();
        }

        private static string calcd(int k, int c, int s)
        {
            string imp = "IMPOSSIBLE";
            string ans = "";
            if (c == 1)
            {
                if (s < k)
                {
                    return imp;
                }
                else
                {
                    for(int i = 1; i <= k; i++)
                    {
                        ans += i + " ";
                    }
                }
            }
            else
            {
                if(s < (k+1) / 2)
                {
                    return imp;
                }
                else
                {
                    long interval = (long)Math.Pow(k, c - 1);
                    for (long i = 0; i < (k+1)/2; i++)
                    {
                        ans += (i * interval + (k - i)) + " ";
                    }
                }
            }
            return ans;
        }

        private static string calcc(int n, int j)
        {
            string ans = "";
            string line = " 3 2 3 2 7 2 3 2 3";
            int first = (1 << (n - 1)) + 1;
            int count = 0;
            for (int a = 1; a < n - 1; a++)
            {
                for (int b = a + 1; b < n - 1; b++)
                {
                    for (int c = b + 1; c < n - 1; c++)
                    {
                        if (!((a + b) % 2 == 0 && (b + c) % 2 == 0))
                        {
                            for (int d = c + 1; d < n - 1; d++)
                            {
                                if (d % 2 == (a + b + c) % 2)
                                {
                                    int ind = first | 1 << a | 1 << b | 1 << c | 1 << d;
                                    //check(n, ind);

                                    ans += "\n" + Convert.ToString(ind, 2) + line;
                                    count++;
                                    if (count == j)
                                    {
                                        return ans;
                                    }
                                }
                            }
                        }
                    }

                }

            }
            return "uh-oh";
        }

        private static void check(int n, int ind)
        {
            int[] check = new int[] { 3, 2, 3, 2, 7, 2, 3, 2, 3 };
            for (int i = 2; i < 10; i++)
            {
                double number = 0;
                for (int a = 0; a < n; a++)
                {

                    if (((1 << a) & ind) > 0)
                    {
                        number += Math.Pow(i, a);
                    }
                }
                if (number % check[i - 2] != 0)
                {
                    throw new Exception();
                }
            }
        }

        private static int calcb(string s, int moves)
        {
            if (s.Length == 0)
            {
                return moves;
            }

            int i = s.Length - 1;
            while (i >= 0 && s[i] == '+')
            {
                i--;
            }
            if (i != s.Length - 1)
            {
                return calcb(s.Substring(0, i + 1), moves);
            }

            i = 0;
            while (i < s.Length && s[i] == '-')
            {
                i++;
            }
            if (i != 0)
            {
                return calcb(flip(s, i), moves + 1);
            }

            i = 0;
            while (i < s.Length && s[i] == '+')
            {
                i++;
            }
            return calcb(flip(s, i), moves + 1);
        }

        private static string flip(string s, int i)
        {
            string front = s.Substring(0, i);
            string end = s.Substring(i);
            string res = "";
            for (int a = front.Length - 1; a >= 0; a--)
            {
                if (front[a] == '-')
                {
                    res += '+';
                }
                else
                {
                    res += '-';
                }
            }
            return res + end;
        }

        private static string calca(int N)
        {
            if (N == 0)
            {
                return "INSOMNIA";
            }
            int digits = 0;
            int done = (1 << 10) - 1;
            int cur = 0;
            while (done != digits)
            {
                cur += N;
                int curtemp = cur;
                while (curtemp > 0)
                {
                    int dig = curtemp % 10;
                    digits |= 1 << dig;
                    curtemp /= 10;
                }
            }
            return cur.ToString();
        }
    }
}