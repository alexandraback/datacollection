import java.io.FileInputStream;
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

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}