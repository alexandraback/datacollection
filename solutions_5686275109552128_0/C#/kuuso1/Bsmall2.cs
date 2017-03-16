using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

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
		
		N=ri();
		A=ria();
		Min=9999999;
		List<int> L=new List<int>(A);
		dfs(0,L);
		
		Console.WriteLine(Min);
		
	}
	
	void dfs(int cnt,List<int> L){
		var max=L.Max();
		if(cnt>Min)return;
		
		if(max==0){
			Min=Math.Min(Min,cnt);
			return;
		}
		
		var L0=new List<int>(L);
		for(int i=0;i<L0.Count;i++){
			if(L0[i]!=0)L0[i]--;
		}
		dfs(cnt+1,L0);
		
		if(max>1){
			var L1=new List<int>(L);
			int idx=-1;
			for(int i=0;i<L1.Count;i++){
				if(L1[i]==max){
					idx=i;
					break;
				}
			}
			int half=max/2;
			L1.Add(0);
			for(int j=1;j<=half;j++){
				L1[L1.Count-1]++;
				L1[idx]--;
				dfs(cnt+1,L1);
			}
		}
	}
	
	int Min;
	
	
	int N;
	int[] A;
	public Sol(int T){
		Console.Write("Case #{0}: ",T);
	}




	static String rs(){return Console.ReadLine();}
	static int ri(){return int.Parse(Console.ReadLine());}
	static long rl(){return long.Parse(Console.ReadLine());}
	static double rd(){return double.Parse(Console.ReadLine());}
	static String[] rsa(){return Console.ReadLine().Split(' ');}
	static int[] ria(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>int.Parse(e));}
	static long[] rla(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>long.Parse(e));}
	static double[] rda(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>double.Parse(e));}

}

struct Pair{
	public char C;
	public int N;
	public Pair(char c,int n){
		this.N=n;
		this.C=c;
	}
}