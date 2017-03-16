import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TaskA {

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	void run() throws IOException {
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		String s1 = br.readLine();
		st = new StringTokenizer(s1);
		int t = Integer.parseInt(st.nextToken());
		for (int i1 = 1; i1 <= t; i1++) {
			out.print("Case #" + i1 + ": ");
			s1 = br.readLine();
			st = new StringTokenizer(s1);
			long x = Long.parseLong(st.nextToken());
			int n = Integer.parseInt(st.nextToken());
			s1 = br.readLine();
			st = new StringTokenizer(s1);
			long[] a = new long[n];
			for (int i = 0; i < n; i++) {
				a[i] = Long.parseLong(st.nextToken());
			}
			Arrays.sort(a);
			int min = n;
			int k = 0;
			if (x > 1) {
				for (int i = 0; i < n; i++) {
					while (x <= a[i]) {
						x = 2 * x - 1;
						k++;
					}
					x = x + a[i];

					if (k + (n - i-1) < min) {
						min = k + (n - i-1);
					}
				}
			}

			out.println(min);

		}

		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new TaskA().run();
	}

}