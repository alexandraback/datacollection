import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemB {
	String PROBLEM_ID = "problemB";

	enum TestType {
		EXAMPLE, SMALL, LARGE
	}

//	TestType TYPE = TestType.EXAMPLE;
//	 TestType TYPE = TestType.SMALL;
	TestType TYPE = TestType.LARGE;

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
		new ProblemB();
	}

	public ProblemB() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int numberA = scan.nextInt();
			int numberB = scan.nextInt();
			int numberK = scan.nextInt();
			a = toBits(numberA);
			b = toBits(numberB);
			x = toBits(numberK);
			memo = new long[N][8];
//			System.out.println(Arrays.toString(a));
//			System.out.println(Arrays.toString(b));
//			System.out.println(Arrays.toString(x));
			for ( long[] z: memo) Arrays.fill(z, -1L);
			long result = go(0, true, true, true);
			String resultStr = String.format("Case #%d: %d", test + 1, result);
			// add answer here

			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	}
	
	int N = 31;
	int[] a, b, x;
	long[][] memo;
	
	long go(int index, boolean equalA, boolean equalB, boolean equalX) {
		if ( index == N ) {
			return !equalA && !equalB && !equalX ? 1: 0;
		}
		int mask = toMask(equalA, equalB, equalX);
		if ( memo[index][mask] >= 0) return memo[index][mask];
		long result = 0;
		boolean aOne = !equalA || a[index] == 1;
		boolean bOne = !equalB || b[index] == 1;
		boolean xOne = !equalX || x[index] == 1;
		
		for ( int na = 0; na <= 1; na++) {
			if ( na == 1 && !aOne) continue;
			for ( int nb = 0; nb <= 1; nb++) {
				if ( nb == 1 && !bOne ) continue;
				int nx = na == 1 && nb == 1 ? 1:0;
				if ( nx == 1 && !xOne ) continue;
				result += go(index + 1, equalA & a[index] == na,
							     equalB & b[index] == nb, equalX & x[index] == nx);
			}
		}
//		System.out.printf("index %d a %s b %s x %s result %d\n", index, equalA, equalB, equalX, result);
		return memo[index][mask] = result;		
	}
	
	
	int[] toBits(int x) {
		int[] result = new int[N];
		for ( int i = 0; i < N; i++) {
			result[N-1-i] = ((1<<i) & x) != 0 ? 1 : 0;
		}
		return result;
	}
	
	int toMask(boolean x, boolean y, boolean z) {
		int result = 0;
		if ( x ) result |= 4;
		if ( y ) result |= 2;
		if ( z ) result |= 1;
		return result;
	}
}
