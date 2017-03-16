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
		
		int N=ri();
		var S=new String[N][];
		for(int i=0;i<N;i++)S[i]=rsa();
		
		int Ans=0;
		for(int i=1;i<(1<<N);i++){
			HashSet<String> H0=new HashSet<String>();
			HashSet<String> H1=new HashSet<String>();
			int bcnt=0;
			for(int j=0;j<N;j++){
				if((i&(1<<j))>0){
					H0.Add(S[j][0]);
					H1.Add(S[j][1]);
					bcnt++;
				}
			}
			bool chk=true;
			for(int j=0;j<N;j++){
				if((i&(1<<j))==0){
					if(H0.Contains(S[j][0])&&H1.Contains(S[j][1])){
						continue;
					}
					chk=false;break;
				}
			}
			if(chk){
				Ans=Math.Max(Ans,N-bcnt);
			}
		}
		
		Console.WriteLine(Ans);
		
		
		
	}

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