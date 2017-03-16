package gcj2015.round1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A {
	public static void main(String args[]) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(args[0]));
		
		int T = scanner.nextInt();
		for(int t=1; t<=T; t++) {
			long N = scanner.nextLong();
			
			System.out.println("Case #" + t + ": " + solve(N));
		}
		
		scanner.close();
	}
	
	static long solve(long n) {
		if(n <= 10)
			return n;
		
		if(n <= 100) {
			long result = 10;
			long n_left = n/10;
			long n_right = n%10;
			
			if(n_left == 1) {
				result += n_right;
			}
			else if(n_right == 0) {
				result += n_left-1;
				result ++; // invert
				result += 9;
			}
			else {
				result += n_left;
				result ++; // invert
				result += n_right-1;
			}

			return result;
		}
		
		// First reach 10000...
		Byte[] digits = digits(n);
		long result = reachPowerOf10(digits.length);
		// Then
		long leftPart = leftPart(digits);
		long rightPart = rightPart(digits);
		if(leftPart == 1) {
			result += rightPart;
		}
		else if(rightPart == 0){
			result += leftPart-1;
			result ++; // invert
			result += pow10((digits.length+1)/2);
		}
		else {
			result += leftPart;
			result ++;// invert
			result += rightPart-1;
		}
		
		return result;
	}
	
	private static long rightPart(Byte[] digits) {
		long result = 0;
		for(int i = (digits.length-1)/2; i >= 0; i--) {
			result = result*10 + digits[i];
		}
		return result;
	}

	static long leftPart(Byte[] digits) {
		long result = 0;
		for(int i = (digits.length+1)/2; i < digits.length; i++) {
			result = result*10 + digits[i];
		}
		return result;
	}

	static long reachPowerOf10(int length) {
		int result = 0; // 100 => 29
		for(int n = 1; n < length; n++) {
			result += nextPower(n);
		}
		
		return result;
	}
	
	static long nextPower(int n) {
		long n2 = n/2;
		return pow10(n2)-1 + pow10(n-n2);
	}
	
	static long pow10(long n) {
		long pow = 1;
		while(n > 0) {
			pow *= 10;
			n--;
		}
		return pow;
	}

	static Byte[] digits(long n) {
		List<Byte> digits = new ArrayList<Byte>();
		
		while(n != 0) {
			digits.add(Byte.valueOf((byte)(n%10)));
			n /= 10;
		}
		
		return digits.toArray(new Byte[0]);
	}
}
