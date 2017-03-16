using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Kingdom_Rush
{
    class Star
    {
        public int lv1;
        public int lv2;
        public int clear;

        public Star(int a, int b)
        {
            lv1 = a; lv2 = b; clear = 0;
        }
    }

    class program
    {
        public static void Main()
        {
            string[] lines = funcs.getInputDocs(@"B-small-attempt0.in");
            int size = int.Parse(lines[0]);
            List<string> newlines = new List<string>();
            int count = 0;
            for (int i = 0; i < size; i++)
            {
                count++;
                int levels = int.Parse(lines[count]);
                List<Star> stars = new List<Star>();

                for (int j = 0; j < levels; j++)
                {
                    count++;
                    string thisline = lines[count];
                    string[] words = thisline.Split();
                    Star star = new Star(int.Parse(words[0]), int.Parse(words[1]));
                    stars.Add(star);
                }
                //Construction Complete.

                int steps = 0, flag = 0, total_star = 0;
                while ((total_star <= 2 * levels) && (flag == 0))
                {
                    int change = 0;
                    for (int j = 0; j < levels; j++)
                        if (stars[j].clear != 2)
                            if (total_star >= stars[j].lv2)
                            {
                                steps++;
                                total_star = total_star + (2 - stars[j].clear);
                                stars[j].clear = 2;
                                j = -1; change = 1;
                            }


                    //Find the largest 2-level value.
                    int max = -1, posmin = -1;
                    for (int j = 0; j < levels; j++)
                    {
                        if (stars[j].clear == 0)
                            if (total_star >= stars[j].lv1)
                                if (stars[j].lv2 > max)
                                {
                                    max = stars[j].lv2;
                                    posmin = j; change = 1;
                                }
                    }

                    if (posmin != -1)
                    {
                        steps++;
                        total_star++;
                        stars[posmin].clear = 1;
                    }

                    if (change == 0)
                        flag = 1;

                }

                if (total_star != 2 * levels)
                    newlines.Add("Case #" + (i + 1).ToString() + ": Too Bad");
                else
                    newlines.Add("Case #" + (i + 1).ToString() + ": " + steps);
            }

            funcs.WriteLines(@"B-small-attempt0.out", newlines);
        }
    }
}
