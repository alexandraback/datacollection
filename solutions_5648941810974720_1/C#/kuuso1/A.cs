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
		String S=rs();
		String[] Digit=new String[]{
			"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
		};
		
		int[] cnt=new int[256];
		int N=S.Length;
		for(int i=0;i<N;i++){
			cnt[S[i]]++;
		}
		
		int[] num=new int[10];
		int trgt=0;
		
		trgt=0;
		num[trgt]=cnt['Z'];
		for(int i=0;i<Digit[trgt].Length;i++)cnt[Digit[trgt][i]]-=num[trgt];
		
		trgt=2;
		num[trgt]=cnt['W'];
		for(int i=0;i<Digit[trgt].Length;i++)cnt[Digit[trgt][i]]-=num[trgt];
		
		trgt=4;
		num[trgt]=cnt['U'];
		for(int i=0;i<Digit[trgt].Length;i++)cnt[Digit[trgt][i]]-=num[trgt];
		
		trgt=6;
		num[trgt]=cnt['X'];
		for(int i=0;i<Digit[trgt].Length;i++)cnt[Digit[trgt][i]]-=num[trgt];
		
		trgt=8;
		num[trgt]=cnt['G'];
		for(int i=0;i<Digit[trgt].Length;i++)cnt[Digit[trgt][i]]-=num[trgt];
		
		trgt=1;
		num[trgt]=cnt['O'];
		for(int i=0;i<Digit[trgt].Length;i++)cnt[Digit[trgt][i]]-=num[trgt];
		
		trgt=5;
		num[trgt]=cnt['F'];
		for(int i=0;i<Digit[trgt].Length;i++)cnt[Digit[trgt][i]]-=num[trgt];
		
		trgt=3;
		num[trgt]=cnt['H'];
		for(int i=0;i<Digit[trgt].Length;i++)cnt[Digit[trgt][i]]-=num[trgt];
		
		trgt=7;
		num[trgt]=cnt['S'];
		for(int i=0;i<Digit[trgt].Length;i++)cnt[Digit[trgt][i]]-=num[trgt];
		
		trgt=9;
		num[trgt]=cnt['I'];
		for(int i=0;i<Digit[trgt].Length;i++)cnt[Digit[trgt][i]]-=num[trgt];
		
		List<char> L=new List<char>();
		for(int i=0;i<=9;i++){
			for(int j=0;j<num[i];j++){
				L.Add((char)('0'+i));
			}
		}
		Console.WriteLine(new String(L.ToArray()));
		
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