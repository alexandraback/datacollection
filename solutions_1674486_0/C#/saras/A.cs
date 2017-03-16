using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GCJ.GCJ2012.Round1C
{
    public class A
    {
        public static void Main()
        {
            var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\A-small-attempt0.in");
            var outputStream = new StreamWriter(@"C:\Users\asaraswat\Downloads\A-small-attempt0.out");

            Console.SetIn(inputStream);
            Console.SetOut(outputStream);

            int totalCases = GetInt();
            for (int cs = 1; cs <= totalCases; ++cs)
            {
                int n = GetInt();

                var nums = new List<List<int>>();
                for (int i = 0; i < n; ++i)
                {
                    var lst = GetListOfInt();
                    var nbrs = new List<int>();
                    nbrs.AddRange(lst.GetRange(1, lst.Count - 1));
                    for (int ii = 0; ii < nbrs.Count; ++ii)
                    {
                        nbrs[ii]--;
                    }
                    nums.Add(nbrs);
                }

                var diamond = false;
                for (int i = 0; !diamond && i < n; ++i)
                {
                    if (nums[i].Count > 1)
                    {
                        List<int> pq = new List<int>();
                        for (int j = 0; j < nums[i].Count; ++j)
                        {
                            pq.Add(nums[i][j]);
                        }

                        int ptr = 0;
                        while (!diamond && ptr < pq.Count)
                        {
                            int cp = pq[ptr];

                            for (int i1 = 0; !diamond && i1 < nums[cp].Count; ++i1)
                            {
                                if (pq.Contains(nums[cp][i1]))
                                {
                                    diamond = true;
                                }
                                else
                                {
                                    pq.Add(nums[cp][i1]);
                                }
                            }
                            ptr++;
                        }
                    }
                }

                Console.WriteLine("Case #{0}: {1}", cs, diamond ? "Yes" : "No");
            }

            inputStream.Close();
            outputStream.Close();
        }

        private static int GetInt()
        {
            string p = Console.ReadLine();
            return Convert.ToInt32(p);
        }

        private static List<int> GetListOfInt(char separator = ' ')
        {
            string p = Console.ReadLine();
            return p.Split(separator).Select(t => int.Parse(t)).ToList();
        }
    }
}
