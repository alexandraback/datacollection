/*
 * Created by SharpDevelop.
 * User: cheapwine
 * Date: 2013/4/27
 * Time: 8:44
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.IO;
using System.Collections.Generic;

namespace A2
{
	static class Tool{
		public static string[] NextStringArray(this TextReader cin){
			return cin.ReadLine().Trim().Split(new char[]{},StringSplitOptions.RemoveEmptyEntries);
		}
		public static int[] ToIntArray(this string[] strarr){
			int[] ret=new int[strarr.Length];
			for(int i=0;i<strarr.Length;++i)
				ret[i]=int.Parse(strarr[i]);
			return ret;
		}
	}

	class Program
	{
		
		long solvecase(int casenumber){
			int[] iarr=cin.NextStringArray().ToIntArray();
			int E=iarr[0],R=iarr[1],N=iarr[2];
			int[] a=cin.NextStringArray().ToIntArray();
			
			long ret=0;
			
			if(R>=E){
				foreach(int v in a){
					ret+=v*E;
				}
				return ret;
				
			}
			
			long[] sum=new long[E+1];
			for(int i=0;i<=E;++i)sum[i]=long.MinValue;
			sum[E]=0;
			
			foreach(int v in a){
				long[] newsum=new long[E+1];
				for(int i=0;i<=E;++i)newsum[i]=long.MinValue;
				
				for(int i=R;i<=E;++i){
					int enow=i;
					long cursum=sum[i];
					for(int cost=0;cost<=enow;++cost){
						int enew=enow-cost+R;
						if(enew>E)enew=E;
						long ns=cursum+cost*v;
						if(ns>newsum[enew])newsum[enew]=ns;
					}
				}
				sum=newsum;
			}
			return sum[R];
		}
		
		void solve(){
			cases=int.Parse(cin.ReadLine());
			for(int i=1;i<=cases;++i){
				cout.WriteLine("Case #{0}: {1}",i,solvecase(i));
			}
		}
		int cases;
		TextReader cin;
		TextWriter cout,cerr;
		void solve(TextReader cin){
			this.cin=cin;
			this.cout=Console.Out;
			this.cerr=Console.Error;
			solve();
		}
		public static void Main(string[] args)
		{
			bool UseCin=false;
			string InputFileName;
			if(args.Length==0){
				InputFileName="../../in.txt";
			}else{
				InputFileName=args[0];
			}
			try{
				new Program().solve(UseCin ? Console.In : new StreamReader(InputFileName));
			}catch(Exception ex){
				Console.WriteLine(ex.StackTrace);
				Console.Read();
			}		
		}
	}
}