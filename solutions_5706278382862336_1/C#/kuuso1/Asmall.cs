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
		long gcd=cal_gcd(p,q);
		p/=gcd;
		q/=gcd;
		if(cal_bcnt(q)!=1){
			Console.WriteLine("impossible");
			return;
		}
		int ans=0;
		long q2=q;
		while(q2>0){
			ans++;
			q2/=2;
		}
		
		long p2=p;
		while(p2>0){
			ans--;
			p2/=2;
		}
		
		Console.WriteLine(ans);
		
	}

	int cal_bcnt(long l){
		int cnt=0;
		for(int i=0;i<63;i++){
			cnt+=(int)((l>>i)&1L);
		}
		return cnt;
	}

	long p;
	long q;
	public Sol(int T){
		Console.Write("Case #{0}: ",T);
		var s=rs();
		var ss=s.Split('/');
		p=long.Parse(ss[0]);
		q=long.Parse(ss[1]);
	}

	long cal_gcd(long a,long b){
		if(b==0)return a;
		return cal_gcd(b,a%b);
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