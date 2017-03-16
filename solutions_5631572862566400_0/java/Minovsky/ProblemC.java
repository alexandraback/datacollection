package problemc;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;
import java.io.PrintWriter;

public class ProblemC {

static final String FILENAME = "C-small-attempt0";
static final String IN = FILENAME + ".in";
static final String OUT = FILENAME + ".out";
//static PrintStream out = System.out;
static Scanner sc;
static PrintWriter out;

private void solve() {

	int ans = 0;
	
	int n = sc.nextInt();
	int bff[] = new int[1001];
	boolean marks[] = new boolean[1001];
	//the longest chain ends at index
	int lco[] = new int[1001];
	// llc closed?
	int lcc[] = new int[1001];

	//the second longest chain ends at index
	int slco[] = new int[1001];
	int slcc[] = new int[1001];
	
	for (int i = 0; i < n; ++i) {
		bff[i] = sc.nextInt() - 1;
	}
	
	// starts at index
	for (int i = 0; i < n; ++i) {
		if (marks[i] == true) {
			continue;
		}
		int p = i;
		int len = 1;
		while (true) {
			marks[p] = true;
			if (marks[bff[p]] == true) {
				if (!(bff[bff[p]] == p)) {
					p = bff[p];
					len ++;
				}
				break;
			}
			p = bff[p];
			len ++;
		}
		if (bff[p] == i || (bff[p] == p - 1 && bff[bff[p]] == p)) {
			//close
			if (len > lcc[p]) {
				slcc[p] = lcc[p];
				lcc[p] = len;
			} else {
				if (len > slcc[p]) {
					slcc[p] = len;
				}
			}
		} else {
			// open
			if (len > lco[p]) {
				slco[p] = lco[p];
				lco[p] = len;
			} else {
				if (len > slco[p]) {
					slco[p] = len;
				}
			}
		}
		
	}
	
	for (int i = 0; i < n; ++i) {
		if (lcc[i] > ans) {
			ans = lcc[i];
		}
		if (lco[i] + slco[i] -1 > ans) {
			ans = lco[i] + slco[i] - 1;
		}
	}
	
	out.println(ans);
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
	new ProblemC().run();
}

}