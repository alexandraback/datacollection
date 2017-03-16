import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class A {

	/**
	 * @param args
	 */
	public static boolean ai00(BigInteger r, BigInteger t, BigInteger n){
		BigInteger s = r.multiply(BigInteger.valueOf(2)).add(n.multiply(BigInteger.valueOf(2))).subtract(BigInteger.ONE).multiply(n);
		return (s.compareTo(t) <= 0);
		//return true;
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader f = new BufferedReader(new FileReader("input"));
        // input file name goes above
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output")));
		// Use StringTokenizer vs. readLine/split -- lots faster
		StringTokenizer st = new StringTokenizer(f.readLine());
		// Get line, break into tokens
		int n = Integer.parseInt(st.nextToken());
		//out.println(n);
		for (int i = 0; i < n; ++i){
			st = new StringTokenizer(f.readLine());
			BigInteger r = new BigInteger(st.nextToken());
			BigInteger t = new BigInteger(st.nextToken());
			BigInteger a = BigInteger.ONE;
			BigInteger b = t;
			while (a.compareTo(b) < 0){
				BigInteger mid = a.add(b).divide(BigInteger.valueOf(2)).add(BigInteger.ONE);
				if (ai00(r, t, mid)){
					a = mid;
				}else {
					b = mid.subtract(BigInteger.ONE);
				}
			}
			out.println("Case #" + (i + 1) + ": " + a);
		}
		//int i1 = Integer.parseInt(st.nextToken());    // first integer
		//int i2 = Integer.parseInt(st.nextToken());    // second integer
		//out.println(i1+i2);                           // output result
		out.close();                                  // close the output file
		System.exit(0);
	}

}
