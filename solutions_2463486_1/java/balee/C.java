import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Scanner;

// Fair and Square
// https://code.google.com/codejam/contest/2270488/dashboard#s=p2

public class C {

	private static boolean checkPalindrom(String str) {
		byte[] b = str.getBytes();
		int len = b.length / 2;
		for(int i = 0; i < len + 1; i++)
			if ( b[i] != b[b.length - i - 1] )
				return false;
		return true;
	}

	/*
	// Quick solution for small dataset :)
	private static String process(Scanner in) {
		int A = in.nextInt();
		int B = in.nextInt();
		int a = (int)Math.sqrt(A);
		int b = 1 + (int)Math.sqrt(B);
		int count = 0;
		for(int i = a; i <= b; i++) {
			int i2 = i * i;
			if ( i2 >= A && i2 <= B )
				if ( checkPalindrom(Integer.toString(i)) )
					if ( checkPalindrom(Integer.toString(i2)) )
						count++;
		}
		return Integer.toString(count);
	}
	 */

	private static ArrayList<Long> values = getFairAndSquareValues();
	
	private static ArrayList<Long> getFairAndSquareValues() {
		long a = 1;
		long b = 10000000;
		ArrayList<Long> res = new ArrayList<Long>();
		for(long i = a; i <= b; i++) {
			long i2 = i * i;
			if ( checkPalindrom(Long.toString(i)) )
				if ( checkPalindrom(Long.toString(i2)) ) 
					//System.out.println(i + " " + i2);
					res.add(i2);
		}
		return res;
	}

	// Quick solution 2 for middle dataset :)
	private static String process(Scanner in) {
		long A = in.nextLong();
		long B = in.nextLong();
		int count = 0;
		for(int i = 0; i < values.size(); i++) 
			if ( values.get(i) >= A && values.get(i) <= B )
				count++;
		return Integer.toString(count);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}