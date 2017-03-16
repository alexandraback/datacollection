import java.io.*;
import java.util.*;

public class ProblemA {
	static Scanner scan = new Scanner(System.in);
	static PrintStream out = System.out;
		
	static void test () {
		long r = scan.nextLong(), t = scan.nextLong();
		long cnt = 0;
		long tot = 0;
		while (tot <= t) {
			++cnt;
			tot += r*2 + 4 * cnt - 3;
		}
		out.println(cnt - 1);
	}
	
	public static void main(String[] args) {
		int T = scan.nextInt();
		for (int i = 1; i <= T; ++i) {
			out.print("Case #" + i + ": ");
			test();
		}
	}
}
