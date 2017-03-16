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
	int[] gp;
	int[] gpcnt;
	public void Solve(){
		gp=new int[N];
		
		List<HashSet<char>> LH=new List<HashSet<char>>();
		LH.Add(new HashSet<char>());
		for(int i=0;i<S[0].Length;i++){
			LH[0].Add(S[0][i]);
		}
		gp[0]=0;

		
		for(int i=1;i<N;i++){
			bool chk=false;
			for(int j=0;j<LH.Count;j++){
				for(int k=0;k<S[i].Length;k++){
					if(LH[j].Contains(S[i][k])){
						chk=true;
						break;
					}
				}
				if(chk){
					for(int k=0;k<S[i].Length;k++){
						LH[j].Add(S[i][k]);
					}
					gp[i]=j;
					break;
				}
			}
			if(chk)continue;
			LH.Add(new HashSet<char>());
			for(int j=0;j<S[i].Length;j++){
				LH[LH.Count-1].Add(S[i][j]);
				gp[i]=LH.Count-1;
			}
		}
		
		
		gpcnt=new int[LH.Count];
		for(int i=0;i<LH.Count;i++)gpcnt[i]=0;
		for(int i=0;i<N;i++){
			gpcnt[gp[i]]++;
		}

		
		int[] visit=new int[N];
		remS=new long[LH.Count];
		for(int i=0;i<LH.Count;i++)remS[i]=0;
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)visit[j]=-1;
			visit[0]=i;
			dfs(visit);
			
		}
		long ans=1;
		for(int i=0;i<LH.Count;i++){
			ans*=remS[i];
			ans%=1000000007;
		}
		ans*=ex(LH.Count);
		ans%=1000000007;
		Console.WriteLine(ans);
	}
	
	long ex(int n){
		if(n==1) return 1L;
		return ((long)n * ex(n-1) )%1000000007L;
	}
	
	long[] remS;

	void dfs(int[] visit_){
		int[] visit=new int[N];
		int now=-1;
		for(int i=0;i<N;i++){
			visit[i]=visit_[i];
			if(visit[i]!=-1)now=i;
		}
		if(now==gpcnt[gp[visit[0]]]-1){
			//String sss="";
			//for(int i=0;i<now;i++)sss+=S[visit[i]];
			//remS[gp[visit[0]]].Add(sss);
			remS[gp[visit[0]]]++;
			remS[gp[visit[0]]]%=1000000007L;
			return;
		}
		
		for(int i=0;i<N;i++){
			if(Arr[visit[now],i]==1 && gp[i]==gp[visit[now]]){
				Arr[visit[now],i]=0;
				visit[now+1]=i;
				dfs(visit);
				visit[now+1]=-1;
				Arr[visit[now],i]=1;
			}
		}
	}





	int N;
	String[] S;
	int[,] Arr;
	public Sol(int T){
		Console.Write("Case #{0}: ",T);
		N=ri();
		S=rsa();
		Arr=new int[N,N];
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)Arr[i,j]=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(i==j)continue;
				if(S[i][S[i].Length-1]==S[j][0])Arr[i,j]=1;
			}
		}
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