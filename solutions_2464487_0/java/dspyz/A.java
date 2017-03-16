import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int numTrials = scan.nextInt();
		for (int i = 0; i < numTrials; i++) {
			long r = scan.nextLong();
			long t = scan.nextLong();
			double n = Math.floor((-(2D * r - 1D) + Math.sqrt((2D * r - 1D)
					* (2D * r - 1D) + 8D * t)) / 4D);
			System.out
					.println("Case #" + (i + 1) + ": " + (long) Math.floor(n));
		}
	}
}
