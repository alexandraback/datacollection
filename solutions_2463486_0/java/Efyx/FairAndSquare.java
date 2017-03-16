package gcj2013.C;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class FairAndSquare {
	
	public static void main(String args[]) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(args[0]));
		
		int T = scanner.nextInt();
		for(int t=0; t<T; t++) {
			long A = scanner.nextLong();
			long B = scanner.nextLong();
			// Need BigInteger for second large dataset (10^100 !!)
			
			int num = 0;
			for(long n=A; n<=B; n++) {
				if(isFairAndSquare(n)) {
					num++;
				}
			}
			
			System.out.println("Case #" + (t+1) + ": " + num);
		}
	}

	private static boolean isFairAndSquare(long n) {
		if(isFair(n)) {
			long sqrt = (long)Math.sqrt(n); // rounding should be ok while n <= 10^14 (double precision is 15 decimal digits
			if(sqrt * sqrt == n) {
				if(isFair(sqrt)) {
					System.out.print(n + "=" + sqrt + "², ");
					return true;
				}
			}
		}
		return false;
	}

	// Is a palindrome, in base 10
	private static boolean isFair(long n) {
		String str = Long.toString(n);
		for(int i = 0; i<str.length()/2; i++) {
			if(str.charAt(i) != str.charAt(str.length()-1-i)) {
				return false;
			}
		}
		return true;
	}
}
