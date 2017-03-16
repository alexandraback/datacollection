using System;
using System.IO;

namespace CodeJam1
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(new FileStream("A-small-attempt0.in", FileMode.Open));
            StreamWriter sw = new StreamWriter(new FileStream("A_small.out", FileMode.Create));
            string temp = sr.ReadLine();

            int test_num = int.Parse(temp);

            for (int i = 1; i < test_num+1; i++)
            {
                temp = sr.ReadLine();
                string[] words = temp.Split(' ');

                int max_shy = int.Parse(words[0]);

                int people_count = (int)Char.GetNumericValue(words[1][0]);
                int total_required = 0;
                int temp_required = 0;

                for (int j = 1; j < max_shy + 1; j++)
                {
                    int num = (int)Char.GetNumericValue(words[1][j]);
                    if (num != 0)
                    {
                        if (j > people_count)
                        {
                            temp_required = j - people_count;
                            people_count += (num + temp_required);
                            total_required += temp_required;
                        }
                        else
                        {
                            people_count += num;
                        }
                    }

                }
                sw.WriteLine("Case #{0}: {1}", i, total_required);
            }
            sw.Close();
            sr.Close();
        }
    }
}
