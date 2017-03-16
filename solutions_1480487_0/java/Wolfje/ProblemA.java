import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

import static java.lang.Math.*;

public class ProblemA {
	String PROBLEM_ID = "problemA";

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
		new ProblemA();
	}

	public ProblemA() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			int[] s = new int[n];
			for ( int i = 0; i < n; i++) s[i] = scan.nextInt();
			int sum = 0;
			for ( int p: s) sum += p;
			String m = "";
			for ( int i = 0; i < n; i++ ) {
				double lb = 0.0;
				double ub = 1.0 + 1e-12;
				for ( int k = 0; k < 40; k++) {
					double mid = (lb + ub)/2;
					double score = s[i] + mid*sum;
					double x = 0.0;
					for ( int j = 0; j < n; j++) {
						if ( i == j ) continue;
						x += max(0.0, (score - s[j])/sum);
					}
					if ( x > 1.0 - mid ) ub = mid; else lb = mid; 
				}
				m += String.format(" %f", 100*lb);
			}
			m = m.substring(1);
			String resultStr = String.format("Case #%d: %s", test + 1, m);
			// add answer here

			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	}
}
