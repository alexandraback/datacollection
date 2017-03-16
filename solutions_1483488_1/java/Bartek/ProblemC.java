import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemC {

	public static void main(String[] args) {
		final Scanner in = new Scanner(System.in);
		final PrintWriter out = new PrintWriter(System.out);
		
		final int t = in.nextInt();
		
		for (int tt = 0; tt < t; tt++) {
			final int a = in.nextInt();
			final int b = in.nextInt();
			
			int count = 0;
			for (int n = a; n < b; n++) {
				count += recycledNumbersCount(n, b);
			}
			
			out.println("Case #" + (tt + 1) + ": " + count); 
		}

		out.flush();
	}
	
	private static int recycledNumbersCount(int n, int b) {
		int count = 0;
		final String s = "" + n;
		String ss = s.charAt(s.length() - 1) + s.substring(0, s.length() - 1);
		while (!s.equals(ss)) {
			if (ss.charAt(0) != '0') {
				final int m = Integer.parseInt(ss);
				if (m > n && m <= b) {
					count++;
				}
			}
			ss = ss.charAt(ss.length() - 1) + ss.substring(0, ss.length() - 1);
		}
		return count;
	}

}
