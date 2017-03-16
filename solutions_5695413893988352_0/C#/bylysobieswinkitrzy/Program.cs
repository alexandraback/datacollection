using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;

namespace CJ2Round
{
    class Comb
    {
       public int left;
        public string lefts;
        public string rights;
       public int right;
       public int diff;
    }

    class Program
    {
        static void Main(string[] args)
        {


            string[] lines = File.ReadAllLines("B-small-attempt2.in");

            int noOfCases = int.Parse(lines[0]);



            List<string> output = new List<string>();

            List<int> nums3 = Enumerable.Range(0, 1000).ToList();
            List<int> nums2 = Enumerable.Range(0, 100).ToList();
            List<int> nums1 = Enumerable.Range(0, 10).ToList();
            List<Comb> preend3 = new List<Comb>();

            for (int i = 0; i < nums3.Count; i++)
            {
                for (int j = 0; j < nums3.Count; j++)
                {
                    preend3.Add(new Comb()
                    {
                        left = nums3[i],
                        right = nums3[j],
                        lefts = nums3[i].ToString().PadLeft(3, '0'),
                    rights = nums3[j].ToString().PadLeft(3, '0'),
                    diff = Math.Abs(nums3[i] - nums3[j])
                    });
                }
            }

            List<Comb> preend2 = new List<Comb>();

            for (int i = 0; i < nums2.Count; i++)
            {
                for (int j = 0; j < nums2.Count; j++)
                {
                    preend2.Add(new Comb()
                    {
                        left = nums2[i],
                        right = nums2[j],
                        lefts = nums2[i].ToString().PadLeft(2, '0'),
                        rights = nums2[j].ToString().PadLeft(2, '0'),
                        diff = Math.Abs(nums2[i] - nums2[j])
                    });
                }
            }

            List<Comb> preend1 = new List<Comb>();

            for (int i = 0; i < nums1.Count; i++)
            {
                for (int j = 0; j < nums1.Count; j++)
                {
                    preend1.Add(new Comb()
                    {
                        left = nums1[i],
                        right = nums1[j],
                        lefts = nums1[i].ToString().PadLeft(1, '0'),
                        rights = nums1[j].ToString().PadLeft(1, '0'),
                        diff = Math.Abs(nums1[i] - nums1[j])
                    });
                }
            }

            for (int i = 1; i <= noOfCases; i++)
            {
                var line = lines[i].Split(' ');
                var xxxx = String.Empty;

                List<Comb> end = new List<Comb>();
                    if (line[0].Length == 3)
                    {
                        end.AddRange(preend3);
                    }
                    if (line[0].Length == 2)
                    {
                        end.AddRange(preend2);
                    }
                    if (line[0].Length == 1)
                    {
                        end.AddRange(preend1);
                    }

                    line[0] = string.Concat("^", line[0], "$").Replace("?", "[0-9]");
                    line[1] = string.Concat("^", line[1], "$").Replace("?", "[0-9]");
                var outp = end.Where(w => Regex.Match(w.lefts, line[0]).Success && Regex.Match(w.rights, line[1]).Success).OrderBy(o => o.diff).First();
                    xxxx = String.Format("Case #{0}: {1} {2}", i, outp.lefts, outp.rights);
       
               
                output.Add(xxxx);
                Console.WriteLine(xxxx);

            }
            File.WriteAllLines("output.out", output);
            Console.WriteLine("Done.");
            Console.ReadKey();
        }
        
    }
}
