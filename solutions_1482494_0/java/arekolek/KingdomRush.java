import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;
import java.util.TreeMap;

public class KingdomRush {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileInputStream(args[0]));
		int T = in.nextInt();
		for (int t = 1; t <= T; ++t) {
			TreeMap<Pair<Integer, Integer>, Integer> levels = new TreeMap<KingdomRush.Pair<Integer, Integer>, Integer>();
			int N = in.nextInt();
			int goal = 0;
			for (int i = 0; i < N; ++i) {
				Pair<Integer, Integer> p = new Pair<Integer, Integer>(
						in.nextInt(), in.nextInt());
				levels.put(p, 3);
				goal = Math.max(goal, p.getSecond());
			}
			int moves = 0;
			int stars = 0;
			while (stars < goal && !levels.isEmpty()) {
				boolean c = false;
				for (Pair<Integer, Integer> l : levels.keySet()) {
					if (levels.containsKey(l) && levels.get(l) == 3
							&& l.getSecond() <= stars) {
						moves += 1;
						levels.put(l, 2);
						stars += 2;
						c = true;
						break;
					}
				}
				if (c) {
					continue;
				}
				for (Pair<Integer, Integer> l : levels.keySet()) {
					if (levels.containsKey(l) && levels.get(l) == 3
							&& l.getFirst() <= stars) {
						moves += 1;
						levels.put(l, 1);
						stars += 1;
						c = true;
						break;
					}
				}
				if (c) {
					continue;
				}
				for (Pair<Integer, Integer> l : levels.keySet()) {
					if (levels.containsKey(l) && levels.get(l) == 2
							&& l.getSecond() <= stars || levels.containsKey(l)
							&& levels.get(l) == 1 && l.getFirst() <= stars) {
						moves += 1;
						levels.remove(l);
						stars += 1;
						c = true;
						break;
					}
				}
				if (c) {
					continue;
				} else {
					break;
				}
			}
			System.out.println("Case #" + t + ": "
					+ (stars < goal ? "Too Bad" : moves + 1));
		}
	}

	public static class Pair<A extends Comparable<A>, B extends Comparable<B>>
			implements Comparable<Pair<A, B>> {
		private final A first;
		private final B second;

		public Pair(A first, B second) {
			super();
			this.first = first;
			this.second = second;
		}

		public int hashCode() {
			int hashFirst = first != null ? first.hashCode() : 0;
			int hashSecond = second != null ? second.hashCode() : 0;

			return (hashFirst + hashSecond) * hashSecond + hashFirst;
		}

		public boolean equals(Object other) {
			if (other instanceof Pair) {
				Pair<?, ?> otherPair = (Pair<?, ?>) other;
				return ((this.first == otherPair.first || (this.first != null
						&& otherPair.first != null && this.first
							.equals(otherPair.first))) && (this.second == otherPair.second || (this.second != null
						&& otherPair.second != null && this.second
							.equals(otherPair.second))));
			}

			return false;
		}

		public String toString() {
			return "(" + first + ", " + second + ")";
		}

		public A getFirst() {
			return first;
		}

		public B getSecond() {
			return second;
		}

		@Override
		public int compareTo(Pair<A, B> o) {
			if (this.equals(o)) {
				return 0;
			} else if (this.second.compareTo(o.second) < 0
					|| this.first.compareTo(o.first) < 0) {
				return -1;
			} else {
				return 1;
			}
		}
	}

}
