using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GTran
{
    class Diamond
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
                        int n = int.Parse(numStr);
                        int[,] path = new int[n, n];
                        for (int j = 0; j < n; j++)
                        {
                            for (int jj = 0; jj < n; jj++)
                            {
                                path[j, jj] = 0;
                            }
                        }


                        for (int j = 0; j < n; j++)
                        {
                            numStr = sr.ReadLine();
                            string[] nums = numStr.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                            int m = int.Parse(nums[0]);
                            for (int jj = 0; jj < m; jj++)
                            {
                                int pt = int.Parse(nums[jj + 1]);
                                path[j, pt - 1] = 1;
                            }
                        }

                        bool found = false;
                        for (int j = 0; j < n; j++)
                        {
                            if (Try(j, path, n))
                            {
                                found = true;
                                break;
                            }
                        }

                        sw.WriteLine("Case #" + (i + 1) + ": " + (found ? "Yes" : "No"));
                    }
                }
            }
        }

        private static bool Try(int startPt, int[,] path, int n)
        {
            List<int> reachablePoints = new List<int>();
            List<int> pointsToTry = new List<int>();
            pointsToTry.Add(startPt);

            while (pointsToTry.Count > 0)
            {
                int pt = pointsToTry[0];
                pointsToTry.RemoveAt(0);

                for (int i = 0; i < n; i++)
                {
                    if (path[pt, i] == 1)
                    {
                        if (reachablePoints.Contains(i))
                        {
                            return true;
                        }

                        reachablePoints.Add(i);
                        pointsToTry.Add(i);
                    }
                }
            }

            return false;
        }
    }
}