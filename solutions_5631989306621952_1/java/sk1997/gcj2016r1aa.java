import java.util.*;
import java.io.*;

public class gcj2016r1aa {
	
	private static Scanner sc;
	private static PrintStream ps;
	
	private static void oneCase() {
		String s = sc.next();
		String ans = "";
		int lens = s.length();
		for (int i = 0; i < lens; i++) {
			if (ans.length() == 0)
				ans = ans + s.charAt(i);
			else if (s.charAt(i) >= ans.charAt(0))
				ans = s.charAt(i) + ans;
			else
				ans = ans + s.charAt(i);
		}
		ps.println(ans);
	}

	public static void main(String[] args) throws IOException {
		sc = new Scanner(new File("infile.txt"));
		ps = new PrintStream(new FileOutputStream(new File("outfile.txt")));
		//
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			ps.format("Case #%d: ", t);
			//
			oneCase();
		}
	}

}
