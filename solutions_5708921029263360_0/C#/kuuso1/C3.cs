using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Diagnostics;

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
		
		var d=ria();
		J=d[0];P=d[1];S=d[2];K=d[3];
		ul=J*P*S;
		
		max=0;
		sw=new Stopwatch();
		sw.Start();
		for(int j=0;j<1;j++){
			for(int p=0;p<1;p++){
				for(int s=0;s<1;s++){
					List<int> H=new List<int>();
					H.Add(enc(j,p,s));
					dfs(H,new Dictionary<int,int>());
				}
			}
		}
		
		Console.WriteLine(max);
		foreach(var st in Hmax){
			Console.WriteLine("{0} {1} {2}",decJ(st)+1,decP(st)+1,decS(st)+1);
		}
	}
	
	static int ul;
	static Stopwatch sw;
	void dfs(List<int> l,Dictionary<int,int> dic){
	if(max==ul)return;
	if(sw.ElapsedMilliseconds>20000)return;
		var H=new HashSet<int>(l);
		if(H.Count>max){
			max=H.Count;
			Hmax=new List<int>(l);
		}
		for(int j=0;j<J;j++){
			for(int p=0;p<P;p++){
				for(int s=0;s<S;s++){
					int nxt=enc(j,p,s);
					if(H.Contains(nxt))continue;
					var ndic=new Dictionary<int,int>(dic);
					int mx=0;
					foreach(var st in l){
						int j0=decJ(st);
						int p0=decP(st);
						int s0=decS(st);
						if(j0==j && s0==s){
							if(ndic.ContainsKey(enc(j,11,s))==false)ndic.Add(enc(j,11,s),0);
							ndic[enc(j,11,s)]++;
							if(mx<ndic[enc(j,11,s)])mx=ndic[enc(j,11,s)];
						}
						if(p0==p && s0==s){
							if(ndic.ContainsKey(enc(11,p,s))==false)ndic.Add(enc(11,p,s),0);
							ndic[enc(11,p,s)]++;
							if(mx<ndic[enc(11,p,s)])mx=ndic[enc(11,p,s)];
						}
						if(p0==p && j0==j){
							if(ndic.ContainsKey(enc(j,p,11))==false)ndic.Add(enc(j,p,11),0);
							ndic[enc(j,p,11)]++;
							if(mx<ndic[enc(j,p,11)])mx=ndic[enc(j,p,11)];
						}
					}
					if(mx<K){
						var ln=new List<int>(l);
						ln.Add(nxt);
						dfs(ln,ndic);
					}
				}
			}
		}
	}
	
	
	
	
	
	static int max;
	static List<int> Hmax;
	
	
	static int enc(int j,int p, int s){
		return j*256+p*16+s;
	}
	static int decJ(int st){
		return st/256;
	}
	static int decP(int st){
		return (st%256)/16;
	}
	static int decS(int st){
		return st%16;
	}
	
	static int J,P,S,K;
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