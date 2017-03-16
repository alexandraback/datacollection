package year2013.round1a.a;

import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Problem {
	public static void main(String[] args) throws Exception{
		// GCJ共通 ここから
		String filename = "src/year2013/round1a/a/A-large";
		PrintWriter out = new PrintWriter(new File(filename + ".out"));
		Scanner scan = new Scanner(new File(filename + ".in"));
		final int N = scan.nextInt();
		StringBuilder ret = new StringBuilder();
		for (int i = 0; i < N; i++) {
			ret.append("Case #"+(i+1)+": ");
			// 問題文を読んでsolve()に渡す ここから
			long r = scan.nextLong();
			long t = scan.nextLong();
			
			ret.append(solve2(r,t));
			// 問題文を読んでsolve()に渡す ここまで
			ret.append("\n");
		}
		out.write(ret.substring(0, ret.length()-1));
		out.flush();
		// GCJ共通 ここまで
	}
	
	static int solve(long r, long t){
		int ret = 0;
		for(int k=1; ; k++){
			t-=(-3+4*k+2*r);
			if(t<0) break;
			ret++;
		}
		
		return ret;
	}
	
	static long solve2(long r, long t){
		//binary search
		long hi=100000000000L, lo=1L;
		long ret = 1;
		while(lo<=hi){
			long mid = (hi+lo)/2L;
			
			if(f(mid,r).compareTo(new BigInteger(String.valueOf(t)))<=0 &&
					f(mid+1,r).compareTo(new BigInteger(String.valueOf(t)))>0){
				ret = mid;
				break;
			} else if(f(mid,r).compareTo(new BigInteger(String.valueOf(t)))>0 ){
				//インクが足りない -> midを減らす
				hi = mid - 1;
			}else{
				lo = mid + 1;
			}
		}
		return ret;
	}
	
	static BigInteger f(long k, long r){
		BigInteger A = new BigInteger("2").multiply(new BigInteger(String.valueOf(k))).multiply(new BigInteger(String.valueOf(k+1)));
		BigInteger B = new BigInteger("2").multiply(new BigInteger(String.valueOf(k))).multiply(new BigInteger(String.valueOf(r)));
		BigInteger C = new BigInteger("3").multiply(new BigInteger(String.valueOf(k)));
		
		return A.add(B).subtract(C);
		
//		long a = 2*k*(k+1);
//		long b = 2*k*r;
//		long c = 3*k;
//		return a+b-c;
	}
}
