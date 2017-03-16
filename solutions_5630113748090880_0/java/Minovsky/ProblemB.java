package problemb;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;
import java.io.PrintWriter;

public class ProblemB {

static final String FILENAME = "B-small-attempt0";
static final String IN = FILENAME + ".in";
static final String OUT = FILENAME + ".out";
//static PrintStream out = System.out;
static Scanner sc;
static PrintWriter out;

private void solve() {
	int ans = 0;
	int n = sc.nextInt();
	int marks[] = new int[2501];
	
	for (int i = 0; i < n*2 - 1; ++i) {
		for (int j = 0; j < n; ++j) {
			int tmp = sc.nextInt();
			marks[tmp] ++;
		}
	}
	
	for (int i = 1; i <= 2500; i++) {
		if (marks[i]%2 != 0) {
			out.print(i);
			out.print(" ");
		}
	}
	
	out.println();
}

private void run() throws Exception {
// out = new PrintStream(new FileOutputStream(OUT));
	int t = sc.nextInt();
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
	new ProblemB().run();
}

}