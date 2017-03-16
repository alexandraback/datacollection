import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class A {

	
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens())
				tk=new StringTokenizer(br.readLine());
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		public long nextLong() throws NumberFormatException, IOException{
			return Long.valueOf(next());
		}
		
	}
	
	static long R,t;
	static BigInteger RR,tt;
	
	static BigInteger function(BigInteger k){
		BigInteger first = k.add(BigInteger.ONE);
		BigInteger second = RR.multiply(new BigInteger("2")).add(BigInteger.ONE).add(k.multiply(new BigInteger("2")));
		return first.multiply(second);
	}
	
	static boolean test(BigInteger k){
		BigInteger t = function(k);
		return t.compareTo(tt) <= 0;
	}
	
	static long bsearch(){
		long low = 0;
		long high = 707106785;
		while(true){
			long m = (low + high) / 2;
			BigInteger mid = new BigInteger(m+"");
			if (test(mid) && !test(mid.add(BigInteger.ONE)))
				return m + 1;
			if (!test(mid))
				high = m - 1;
			else
				low = m + 1;
		}
	}
	/*
	static long naive(){
		long p = 0;
		while(function(p + 1) <= t)
			p++;
		return p + 1;
	}*/
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c = 1; c <= T; c++){
			R = sc.nextLong();
			t = sc.nextLong();
			RR = new BigInteger(R+"");
			tt = new BigInteger(t+"");
			//System.out.println(naive());
			System.out.println("Case #"+c+": "+bsearch());
		}
	}
}
