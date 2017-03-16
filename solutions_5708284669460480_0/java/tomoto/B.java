import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		new B().run();
	}
	
	// private static final String FILE = "../sample";
	private static final String FILE = "../B-small-attempt3";
	
	private Scanner scanner;
	private PrintWriter out;
	
	void run() throws FileNotFoundException {
		scanner = new Scanner(new File(FILE + ".in"));
		out = new PrintWriter(new File(FILE + ".out"));
		
		int n = scanner.nextInt();
		for (int i = 1; i <= n; i++) {
			solve(i);
		}
		
		scanner.close();
		out.close();
	}
	
	void solve(int index) {
		out.println("Case #" + index + ": " + solve1());
	}

	private String solve1() {
		int k = scanner.nextInt();
		int l = scanner.nextInt();
		int s = scanner.nextInt();
		
		String keyboard = scanner.next();
		String target = scanner.next();
		
		long combinations = 1;
		for (int i = 0; i < s; i++) {
			combinations *= k;
		}
		
		long occurrences = 0;
		long maxCount = 0;
		
		for (long i = 0; i < combinations; i++) {
			StringBuilder sb = new StringBuilder();
			long p = i;
			for (int j = 0; j < s; j++) {
				sb.append(keyboard.charAt((int) (p % k)));
				p /= k;
			}
			
			// System.err.println(sb);
			
			long count = count(sb.toString(), target);
			if (count > maxCount) {
				maxCount = count;
			}
			
			occurrences += count(sb.toString(), target);
		}
		
		System.err.println(keyboard + " " + target + " " + s + " " + combinations + " " + occurrences + " " + maxCount);
		
		return String.valueOf(maxCount - ((float) occurrences) / combinations);
	}
	
	private int count(String s, String t) {
		int count = 0;
		for (int i = 0; i <= s.length() - t.length(); i++) {
			if (s.substring(i, i+t.length()).equals(t)) {
				count++;
			}
		}
		return count;
	}
	
}

