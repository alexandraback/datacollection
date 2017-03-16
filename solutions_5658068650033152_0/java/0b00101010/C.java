import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class C {
	private static int[] SMALL_SOLUTIONS = new int[(int) Math.sqrt(1000) + 1];
	private static Scanner scan = new Scanner(System.in);

	public static void main(String[] args) throws FileNotFoundException {
		int total = 0;
		int rate = 1;
		for (int i = 0; i < SMALL_SOLUTIONS.length; i++) {
			if ((i & 7) == 3)
				rate++;
			total += rate;
			SMALL_SOLUTIONS[i] = total;
			System.out.println(i + ": " + SMALL_SOLUTIONS[i]);
		}

		int cases = scan.nextInt();
		PrintStream outfile = new PrintStream("C-small.out.txt");

		String result = "";
		for (int c = 1; c <= cases; c++) {
			result = "Case #" + c + ": "
					+ test(scan.nextInt(), scan.nextInt(), scan.nextInt());
			outfile.println(result);
			System.out.println(result);
		}
		outfile.close();
	}

	private static int test(int n, int m, int k) {
		if (k == 1)
			return 1;
		if (n > m) {
			int temp = m;
			m = n;
			n = temp;
		}
		for (int i = 1; i < 2 * n; i++) {
			System.out.println(k + "/" + SMALL_SOLUTIONS[i]);
			if (k < SMALL_SOLUTIONS[i])
				return i;
		}
		int covered = n * m;
		int stones = 2 * (n + m) - 4;
		int i = 1;
		for (; i <= n/2; i++)
			for (int j = 1; j <= 4; j++) {
				covered -= i;
				if (covered < k)
					return stones;
				stones--;
			}
		for (; i <= m/2; i++) {
			for (int j = 1; j <= 2; j++) {
				covered -= (n+1)/2;
				if (covered < k)
					return stones;
				stones--;
				covered -= n/2;
				if (covered < k)
					return stones;
				stones--;
			}
		}
		IllegalStateException up = new IllegalStateException();
		throw up;
	}
}
