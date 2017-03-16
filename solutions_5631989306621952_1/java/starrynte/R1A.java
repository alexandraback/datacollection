import java.io.*;
import java.util.*;

public class R1A {
	public static void main(String[] args) throws Exception {
		Scanner scan = new Scanner(System.in);
		int nCases = scan.nextInt();
		for (int z = 0; z < nCases; z++) {
			String s = scan.next();

			String last = s.substring(0, 1);
			for (int i = 1; i < s.length(); i++) {
				char c = s.charAt(i);
				String before = c + last, after = last + c;
				last = (before.compareTo(after) >= 0) ? before : after;
			}
			System.out.printf("Case #%d: %s\n", z + 1, last);
		}
		scan.close();
	}
}
