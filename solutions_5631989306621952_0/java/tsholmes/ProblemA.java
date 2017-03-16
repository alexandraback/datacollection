import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemA {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("A-small.in"));
		PrintStream out = new PrintStream("A-small.out");
		
		int T = in.nextInt();
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			String s = in.next();
			char[] cs = s.toCharArray();
			String cur = "";
			for (char c : cs) {
				String s1 = c + cur;
				String s2 = cur + c;
				if (s1.compareTo(s2) > 0) {
					cur = s1;
				} else {
					cur = s2;
				}
			}
			out.printf("Case #%d: %s%n", caseNum, cur);
		}
	}
}
