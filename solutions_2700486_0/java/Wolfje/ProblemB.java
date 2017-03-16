import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.MathContext;
import java.util.*;
import static java.lang.Math.*;



public class ProblemB {
	String PROBLEM_ID = "problemB";

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
		new ProblemB();
	}
	
	BigDecimal[][] bin;
	
	MathContext ctx = new MathContext(35);

	public BigDecimal nchoosek(int n, int k) {
		if (k == 0 | k == n)
			return new BigDecimal(1);
		if (bin[n][k] != null)
			return bin[n][k];
		else {
			BigDecimal left = nchoosek(n - 1, k-1);
			BigDecimal right = nchoosek(n - 1, k);
			BigDecimal sum = left.add(right, ctx);
			bin[n][k] = sum;
			return sum;
		}
	}
	

	public ProblemB() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		BigDecimal TWO = new BigDecimal(2);
		bin = new BigDecimal[750][];
		for ( int i = 0; i < 750; i++) bin[i] = new BigDecimal[i+2];
//		int a = 0;
//		for ( int b = 0; b < 800; b++) {
//			a += 4*b +1;
//			System.out.printf("k = %d sum = %d\n", b, a);
//		}
		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			int x = abs(scan.nextInt());
			int y = scan.nextInt();
			int tgtLayer = (x+y)/2;
			int remaining = n;
			int layer = 0;
			while (remaining >= 4*layer+1) {
				remaining -= 4*layer+1;
				layer++;
			}
			double result = 0.0;
			if ( tgtLayer < layer ) result = 1.0;
			else if ( tgtLayer > layer ) result = 0.0;
			else {
//				System.out.printf("tgtLayer %d layer %d remaining %d\n", tgtLayer, layer, remaining);
				BigDecimal sum = new BigDecimal(0);
				for ( int left = 0; left <= remaining; left++) {
					int right = remaining - left;
					if ( left > 2*layer ) right += left - 2*layer;
					right = min(2*layer, right);
					if ( right >= y +1 ) {
						sum = sum.add(nchoosek(remaining, left), ctx);
					}
				}
				BigDecimal prob = sum.divide(TWO.pow(remaining), ctx);
				result = prob.doubleValue();
			}
			String resultStr = String.format("Case #%d: %f", test + 1, result);
			// add answer here

			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	}
}
