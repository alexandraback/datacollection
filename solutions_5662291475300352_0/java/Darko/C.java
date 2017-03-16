import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class C {

	class Hiker implements Comparable<Hiker> {
		long start, time;

		Hiker(int s, int t) {
			start = s;
			time = t;
		}

		@Override
		public int compareTo(Hiker h) {
			if (time == h.time) {
				if (start > h.start)
					return -1;
				if (start < h.start)
					return 1;
				return 0;
			}
			if (time < h.time)
				return -1;
			return 1;
		}
	}

	private void work() throws Exception {
		Scanner sc = new Scanner(new BufferedReader(new FileReader(
				"C-small-1-attempt0.in")));
		PrintWriter pw = new PrintWriter(new FileWriter(
				"C-small-1-attempt0.out"));
		List<Hiker> hikers = new ArrayList<Hiker>();
		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			int n = sc.nextInt();
			hikers.clear();
			while (n-- > 0) {
				int d = sc.nextInt();
				int h = sc.nextInt();
				int m = sc.nextInt();
				for (int i = m; i < m + h; i++) {
					hikers.add(new Hiker(d, i));
				}
			}
			Collections.sort(hikers);
			int ans = 0;
			if (hikers.size() == 2) {
				if ((720 - hikers.get(0).start) * hikers.get(0).time <= (360 - hikers
						.get(1).start) * hikers.get(1).time)
					ans = 1;
			}
			pw.printf("Case #%d: %d\n", tc, ans);
		}
		sc.close();
		pw.close();
	}

	public static void main(String[] args) throws Exception {
		new C().work();
	}

}
