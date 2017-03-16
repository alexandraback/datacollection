import java.util.*;

public class B {
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int caze = 1; caze <= T; caze++) {
			int diners = sc.nextInt();
			TreeMap<Integer, Integer> ppl = new TreeMap<Integer, Integer>();
			int sum = 0;
			for (int i = 0; i < diners; i++) {
				int val = sc.nextInt();
				sum += val;
				if (ppl.containsKey(val)) {
					ppl.put(val, ppl.get(val)+1);
				} else {
					ppl.put(val, 1);
				}
			}
			int bes = ppl.lastKey();
			//if (caze == 26 || caze == 13) System.out.println(ppl);
			for (int mid = 0; mid <= sum; mid++) {

				TreeMap<Integer, Integer> clone = (TreeMap<Integer, Integer>) ppl.clone();
				//System.out.println("CLONE: " + clone);
				//System.out.println("MID: " + mid);
				int cnt = 0;
				for (int i = 0; i < mid; i++) {
					int max = clone.lastKey();
					int bestd = 2;
					if (i != mid-1 && max %3 == 0) {
						removeOne(clone, max);
						int maxx = clone.isEmpty() ? 0 : clone.lastKey();
						int ll = max-(max/((int) Math.sqrt(max)));
						int rr = max/((int) Math.sqrt(max));
						if (ll >= maxx || rr >= maxx) {
							bestd = (int) Math.sqrt(max);
						}

						addOne(clone, max);
					}
					int left = max-(max/bestd);
					int right = max/bestd;

					if (left <= 0 || right <= 0) continue;
					removeOne(clone, max);
					addOne(clone, left);
					addOne(clone, right);
					//System.out.println("AFTER: " + clone + " LEFT: " + left + " RIGH: " + right + " MAX: " + max);
					cnt++;
				}
				int cost = cnt+clone.lastKey();
				
				bes = Math.min(bes, cost);
			}

			int ans = bes;

			//ans = Math.min(ans, test(ppl, 0));

			System.out.printf("Case #%d: %d\n", caze, ans);
		}
	}

	static int test(TreeMap<Integer, Integer> clone, int splits) {
		int cur = splits+clone.lastKey();
		int top = clone.lastKey();
		removeOne(clone, top);
		int spl = -1;
		for (int split = top/2-1; split <= top/2+1; split++) {
			int first = top-split;
			int second = split;
			if (second == 0 || first == 0) continue;
			if (first+second != top) continue;
			if (first >= top || second >= top) continue;
			addOne(clone, first);
			addOne(clone, second);
			cur = Math.min(cur,test(clone, splits+1));
			removeOne(clone, first);
			removeOne(clone, second);

		}
		addOne(clone, top);
		return cur;
	}

	static void addOne(TreeMap<Integer, Integer> clone, int top) {
		if (!clone.containsKey(top)) {
			clone.put(top, 1);
		} else {
			clone.put(top, clone.get(top)+1);
		}
	}

	static void removeOne(TreeMap<Integer, Integer> clone, int top) {
		if (clone.containsKey(top)) {
			if (clone.get(top) > 1) {
				clone.put(top, clone.get(top)-1);
			} else {
				clone.remove(top);
			}
		}
	}
}