using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Linq;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            Exercise3();

            Console.WriteLine("Press any key to continue...");
            Console.ReadKey();
        }

        static void Exercise1()
        {
            List<string> lines = Utils.GetStringList("input.txt");
            int numofCases = Convert.ToInt32(lines[0]);

            List<string> outputs = new List<string>();

            for (int i = 1; i <= numofCases; i++)
            {
                string[] arr = lines[i].Split(null);
                int maxShynessLevel = Convert.ToInt32(arr[0]);
                string last = arr[1];

                bool flag = false;
                int totalAudience = 0;
                int added = 0;
                for (int j = 0; j < maxShynessLevel + 1; j++)
                {
                    char cNumofAudience = last[j];
                    int numofAudiene = Int32.Parse(cNumofAudience.ToString());
                    if (numofAudiene == 0)
                    {
                        flag = true;
                    }
                    else
                    {
                        if (flag == true)
                        {
                            added += Math.Max(0, j - totalAudience);
                            totalAudience += added;
                        }
                        totalAudience += numofAudiene;
                        flag = false;
                    }
                }

                outputs.Add("Case #"+ i +": " + added);
            }

            Utils.WriteFile(outputs, "output.txt");
        }


        static void Exercise2()
        {
            List<string> lines = Utils.GetStringList("B-large.in");
            //List<string> lines = Utils.GetStringList("input.txt");
            int numofCases = Convert.ToInt32(lines[0]);

            List<string> outputs = new List<string>();

            for (int i = 0; i < numofCases; i++)
            {
                int D = Int32.Parse(lines[2 * i + 1]);
                string[] arr = (lines[2 * i + 2]).Split(null);
                int[] arrInt = Array.ConvertAll(arr, s => int.Parse(s));

                List<int> myInts = new List<int>(arrInt);
                int minMinutes = 1000;
                int maxInt = myInts.Max();
                for (int j = 1; j <= maxInt; j++)
                {
                    int numofDivided = 0;
                    for (int k = 0; k < myInts.Count; k++)
                    {
                        int element = myInts[k];
                        if (element > j)
                        {
                            numofDivided += (int)Math.Ceiling(element / (float) j) - 1;
                        }
                    }

                    if (numofDivided + j < minMinutes)
                    {
                        minMinutes = numofDivided + j;
                    }
                }

                outputs.Add("Case #" + (i + 1) + ": " + minMinutes);
                Console.WriteLine("Testcase:" + (i + 1));
            }

            Utils.WriteFile(outputs, "2-output-2.txt");
        }


        static void Exercise3()
        {
            List<string> lines = Utils.GetStringList("C-small-attempt0.in");
            //List<string> lines = Utils.GetStringList("input.txt");
            int numofCases = Convert.ToInt32(lines[0]);

            List<string> outputs = new List<string>();

            for (int i = 0; i < numofCases; i++)
            {
                string LX = lines[2 * i + 1];
                string pattern = lines[2 * i + 2];
                string[] arr = LX.Split(null);
                Int64 L = Int64.Parse(arr[0]);
                Int64 X = Int64.Parse(arr[1]);

                char result = '1';
                int sign = 1;
                bool iOk = false, jOk = false, kOk = false;
                for (Int64 j = 0; j < X; j++)
                {
                    for (int k = 0; k < pattern.Length; k++)
                    {
                        char element = pattern[k];
                        result = Merge(result, element, ref sign);

                        if (sign == 1)
                        {
                            if (iOk == false && result == 'i')
                            {
                                iOk = true;
                                result = '1';
                            }
                            else if (iOk == true && jOk == false && result == 'j')
                            {
                                jOk = true;
                                result = '1';
                            }
                            else if (iOk == true && jOk == true && result == 'k' && k == pattern.Length - 1
                                && j == X - 1)
                            {
                                kOk = true;
                                result = '1';
                            }
                        }
                    }
                }

                string output = (iOk && jOk && kOk) ? "YES" : "NO";

                outputs.Add("Case #" + (i + 1) + ": " + output);
                Console.WriteLine("Testcase:" + (i + 1));
            }

            Utils.WriteFile(outputs, "3-output.txt");
        }

        private static char Merge(char a, char b, ref int sign)
        {
            if (a == '1')
            {
                return b;
            }

            if (b == '1')
            {
                return a;
            }

            if (a == b)
            {
                sign = -sign;
                return '1';
            }

            if (a == 'i' && b == 'j')
            {
                return 'k';
            }

            if (a == 'j' && b == 'i')
            {
                sign = -sign;
                return 'k';
            }

            if (a == 'i' && b == 'k')
            {
                sign = -sign;
                return 'j';
            }

            if (a == 'k' && b == 'i')
            {
                return 'j';
            }

            if (a == 'j' && b == 'k')
            {
                return 'i';
            }

            if (a == 'k' && b == 'j')
            {
                sign = -sign;
                return 'i';
            }

            return '1';
        }
    }
}
