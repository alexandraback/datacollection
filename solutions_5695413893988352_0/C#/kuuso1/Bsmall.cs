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
		
		var SS=rsa();
		//smallcase
		
		String S0=SS[0];
		String S1=SS[1];
		
		HashSet<long> H0=new HashSet<long>();
		H0.Add(0);
		long keta=1;
		for(int i=S0.Length-1;i>=0;i--){
			HashSet<long> nxt=new HashSet<long>();
			foreach(var l in H0){
				if(S0[i]!='?'){
					nxt.Add(l+keta*(long)(S0[i]-'0'));
				}
				if(S0[i]=='?'){
					if(S1[i]!='?'){
						//nxt.Add(l+keta*(long)(S1[i]-'0'));
						//nxt.Add(l+keta*((1+(long)(S1[i]-'0'))%10));
						for(int k=0;k<=9;k++){
							nxt.Add(l+keta*k);
						}
					}else{
						//nxt.Add(l+keta*(long)('9'-'0'));
						//nxt.Add(l+keta*((1+(long)('9'-'0'))%10));
						for(int k=0;k<=9;k++){
							nxt.Add(l+keta*k);
						}
					}
				}
			}
			keta*=10;
			H0=nxt;
		}
		
		HashSet<long> H1=new HashSet<long>();
		H1.Add(0);
		keta=1;
		for(int i=S1.Length-1;i>=0;i--){
			HashSet<long> nxt=new HashSet<long>();
			foreach(var l in H1){
				if(S1[i]!='?'){
					nxt.Add(l+keta*(long)(S1[i]-'0'));
				}
				if(S1[i]=='?'){
					if(S0[i]!='?'){
						//nxt.Add(l+keta*(long)(S0[i]-'0'));
						//nxt.Add(l+keta*((1+(long)(S0[i]-'0'))%10));
						for(int k=0;k<=9;k++){
							nxt.Add(l+keta*k);
						}
					}else{
						//nxt.Add(l+keta*(long)('9'-'0'));
						//nxt.Add(l+keta*((1+(long)('9'-'0'))%10));
						for(int k=0;k<=9;k++){
							nxt.Add(l+keta*k);
						}
					}
				}
			}
			keta*=10;
			H1=nxt;
		}
		
		
		var L0=H0.ToList();
		var L1=H1.ToList();
//Console.WriteLine(String.Join(" ",L0.ToArray()));		
//Console.WriteLine(String.Join(" ",L1.ToArray()));		
		L0.Sort();
		L1.Sort();
		
		long cc=0;
		long jj=0;
		long min=long.MaxValue;
		
		for(int i=0;i<L0.Count;i++){
			for(int j=0;j<L1.Count;j++){
				if(min>Math.Abs(L0[i]-L1[j])){
					min=Math.Abs(L0[i]-L1[j]);
					cc=L0[i];
					jj=L1[j];
				}
			}
		}
		
		String form0="";
		for(int i=0;i<S0.Length;i++)form0+="0";
		String form1="";
		for(int i=0;i<S1.Length;i++)form1+="0";
		
		Console.WriteLine("{0} {1}",cc.ToString(form0),jj.ToString(form1));
		
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