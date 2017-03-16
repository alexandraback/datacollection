import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class GCJA {
	public static void main(String[] args) throws IOException {
		pw = new PrintWriter(new FileWriter("data.txt"));
		readLine();
		int tests = readInt();
		for(int i=1; i<=tests; i++){
			readLine();
			r = readLong();
			t = readLong();
			R = BigInteger.valueOf(r);
			T = BigInteger.valueOf(t);
			BigInteger ans = bin(BigInteger.ZERO, MAX);
			pw.println("Case #"+i+": "+ans);
		}
		pw.flush();
	}
	
	static BigInteger MAX = BigInteger.valueOf(10).pow(20);
	
	static BigInteger bin(BigInteger a, BigInteger b){
		if(a.equals(b)) return a;
		if(b.subtract(a).equals(BigInteger.ONE)) return enough(b)? b: a;
		BigInteger mid = a.add(b).divide(two);
		return enough(mid)? bin(mid, b): bin(a, mid.subtract(BigInteger.ONE));
	}
	
	static BigInteger two = BigInteger.valueOf(2);
	
	static boolean enough(BigInteger K){
		BigInteger d = two.multiply(K).multiply(K);
		d = d.subtract(K);
		d = d.add(two.multiply(K).multiply(R));
		return d.compareTo(T)<=0;
	}
	
	static BigInteger R, T;
	
	static long r, t;
	
	static int readInt() throws IOException {
		return Integer.parseInt(st.nextToken());
	}
	
	static long readLong() throws IOException {
		return Long.parseLong(st.nextToken());
	}
	
	static void readLine() throws IOException {
		st = new StringTokenizer(rd.readLine());
	}
	
	static BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));

	static PrintWriter pw = new PrintWriter(System.out);
	
	static StringTokenizer st;
	
}
