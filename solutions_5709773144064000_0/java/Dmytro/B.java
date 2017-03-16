import java.io.*;
import java.math.BigDecimal;
import java.math.MathContext;
import java.util.*;


public class B {
	
	static Scanner in;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = new FileInputStream(new File("src/B-small-attempt0.in"));
		PrintStream output = new PrintStream(new File("src/B-small-attempt0.out"));
		in = new Scanner(input);
		out = new PrintWriter(output);
		solveMultiTest();
		out.close();
	}
	
	static void solveMultiTest() throws IOException {
		int T = in.nextInt();
		for (int testCase = 1; testCase <= T; testCase++) {
			out.println("Case #" + testCase + ": " + solveOneTest());
		}
	}  
	
	static String solveOneTest() {
		double C = in.nextDouble();
		double F = in.nextDouble();
		double X = in.nextDouble();
		
		double speed = 2;
		double sum = 0;
		//BigDecimal bigsum = BigDecimal.ZERO;
		while (true) {
			if (X / speed <= C / speed + X / (speed + F)) {
				sum += X / speed;
				//bigsum = bigsum.add(BigDecimal.valueOf(X).divide(BigDecimal.valueOf(speed), MathContext.DECIMAL128));
				break;
			}
			else {
				sum += C / speed;
				//bigsum = bigsum.add(BigDecimal.valueOf(C).divide(BigDecimal.valueOf(speed), MathContext.DECIMAL128));
				speed += F;
			}
		} 
		
		return new Double(sum).toString();
		//return new Double(bigsum.doubleValue()).toString();
	}
}
