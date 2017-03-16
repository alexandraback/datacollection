using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamPlayground
{
    struct level_req
    {
        public int lev1;
        public int lev2;
        public bool played;
    }

    class Solution
    {
        public string solve(StreamReader sr)
        {
            int N = Convert.ToInt32(sr.ReadLine());
            //int[,] star_req = new int[N, 2];
            List<level_req> star_req = new List<level_req>();

            for (int i = 0; i < N; i++)
            {
                string line = sr.ReadLine();
                string[] part = line.Split();

                level_req this_req = new level_req();
                this_req.lev1 = Convert.ToInt32(part[0]);
                this_req.lev2 = Convert.ToInt32(part[1]);
                this_req.played = false;

                star_req.Add(this_req);
            }

            int trial = 0;
            int stars = 0;

            do
            {
                trial++;
                bool played = false;

                // find if current star sufficient to earn 2 stars
                foreach (level_req l in star_req)
                {
                    if (l.lev2 <= stars)
                    {
                        // play this level
                        played = true;

                        if (l.played) stars = stars + 1;
                        else stars = stars + 2;

                        // remove this level on the list
                        star_req.Remove(l);
                        break;
                    }
                }

                if (played) continue;

                // find if current star sufficient to earn 1 star
                foreach (level_req l in star_req)
                {
                    if (l.lev1 <= stars && l.played == false)
                    {
                        // play this level
                        played = true;
                        stars = stars + 1;
                        level_req l_new = l;
                        l_new.played = true;
                        star_req.Remove(l);
                        star_req.Add(l_new);

                        break;
                    }
                }

                if (played) continue;

                // no more level can be played
                else return "Too Bad";

            } while (stars < N * 2);

            return trial.ToString();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string input_id = "B-small-attempt1";
            StreamReader sr = new StreamReader(input_id + ".in");
            StreamWriter sw = new StreamWriter(input_id + ".out");

            int total_test_case = Int32.Parse(sr.ReadLine());
            Console.WriteLine("Total test case: " + total_test_case);

            Solution s = new Solution();

            for (int i = 1; i <= total_test_case; i++)
            {
                Console.WriteLine("==== Test case: " + i + " ====");
                string result = s.solve(sr);
                sw.WriteLine("Case #" + i + ": " + result);
                Console.WriteLine("Case #" + i + ": " + result);
            }

            sr.Close();
            sw.Close();

            Console.WriteLine("Press any key to continue...");
            Console.ReadKey();
        }
    }
}
