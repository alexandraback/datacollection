import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(new File("B-large.in"));
		System.setOut(new PrintStream("B-large.out"));

		int t = scan.nextInt();
		for (int c = 0; c < t; c++) {
			int n = scan.nextInt(); // num
			int s = scan.nextInt(); // surprising
			int p = scan.nextInt(); // best result cutoff
			int[] totalPoints = new int[n];
			for (int i = 0; i < n; i++)
				totalPoints[i] = scan.nextInt();

			int sUsed = 0;
			int ans = 0;
			for (int i = 0; i < n; i++) {
				int pts = totalPoints[i];
				// can it be done normal?
				if (pts >= p + (p - 1) * 2)
					ans++;
				// can it be done surp?
				else if (pts >= p + Math.max(p - 2, 0) * 2)
					if (sUsed < s) {
						ans++;
						sUsed++;
					}
			}

			System.out.printf("Case #%d: %d%n", c + 1, ans);
		}
	}
}