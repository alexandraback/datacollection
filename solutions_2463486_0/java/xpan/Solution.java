
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class Solution {
	public static Scanner in;
	public static PrintWriter out;
	public static final String IN_FILE = "C-small-attempt0.in";
	public static final String OUT_FILE = "C-small-attempt0.out";
	
	public static void main(String[] args) throws IOException {
		Set<Integer> fits = new HashSet<Integer>();
		for (int i = 1; i <= Math.sqrt(1000); i++) {
			int square = i * i;
			if (isPalindrome(i) && isPalindrome(square)) {
				fits.add(square);
				//System.out.println(square);
			}
		}
		
		in = new Scanner(new FileReader(IN_FILE));
		out = new PrintWriter(new FileWriter(OUT_FILE));
		
		int cases = in.nextInt();
		in.nextLine();
		
		for (int i = 1; i <= cases; i++) {
			int small = in.nextInt();
			int large = in.nextInt();
			int tmp = 0;
			for (int k = small; k <= large; k++) {
				if (fits.contains(k))
					tmp++;
			}
			out.print(String.format("Case #%d: %d%n", i, tmp));
		}
		out.flush();
		out.close();
		in.close();
	}

	private static boolean isPalindrome(int square) {
		String s = Integer.toString(square);
		for (int k = 0; k < s.length(); k++) {
			if (s.charAt(k) != s.charAt(s.length()-1-k))
				return false;
		}
		return true;
	}
}
