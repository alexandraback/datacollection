using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14.R1B
{
    using System.Globalization;
    using System.Runtime.Remoting.Channels;
    using System.Security.Policy;

    class B
    {
          public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];


            
            for (int test = 0; test < cases; test++)
            {
                string[] s = lines[test + 1].Split(' ');

                char[][] all = new char[2][];
                all[0] = s[0].Trim().ToCharArray();
                
               all[1] = s[1].Trim().ToCharArray();

                  Tuple<long, long> ans = null;

                int dir = 0;
                long c1 = 0, c2 = 0;
                bool full = true;
                for (int i = 0; i < all[0].Length; i++)
                {
                    if (all[0][i] != '?' && all[1][i] != '?')
                    {
                        c1 = c1 * 10 + all[0][i] - '0';
                        c2 = c2 * 10 + all[1][i] - '0';

                        if (c1 != c2)
                        {
                            var v = assign(c1, c2, all, i + 1, c1 - c2);
                            ans = checkans(ans, v);
                            full = false;
                            break;
                        }

                        continue;
                    }

                    if (all[0][i] == '?' && all[1][i] == '?')
                    {
                        for (int q = 0; q <= 9; q++)
                        {
                            for (int w = Math.Max(0, q - 1); w <= Math.Min(9, q + 1); w++)
                                if (q != w)
                                {
                                    long n1 = c1 * 10 + q;
                                    long n2 = c2 * 10 + w;
                                    var v = assign(n1, n2, all, i + 1, n1 - n2);
                                    ans = checkans(ans, v);
                                }
                        }

                        c1 = c1 * 10;
                        c2 = c2 * 10;
                        continue;
                    }

                    if (all[0][i] == '?')
                    {
                        int know = all[1][i]-'0';
                        for (int j = Math.Max(0, know - 1); j <= Math.Min(9, know + 1); j++)
                        {
                            var v = assign(c1 * 10 + j, c2 * 10 + know, all, i + 1, (c1 * 10 + j) - (c2 * 10 + know));
                            ans = checkans(ans, v);
                        }
                        c1 = c1 * 10 + know;
                        c2 = c2 * 10 + know;
                        continue;
                    }

                    if (all[1][i] == '?')
                    {
                        int know = all[0][i]-'0';
                        for (int j = Math.Max(0, know - 1); j <= Math.Min(9, know + 1); j++)
                        {
                            var v = assign(c1 * 10 + know, c2 * 10 + j, all, i + 1, (c1 * 10 + know) - (c2 * 10 + j));
                            ans = checkans(ans, v);
                        }
                        c1 = c1 * 10 + know;
                        c2 = c2 * 10 + know;
                        continue;
                    }
                }

                if (full)
                {
                    ans = new Tuple<long, long>(c1,c2);
                    
                }


//                var bf = Brute(s[0], s[1]);
//                if (ans.Item1 != bf.Item1 || ans.Item2 != bf.Item2)
//                {
//                    Console.WriteLine(s[0] + " " +s[1]);
//                }

                string r = ans.Item1.ToString().PadLeft(all[0].Length, '0') + " "
                           + ans.Item2.ToString().PadLeft(all[0].Length, '0');
                Console.WriteLine("Case #{0}: {1}", (test+1), r);
                res[test] = string.Format("Case #{0}: {1}", (test+1), r);


            }
            return res;
        }

          Tuple<long, long> checkans(Tuple<long, long> ans, Tuple<long, long> can)
          {
              if (ans == null)
                  return can;
              long dif = Math.Abs(can.Item1 - can.Item2) - Math.Abs(ans.Item1 - ans.Item2);
              if (dif < 0)
              {
                  return can;
              }
              if (dif == 0)
              {
                  if (can.Item1 < ans.Item1 || can.Item1 == ans.Item1 && can.Item2 < ans.Item2)
                  {
                      return can;
                  }
              }

              return ans;
          }

        Tuple<long, long> assign(long c1, long c2, char[][] all, int k, long dir)
        {
            for (int i = k; i < all[0].Length; i++)
            {
                if (all[0][i] != '?')
                {
                    c1 = c1 * 10 + all[0][i] - '0';
                }
                else if (dir > 0)
                {
                    c1 = c1 * 10;
                }
                else if (dir < 0)
                {
                    c1 = c1 * 10 + 9;
                }
                else
                {
                    c1 = c1 * 10 + (all[1][i] != '?' ? all[1][i] - '0' : 0);
                }


                if (all[1][i] != '?')
                {
                    c2 = c2 * 10 + all[1][i] - '0';
                }
                else if (dir > 0)
                {
                    c2 = c2 * 10 + 9;
                }
                else if (dir < 0)
                {
                    c2 = c2 * 10 + 0;
                }
                else
                {
                    c2 = c2 * 10 + (all[0][i] != '?' ? all[0][i] - '0' : 0);
                }
            }

            return new Tuple<long, long>(c1, c2);
        }


        Tuple<long, long> Brute(string s1, string s2)
        {
            long r1 = 5, r2 = long.MaxValue;
            for (long a = 0;; a++)
            {
                string t1 = a.ToString();
                if (t1.Length > s1.Length)
                    break;
                t1 = t1.PadLeft(s1.Length, '0');
                for (long b = 0;; b++)
                {

                    string t2 = b.ToString();
                    if (t2.Length > s2.Length)
                        break;

                    long dif = Math.Abs(a - b);
                    if (dif > Math.Abs(r1 - r2) || dif == Math.Abs(r1 - r2) && a > r1 || dif == Math.Abs(r1 - r2) && a == r1 && b > r2)
                        continue;

                    t2 = t2.PadLeft(s2.Length, '0');

                    bool ok = true;
                    for (int q = 0; q < t1.Length; q++)
                        if (s1[q] != '?' && s1[q] != t1[q])
                            ok = false;

                    for (int q = 0; q < t2.Length; q++)
                        if (s2[q] != '?' && s2[q] != t2[q])
                            ok = false;
                    if (ok)
                    {
                        r1 = a;
                        r2 = b;
                    }
                }
            }

            return new Tuple<long, long>(r1, r2);
        }

    }
}
