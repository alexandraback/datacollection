import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class War {
	private static InputStream in;
	private static PrintStream out;
	private static Scanner sc;
	static {
		try {
			in = new FileInputStream("D-large.in");
			// System.in;
			out = new PrintStream(new FileOutputStream("out.txt"));
			// System.out;
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		sc = new Scanner(in);
		int numCases = sc.nextInt();
		for (int i = 0; i < numCases; i++) {
			out.println("Case #" + (i + 1) + ": " + solve());
		}
	}

	private static String solve() {
		int n = sc.nextInt();
		double[] naomi = new double[n];
		for (int i = 0; i < n; i++)
			naomi[i] = sc.nextDouble();
		double[] ken = new double[n];
		for (int i = 0; i < n; i++)
			ken[i] = sc.nextDouble();

		Arrays.sort(naomi);
		Arrays.sort(ken);

		int firstLarger = 0;
		for (; firstLarger < n; firstLarger++)
			if (ken[firstLarger] > naomi[0])
				break;

		int kenWarPoints = 0;
		int naomiN = 0;
		for (int i = firstLarger; i < n;) {
			while (i < n && ken[i] <= naomi[naomiN]) {
				i++;
			}
			if (i == n)
				break;
			kenWarPoints++;

			i++;
			naomiN++;
		}

		int warPoints = (n - kenWarPoints);
		int deceitPoints = 0;
		int kenPos = 0;
		for (int i = 0; i < n; i++) {
			if (ken[kenPos] < naomi[i]) {
				deceitPoints++;
				kenPos++;
			}
		}
		return deceitPoints + " " + warPoints;

	}
}
