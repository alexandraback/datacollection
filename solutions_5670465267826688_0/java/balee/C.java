import java.io.FileInputStream;
import java.util.Scanner;

public class C {

	// i: 2
	// j: 3
	// k: 4
	
	static int[][] table = {
		{},
		{0,  1,  2,  3,  4},
		{0,  2, -1,  4, -3},
		{0,  3, -4, -1,  2},
		{0,  4,  3, -2, -1}
	};
	
	static int mul(int c1, int c2) {
		int sign = 1;
		if ( c1 < 0 ) {
			c1 = -c1;
			sign *= -1;
		}
		if ( c2 < 0 ) {
			c2 = -c2;
			sign *= -1;
		}
		return sign * table[c1][c2];
	}
	
	static int pow(int c, long pow) {
		long mod = pow % 4L;
		int product = 1;
		while( mod-- > 0 )
			product = mul(product, c);
		return product;
	}
	
	private static String process(Scanner in) {
		int L = in.nextInt();
		long X = in.nextLong();
		long fullLength = L * X;
		String str = in.next();
		int[] chars = new int[L];
		int strProduct = 1;
		for(int i = 0; i < L; i++) {
			char ith = str.charAt(i);
			chars[i] = ith == 'i' ? 2 : ith == 'j' ? 3 : 4;
			strProduct = mul(strProduct, chars[i]);
		}
		if ( strProduct == 1 )
			return "NO";

		// calc first pos for product i
		int iPos = -1;
		int product = 1;
		for(int i = 0; iPos < 0 && i < 6 * L; i++) {
			int index = i % L;
			product = mul(product, chars[index]);
			if ( product == 2 ) // i
				iPos = i;
		}

		if ( iPos < 0 || iPos >= fullLength )
			return "NO";

		// calc first pos for product j
		int jPos = -1;
		product = 1;
		for(int i = iPos + 1; jPos < 0 && i < iPos + 6 * L; i++) {
			int index = i % L;
			product = mul(product, chars[index]);
			if ( product == 3 ) // j
				jPos = i;
		}

		if ( jPos < 0 || jPos >= fullLength )
			return "NO";

		int usedCount = (jPos + 1) / L + 1;
		long remainingCount = X - usedCount;
		
		// Check whether the remaining is k
		product = 1;
		for(int i = jPos + 1; i < usedCount * L; i++) {
			int index = i % L;
			product = mul(product, chars[index]);
		}

		if ( remainingCount < 0 )
			return "NO";

		if ( mul(product, pow(strProduct, remainingCount)) == 4 ) // k
			return "YES";
		
		return "NO";
		/*
		return str + " " + strProduct + " " + iPos + " " + jPos + " " + product + " " + remainingCount;
		*/
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
