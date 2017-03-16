import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos {

	private static final String INPUT_NAME = "A-small-attempt0";

	private static final String INPUT_PATH = INPUT_NAME + ".in";
	private static final String OUTPUT_PATH = INPUT_NAME + "-Output.txt";

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
		int a = in.nextInt();
		int n = in.nextInt();
		int[] m = new int[n];
		in.nextLine();
		for (int i = 0 ; i < n ; i++) {
			m[i] = in.nextInt();
		}

		return completeCase(a, m);
	}

	public static String completeCase(int a, int[] m) {
		Arrays.sort(m);
		int added = 0;
		int min = Integer.MAX_VALUE;
		for (int i = 0 ; i < m.length ; i++) {
			if (m[i] < a) {
				a += m[i];
			} else {
				min = Math.min(min, (m.length - i) + added);
				if (a <= 1) {
					added = Integer.MAX_VALUE;
					break;
				}
				while (m[i] >= a) {
					added++;
					a += a - 1;
				}
				a+= m[i];
			}
		}
		min = Math.min(min, added);
		return Integer.toString(min);
	}

}
