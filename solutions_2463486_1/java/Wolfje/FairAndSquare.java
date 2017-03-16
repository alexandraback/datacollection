import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;




public class FairAndSquare {
	String PROBLEM_ID = "problemC";

	enum TestType {
		EXAMPLE, SMALL, LARGE
	}

//	 TestType TYPE = TestType.EXAMPLE;
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
		new FairAndSquare();
	}

	public FairAndSquare() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				getOutFileName())));
		ArrayList<Long> numbers = new ArrayList<Long>();
		for ( long k = 1; k <= 21000000; k++) {
			if ( isPalindrome(k) && isPalindrome(k*k)) {
//				System.out.printf("%8d %16d\n",k,k*k);
				numbers.add(k*k);
			}
		}
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			long a = scan.nextLong();
			long b = scan.nextLong();
//			System.out.printf("a = %d b = %d\n", a, b);
			int count = 0;
			for ( long c: numbers) {
				if ( c >= a && c <= b) count++;
			}
			String resultStr = String.format("Case #%d: %d", test + 1, count);
			// add answer here

			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		
		
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	}
	
	boolean isPalindrome(long n) {
		long k = 0;
		long m = n;
		while (m > 0 ) {
			k = 10*k + (m % 10);
			m/= 10;
		}
		return k == n;
	}
}
