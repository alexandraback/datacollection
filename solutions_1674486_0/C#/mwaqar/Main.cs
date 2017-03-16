using System;
using System.IO;
using System.Collections.Generic;

namespace ProblemA
{
	class MainClass
	{
		public static StreamReader sr;
		public static StreamWriter sw;
		public static List<List<int>> paths, l;
		public static List<int> tpath;
		
		public static void find(int a)
		{
			tpath.Add(a);
			
			if(l[a].Count > 0)
			{
				for(int i=0; i<l[a].Count; i++)
				{
					if(!tpath.Contains(l[a][i]))
						find(l[a][i]);
				}
			}
			else
			{
				paths.Add(tpath);
				
				tpath = new List<int>();
				for(int i=0; i<paths[paths.Count-1].Count; i++)
					tpath.Add(paths[paths.Count-1][i]);
			}
			
			tpath.RemoveAt(tpath.Count-1);
		}
		
		public static void solve()
		{
			l = new List<List<int>>();
			
			int n = Convert.ToInt32(sr.ReadLine());
			
			for(int i=0; i<n; i++)
			{
				String[] splits = sr.ReadLine().Split(' ');
				int c = Convert.ToInt32(splits[0]);
				List<int> l2 = new List<int>();
				
				for(int j=0; j<c; j++)
				{
					l2.Add(Convert.ToInt32(splits[j+1])-1);
				}
				
				l.Add(l2);
			}
			
			bool diamond = false;
				
			for(int i=0; (i<n) && (!diamond); i++)
			{
				paths = new List<List<int>>();
				paths.Clear();
				
				tpath = new List<int>();
				
				find(i);
				if(paths.Count == 1)
					continue;
				else
				{
					for(int m=0; (m<paths.Count) && (!diamond); m++)
					{
						for(int j=0; (j<paths.Count) && (!diamond); j++)
						{
							if(m == j)
								continue;
							
							int index = 1;
							
							for(int k=1; (k<paths[m].Count) && (k<paths[j].Count); k++)
							{
								if(paths[m][k] != paths[j][k])
								{
									index = k;
									break;
								}
							}
							
							for(int k=index; (k<paths[m].Count) && (!diamond); k++)
							{
								for(int o=index; (o<paths[j].Count) && (!diamond); o++)
								{
									if(paths[m][k] == paths[j][o])
										diamond = true;
								}
							}
						}
					}
				}
			}
			
			if(diamond)
				sw.WriteLine("Yes");
			else
				sw.WriteLine("No");
		}
		
		public static void Main(string[] args)
		{
			sr = new StreamReader("A-small-attempt2.in");
			sw = new StreamWriter("output.out");
			
			int tc = Convert.ToInt32(sr.ReadLine());
			
			for(int i_tc = 0; i_tc < tc; i_tc++)
			{
				sw.Write("Case #" + (i_tc+1) + ": ");
				solve();	
			}
			
			sr.Close();
			sw.Close();
		}
	}
}
