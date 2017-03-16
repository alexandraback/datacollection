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

namespace A1
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
		
		long calc(long r,long t){
			long cnt=0;
			r=r*2+1;
			
			while(t>=r){
				t-=r;
				r+=4;
				cnt+=1;
			}
			return cnt;
		}
		
		long solvecase(int casenumber){
			string[] arr=cin.NextStringArray();
			return calc(long.Parse(arr[0]),long.Parse(arr[1]));
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
			bool UseCin;
			string InputFileName="";
			if(args.Length==0){
				UseCin=false;
				InputFileName="in.txt";
			}else{
				UseCin=true;
			}
			new Program().solve(UseCin ? Console.In : new StreamReader(InputFileName));
		}
	}
}