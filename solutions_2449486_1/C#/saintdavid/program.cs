using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemB
{
    class program
    {
        public static void Main()
        {
            //List<string> lines = funcs.getInputDocs2(@"input.txt");
            List<string> lines = funcs.getInputDocs2(@"B-large.in");

            int num = int.Parse(lines[0]);
            int count = 1;
            List<string> outlines = new List<string>();
            for (int samples = 0; samples < num; samples++)
            {
                string[] words = lines[count].Split(' '); count++;
                int h = int.Parse(words[0]); int l = int.Parse(words[1]);
                int[,] matrix = new int[h, l];

                for (int i = 0; i < h; i++)
                {
                    string[] ht = lines[count].Split(' '); count++;
                    for (int j = 0; j < ht.Length; j++)
                        matrix[i, j] = int.Parse(ht[j]);
                }
                //Manipulating Begins
                //Cut, if one of them >= on all path
                bool PassNot = true;

                for (int i = 0; i < h; i++)
                    for (int j = 0; j < l; j++)
                        if (matrix[i, j] > 100) PassNot = false;

                if (PassNot)
                    for (int i = 0; i < h; i++)
                    {
                        for (int j = 0; j < l; j++)
                        {
                            int desire = matrix[i, j];

                            bool flag = true;
                            for (int k = 0; k < l; k++)
                                if (matrix[i, k] > desire)
                                {
                                    flag = false;
                                    break;
                                }

                            if (flag == true) continue;

                            flag = true;
                            for (int k = 0; k < h; k++)
                                if (matrix[k, j] > desire)
                                {
                                    flag = false;
                                    break;
                                }


                            if (flag == false)
                            {
                                PassNot = false;
                                break;
                            }
                        }
                        if (PassNot == false) break;
                    }

                string outline = "Case #" + (samples + 1).ToString() + ": ";
                if (PassNot) outline += "YES"; else outline += "NO";
                outlines.Add(outline);
            }
            funcs.WriteLines("output.txt", outlines);            
        }
    }
}
