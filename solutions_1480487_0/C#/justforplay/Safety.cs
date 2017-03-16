using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Safety
{
    class Safety
    {
        static void Main(string[] args)
        {
            int t;
            using (StreamWriter sw = new StreamWriter(args[1]))
            {
                using (StreamReader sr = new StreamReader(args[0]))
                {
                    string tStr = sr.ReadLine();
                    t = int.Parse(tStr);

                    for (int i = 0; i < t; i++)
                    {
                        string numStr = sr.ReadLine();
                        string[] nums = numStr.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);
                        int n = int.Parse(nums[0]);
                        double total = 0;
                        int[] original = new int[n];
                        List<int> inputs = new List<int>();
                        for (int j = 0; j < n; j++)
                        {
                            original [j] = int.Parse(nums[j+1]);
                            total += original[j];
                            inputs.Add(original[j]);
                        }

                        inputs.Sort();
                        double[] acc = new double[n];

                        double left = 1;
                        for (int j = 1; j < n; j++)
                        {
                            if (1.0 * inputs[j - 1] + total * left * 1.0 / j < 1.0 * inputs[j])
                            {
                                for (int jj = 0; jj < j; jj++)
                                {
                                    acc[jj] += left/j;
                                }
                                left = 0;
                                break;
                            }

                            double avg = 1.0 * (inputs[j] - inputs[j -1]) / total;
                            left -= avg * j;
                            for (int jj = 0; jj < j; jj++)
                            {
                                acc[jj] += avg;
                            }
                        }

                        if (left > 0)
                        {
                            for (int jj = 0; jj < n; jj++)
                            {
                                acc[jj] += left/n;
                            }
                        }

                        if (i > 0)
                        {
                            sw.WriteLine();
                        }

                        sw.Write("Case #" + (i + 1) + ": ");

                        for (int j = 0; j < n; j++)
                        {
                            if (j > 0)
                            {
                                sw.Write(' ');
                            }

                            for (int jj = 0; jj < n; jj++)
                            {
                                if (original[j] == inputs[jj])
                                {
                                    sw.Write(Math.Round(acc[jj] * 100, 6));
                                    break;
                                }
                            }
                        }

                        

                    }
                }
            }
        }

    }
}
