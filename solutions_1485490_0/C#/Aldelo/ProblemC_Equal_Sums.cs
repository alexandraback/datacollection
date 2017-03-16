using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamQualificationRound2012Console
{
    class ProblemC_Box_Factory
    {

        public static void Run(string fname, string ofname)
        {
            string[] solution = ReadProblemA(fname);

            string[] output = new string[solution.Length];
            for (int i = 0; i < solution.Length; i++)
            {
                output[i] = String.Format("Case #{0}: {1}", i + 1, solution[i]);

                Console.Out.WriteLine(output[i]);

            }
            Helpers.IO.WriteOutput(ofname, output.Length, output);

            //Console.ReadLine();
        }

        public static string[] ReadProblemA(string fname)
        {
            string[] outputStr = null;
            int inputlength = 0;
            int count = 0;
            StreamReader fr = new StreamReader("..\\..\\" + fname);
            while (!fr.EndOfStream)
            {
                if (inputlength == 0) // read total case
                {
                    string s = fr.ReadLine();
                    inputlength = Convert.ToInt32(s);
                    outputStr = new string[inputlength];
                }
                else
                {
                    /*
                     *  3 3
                        10 1 20 2 25 3
                        10 2 30 3 20 1
                     */
                    string mntext = fr.ReadLine();
                    string[] linea = fr.ReadLine().Split(' ');
                    string[] lineb = fr.ReadLine().Split(' ');

                    BoxFactoryCase input = new BoxFactoryCase();

                    bool skip = true;
                    long tempItem = 0;
                    //line A
                    foreach (var item in linea)
                    {
                        if (skip)
                        {
                            tempItem = Convert.ToInt64(item);
                            skip = false;
                        }
                        else
                        {
                            input.A.Add(new Product { Number = tempItem, Type = Convert.ToInt32(item) });
                            tempItem = 0;
                            skip = true;
                            
                        }                        
                    }

                    skip = true;
                    tempItem = 0;
                    //line B
                    foreach (var item in lineb)
                    {
                        if (skip)
                        {
                            tempItem = Convert.ToInt64(item);
                            skip = false;
                        }
                        else
                        {
                            input.B.Add(new Product { Number = tempItem, Type = Convert.ToInt32(item) });
                            tempItem = 0;
                            skip = true;

                        }
                    }

                    outputStr[count] = AnswerOfCase(input);

                    ++count;
                }
            }
            fr.Close();
            return outputStr;
        }

        public class BoxFactoryCase
        {
            public List<Product> A = new List<Product>();
            public List<Product> B = new List<Product>();
        }

        public class Product
        {
            public long Number { get; set; }
            public int Type { get; set; }
        }

        private static string AnswerOfCase(BoxFactoryCase c)
        {
            long max = findMax(c.A,0, c.B,0);
            return "" + max;
        }

        private static long findMax(List<Product> a, int ai, List<Product> b, int bi)
        {
            long count = 0;
            if (ai >= a.Count || bi >= b.Count)
            {
                return count;
            }
            if (a[ai].Type == b[bi].Type)
            {
                long minCount = a[ai].Number < b[bi].Number ? a[ai].Number : b[bi].Number;
                count += minCount;
                if (a[ai].Number == b[bi].Number)
                {
                    count += findMax(a, ai + 1, b, bi + 1);
                }
                else if (a[ai].Number < b[bi].Number)
                {
                    List<Product> newb = new List<Product>();
                    foreach (var item in b)
                    {
                        newb.Add(new Product { Number = item.Number, Type = item.Type });
                    }

                    newb[bi].Number = newb[bi].Number - a[ai].Number;

                    count += findMax(a, ai + 1, newb, bi);
                }
                else
                {
                    List<Product> newa = new List<Product>();
                    foreach (var item in a)
                    {
                        newa.Add(new Product { Number = item.Number, Type = item.Type });
                    }

                    newa[ai].Number = newa[ai].Number - b[bi].Number;

                    count += findMax(newa, ai, b, bi + 1);
                }
            }
            else
            {
                long way1 = findMax(a,ai + 1, b, bi);
                long way2 = findMax(a, ai, b, bi + 1 );
                if (way1 < way2)
                {
                    count += way2;
                }
                else
                {
                    count += way1;
                }
            }

            return count;
        }

    }
}
