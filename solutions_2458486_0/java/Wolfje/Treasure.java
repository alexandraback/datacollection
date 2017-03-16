import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Treasure {
	String PROBLEM_ID = "problemD";

	enum TestType {
		EXAMPLE, SMALL, LARGE
	}

//	 TestType TYPE = TestType.EXAMPLE;
	 TestType TYPE = TestType.SMALL;
//	TestType TYPE = TestType.LARGE;

	public String getFileName() {
		String result = PROBLEM_ID + "_";
		switch (TYPE) {
		case EXAMPLE:
			result += "example";
			break;
		case SMALL:
			result += "small";
			break;
		case LARGE:
			result += "large";
			break;
		}
		return result;
	}

	public String getInFileName() {
		return getFileName() + ".in";
	}

	public String getOutFileName() {
		return getFileName() + ".out";
	}

	public static void main(String[] args) throws Exception {
		new Treasure();
	}

	public Treasure() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int k = scan.nextInt();
			n = scan.nextInt();
			startKeys = new int[k];
			for ( int i = 0; i < k; i++) startKeys[i] = scan.nextInt() - 1;
			chestType = new int[n];
			chestKeys = new int[n][];
			for ( int i = 0; i < n; i++) {
				chestType[i] = scan.nextInt() - 1;
				int ki = scan.nextInt();
				chestKeys[i] = new int[ki];
				for ( int j = 0; j < ki; j++) chestKeys[i][j] = scan.nextInt() - 1;
			}
			memo = new int[1<<n];
			Arrays.fill(memo, -1);
			String answer = "";
			if ( go(0) ) {
				int[] keyCount = new int[201	];
				for ( int key: startKeys) keyCount[key]++;
				int mask = 0;
				while (mask != (1<<n) - 1) {
					int pick = -1;
					for ( int i = 0; i < n && pick == -1; i++) {
						if ( ((1<<i) & mask) != 0 ) continue;
						if ( go(mask | (1<<i)) && keyCount[chestType[i]] > 0) {
							pick = i;
						}
					}
					answer += (pick+1) + " ";
					keyCount[chestType[pick]]--;
					for ( int key: chestKeys[pick]) keyCount[key]++;
					mask |= (1<<pick);
				}
			} else answer = "IMPOSSIBLE";
			String resultStr = String.format("Case #%d: %s", test + 1, answer);
			// add answer here

			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	}
	
	int n;
	int[] startKeys;
	int[] chestType;
	int[][] chestKeys;
	int[] memo;
	public boolean go(int mask) {
		if ( mask == (1<<n) - 1) return true;
		if ( memo[mask] >= 0 ) return memo[mask] == 1;
		// compute how many keys you have now
		int[] keyCount = new int[201	];
		for ( int key: startKeys) keyCount[key]++;
		for ( int i = 0; i < n; i++) {
			if ( ((1<<i) & mask) == 0 ) continue;
			keyCount[chestType[i]]--;
			for ( int key: chestKeys[i]) keyCount[key]++;
		}
		boolean ok = false;
		for ( int i = 0; i < n; i++) {
			if ( ((1<<i) & mask) != 0) continue;
			if ( keyCount[chestType[i]] == 0) continue;
			ok |= go(mask | (1<< i));
		}
		memo[mask] = ok ? 1: 0;
		return ok;		
	}
}
