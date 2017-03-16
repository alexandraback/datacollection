using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ_R1B
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines(@"..\..\input.txt");

            StringBuilder output = new StringBuilder();

            int countOfTests = int.Parse(input[0]);
            for (int i = 0; i < countOfTests; i++)
            {
                string[] test = input[i + 1].Split(' ');

                int n = int.Parse(test[0]);
                double[] a = new double[n];
                double[] res = new double[n];


                for (int j = 0; j < n; j++)
                {
                    a[j] = double.Parse(test[j + 1]);
                    res[j] = -1;
                }

                int shift = 0;
                while (true)
                {
                    double s = 0;
                    for (int j = 0; j < n; j++)
                        if (res[j] == -1)
                            s += a[j];
                    if (s == 0)
                    {
                        double p = 100 / (n * 1.0 - shift * 1.0);
                        for (int j = 0; j < n; j++)
                            if (res[j] == -1)
                                res[j] = p;
                        break;
                    }

                    double d = (2 * s) / (n * 1.0 - shift * 1.0);

                    bool isNew = false;
                    for (int j = 0; j < n; j++)
                    {
                        if (res[j] == -1)
                        {
                            double result = ((d - a[j]) / s) * 100.0;
                            if (result < 0)
                            {
                                res[j] = 0;
                                shift++;
                                isNew = true;
                            }
                        }
                    }

                    if (!isNew)
                    {
                        for (int j = 0; j < n; j++)
                            if (res[j] == -1)
                            {
                                res[j] = ((d - a[j]) / s) * 100.0;
                            }
                        break;
                    }

                }
                StringBuilder str = new StringBuilder();

                str.Append(string.Format("Case #{0}: ", i + 1));
                for (int j = 0; j < n; j++)
                    if (j == n - 1)
                        str.Append(string.Format("{0:0.00000}", res[j]));
                    else
                        str.Append(string.Format("{0:0.00000} ", res[j]));

                output.AppendLine(str.ToString());
            }

            File.WriteAllText(@"..\..\output.txt", output.ToString());
        }
    }
}
