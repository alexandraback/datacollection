import java.io.FileInputStream;
import java.util.Locale;
import java.util.Scanner;

// Cookie Clicker Alpha
// https://code.google.com/codejam/contest/2974486/dashboard#s=p1

public class B {

	private static String process(Scanner in) {
		in.useLocale(Locale.US);
		double C = in.nextDouble();
		double F = in.nextDouble();
		double X = in.nextDouble();
		double currentRate = 2;
		double bestTime = Double.MAX_VALUE;
		double elapsed = 0;
		while( true ) {
			double timeNeeded = X / currentRate;
			if ( elapsed + timeNeeded < bestTime )
				bestTime = elapsed + timeNeeded;
			else
				break;
			elapsed += C / currentRate;
			currentRate += F;
		}
		return Double.toString(bestTime);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
