import java.util.Arrays;
import java.util.Scanner;

public class B {
	private static final class IntPair implements Comparable<IntPair> {
		private final int i;
		private final int val;
		private int minRemain;

		public IntPair(int i, int val, int startRemain) {
			this.i = i;
			this.val = val;
			this.minRemain = startRemain;
		}

		@Override
		public int compareTo(IntPair o) {
			return val - o.val;
		}

		public String toString() {
			return Integer.toString(minRemain);
		}
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int numTests = scan.nextInt();
		for (int testCase = 1; testCase <= numTests; testCase++) {
			int e = scan.nextInt();
			int r = scan.nextInt();
			int n = scan.nextInt();
			IntPair[] values = new IntPair[n];
			for (int i = 0; i < n; i++) {
				values[i] = new IntPair(i, scan.nextInt(), e);
			}
			IntPair[] sorted = Arrays.copyOf(values, values.length);
			Arrays.sort(sorted);
			for (IntPair ip : sorted) {
				ip.minRemain = 0;
				int remain = e;
				for (int i = ip.i - 1; i >= 0; i--) {
					remain -= r;
					if (remain >= values[i].minRemain)
						values[i].minRemain = remain;
					else
						break;
				}
			}
			long value = 0;
			int energy = e;
			for (IntPair ip : values) {
				long spent = energy - ip.minRemain;
				if (spent >= 0) {
					value += spent * ip.val;
					energy -= spent;
				}
				energy += r;
			}
			System.out.println("Case #" + testCase + ": " + value);
		}
	}
}
