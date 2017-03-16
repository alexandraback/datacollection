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
		
		int X,R,C;
		var d=ria();
		X=d[0];R=d[1];C=d[2];
		if(X>=7){
			Console.WriteLine("RICHARD");
			return;
		}
		if(X==1){
			Console.WriteLine("GABRIEL");
			return;
		}
		if(X==2){
			if((R*C)%2!=0){
				Console.WriteLine("RICHARD");
				return;
			}
			Console.WriteLine("GABRIEL");
			return;
		}
		if(X==3){
			if((R*C)%3!=0||R==1||C==1){
				Console.WriteLine("RICHARD");
				return;
			}
			Console.WriteLine("GABRIEL");
			return;
		}
		if(X==4){
			if((R*C)%4!=0||R==1||C==1){
				Console.WriteLine("RICHARD");
				return;
			}
			if(R%4==0&&C>=3){
				Console.WriteLine("GABRIEL");
				return;
			}
			if(C%4==0&&R>=3){
				Console.WriteLine("GABRIEL");
				return;
			}
			if(R%8==0&&C>=3){
				Console.WriteLine("GABRIEL");
				return;
			}
			if(C%8==0&&R>=3){
				Console.WriteLine("GABRIEL");
				return;
			}
			Console.WriteLine("RICHARD");
			return;
		}
		
		if(X==5){
			if((R*C)%5!=0||R==1||C==1){
				Console.WriteLine("RICHARD");
				return;
			}
			if(R%5==0&&C>=4){
				Console.WriteLine("GABRIEL");
				return;
			}
			if(C%5==0&&R>=4){
				Console.WriteLine("GABRIEL");
				return;
			}
			Console.WriteLine("RICHARD");
			return;
		}
		if(X==6){
			if((R*C)%6!=0||R==1||C==1){
				Console.WriteLine("RICHARD");
				return;
			}
			if(R%6==0&&C>=4){
				Console.WriteLine("GABRIEL");
				return;
			}
			if(C%6==0&&R>=4){
				Console.WriteLine("GABRIEL");
				return;
			}
			if(R%4==0&&C>=6){
				Console.WriteLine("GABRIEL");
				return;
			}
			if(C%4==0&&R>=6){
				Console.WriteLine("GABRIEL");
				return;
			}
			Console.WriteLine("RICHARD");
			return;
		}
		
		
		
		
		
		
		Console.WriteLine("RICHARD");
		return;
		
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