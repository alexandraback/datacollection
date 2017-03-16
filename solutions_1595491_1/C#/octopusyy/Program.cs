
using System;

namespace GCJ12q2
{
	class Program
	{
		
		void solveCase(int number){
			string[] ins=Console.ReadLine().Split(new char[0],StringSplitOptions.RemoveEmptyEntries);
			int N=int.Parse(ins[0]),S=int.Parse(ins[1]),p=int.Parse(ins[2]);
			int[] a=new int[N];
			
			for(int i=3;i<ins.Length;++i){
				a[i-3]=int.Parse(ins[i]);
			}
			Array.Sort(a);
			int count=0,poss=0;
			for(int i=0;i<N;++i){
				
				if(a[i]<2){
					if(p<=a[i])++count;
					continue;
				}
				if(a[i]>28){
					++count;
					continue;
				}
				
				int nsmax=a[i]/3;
				if(a[i]%3!=0) ++nsmax;
				
				int smax=a[i]/3+1;
				if(a[i]%3==2) ++smax;
				
				if(smax<p){
					//impossible
				}else if(nsmax>=p){
					++count;
				}else{
					++poss;
				}
			}
			if(poss>S)poss=S;
			Console.WriteLine(String.Format("Case #{0}: {1}",number,count+poss));
		}
		
		void solve(){
			int n=int.Parse(Console.ReadLine());
			for(int i=0;i<n;++i)
				solveCase(i+1);
		}
		
		public static void Main(string[] args)
		{
			new Program().solve();
		}
	}
}