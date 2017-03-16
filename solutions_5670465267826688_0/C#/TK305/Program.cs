using System;
using System.IO;
using System.Collections;

namespace CodeJamC
{
    class Program
    {
        public static bool Find(int[] int_code, int[,] qt, int L, long X)
        {
            long index = 0;
            int result = 1;
            int j;
            bool found_i = false;
            for (; index < L * X - 2; index++)
            {
                j = (int)(index % (long)L);
                result = (result > 0) ? qt[result, int_code[j]] : qt[result * (-1), int_code[j]] * (-1);
                if (result == 2)
                {
                    found_i = true;
                    break;
                }
            }
            if (!found_i)
                return false;
            else
            {
                result = 1;
                index++;
                do
                {
                    j = (int)(index % (long)L);
                    result = (result > 0) ? qt[result, int_code[j]] : qt[result * (-1), int_code[j]] * (-1);
                    index++;
                    if (result == 3)
                    {
                        result = 1;
                        long next_start = 0;
                        for (; index < L * X; index++)
                        {
                            j = (int)(index % (long)L);
                            result = (result > 0) ? qt[result, int_code[j]] : qt[result * (-1), int_code[j]] * (-1);
                            if (result == -3 && next_start == 0)
                                next_start = index + 1;
                        }
                        if (result == 4)
                            return true;
                        else
                        {
                            if (next_start == 0)
                                return false;
                            else
                            {
                                index = next_start;
                                result = 1;
                            }
                        }
                    }
                } while (index < L * X - 1);
            }
            return false;
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(new FileStream("C-small-attempt0.in", FileMode.Open));
            StreamWriter sw = new StreamWriter(new FileStream("C_small.out", FileMode.Create));
            string temp = sr.ReadLine();
            int[,] qt = new int[5, 5] { { 0, 0, 0, 0, 0 }, { 0, 1, 2, 3, 4 }, { 0, 2, -1, 4, -3 }, { 0, 3, -4, -1, 2 }, { 0, 4, 3, -2, -1 } };
            
            int test_num = int.Parse(temp);

            for (int i = 1; i < test_num + 1; i++)
            {
                temp = sr.ReadLine();
                string[] words = temp.Split(' ');

                int L = int.Parse(words[0]);
                long X = int.Parse(words[1]);

                string code = sr.ReadLine();
                string new_code = code.Replace('i', '2').Replace('j', '3').Replace('k', '4');
                int[] int_code = new int[L];

                for (int j = 0; j < L; j++)
                    int_code[j] = (int)Char.GetNumericValue(new_code[j]);

                if (Find(int_code, qt, L, X))
                    sw.WriteLine("Case #{0}: Yes", i);
                else
                    sw.WriteLine("Case #{0}: No", i);
            }
            sr.Close();
            sw.Close();
        }
    }
}
