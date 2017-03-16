using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodejamDiamondInheritance
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("input.txt");
            StreamWriter sw = new StreamWriter("output.txt");

            int T = Convert.ToInt32(sr.ReadLine());

            for (int tt = 0; tt < T; tt++)
            {
                List<int> repeated = new List<int>();
                List<int> comesofar = new List<int>();
                Dictionary<int, List<int>> classes = new Dictionary<int, List<int>>();
                int N = Convert.ToInt32(sr.ReadLine());
                for (int n = 0; n < N; n++)
                {
                    classes.Add(n + 1, new List<int>());
                    String l = sr.ReadLine();
                    String[] line = l.Split(' ');
                    int relations = Convert.ToInt32( line[0] );
                    for (int r = 0; r < relations; r++)
                    {
                        int element = Convert.ToInt32(line[r+1]);
                        classes[(n + 1)].Add(element);
                        if (comesofar.Contains(element))
                            repeated.Add(element);
                        else
                            comesofar.Add(element);
                    }
                }

                bool diamond = false;
                //For all repeats
                for (int r = 0; r < repeated.Count; r++)
                {
                    int element = repeated[r];
                    int position = 0;
                    List<int> childs = new List<int>();
                    for (int n = 0; n < N; n++)
                    {
                        if (classes[(n+1)].Contains(element))
                        {
                            childs.Add(n + 1);
                        }
                    }
                    while (position < childs.Count)
                    {
                        element = childs[position];
                        for (int n = 0; n < N; n++)
                        {
                            if (classes[(n + 1)].Contains(element))
                            {
                                if (childs.Contains(n + 1))
                                {
                                    position = childs.Count;
                                    diamond = true;
                                    sw.WriteLine("Case #"+ (tt+1) +": Yes");
                                    break;
                                }
                                else
                                    childs.Add(n + 1);
                            }
                        }
                        position++;
                    }
                    if (diamond) break;
                }

                if (!diamond)
                    sw.WriteLine("Case #" + (tt + 1) + ": No");
            }

            sw.Close();
            sr.Close();
        }
    }
}
