import java.util.*;
import java.io.*;

public class A {
	static int A, B;
	static double p[];
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		System.setOut(new PrintStream(new File("A.out")));
		
		int T = sc.nextInt();
		for(int tc = 1; tc <= T; tc++) {
			A = sc.nextInt();
			B = sc.nextInt();
			p = new double[A];
			for(int i=0; i<A; i++)
				p[i] = sc.nextDouble();
			double cc[] = new double[A+1];
			cc[0] = 1;
			for(int i=1; i<=A; i++)
				cc[i] = cc[i-1] * p[i-1];
			double min = 1 << 29;
			for(int i=0; i<=A; i++) {
				double x = cc[A - i];
				double exp = x * (B - A + 1 + 2 * i) + (1 - x) * (B - A + 1 + B + 1 + 2* i);
				min = Math.min(min, exp);
			}
			min = Math.min(2 + B, min);
			System.out.printf("Case #%d: %f\n", tc, min);
		}
	}
}
