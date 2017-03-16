using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Dancing
{
    class program
    {
        public static void Main()
        {
            string[] lines = funcs.getInputDocs(@"B-small-attempt0.in");
            int size = int.Parse(lines[0]);
            List<string> newlines = new List<string>();

            for (int i = 1; i < size+1; i++)
            {
                string thisline = lines[i];
                string[] numbers = thisline.Split();

                int num_size = int.Parse(numbers[0]);
                int fault_tolerance = int.Parse(numbers[1]);
                int th = int.Parse(numbers[2]);

                int th1 = 3 * th - 4, th2 = 3 * th - 2;
                int count = 0, left_numbers = 0;

                if (th == 0)
                {
                    th1 = 0; th2 = 0;
                }
                if (th == 1)
                {
                    th1 = 1; th2 = 1;
                }

                for (int j = 0; j < num_size; j++)
                {
                    int thisnumber = int.Parse(numbers[j + 3]);
                    if (thisnumber < th1) { continue; }//messi
                    if (thisnumber >= th2) { count++; continue; }
                    left_numbers++;
                }
                count = count + Math.Min(left_numbers, fault_tolerance);
                newlines.Add("Case #" + i.ToString() + ": " + count.ToString());
            }
            funcs.WriteLines(@"B-small-attempt0.out", newlines);            
        }
    }
}
