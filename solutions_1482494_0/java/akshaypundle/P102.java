import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class P102 {

	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		int t = inp.nextInt();
		int i = 1;
		while (t > 0) {
			int n = inp.nextInt();
			List<PP> levels = new ArrayList<PP>();
			for (int c = 0; c < n; c++) {
				levels.add(new PP(inp.nextInt(), inp.nextInt()));
			}
			System.out.println("Case #" + i + ": " + calc(levels));
			--t;
			++i;
		}

	}

	private static String calc(List<PP> levels) {
		Collections.sort(levels);
		int stars = 0;
		int ret = 0;
		for (int i = 0; i < levels.size(); i++) {
			int tries = 1001;
			boolean donezo = false;
			while (tries > 0) {
				for (int j = 0; j < i && stars < levels.get(i).l2; ++j) {
					if (j == i)
						continue;
					PP lev = levels.get(j);
					if (!lev.done1 && stars >= lev.l1) {
						lev.done1 = true;
						stars++;
						ret++;
					}
				}

				for (int j = levels.size() - 1; j > i
						&& stars < levels.get(i).l2; --j) {
					if (j == i)
						continue;
					PP lev = levels.get(j);
					if (!lev.done1 && stars >= lev.l1) {
						lev.done1 = true;
						stars++;
						ret++;
					}
				}
				if (stars < levels.get(i).l2 && !levels.get(i).done1
						&& stars >= levels.get(i).l1) {
					stars++;
					levels.get(i).done1 = true;
					ret++;
				}
				tries--;
			}
			if (stars < levels.get(i).l2) {
				return "Too Bad";
			} else {
				if (levels.get(i).done1) {
					stars++;
				} else {
					stars += 2;
				}
				levels.get(i).done1 = true;
				ret++;
			}
		}
		return "" + ret;
	}

	private static final class PP implements Comparable<PP> {
		public final int l1;
		public final int l2;
		boolean done1;

		PP(int l1, int l2) {
			this.l1 = l1;
			this.l2 = l2;
			done1 = false;
		}

		@Override
		public int compareTo(PP o) {
			if (o.l2 != l2) {
				return l2 - o.l2;
			} else {
				return o.l1 - l1;
			}
		}
	}
}
