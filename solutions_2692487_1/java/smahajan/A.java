import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class A {

	static int n = 0;
	static long[] e;
	static Map<Integer, Integer> map;

	public static void main(String[] args) throws IOException {
		InputStreamReader converter = new InputStreamReader(System.in);
		BufferedReader in = new BufferedReader(converter);
		String line = in.readLine();

		long T = Integer.parseInt(line);

		for (long t = 1; t <= T; t++) {
			line = in.readLine();
			long a = Long.parseLong(line.split(" ")[0]);
			n = Integer.parseInt(line.split(" ")[1]);
			map = new HashMap<>();
			line = in.readLine();
			String[] ss = line.split(" ");
			e = new long[n];
			List<Long> list = new ArrayList<>();
			for (int i = 0; i < ss.length; i++) {
				e[i] = Long.valueOf(ss[i]);
				list.add(e[i]);
				map.put(i, Integer.MAX_VALUE);
			}
			Collections.sort(list);
			for (int i = 0; i < list.size(); i++) {
				e[i] = list.get(i);
			}
			System.out.println("Case #" + t + ": " + doIt(a, 0, 0));
		}
	}

	private static long doIt(long a, int i, int r) {
		if (i == n) {
			return 0;
		}
		if (map.containsKey(i)) {
			if (map.get(i) < r) {
				return map.get(i);
			}
		}
		if (a > e[i]) {
			map.put(i, r);
			return doIt(a + e[i], i + 1, r);
		} else {
			long r1 = Long.MAX_VALUE;
			if (a != 1)
				r1 = doIt(a + a - 1, i, r + 1) + 1;

			long r2 = doIt(a, i + 1, r + 1) + 1;

			return Math.min(r1, r2);
		}
	}
}
