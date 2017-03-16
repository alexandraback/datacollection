import java.util.*;
import java.io.*;
public class FairAndSquare {
	public static void main(String[] args) {
		String inputfile = args[0];
		BufferedReader input;
		try {
			input = new BufferedReader(new FileReader(inputfile));
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}
		Scanner s = new Scanner(input);
		int T = s.nextInt();
		for (int x = 1; x <=T; x++) {
			int A = s.nextInt();
			int B = s.nextInt();
			int count = 0;
			for (int i = A; i <= B; i++) {
				if (isPalindrome(i)) {
					double sqrt = Math.sqrt(i);
					if (sqrt - (int)sqrt == 0 && isPalindrome((int)sqrt)) {
						count++;
					}
				}
			}
			System.out.println("Case #" + x + ": " + count);
		}
	}

	public static boolean isPalindrome(int number) {
		String original = String.valueOf(number);
		for (int i = 0; i < original.length()/2; i++) {
			if (original.charAt(i) != original.charAt(original.length()-i-1)) {
				return false;
			}
		}
		return true;
	}
}
