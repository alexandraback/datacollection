import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ManageYourEnergy {
	private static String PROG_NAME = ManageYourEnergy.class.getSimpleName();
	private static PrintWriter out;

	public static void main(String[] args) throws Exception {
		main(new FileReader(PROG_NAME + ".small.in"), new FileWriter(PROG_NAME + ".small.out"));
		// main(new FileReader(PROG_NAME + ".large.in"), new
		// FileWriter(PROG_NAME + ".large.out"));
	}

	public static String caseStr(int caseId) {
		return "Case #" + caseId + ":";
	}

	public static void main(FileReader fileReader, FileWriter fileWriter) throws Exception {
		long start = System.currentTimeMillis();
		BufferedReader f = new BufferedReader(fileReader);
		out = new PrintWriter(new BufferedWriter(fileWriter));
		Integer caseCount = Integer.parseInt(f.readLine());
		for (int caseId = 1; caseId <= caseCount; caseId++) {
			StringTokenizer st = new StringTokenizer(f.readLine());
			int E = Integer.parseInt(st.nextToken());
			int R = Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());

			st = new StringTokenizer(f.readLine());
			int[] value = new int[N];
			for (int i = 0; i < N; i++) {
				value[i] = Integer.parseInt(st.nextToken());
			}
			System.out.println(Arrays.toString(value));

			int[][] dp = new int[N][E + 1];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j <= E; j++) {
					if (i == 0) {
						dp[i][j] = j * value[i];
					} else {
						// int a = Math.min(R + E - j, E) * value[i] + dp[i -
						// 1][j];
						int a = j == 0 ? 0 : dp[i][j - 1] + value[i];
						int b = dp[i - 1][Math.min(j + R, E)];
						dp[i][j] = Math.max(a, b);
					}
				}
			}

			print(dp);
			System.out.println(caseStr(caseId) + " " + dp[N - 1][E]);
			out.println(caseStr(caseId) + " " + dp[N - 1][E]);

		}
		System.out.println(System.currentTimeMillis() - start);
		out.close(); // close the output file
	}

	private static void print(int[][] array) {
		String leftFormat = "%-4s";
		String cellFormat = "%-4s";
		System.out.format(leftFormat, " ");
		for (int i = 0; i < array[0].length; i++) {
			System.out.format(cellFormat, i);
		}
		System.out.println();
		for (int i = 0; i < array.length; i++) {
			System.out.format(leftFormat, i);
			for (int j = 0; j < array[i].length; j++) {
				System.out.format(cellFormat, array[i][j]);
			}
			System.out.println();
		}
	}
}
