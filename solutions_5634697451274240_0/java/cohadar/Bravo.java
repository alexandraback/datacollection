import java.util.*;
import java.io.*;

/**
  * @author Mighty Cohadar 
  */
public class Bravo {

	public static char last(String s) {
		return s.charAt(s.length() - 1);
	}

	public static int solve(char[] C) {
		String s = "" + C[0];
		for (int i = 1; i < C.length; i++) {
			if (C[i] != last(s)) {
				s += C[i];
			}
		}
		return s.length() - ((last(s) == '+') ? 1 : 0);
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int t = scanner.nextInt();
		assert 1 <= t && t <= 100 : "out of range, t: " + t;
		scanner.nextLine();
		for (int it = 1; it <= t; it++) {
			System.out.printf("Case #%d: %d\n", it, solve(scanner.nextLine().toCharArray()));
		}
	}

	static void debug(Object...os) {
		System.err.printf("%.65536s\n", Arrays.deepToString(os));
	}	

}
