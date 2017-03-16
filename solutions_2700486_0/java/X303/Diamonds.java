import java.io.*;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class Diamonds {

	private static final String INPUT_NAME = "B-small-attempt1";

	private static final String INPUT_PATH = INPUT_NAME + ".in";
	private static final String OUTPUT_PATH = INPUT_NAME + "-Output.txt";

	private static final int[][] PASCAL = calcPascal();

	private static int[][] calcPascal() {
		int[][] triangle = new int[10005][];
		for (int i = 0 ; i < 10005 ; i++) {
			triangle[i] = new int[i + 1];
			triangle[i][0] = 1;
			triangle[i][i] = 1;
			for (int j = 1 ; j < i ; j++) {
				triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
			}
		}
		return triangle;
	}

	public static void main(String[] ignored) throws IOException {
		try (Scanner in = new Scanner(new File(INPUT_PATH)) ;
			 BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(OUTPUT_PATH)))) {

			completeProblem(in, out);

		}
	}

	public static void completeProblem(Scanner in, BufferedWriter out) throws IOException {
		final int caseCount = in.nextInt();
		for (int i = 1 ; i <= caseCount ; i++) {
			in.nextLine();
			System.out.println("Case #" + i);
			out.write("Case #" + i + ": ");
			out.write(parseCase(in));
			out.newLine();
			out.flush();
		}
	}

	private static String parseCase(Scanner in) throws IOException {
		int n = in.nextInt();
		int x = in.nextInt();
		int y = in.nextInt();

		return completeCase(n, x, y);
	}

	public static String completeCase(int n, int x, int y) {

		int layer = (Math.abs(x) + y) / 2;
		int height = y;
		int diaToFillUnder = 0;
		for (int i = 0 ; i < layer ; i++) {
			diaToFillUnder += (i * 4) + 1;
			if (diaToFillUnder >= n) {
				System.out.println("A: " + n + " ; " + x + " ; " + y);
				return "0.0";
			}
		}
		int remaining = n - diaToFillUnder;

		int needed = height + 1;
		if (remaining <= 0) {
			System.out.println("B: " + n + " ; " + x + " ; " + y);
			return "0.0";
		} else if (remaining >= (layer * 4) + 1) {
			System.out.println("C: " + n + " ; " + x + " ; " + y);
			return "1.0";
		} else if (remaining < needed || x == 0) {
			System.out.println("D: " + n + " ; " + x + " ; " + y);
			return "0.0";
		}

		System.out.println(n + " ; " + x + " ; " + y);
		System.out.println(layer + " ; " + diaToFillUnder + " ; " + remaining + " ; " + needed);

		BigDecimal numerator = BigDecimal.ZERO;

		for (int i = needed ; i <= remaining ; i++) {
			numerator = numerator.add(BigDecimal.valueOf(PASCAL[remaining][i]));
			System.out.print(PASCAL[remaining][i] + " + ");
		}
		System.out.println();
		BigDecimal denominator = BigDecimal.valueOf(2).pow(remaining);
		System.out.println(numerator + " / " + denominator);

		if (numerator.compareTo(BigDecimal.ZERO) <= 0 || denominator.compareTo(BigDecimal.ZERO) <= 0 || numerator.compareTo(denominator) >= 0) {
			throw new RuntimeException();
		}

		return numerator.divide(denominator, 10, RoundingMode.HALF_EVEN).toPlainString();
	}

}
