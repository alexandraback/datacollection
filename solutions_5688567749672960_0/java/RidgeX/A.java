import java.util.*;

public class A {
	private static final int N_MAX = 1000000;

	static class State implements Comparable<State> {
		long num;
		long steps;

		public State(long num, long steps) {
			this.num = num;
			this.steps = steps;
		}

		public int compareTo(State s) {
			long d = num - s.num;
			if (d < 0) {
				return -1;
			} else if (d > 0) {
				return 1;
			} else {
				d = steps - s.steps;
				if (d < 0) {
					return -1;
				} else if (d > 0) {
					return 1;
				} else {
					return 0;
				}
			}
		}
	}

	public static void main(String[] args) {
		HashMap<Long, Long> steps = new HashMap<Long, Long>();

		PriorityQueue<State> queue = new PriorityQueue<State>();
		HashSet<Long> visited = new HashSet<Long>();
		queue.add(new State(1, 1));
		while (!queue.isEmpty()) {
			State s = queue.remove();
			if (visited.contains(s.num)) continue;
			visited.add(s.num);
			steps.put(s.num, s.steps);
			if (s.num == N_MAX) break;
			StringBuilder sb = new StringBuilder();
			sb.append(Long.toString(s.num));
			sb.reverse();
			long t = Long.parseLong(sb.toString());
			queue.add(new State(s.num + 1, s.steps + 1));
			if (t > s.num) queue.add(new State(t, s.steps + 1));
		}

		Scanner input = new Scanner(System.in);
		int cases = input.nextInt();
		for (int c = 0; c < cases; c++) {
			long n = input.nextLong();
			System.out.println(String.format("Case #%d: %d", c+1, steps.get(n)));
		}
	}
}
