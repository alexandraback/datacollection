using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Google_Code_Jam
{
    public static class Problem_D
    {
        
        public static void Run()
        {
            List<string> output = new List<string>();

            using (StreamReader sr = File.OpenText(@"E:\My Documents\Google Drive\Coding\Google Code Jam\Google Code Jam\D-small-attempt0.in"))
            {
                int testCases = int.Parse(sr.ReadLine());
                for (int caseNum = 1; caseNum <= testCases; caseNum++)
                {
                    int[] testCase = sr.ReadLine().Split(' ').Select(int.Parse).ToArray();
                    int x = testCase[0];
                    int rows = testCase[1];
                    int cols = testCase[2];

                    if (rows > cols)
                    {
                        int tmp = rows;
                        rows = cols;
                        cols = tmp;
                    }

                    bool rWin = false;

                    
                    if (rows*cols % x != 0)
                    {
                        rWin = true;
                    }
                    else if (x > rows + cols - 1)
                    {
                        rWin = true;
                    }
                    else if (x == 1)
                    {
                        rWin = false;
                    }
                    else if (x == 2)
                    {
                        rWin = false;
                    }
                    else if (x == 3)
                    {
                        if (rows >= 2 && cols >= 3)
                        {
                            rWin = false;
                        }
                        else
                        {
                            rWin = true;
                        }
                    }
                    else if (x == 4)
                    {
                        if (rows >= 3 && cols >= 4)
                        {
                            rWin = false;
                        }
                        else
                        {
                            rWin = true;
                        }
                    }
                    else
                    {
                        throw new Exception("Shouldn't happen");
                    }
                    //else if (x == 5)
                    //{
                    //    if (rows >= 4 && cols >= 4)
                    //    {
                    //        rWin = false;
                    //    }
                    //    else
                    //    {
                    //        rWin = true;
                    //    }
                    //}
                    //else if (x == 6)
                    //{
                    //    if (rows >= 4 && cols >= 4)
                    //    {
                    //        rWin = false;
                    //    }
                    //    else
                    //    {
                    //        rWin = true;
                    //    }
                    //}
                    //else if (x >= 7)
                    //{
                    //    rWin = true;
                    //}


                    output.Add(String.Format("Case #{0}: {1}", caseNum, rWin ? "RICHARD" : "GABRIEL"));
                }
            }


            using (StreamWriter sw = File.CreateText(@"E:\My Documents\Google Drive\Coding\Google Code Jam\Google Code Jam\D-small-attempt0.out"))
            {
                foreach (var line in output)
                {
                    sw.WriteLine(line);
                }
            }
        }


        private static void Test()
        {
            
        }
    }
}
