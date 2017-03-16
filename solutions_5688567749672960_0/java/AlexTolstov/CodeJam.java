import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class CodeJam {

	Scanner in;
	PrintWriter out;

	
	int reverse(int x) {
		StringBuilder s = new StringBuilder(x + "");
		return Integer.parseInt(s.reverse().toString());
	}
	
	void solveFor() {
		int n = in.nextInt();
		int ar[] = new int[1 + n];
		ar[1] = 1;
		for (int i = 2; i <= n; i++) {
			ar[i] = ar[i - 1] + 1;
			int rev = reverse(i);
			int len = (rev + "").length();
			int len2 = (i + "").length();
			if (len == len2 && rev < i) {
				ar[i] = Math.min(ar[i], ar[rev] + 1);
			}
		}
		out.println(ar[n]);
	}

	void solve() {
		int n = in.nextInt();
		for (int test = 1; test <= n; test++) {
			out.print("Case #" + test + ": ");
			solveFor();
			out.flush();
		}
	}
	
	static private final String path = "C:\\jam\\1B\\";
	static private final String problem = "A";
	static private final String tests = "A-small";
	

	void run() {
		try {
			in = new Scanner(new FileReader(path + problem + "\\" + tests + ".in"));
			out = new PrintWriter(path + problem + "\\" + tests + ".out");
		} catch (IOException e) {
			throw new Error(e);
			
//			in = new Scanner(System.in);
//			out = new PrintWriter(System.out);
//			out.println(">");
//			out.flush();
		}
		try {
			solve();
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) {
		new CodeJam().run();
	}
}