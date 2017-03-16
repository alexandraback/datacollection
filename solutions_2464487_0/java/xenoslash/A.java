package round1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class A {
	public static void main(String[] args) throws Exception{	
		//BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		//PrintWriter out = new PrintWriter(System.out);
	   
		BufferedReader f = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small.out")));
		long T = Long.parseLong(f.readLine());
		for(int i=1; i<=T;i++){
			solve(f, out, i);
		}
		out.close();
	}
	
	public static void solve(BufferedReader f, PrintWriter out, long i) throws Exception{
		out.print("Case #" + i + ": ");
		StringTokenizer tkz = new StringTokenizer(f.readLine());
		long r = Long.parseLong(tkz.nextToken());
		long t = Long.parseLong(tkz.nextToken());
		
		out.println(binSearch(t, t, r));
	}
	
	public static long binSearch(long hi, long target, long startRad){
		long lo=1;
		
		//in this case B = val[i] >= s, A = val[i]<s
		//inv: lo...hi contains 'A' -> AAAABB
		BigInteger targetArea = BigInteger.valueOf(target);
		while(lo < hi){
			long mid = lo + (hi-lo+1)/2;
			BigInteger needPaint = BigInteger.valueOf(startRad);
			needPaint = needPaint.multiply(BigInteger.valueOf(2));
			needPaint = needPaint.add(BigInteger.valueOf(mid));
			needPaint = needPaint.add(BigInteger.valueOf(mid));
			needPaint = needPaint.subtract(BigInteger.ONE);
			needPaint = needPaint.multiply(BigInteger.valueOf(mid));
			if(needPaint.compareTo(targetArea) > 0){
				hi = mid-1;
			}else{
				lo = mid;
			}
		}
		//lo points to highest index where A is true
		//EXCEPT for when everything is BBBBBB, then output still 0.
		//need to check case when arr[0] is B, if so, lo = -1
		return lo;
	}
	
	
public static class FastScanner {
	BufferedReader br;
	StringTokenizer st;

	public FastScanner(String s) {
		try {
			br = new BufferedReader(new FileReader(s));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public FastScanner() {
		br = new BufferedReader(new InputStreamReader(System.in));
	}

	String nextToken() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}

}
