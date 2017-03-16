using System;
using System.Collections.Generic;

namespace GCJ12q2
{
	class Program
	{
		
		void solveCase(int number){
			string[] ins=Console.ReadLine().Split(new char[0],StringSplitOptions.RemoveEmptyEntries);
			int min=int.Parse(ins[0]),max=int.Parse(ins[1]),count=0;
			for(int x=min;x<=max;++x){
				foreach(int v in d[x])if(v<=max){++count;
					//Console.Write(String.Format("({0},{1}) ",x,v)		);
				}
			}
			Console.WriteLine(String.Format("Case #{0}: {1}",number,count));
		}
		List<List<int> > d=new List<List<int> >();
			
		void solve(){
			//1 ≤ A ≤ B ≤ 2000000.
			
			d.Add(new List<int>());
			
			for(int i=1;i<=2000000;++i){
				string s=i.ToString();
				List<int> lst=new List<int>();
				for(int j=1;j<s.Length;++j){
					string ns=s.Substring(j)+s.Substring(0,j);
					if(ns.CompareTo(s)>0){
						int v=int.Parse(ns);
						if(lst.IndexOf(v)==-1)
							lst.Add(int.Parse(ns));
					}
				}
				d.Add(lst);				
			}
			
			int n=int.Parse(Console.ReadLine());
			for(int i=1;i<=n;++i)
				solveCase(i);
		}
		
		public static void Main(string[] args)
		{
			new Program().solve();
		}
	}
}