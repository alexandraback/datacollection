using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GTran
{
    class Diamond1
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
                            if (Try(j, path, n, new List<int>()))
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

        private static bool Try(int point, int[,] path, int n, List<int> reachedPoints)
        {
            for (int i = 0; i < n ; i++)
            {
                if (path[point, i] == 1)
                {
                    if (reachedPoints.Contains(i))
                    {
                        return true;
                    }

                    reachedPoints.Add(i);
                    if (Try(i, path, n, reachedPoints))
                    {
                        return true;
                    }
                }
            }

            return false;
        }
    }
}
