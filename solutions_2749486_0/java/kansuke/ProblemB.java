import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class ProblemB {
	static Scanner scan = new Scanner(System.in);
	static PrintStream out = System.out;
	
	static void test () {
		int x = scan.nextInt(), y = scan.nextInt();
		
		StringBuffer ans = new StringBuffer ();
		if (x != 0) {
			if (x < 0) {
				for (int i = 0; i < -x; ++i)
					ans.append("EW");
			} else {
				for (int i = 0; i < x; ++i)
					ans.append("WE");
			}
		}
		if (y != 0) {
			if (y < 0) {
				for (int i = 0; i < -y; ++i)
					ans.append("NS");
			} else {
				for (int i = 0; i < y; ++i)
					ans.append("SN");
			}
		}
		out.println (ans);
	}
	
	public static void main (String[] args) {
		int T = scan.nextInt();
		for (int i = 1; i <= T; ++i) {
			out.print("Case #" + i + ": ");
			test();
		}
	}
}
