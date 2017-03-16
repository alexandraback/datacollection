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
		
		int cnt=(R-1)*(C/W);
		if(C%W==0){
			cnt+=C/W;
			cnt+=W-1;
		}else{
			int cnt0=0;
			cnt0+=C/W-1;
			int rest=C-W*(C/W-1);
			cnt0+=2*W-rest;
			cnt0+=rest-W+1;
			cnt+=cnt0;
		}
		
		return ret=cnt.ToString();
	}
	int R,C,W;
	public Sol(List<String> input){
		var d=ria(input[0]);
		R=d[0];C=d[1];W=d[2];
	}

	static int[] ria(String s){return Array.ConvertAll(s.Split(' '),e=>int.Parse(e));}
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