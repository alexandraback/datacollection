using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.Text.RegularExpressions;


namespace GoogleCodeJam
{
    public class ATestCase : TestCase
    {       
        public override void Execute()
        {
            string[] tmp = this.input.Split('\n');

            int classes = int.Parse(tmp[0]);
            bool[,] matrix = new bool[classes, classes];

            List<int> manyFathers = new List<int>();
            Dictionary<int, List<int>> fathers = new Dictionary<int, List<int>>();

            List<int> manyChilds = new List<int>();

            int[] childsTmp = new int[classes];

            for (int i = 1; i < tmp.Length; i++)
            {
                string[] t = tmp[i].Split(' ');
                List<int> inh = new List<int>();
                
                for (int s = 1; s < t.Length; s++)
                    inh.Add(int.Parse(t[s]) - 1);

                if (inh.Count > 0)
                {
                    if (inh.Count > 1)
                    {
                        manyFathers.Add(i - 1);
                        fathers.Add(i - 1, inh);
                    }

                    for (int j = 0; j < inh.Count; j++)
                    {
                        matrix[i - 1, inh[j]] = true;
                        childsTmp[inh[j]]++;
                    }
                }
            }

            for (int i = 0; i < childsTmp.Length; i++)
            {
                if (childsTmp[i] > 1)
                    manyChilds.Add(i);
            }


            if (manyFathers.Count == 0 || manyChilds.Count == 0)
                this.output = "No";
            else
            {
                bool f = false;

                foreach (int a in manyFathers)
                    foreach (int b in manyChilds)
                        if (FindTwoPaths(fathers[a], b, matrix) == true)
                        {
                            f = true;
                            break;
                        }

                if (f)
                    this.output = "Yes";
                else
                    this.output = "No";
            }
        }

        public static bool FindTwoPaths(List<int> a, int b, bool[,] matrix)
        {
            int paths = 0;

            foreach (int i in a)
            {
                if (IsConnected(i, b, matrix))
                    paths++;

                if (paths > 1)
                    break;
            }

            if (paths > 1)
                return true;
            else
                return false;
        }

        public static bool IsConnected(int a, int b, bool[,] matrix)
        {
            if (a == b)
                return true;

            List<int> visited = new List<int>();
            bool f = false;

            for (int i = 0; i < matrix.GetLength(1); i++)
            {
                if (matrix[a, i] == true)
                {
                    if (i == b)
                    {
                        f = true;
                        break;
                    }
                    else
                    {
                        if (IsConnected(i, b, matrix) == true)
                        {
                            f = true;
                            break;
                        }
                        else
                            visited.Add(i);
                    }
                }
            }

            if (f)
                return true;
            else
                return false;
        }
    }
}
