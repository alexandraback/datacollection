import java.io.*;
import java.util.*;


public class Main {
	
	Scanner in;
	PrintWriter out;
	
	static final String path = "C:/gcj2013_r1/";
	static final String problem = "A-small2";
	
	Integer ar[];
	int res[][];
	int maxValue;
	
	int getMinimalSteps(int taken, int currIdx) {
		if (currIdx == ar.length) {
			return 0;
		}
		if (taken > maxValue) {
			taken = maxValue + 1;
		}
		if (res[taken][currIdx] != -1) {
			return res[taken][currIdx];
		}
		int ans = 0;
		if (taken > ar[currIdx]) {
			ans = getMinimalSteps(taken + ar[currIdx], currIdx + 1);
		} else {
			if (taken + taken - 1 > ar[currIdx]) {
				// insert taken - 1
				ans = 1 + getMinimalSteps(taken + taken - 1, currIdx);
				
			} else {
				// delete
				ans = 1 + getMinimalSteps(taken, currIdx + 1);
				// ins
				if (taken != 1) {
					int ans2 = 1 + getMinimalSteps(taken + taken - 1, currIdx);
					ans = Math.min (ans, ans2);
				}
			}
		}
		res[taken][currIdx] = ans;
		return ans;
	}
	
	void solveOne(int test) {
		int taken = in.nextInt();
		ar = new Integer[in.nextInt()];
		for (int i = 0; i < ar.length; i++) {
			ar[i] = in.nextInt();
		}
		Arrays.sort(ar);
		
		maxValue = ar[ar.length - 1] + 1;
		int len = ar.length + 1;
		res = new int[maxValue + 2][len];
		for (int a[] : res) {
			Arrays.fill(a, -1);
		}
		
		int ans = getMinimalSteps(taken, 0);
		
		out.println("Case #" + test + ": " + ans);
	}
	
	void solve() {
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			solveOne(i + 1);
		}
	}
	
	
	static void check(boolean e) {
		if (!e) {
			throw new Error();
		}
	}
	
	
	public void run() {
		try {
			in = new Scanner(new FileReader(path + problem + ".in"));
			out = new PrintWriter(new FileWriter(path + problem + ".out"));
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
		}
		
		try {
			solve();
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) {
		new Main().run();
	}
}