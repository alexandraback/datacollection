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
		
		var d=rla();
		long L=d[0];
		long X=d[1];
		
		Dictionary<char,Q> D=new Dictionary<char,Q>(){
			{'i',new Q(0,1,0,0)},
			{'j',new Q(0,0,1,0)},
			{'k',new Q(0,0,0,1)}
		};
		
		String S=rs();
		
		Q e=(Q)1;
		Q v=e;
		for(int i=0;i<S.Length;i++){
			v*=D[S[i]];
		}
		
		//Q ans1=sPow(v,X);
		Q ans=Pow(v,X);
//Console.WriteLine("ans={0},ans1={1},Eq={2}",ans,ans1,Q.Eq(ans,ans1));
		if(!isOk(ans)){
			Console.WriteLine("NO");
			return;
		}
		
		String ss="";
		for(int i=0;i<Math.Min(20,X);i++){
			ss+=S;
		}
		
		int ptr=0;
		Q vv=(Q)1;
		Q I=new Q(0,1,0,0);
		Q J=new Q(0,0,1,0);
		bool chk1=false;
		for(;ptr<ss.Length;ptr++){
			vv*=D[ss[ptr]];
//Console.WriteLine("vv={0}",vv);
			if(Q.Eq(vv,I)){
				chk1=true;
				ptr++;
				break;
			}
		}
		vv=(Q)1;
		bool chk2=false;
		for(;ptr<ss.Length;ptr++){
			vv*=D[ss[ptr]];
//Console.WriteLine("vv={0}",vv);
			if(Q.Eq(vv,J)){
				chk2=true;
				ptr++;
			}
		}
		
		Console.WriteLine(chk1&&chk2?"YES":"NO");
		
		
		
	}
	
	Q sPow(Q x,long l){
		Q ans=(Q)1;
		for(int i=0;i<l;i++){
			ans*=x;
		}
		return ans;
	}
	
	Q Pow(Q x,long l){
		Q[] Table=new Q[60];
		Table[0]=(Q)1;
		Table[1]=x;
		for(int i=2;i<60;i++){
			Table[i]=Table[i-1]*Table[i-1];
		}
		Q ans=(Q)1;
		for(int i=1;i<60;i++){
			if(((l>>(i-1))&1)>0){
				ans*=Table[i];
			}
		}
		return ans;
	}
	
	bool isOk(Q p){
		return (p.R==-1)&&(p.I==0)&&(p.J==0)&&(p.K==0);
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

struct Q{
	public int R,I,J,K;
	public Q(int r,int i,int j,int k){
		R=r;I=i;J=j;K=k;
	}
	
	public static Q operator*(Q p,Q q){
		return new Q(
			p.R*q.R - p.I*q.I - p.J*q.J - p.K*q.K,
			p.R*q.I + p.I*q.R + p.J*q.K - p.K*q.J,
			p.R*q.J - p.I*q.K + p.J*q.R + p.K*q.I,
			p.R*q.K + p.I*q.J - p.J*q.I + p.K*q.R
		);
	}
	public static implicit operator Q(int a){
			return new Q(a,0,0,0);
	}
	
	public static bool Eq(Q p,Q q){
		return (p.R==q.R)&&(p.I==q.I)&&(p.J==q.J)&&(p.K==q.K);
	}
	public override String ToString(){
		return String.Format("{0} {1} {2} {3}",this.R,this.I,this.J,this.K);
	}
}