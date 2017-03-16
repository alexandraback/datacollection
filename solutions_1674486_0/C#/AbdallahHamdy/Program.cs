using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam1B
{
    class C
    {
        public int classIndex;
        public List< Int16> anceClasses;
        public C()
        {
        }
        public C(List<string> pa,int ind)
        {
            classIndex = ind;
            anceClasses = new List<Int16>();
            for (int i = 0; i < pa.Count; i++)
                anceClasses.Add(Convert.ToInt16(pa[i]));         
        }
        
    }
   
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("input.txt");
            StreamWriter wr = new StreamWriter("output.txt");
            int T = Convert.ToInt32(sr.ReadLine());
            for (int t = 0; t < T; t++)
            {

                int N = Convert.ToInt32(sr.ReadLine());
                C[] classes = new C[N + 1];
                for (int i = 0; i < N; i++)
                {
                    List<string> par = new List<string>();
                    par.AddRange(sr.ReadLine().Split(' '));
                    int ind = Convert.ToInt32(par[0]);
                    classes[i + 1] = new C(par.GetRange(1, par.Count - 1), i + 1);
                }
                bool diamoned = false;
                for (int i = 1; i < classes.Length; i++)
                {
                    List<Int16> inher = new List<Int16>();
                    inher.AddRange(classes[i].anceClasses);
                    for (int j = 0; j < inher.Count; j++)
                    {
                        for (int a = 0; a < classes[inher[j]].anceClasses.Count; a++)
                        {
                            if (inher.Contains(classes[classes[i].anceClasses[j]].anceClasses[a]))
                            {
                                diamoned = true;
                                break;
                            }
                            else
                            {
                                inher.Add(classes[classes[i].anceClasses[j]].anceClasses[a]);

                            }
                        }
                        if (diamoned)
                            break;
                    }
                    if (diamoned)
                        break;
                }
                if (diamoned)
                    wr.WriteLine("Case #" + (t + 1) + ": Yes");
                else
                    wr.WriteLine("Case #" + (t + 1) + ": No");

            }
            wr.Close();
        }
     
    }
    
}
