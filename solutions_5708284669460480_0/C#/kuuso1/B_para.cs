using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;


class TEST{
	static void Main(){
		int T=int.Parse(Console.ReadLine());
		String[] ret=new String[T];
		List<String>[] Input=new List<String>[T];
		for(int i=0;i<T;i++){
			Input[i]=new List<String>();
			//input read;
			Input[i].Add(rs());
			Input[i].Add(rs());
			Input[i].Add(rs());
		}
		
		
//		Parallel.For(0,T,i=>{
//			Sol mySol =new Sol(Input[i]);
//			ret[i]=mySol.Solve();
//		});

		for(int i=0;i<T;i++){
			Sol mySol =new Sol(Input[i]);
			ret[i]=mySol.Solve();
		}
		
		for(int i=0;i<T;i++){
			Console.WriteLine("Case #{0}: {1}",i+1,ret[i]);
		}
	}
	static String rs(){return Console.ReadLine();}
}

class Sol{
	public String Solve(){
		
		String ret="";
		
		bool chk=true;
		HashSet<char> H=new HashSet<char>(Kb.ToCharArray());
		for(int i=0;i<trgt.Length;i++){
			if(H.Contains(trgt[i])==false)chk=false;
		}
		if(chk==false){
			return "0.0";
		}
		
		int ov=L;
		for(int i=1;i<trgt.Length;i++){
//Console.WriteLine("{0} {1}",trgt.Substring(i),trgt.Substring(0,L-i));
			if(trgt.Substring(i)==trgt.Substring(0,L-i)){
				ov=i;
				break;
			}
		}
//Console.WriteLine("ov"+ov);				
		double MX=1+((S-L)/ov);
		
		D=new Dictionary<String,int>();
		dfs("");
		double sum=0;
		foreach(var k in D.Keys){
			int cnt=0;
			for(int i=0;i<S-L+1;i++){
				if(k.Substring(i,L)==trgt)cnt++;
			}
//Console.WriteLine("k={0},trgt={1},cnt={2},D[k]={3}",k,trgt,cnt,D[k]);
			sum+=cnt*D[k]*Math.Pow(1.0/K,S);
		}
//Console.WriteLine("MX={0},sum={1}",MX,sum);		
		return ret=String.Format("{0:F8}",MX-sum);
	}
	
	Dictionary<String,int> D;
	void dfs(String s){
		if(s.Length==S){
			if(D.ContainsKey(s)==false){
				D.Add(s,0);
			}
			D[s]++;
			return;
		}
		for(int i=0;i<K;i++){
			dfs(s+Kb[i].ToString());
		}
	}
	
	
	
	
	
	
	int K,L,S;
	String Kb;
	String trgt;
	public Sol(List<String> input){
		var d=ria(input[0]);
		K=d[0];L=d[1];S=d[2];
		Kb=input[1];
		trgt=input[2];
	}




	static int ri(){return int.Parse(Console.ReadLine());}
	static long rl(){return long.Parse(Console.ReadLine());}
	static double rd(){return double.Parse(Console.ReadLine());}
	static String[] rsa(){return Console.ReadLine().Split(' ');}
	static int[] ria(String s){return Array.ConvertAll(s.Split(' '),e=>int.Parse(e));}
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