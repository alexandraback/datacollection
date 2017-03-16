using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GTran.Round1
{
    class RETVal
    {
        public int[] curFlag;
        public int[] difFlag;
    }

    class EqualSum
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
                        string[] nums = numStr.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                        int n = int.Parse(nums[0]);
                        double total = 0;
                        int[] original = new int[n];
                        List<int> inputs = new List<int>();
                        for (int j = 0; j < n; j++)
                        {
                            original[j] = int.Parse(nums[j + 1]);
                            total += original[j];
                            inputs.Add(original[j]);
                        }

                        inputs.Sort();

                        int[] flag = new int[n];

                        Dictionary<int, List<int[]>> curVals = new Dictionary<int, List<int[]>>();
                        RETVal retVal = Try(inputs, flag, 0, n, curVals);

                        sw.WriteLine("Case #" + (i + 1) + ":");

                        if (retVal != null)
                        {
                            bool hasOutput = false;
                            for (int j = 0; j< n; j++)
                            {
                                if (retVal.curFlag[j] == 1)
                                {
                                    if (hasOutput)
                                    {
                                        sw.Write(' ');
                                    }
                                    hasOutput = true;
                                    sw.Write(inputs[j]);
                                }
                            }
                            sw.WriteLine();

                            hasOutput = false;
                            for (int j = 0; j < n; j++)
                            {
                                if (retVal.difFlag[j] == 1)
                                {
                                    if (hasOutput)
                                    {
                                        sw.Write(' ');
                                    }
                                    hasOutput = true;
                                    sw.Write(inputs[j]);
                                }
                            }    
                            sw.WriteLine();                        

                        }
                        else
                        {
                            sw.WriteLine("Impossible");
                        }

                    }
                }
            }


        }

        private static RETVal Try(List<int> inputs, int[] flag, int lev, int n, Dictionary<int, List<int[]>> curVals)
        {
            if (lev >= n)
            {
                int cur = 0;
                for (int i = 0; i < n; i++)
                {
                    if (flag[i] == 1)
                    {
                        cur += inputs[i];
                    }
                }

                if (cur == 0)
                {
                    return null;
                }

                if (curVals.ContainsKey(cur))
                {
                    int[] stored = null;                    
                    bool allDif = true;
                    List<int[]> storedList = curVals[cur];
                    for (int si = 0; si < storedList.Count; si++)
                    {
                        stored = storedList[si];
                        for (int i = 0; i < n; i++)
                        {
                            if (flag[i] == 1 && stored[i] == 1)
                            {
                                allDif = false;
                                break;
                            }
                        }
                        if (allDif)
                        {
                            break;
                        }
                    }

                    if (allDif)
                    {
                        return new RETVal()
                        {
                            curFlag = flag,
                            difFlag = stored
                        };
                    }
                }

                int[] newFlag = new int[n];
                for (int i = 0; i < n; i++)
                {
                    newFlag[i] = flag[i];
                }

                if (!curVals.ContainsKey(cur))
                {
                    curVals.Add(cur, new List<int[]>());
                }
                curVals[cur].Add(newFlag);

                return null;
            }

            flag[lev] = 0;
            RETVal retVal;
            retVal = Try(inputs, flag, lev + 1, n, curVals);
            if (retVal != null)
            {
                return retVal;
            }

            flag[lev] = 1;
            return Try(inputs, flag, lev + 1, n, curVals);
        }
    }
}
