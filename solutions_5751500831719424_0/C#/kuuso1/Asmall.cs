using System;
using System.Collections;
using System.Collections.Generic;
 
class TEST{
	static void Main(){
		int T=int.Parse(Console.ReadLine());
		for(int i=1;i<=T;i++){
			Sol mySol =new Sol(i);
			mySol.Solve();
		}
	}
}

class Sol{
	public void Solve(){
		List<char>[] Lc=new List<char>[N];
		List<int>[] Ln=new List<int>[N];
		for(int i=0;i<N;i++){
			Lc[i]=new List<char>();
			Ln[i]=new List<int>();
		}
		for(int i=0;i<N;i++){
			Lc[i].Add(S[i][0]);
			Ln[i].Add(1);
			for(int j=1;j<S[i].Length;j++){
				if(S[i][j]!=S[i][j-1]){
					Lc[i].Add(S[i][j]);
					Ln[i].Add(1);
					continue;
				}else{
					Ln[i][Ln[i].Count-1]++;
				}
			}
		}
		
		//chk;
		for(int i=1;i<N;i++){
			if(Lc[i].Count!=Lc[0].Count){
				Console.WriteLine("Fegla Won");
				return;
			}
		}
		for(int i=1;i<N;i++){
			for(int j=0;j<Lc[0].Count;j++){
				if(Lc[i][j]!=Lc[0][j]){
					Console.WriteLine("Fegla Won");
					return;
				}
			}
		}
/*
Console.WriteLine("debug");
for(int kk=0;kk<N;kk++){
	for(int gg=0;gg<Lc[kk].Count;gg++){
		Console.Write("{0} ",Lc[kk][gg]);
	}
	Console.WriteLine("");
	for(int gg=0;gg<Ln[kk].Count;gg++){
		Console.Write("{0} ",Ln[kk][gg]);
	}
	Console.WriteLine("");
}
*/
		
		int ans=0;
		for(int i=0;i<Lc[0].Count;i++){
			List<int> LL=new List<int>();
			for(int j=0;j<N;j++){
				LL.Add(Ln[j][i]);
			}
			LL.Sort();
			int anss;
			int ans0=0;
			int trgt=LL.Count/2;
			for(int j=0;j<LL.Count;j++){
				ans0+=Math.Abs(LL[trgt]-LL[j]);
			}
			anss=ans0;
			
			if(LL.Count/2+1<LL.Count-1){
				int ans1=0;
				int trgt1=LL.Count/2+1;
				for(int j=0;j<LL.Count;j++){
					ans1+=Math.Abs(LL[trgt1]-LL[j]);
				}
				if(ans1<anss)anss=ans1;
			}
			
			if(LL.Count/2-1>=0){
				int ans2=0;
				int trgt2=LL.Count/2-1;
				for(int j=0;j<LL.Count;j++){
					ans2+=Math.Abs(LL[trgt2]-LL[j]);
				}
				if(ans2<anss)anss=ans2;
			}
			ans+=anss;
		}
		Console.WriteLine("{0}",ans);
	}

	int N;
	String[] S;
	public Sol(int T){
		Console.Write("Case #{0}: ",T);
		N=int.Parse(Console.ReadLine());
		S=new String[N];
		for(int i=0;i<N;i++){
			S[i]=Console.ReadLine();
		}
	}
}

struct Pair{
	public char C;
	public int N;
	public Pair(char c,int n){
		this.N=n;
		this.C=c;
	}
}