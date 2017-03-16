using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14.R1B
{
 using System;
 using System.Globalization;
 using System.Linq;
 using System.Xml.Serialization;

    public class A
    {
        public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];
            
                string[] order = new string[10]
                                     { "ZERO", "SIX", "EIGHT", "THREE", "FOUR", "FIVE", "SEVEN", "NINE", "ONE", "TWO", };
            int[] tores = new int[10] { 0, 6, 8, 3, 4, 5, 7, 9, 1, 2 };

            for (int i = 0; i < cases; i++)
            {
                string s = lines[i + 1];
                int[] nums = new int[26];
                for (int j = 0; j < s.Length; j++)
                {
                    nums[s[j] - 'A']++;
                }

                List<int> ans = new List<int>();
                for (int j = 0; j < order.Length; j++)
                {
                    string d = order[j];
                    while (true)
                    {
                        bool ok = true;
                        for (int q = 0; q < d.Length; q++)
                        {
                            if (nums[d[q] - 'A'] <= 0)
                            {
                                ok = false;
                                break;
                            }
                        }
                        if (!ok)
                            break;
                        for (int q = 0; q < d.Length; q++)
                        {
                            nums[d[q] - 'A']--;
                        }
                        ans.Add(tores[j]);
                    }
                }

                if (!nums.All(n => n == 0))
                    throw new Exception("bad");

                ans.Sort();

                Console.WriteLine("Case #{0}: {1}", (i+1), string.Join("",ans));
                res[i] = string.Format("Case #{0}: {1}", (i+1), string.Join("",ans));


            }
            return res;
        }

    }
}
