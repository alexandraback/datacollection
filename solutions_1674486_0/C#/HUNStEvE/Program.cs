using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace _1
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;

            int T = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                string line = Console.ReadLine();
                string[] s = line.Split(new char[] { ' ' });
                int N = Int32.Parse(s[0]);

                Dictionary<int, HashSet<int>> classInheritsFrom = new Dictionary<int, HashSet<int>>();
                for (int j = 0; j < N; ++j)
                {
                    int thisclass = j + 1;
                    string line2 = Console.ReadLine();
                    string[] s2 = line2.Split(new char[] { ' ' });
                    int M = Int32.Parse(s2[0]);
                    if (!classInheritsFrom.ContainsKey(thisclass))
                    {
                        classInheritsFrom.Add(thisclass, new HashSet<int>());
                    }
                    for (int k = 0; k < M; ++k)
                    {
                        int inheritsfrom = Int32.Parse(s2[k + 1]);                                               
                        classInheritsFrom[thisclass].Add(inheritsfrom);
                    }
                }



                Dictionary<int, HashSet<int>> classLongInheritsFrom = new Dictionary<int, HashSet<int>>();
                Dictionary<int, HashSet<int>> classLongInheritsFromClosed = new Dictionary<int, HashSet<int>>();                
                foreach (int clas in classInheritsFrom.Keys)
                {
                    classLongInheritsFrom.Add(clas, new HashSet<int>());
                    classLongInheritsFromClosed.Add(clas, new HashSet<int>());
                    foreach (int inher in classInheritsFrom[clas])
                    {
                        classLongInheritsFrom[clas].Add(inher);
                    }
                }

                bool addednew = false;
                bool founddiamond = false;

                do {
                    addednew = false;
                    founddiamond = false;

                    //add +1 level
                    foreach (int clas in classInheritsFrom.Keys)
                    {
                        HashSet<int> addtemp = new HashSet<int>();
                        foreach (int inher in classLongInheritsFrom[clas])
                        {                            
                            if (!classLongInheritsFromClosed[clas].Contains(inher))
                            {
                                foreach (int newinher in classInheritsFrom[inher])
                                {
                                    if (!classLongInheritsFrom[clas].Contains(newinher) && !addtemp.Contains(newinher))
                                    {
                                        addednew = true;
                                        addtemp.Add(newinher);                                        
                                    }
                                    else
                                    {
                                        founddiamond = true;
                                    }
                                }
                                classLongInheritsFromClosed[clas].Add(inher);
                            }                            
                        }
                        classLongInheritsFrom[clas].UnionWith(addtemp);

                    }                    

                } while (addednew && !founddiamond);

                if (founddiamond)
                {
                    Console.WriteLine("Case #" + (i + 1) + ": Yes");
                }
                else
                {
                    Console.WriteLine("Case #" + (i + 1) + ": No");
                }
              
            } 
        }
    }
}
