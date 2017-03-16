using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Recycled
{
    class program
    {
        public static void Main()
        {                   
            string[] lines = funcs.getInputDocs(@"C-large.in");
            List<string> newlines = new List<string>();
            int size = int.Parse(lines[0]);
            for (int i = 0; i < size; i++)
            {
                string thisline = lines[i + 1];
                string[] numbers = thisline.Split(' ');
                int A = int.Parse(numbers[0]);
                int B = int.Parse(numbers[1]);               

                int count = 0;
                for (int num = A; num <= B; num++)
                {
                    string s = num.ToString();
                    
                    List<int> numlist = new List<int>();
                    for (int j = 0; j < s.Length - 1; j++)
                    {
                        string s2 = s.Substring(j + 1, s.Length - j - 1) + s.Substring(0, j+1);
                        int num2 = int.Parse(s2);

                        if ((num2 > num) && (num2 <= B) && (!numlist.Contains(num2)))
                        {
                            count++;
                            numlist.Add(num2);
                        }
                    }
                }
                Console.WriteLine("Round " + i);
                newlines.Add("Case #" + (i + 1).ToString() + ": " + count.ToString());
            }
            funcs.WriteLines(@"C-large.out", newlines);
        }
    }
}
