import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class A {

	static int n = 0;
	static int[] e;

	public static void main(String[] args) throws IOException {
		InputStreamReader converter = new InputStreamReader(System.in);
		BufferedReader in = new BufferedReader(converter);
		String line = in.readLine();

		int T = Integer.parseInt(line);

		for (int t = 1; t <= T; t++) {
			line = in.readLine();
			int a = Integer.parseInt(line.split(" ")[0]);
			n = Integer.parseInt(line.split(" ")[1]);
			line = in.readLine();
			String[] ss = line.split(" ");
			e = new int[n];
			List<Integer> list = new ArrayList<>();
			for (int i = 0; i < ss.length; i++) {
				e[i] = Integer.valueOf(ss[i]);
				list.add(e[i]);
			}
			Collections.sort(list);
			for (int i = 0; i < list.size(); i++) {
				e[i] = list.get(i);
			}
			System.out.println("Case #" + t + ": " + doIt(a, 0));
		}
	}

	private static int doIt(int a, int i) {
		if (i == n) {
			return 0;
		}
		if (a > e[i]) {
			return doIt(a + e[i], i + 1);
		} else {
			int r1 = Integer.MAX_VALUE;
			if (a != 1)
				r1 = doIt(a + a - 1, i) + 1;

			int r2 = doIt(a, i + 1) + 1;

			return Math.min(r1, r2);
		}
	}
}
