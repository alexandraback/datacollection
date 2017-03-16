using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace lib {
    [DebuggerStepThrough,DebuggerNonUserCode]
    public partial class g{
		public static IEnumerable<byte> rep(byte N){for(byte i=0;i<N;i++)yield return i;}
		public static IEnumerable<short> rep(short N){for(short i=0;i<N;i++)yield return i;}

		public static IEnumerable<int> rep(int N){
			for(int i=0;i<N;i++)
					yield return i;
		}
		public static IEnumerable<int> rep(int beg,int end){
			for(int i=beg;i<=end;i++)
					yield return i;
		}

		public static IEnumerable<long> rep(long N){
			for(long i=0;i<N;i++)
					yield return i;
		}
		public static IEnumerable<long> rep(long beg,long end){
			for(long i=beg;i<=end;i++)
				yield return i;
		}

		public static IEnumerable<T> rep<T>(T beg,T end){
			for(dynamic i=beg;i<=end;i++) // dynamic is as slow as object http://stackoverflow.com/questions/7478387/dynamic-and-performance
					yield return i;
		}

		public static void rep(int N,Predicate<int> f){
			for(var i=0;i<N;i++)if(f(i))break;
		}

		static g(){
			int t=0;
			rep(3,(e)=>{t+=e;return false;});
			if(t!=3)throw new Exception("loop.test.1");
		}
    }
}
