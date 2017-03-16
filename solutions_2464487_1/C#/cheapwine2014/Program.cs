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
			
			
			/*t-r 
			t-r+4
			
			(r+r+4*(ret-1))*2
			*/	
			
			//4r+8(ret-1)<=t
			/*
			long r0=r,t0=t;
			while(t0>=r0){
				t0-=r0;
				r0+=4;
				cnt++;
			}
			*/
			//4r+8(ret-1)<=t;
			//cnt=(t-4*r)/8+1;
			
			/*t>=cnt*r-cnt*(cnt-1)/2
			2t>=2cnt*r-cnt*cnt-cnt
			2t>=cnt*(2r-1)+cnt*cnt
			*/
			
			double a=2;
			double b=r-2;
			double c=-t;
			
			
			
			double ret1=(-b+Math.Sqrt(b*b-4*a*c))/2/a;
			//double ret2=(-b-Math.Sqrt(b*b-4*a*c))/2/a;
			
			//Console.WriteLine("a={4} b={0} c={1} ret={2},{3}",b,c,ret1,ret2,a);
			
			cnt=((long)ret1)+5;
			while(a*cnt*cnt+b*cnt+c>0){
				--cnt;
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