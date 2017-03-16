using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Pogo
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] x = File.ReadAllLines("input.in");
            File.Delete("output.txt");
            long count = 1;
            for (int i = 0; i < Convert.ToInt16(x[0]); i++)
            {
                long[] num = x[count].Split(' ').Select(s => Convert.ToInt64(s)).ToArray();

                string z = Solve(num[0], num[1]);
                count = count + 1;
                string outputString = String.Format("Case #{0}: {1}" + Environment.NewLine, i + 1, z);
                File.AppendAllText("output.txt", outputString);
            }
        }

        private static string Solve(long p, long p_2)
        {
            StringBuilder result= new StringBuilder();
            long jump = 1, x =0, y =0;
            while (x != p || y != p_2)
            {
                if (x != p)
                {
                    if (p > 0)
                    {
                        if (x + jump <= p)
                        {
                            x = x + jump;
                            jump++;
                            result.Append('E');
                        }
                        else
                        {
                            x = x - jump;
                            jump++;
                            result.Append('W');
                        }
                    }
                    else
                    {
                        if (x + jump <= p)
                        {
                            x = x + jump;
                            jump++;
                            result.Append('E');

                        }
                        else
                        {
                            x = x - jump;
                            jump++;
                            result.Append('W');
                        }
                    }
                }
                else
                {
                    if (p_2 > 0)
                    {
                        if (y + jump <= p_2)
                        {
                            y = y + jump;
                            jump++;
                            result.Append('N');
                        }
                        else
                        {
                            y = y - jump;
                            jump++;
                            result.Append('S');
                        }
                    }
                    else
                    {
                        if (y + jump <= p_2)
                        {
                            y = y + jump;
                            jump++;
                            result.Append('N');

                        }
                        else
                        {
                            y = y - jump;
                            jump++;
                            result.Append('S');
                        }
                    }
                }
 
            }
            if (result.Length > 500)
            {
                throw new Exception("Too Long");
            }
            return result.ToString();
        }
    }
}
