import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.TreeMap;

/*
 2
 5 2 2
 2 1
 5 2 2
 1 2

 */
public class energy {
	static long[] vals;
	// static long[][] memo;
	static long e;
	static long gain;

	static class val implements Comparable<val> {
		long loc;
		long v;

		public val(long a, long b) {
			loc = a;
			v = b;
		}

		@Override
		public int compareTo(val o) {
			return (int)(o.v - v);
		}

	}

	static class activity {
		long before;
		long after;

		public activity(long a, long b) {
			before = a;
			after = b;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++) {
			e = in.nextLong();
			gain = in.nextLong();
			int n = in.nextInt();

			vals = new long[n];
			PriorityQueue<val> q = new PriorityQueue<val>();

			TreeMap<Long, activity> map = new TreeMap<Long, activity>();

			for (int j = 0; j < vals.length; j++) {
				vals[j] = in.nextLong();
				q.add(new val(j, vals[j]));
			}
			// memo = new long[n][e+1];

			long total = 0;
			while (!q.isEmpty()) {
				val v = q.poll();
				long amountBefore = e;
				long amountAfter = 0;
				Entry<Long, activity> left = map.lowerEntry(v.loc);
				Entry<Long, activity> right = map.higherEntry(v.loc);

				if (left != null) {
					amountBefore = Math.min(e, left.getValue().after + ((v.loc - left.getKey()) * gain));
				}
				if (right != null) {
					amountAfter = Math.max(0,
							right.getValue().before
									- ((right.getKey() - v.loc) * gain));
				}
				activity a = new activity(amountBefore, amountAfter);
				map.put(v.loc, a);
//				System.out.prlongf("day %d: %d-%d\n", v.loc, amountBefore,
//						amountAfter);
				total += (amountBefore - amountAfter) * v.v;
			}

			System.out.printf("Case #%d: %d\n", i + 1, total);
		}
	}

	// private static long recurse(long index, long energy) {
	//
	// if (index == memo.length)
	// return 0;
	// else if (memo[index][energy] != 0)
	// return memo[index][energy];
	//
	// long max = 0;
	// for (long i = 0; i <= energy; i++) {
	// max = Math.max(max, (i * vals[index]) + recurse(index +1, Math.min(e,
	// energy - i + gain)));
	// }
	//
	// return memo[index][energy] = max;
	// }
}
