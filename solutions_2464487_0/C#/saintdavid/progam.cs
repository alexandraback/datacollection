using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class progam
    {
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
                long r = long.Parse(words[0]); long t = long.Parse(words[1]);
                long count = 0, sum = 0, usage = 0;
                usage = 2*r+1;
                while (sum + usage <= t)
                {
                    sum += usage; count++;
                    usage += 4;
                }
                Console.WriteLine(count);
                outlines.Add("Case #" + (samples + 1).ToString() + ": " + count);
            }
            funcs.WriteLines(@"a-small.txt", outlines);            
        }
    }
}
