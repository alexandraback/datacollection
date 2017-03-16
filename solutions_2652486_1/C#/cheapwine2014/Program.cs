/*
 * Created by SharpDevelop.
 * User: cheapwine
 * Date: 2013/4/27
 * Time: 8:45
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.IO;
using System.Collections.Generic;

	
namespace A3
{

	static class Tool{
		public static string[] NextStringArray(this TextReader cin){
			string str=cin.ReadLine();
			//Console.Error.WriteLine(str);
			return str.Trim().Split(new char[]{},StringSplitOptions.RemoveEmptyEntries);
		}
		public static int[] ToIntArray(this string[] strarr){
			int[] ret=new int[strarr.Length];
			for(int i=0;i<strarr.Length;++i)
				ret[i]=int.Parse(strarr[i]);
			return ret;
		}
		public static long[] ToLongArray(this string[] strarr){
			long[] ret=new long[strarr.Length];
			for(int i=0;i<strarr.Length;++i)
				ret[i]=long.Parse(strarr[i]);
			return ret;
		}

	}

	class Program
	{
		
		Random rand=new Random();
		
		void solve(int N,int M,long[] data){
			List<int> ret=new List<int>();
			if(N==3){
				for(int a=2;a<=M;++a)
					for(int b=2;b<=M;++b)
						for(int c=2;c<=M;++c){
					
					int[] pos={1,a,b,c,a*b,a*c,b*c,a*b*c};
					
					bool ok=true;
					foreach(int v in data){
						if(Array.IndexOf(pos,v)==-1){
							ok=false;
							break;
						}
					}
					if(ok){
						ret.Add(a*100+b*10+c);
					}						
				}
				if(ret.Count>0){
					cout.WriteLine(ret[rand.Next()%ret.Count]);				
				}else{
					cout.WriteLine("222");
				}
				return;	
			}
			
			//N=12
			//larger case
			
			
			//2 3 4 5 6 7 8
			int max2=0,max3=0,max5=0,max7=0;
			int min2=int.MaxValue,min3=int.MaxValue;
			
			foreach(long vv in data){
				int cnt2=0,cnt3=0,cnt5=0,cnt7=0;
				long v=vv;
				while(v%2==0){
					v/=2;
					++cnt2;
				}
				while(v%3==0){
					v/=3;
					++cnt3;
				}
				while(v%5==0){
					v/=5;
					++cnt5;
				}
				while(v%7==0){
					v/=7;
					++cnt7;
				}
				if(cnt2>max2)max2=cnt2;
				if(cnt3>max3)max3=cnt3;
				if(cnt5>max5)max5=cnt5;
				if(cnt7>max7)max7=cnt7;
				if(cnt2>0 && cnt2<min2)min2=cnt2;
				if(cnt3>0 && cnt3<min3)min3=cnt3;
			}
			
			List<int> output=new List<int>();
			for(int i=0;i<max5;++i)output.Add(5);
			for(int i=0;i<max7;++i)output.Add(7);
			
			
			int nleft=N-output.Count;
			int[] gen=new int[nleft];
			
			
			int[] mat2={0,0,1,0,2,0,1,0,3};
			int[] mat3={0,0,0,1,0,0,1,0,0};
			
			List<long> nd=new List<long>();
			foreach(long v in data){
				long v2=v;
				foreach(int r in output){
					if(v2%r==0)v2/=r;
				}
				nd.Add(v2);
			}
			
			int failcnt=0;
			while(failcnt<1000){
				int cur2=max2,cur3=max3;
				
				for(int i=0;i<nleft;++i){



					
					if(cur2>0){
						gen[i]=2;
						if(rand.Next(2)==1)goto curoff;
					}
					if(cur3>0){
						gen[i]=3;
						if(rand.Next(2)==1)goto curoff;
					}				
					if(cur2>1){
						gen[i]=4;
						if(rand.Next(2)==1)goto curoff;
					}
					if(cur2>0 && cur3>0){
						gen[i]=6;
						if(rand.Next(2)==1)goto curoff;
					}
					if(cur2>2){						
						gen[i]=8;
						if(rand.Next(2)==1)goto curoff;
					}
					
					gen[i]=rand.Next(2,M+1);
				curoff:
					cur2-=mat2[gen[i]];
					cur3-=mat3[gen[i]];					
				}
				if(cur2<=0 && cur3<=0){
					
					foreach(long vv in nd){
						long p=vv;
						foreach(int v in gen){
							if(p%v==0)p/=v;
						}
						if(p!=1) goto breakit;
					
					}
					foreach(int v in gen)
						cout.Write(v);
					foreach(int v in output)
						cout.Write(v);
					cout.WriteLine();
					
					return;
				}
			breakit:
				++failcnt;
			}
			
			foreach(int v in output)
				cout.Write(v);
			for(int i=0;i<nleft;++i)
				cout.Write(rand.Next(2,M+1));
			cout.WriteLine();
		}
		
		string solvecase(int casenumber){
			cout.WriteLine();
			
			int[] ia=cin.NextStringArray().ToIntArray();
			int R=ia[0],N=ia[1],M=ia[2],K=ia[3];
			for(int i=0;i<R;++i){
				long[] d=cin.NextStringArray().ToLongArray();
				solve(N,M,d);
			}
						
			return "";			
		}
		
		void solve(){
			cases=int.Parse(cin.ReadLine());
			for(int i=1;i<=cases;++i){
				cout.Write("Case #{0}: ",i);				
				object ret=solvecase(i);
				cout.WriteLine(ret);
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