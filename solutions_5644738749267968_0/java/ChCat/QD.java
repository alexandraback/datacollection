import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class QD {

	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(new DataInputStream(
				new FileInputStream("r:\\input.txt"))));
		pw = new PrintWriter(new BufferedWriter(
				new FileWriter("r:\\output.txt")));
		final int MAX_NUM_CASE = readInt();

		for (int qq = 1; qq <= MAX_NUM_CASE; qq++) {
			pw.print("Case #" + qq + ": ");

			int N = readInt();

			double[] Naomi = new double[N];
			double[] Ken = new double[N];

			for (int i = 0; i < N; i++) {
				Naomi[i] = readDouble();
			}

			TreeSet<Double> KenSet = new TreeSet<Double>();
			for (int i = 0; i < N; i++) {
				double d = readDouble();
				KenSet.add(d);
				Ken[i] = d;
			}

			Arrays.sort(Naomi);
			Arrays.sort(Ken);

			int cheat = 0;
			int i = 0;
			int j = 0;

			for (i = 0; i < N; i++) {
				if (Naomi[i] > Ken[j]) {
					cheat++;

					j++;
				} else {

				}
			}

			int normal = 0;

			for (i = 0; i < N; i++) {
				double d = Naomi[i];

				Set<Double> tail = KenSet.tailSet(d);
				if (!tail.isEmpty()) {
					Iterator<Double> it = tail.iterator();
					it.next();
					it.remove();
				} else {
					Iterator<Double> it = KenSet.iterator();
					it.next();
					it.remove();
					normal++;
				}
			}

			pw.print(cheat);
			pw.print(" ");
			pw.println(normal);
		}

		pw.close();
	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			if (!br.ready()) {
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}
