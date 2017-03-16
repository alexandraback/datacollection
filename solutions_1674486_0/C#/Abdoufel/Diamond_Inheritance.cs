using System;
using System.Data;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;
using System.Collections.Generic;

namespace Diamond_Inheritance
{
    public class Diamond_Inheritance
    {
	
		[STAThread]
        static void Main(String[] args)
        {
			if (args.Length == 0)
			{
				Console.WriteLine("Error! No input file.");				
			}
			else
			{
				String inp = args[0];
				Diamond_Inheritance bt = new Diamond_Inheritance();
				bt.calculate (inp, Path.GetFileNameWithoutExtension(inp)+".out");
			}
            
        }
		
		private void calculate(String infilename, String outfilename)
        {
            System.IO.StreamReader SR;
			StreamWriter sw = new StreamWriter(outfilename);
			String S;

			SR = File.OpenText(infilename);
            S = SR.ReadLine();

            int tests = int.Parse(S);
            
            int N, n;

            ArrayList graph = new ArrayList();
            

            for (int i = 0; i < tests; i++)
            {
                graph.Clear();
                S = SR.ReadLine();

                N = int.Parse(readWord(S));

                for (int j = 0; j < N; j++)
                {
                    S = SR.ReadLine();
                    ArrayList temp = new ArrayList();
                    n = int.Parse(readWord(S));

                    S = removeWord(S);

                    for (int k = 0; k < n; k++)
                    {
                        temp.Add(int.Parse(readWord(S)));
                        S = removeWord(S);
                    }
                    graph.Add(temp);
                }                
				sw.WriteLine("Case #" + (i + 1) + ": "+ compute(graph));
            }
            SR.Close();
			sw.Close();
        }
		
		private string compute(ArrayList graph)
        {
            ArrayList paths = new ArrayList();

            foreach (ArrayList node in graph)
            {
                paths.Clear();
                if (node.Count > 1)
                {
                    foreach (int dest in node)
                    {
                        paths.Add(getPath(graph, dest));
                    }

                    for (int i = 0; i < paths.Count -1; i++)
                    {
                        for (int j = i+1; j < paths.Count; j++)
                        {
                            if (((HashSet<int>)paths[i]).Intersect((HashSet<int>)paths[j]).Count() > 0)
                            {
                                return "Yes";
                            }
                        }
                    }
                }                
            }

            return "No";
        }


        private HashSet<int> getPath(ArrayList graph, int dest)
        {
            HashSet<int> paths = new HashSet<int>();

            HashSet<int> temp = new HashSet<int>();
            HashSet<int> temp1 = new HashSet<int>();

            temp.Add(dest);

            ArrayList Dest = null;

            while (temp.Count > 0)
            {
                paths.UnionWith(temp);

                temp1.Clear();

                foreach (int n in temp)
                {
                    Dest = (ArrayList)graph[n-1];

                    foreach (int x in Dest)
                    {
                        if (!paths.Contains(x))
                        {
                            temp1.Add(x);
                        }
                    }
                }
                temp.Clear();
                temp.UnionWith(temp1);
            }            

            return paths;
        }


		
		public static String readWord(String S)
        {
            if (S.Contains(' '))
            {
                return S.Substring(0, S.IndexOf(' ')).Trim();
            }
            else
            {
                return S;
            }
        }

        public static String removeWord(String S)
        {
            if (S.Contains(' '))
            {
                return S.Substring(S.IndexOf(' ')).Trim();
            }
            else
            {
                return S;
            }
        }         
    }
 
}