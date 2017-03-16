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
		
		}
		
		
		Parallel.For(0,T,i=>{
			Sol mySol =new Sol(Input[i]);
			ret[i]=mySol.Solve();
		});
		for(int i=0;i<T;i++){
			Console.WriteLine("Case #{0}: {1}",i+1,ret[i]);
		}
	}
	static String rs(){return Console.ReadLine();}

}

class Sol{
	public String Solve(){
		
		String ret="";
		
		HashSet<int> H=new HashSet<int>();
		for(int i=0;i<D;i++){
			HashSet<int> H0=new HashSet<int>();
			foreach(var k in H){
				H0.Add(k);
				H0.Add(k+A[i]);
			}
			H=H0;
		}
		
		HashSet<int> rest=new HashSet<int>();
		for(int i=1;i<=V;i++){
			if(H.Contains(i)==false)rest.Add(i);
		}
		
		int cnt=0;
		for(int i=0;i<6;i++){
			bool chk=false;
			foreach(int k in rest){
				if(((k>>i)&1)==1)chk=true;
			}
			if(chk)cnt++;
		}
		
		
		
		
		return ret=cnt.ToString();
	}
	
	int C,D,V;
	int[] A;
	public Sol(List<String> input){
		var d=ria(input[0]);
		C=d[0];D=d[1];V=d[2];
		A=ria(input[1]);
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