
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Solution {
	public static Scanner in;
	public static PrintWriter out;
	public static final String IN_FILE = "C-large-1.in";
	public static final String OUT_FILE = "C-large-1.out";
	
	public static void main(String[] args) throws IOException {
		List<Long> fits = new ArrayList<Long>();
		for (long i = 1; i <= Math.sqrt(Math.pow(10, 14)); i++) {
			long square = i * i;
			if (isPalindrome(i) && isPalindrome(square)) {
				fits.add(square);
				//System.out.println(square);
			}
		}
		//System.out.println();
		//System.out.println("done!!");
		//System.out.println(fits.size());
		
		in = new Scanner(new FileReader(IN_FILE));
		out = new PrintWriter(new FileWriter(OUT_FILE));
		
		long cases = in.nextLong();
		in.nextLine();
		
		for (int i = 1; i <= cases; i++) {
			long small = in.nextLong();
			long large = in.nextLong();
			int tmp = 0;
			for (int k = 0; k < fits.size(); k++) {
				if (fits.get(k) >= small && fits.get(k) <= large)
					tmp++;
			}

			out.print(String.format("Case #%d: %d%n", i, tmp));
		}
		out.flush();
		out.close();
		in.close();
	}

	private static boolean isPalindrome(long square) {
		String s = Long.toString(square);
		for (int k = 0; k < s.length(); k++) {
			if (s.charAt(k) != s.charAt(s.length()-1-k))
				return false;
		}
		return true;
	}
}
