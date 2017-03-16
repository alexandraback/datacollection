package problema;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;
import java.io.PrintWriter;

public class ProblemA {

static final String FILENAME = "A-large";
static final String IN = FILENAME + ".in";
static final String OUT = FILENAME + ".out";
//static PrintStream out = System.out;
static Scanner sc;
static PrintWriter out;

private void solve() {
	
	String s = sc.nextLine();
	char fl = s.charAt(0);
	char ll = s.charAt(0);
	String ans = ""+fl;
	for (int i = 1; i < s.length(); ++i) {
		char ch = s.charAt(i);
		if (ch >= fl) {
			ans = ch + ans;
			fl = ch;
		} else {
			ans = ans + ch;
		}
	}
	
	out.println(ans);
}

private void run() throws Exception {
// out = new PrintStream(new FileOutputStream(OUT));
	int t = sc.nextInt();
	sc.nextLine();
	for (int i = 1; i <= t; i++) {
		out.print("Case #" + i + ": ");
		solve();
	}
	sc.close();
	out.close();
}

public static void main(String args[]) throws Exception {
	sc = new Scanner(new File(IN));
	out = new PrintWriter(OUT);
	new ProblemA().run();
}

}