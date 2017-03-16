using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A
{
    class progam
    {
        public static bool Cons(char ch)
        {
            if ((ch != 'a') && (ch != 'e') && (ch != 'i') && (ch != 'o') && (ch != 'u'))
                return true;
            return false;
        }

        public static bool YesCons(string st)
        {
            for (int i = 0; i < st.Length; i++)
                if ((st[i] == 'a') || (st[i] == 'e') || (st[i] == 'i') || (st[i] == 'o') || (st[i] == 'u'))
                    return false;
            return true;
        }

        public static void Main()
        {
            //List<string> input_lines = funcs.getInputDocs2(@"input.txt");
            List<string> input_lines = funcs.getInputDocs2(@"A-small-attempt0.in");
            //List<string> input_lines = funcs.getInputDocs2(@"A-large.in");

            int num = int.Parse(input_lines[0]);
            List<string> outlines = new List<string>();
            int lcount = 1;
            for (int samples = 0; samples < num; samples++)
            {
                string thisline = input_lines[lcount]; lcount++;
                string[] words = thisline.Split(' ');
                string bigname = words[0]; int m = int.Parse(words[1]);
                bool[] PassNot = new bool[bigname.Length];
                int sum = 0;

                for (int ct = m; ct <= bigname.Length; ct++)
                {
                    for (int start = 0; start < bigname.Length - ct + 1; start++)
                    {
                        int finish = start + ct;

                        if (ct == m)
                        {
                            string sub = bigname.Substring(start, ct);
                            if (YesCons(sub))
                            {
                                PassNot[start] = true;
                                sum += 1;
                            }
                            else
                                PassNot[start] = false;
                        }
                        else
                        {
                            if ((PassNot[start]) || (PassNot[start+1]))
                            {
                                PassNot[start] = true;
                                sum += 1;
                            }
                            else
                                PassNot[start] = false;
                        }
                    }
                }
                outlines.Add("Case #" + (samples + 1).ToString() + ": " + sum.ToString());
            }
            funcs.WriteLines(@"a-small.txt", outlines);
        }
    }
}
