import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

public class ProblemC {
	
	static BufferedWriter out;

	public static void solve(Scanner sc) throws IOException {
		long count = 0;
		long A = sc.nextLong();
		long B = sc.nextLong();
		long a = (long) Math.sqrt(A);
		long b = (long) Math.sqrt(B);
		if (a * a < A) {
			a++;
		}
		for (long i = a; i <= b; i++) {
			if (isPalindrome(i)) {
				if (isPalindrome(i * i)) {
					count++;
				}
			}
		}
		System.out.println(count);
		out.write("" + count + "\n");
		out.flush();
	}

	public static boolean isPalindrome(long number) {
		long palindrome = number; // copied number into variable
		long reverse = 0;

		while (palindrome != 0) {
			long remainder = palindrome % 10;
			reverse = reverse * 10 + remainder;
			palindrome = palindrome / 10;
		}

		// if original and reverse of number is equal means
		// number is palindrome in Java
		if (number == reverse) {
			return true;
		}
		return false;
	}

	public static void main(String[] args) throws IOException {
//		Scanner sc = new Scanner(new File("C-practice.in"));
//		 Scanner sc = new Scanner(new File("C-small-attempt0.in"));
		 Scanner sc = new Scanner(new File("C-large-1.in"));
			sc.useLocale(Locale.US);
			
		 FileWriter fstream = new FileWriter("out.txt");
		   out = new BufferedWriter(fstream);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			out.write("Case #" + i + ": ");
			solve(sc);
		}
		sc.close();
	}
}
