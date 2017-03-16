import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Alarge {
	private static long a;
	private static int n;
	private static long[] array;

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		 BufferedReader buf = new BufferedReader(new FileReader(
		 "A-large.in"));
		PrintWriter writer = new PrintWriter(new File("Alarge.out"));
		int tCases = Integer.parseInt(buf.readLine().trim());
		for (int t = 1; t <= tCases; t++) {
			StringTokenizer str = new StringTokenizer(buf.readLine());
			a = Integer.parseInt(str.nextToken());
			n = Integer.parseInt(str.nextToken());
			array = new long[n];
			str = new StringTokenizer(buf.readLine());
			for (int i = 0; i < n; i++)
				array[i] = Integer.parseInt(str.nextToken());
			Arrays.sort(array);
			long min = array.length;
			long current = 0;
			for (int i = 0; i < n; i++) {
				if (a > array[i])
					a += array[i];
				else {
					if (a > 1) {
						while (a <= array[i]) {
							a += a - 1;
							current++;
						}
						a += array[i];
					} else {
						min = Math.min(min, current + n - i);
						break;
					}
				}
				min = Math.min(min, current + n - i - 1);

			}
			writer.printf("Case #%d: %d\n", t, min);
		}
		writer.close();
	}
}
