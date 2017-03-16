import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */
	public static BigInteger B1 = BigInteger.ONE;
	public static BigInteger B2 = BigInteger.ONE.add(BigInteger.ONE);

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File file = new File("data.in");
		Scanner in = new Scanner(file);
		File file1 = new File("data.out");
		FileWriter out = new FileWriter(file1);
		//Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int w = 1; w <= T; ++w) {
			BigInteger r, t;
			r = in.nextBigInteger();
			t = in.nextBigInteger();
			BigInteger L = BigInteger.ONE;
			BigInteger R = t;
			while (L.compareTo(R) <= 0) {
				//System.out.println(L+" "+R);
				BigInteger mid = L.add(R).divide(B2);
				//System.out.println(mid);
				if (ok(mid, r, t)) {
					L = mid.add(B1);
				} else {
					R = mid.subtract(B1);
				}
			}
			
			String ans="Case #"+w+": "+R+"\n";
			//System.out.println(ans);
			//char a[]=ans.toCharArray();
			out.write(ans);
			
		}
		out.close();

	}

	public static boolean ok(BigInteger k, BigInteger r, BigInteger t) {
		BigInteger sum = k;
		sum = sum.add(r.multiply(k).multiply(B2));
		sum = sum.add(k.subtract(B1).multiply(k).multiply(B2));
		if (sum.compareTo(t) <= 0) {
			return true;
		}
		return false;
	}

}
