import static java.lang.Math.pow;
import static java.lang.Math.sqrt;
import static java.lang.System.out;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;


public class A {
	public static void main(String[] args) throws Exception{
		Scanner scanner = new Scanner(new File("A-small-attempt0.in"));
		
		PrintStream out = new PrintStream(new File("outputa-small"));
		int N = scanner.nextInt();
		for (int c = 0; c < N; c++){
			double r = scanner.nextDouble();
			double t = scanner.nextDouble();
			
			double xd = (1 - 2 * r + sqrt(pow(2 * r - 1, 2) + 8 * t)) / 4;
			long x = (long) xd;
			
			if ( 2.0 * x * x + (2 * r - 1) * x > t)
			{
				x -= 1;
			}
			out.printf("Case #%d: %d\n", c+1, x);
		}
	}
}
