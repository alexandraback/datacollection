package round1;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

public class C {
	public static void main(String[] args) throws FileNotFoundException {
		Kattio io;

//		io = new Kattio(System.in, System.out);
//		io = new Kattio(new FileInputStream("src/round1/C-sample.in"), System.out);
//		io = new Kattio(new FileInputStream("src/round1/C-small-0.in"), new FileOutputStream("src/round1/C-small-0.out"));
//		io = new Kattio(new FileInputStream("src/round1/C-large-test.in"), new FileOutputStream("src/round1/C-large-test.out"));
		io = new Kattio(new FileInputStream("src/round1/C-large-0.in"), new FileOutputStream("src/round1/C-large-0.out"));

		int cases = io.getInt();
		for (int i = 1; i <= cases; i++) {
			io.print("Case #" + i + ": ");
			new C().solve(io);
		}
		io.close();
	}

	private static class Sum implements Comparable<Sum> {
		public long sum;
		public long mask; // Numbers in the sum

		private Sum(long sum, long mask) {
			this.sum = sum;
			this.mask = mask;
		}

		public int compareTo(Sum that) {
			if (this.sum < that.sum) return -1;
			if (this.sum > that.sum) return 1;
			return 0;
		}
	}

	private void solve(Kattio io) {
		int n = io.getInt();
		long value[] = new long[n];
		for (int i = 0; i < n; i++) {
			value[i] = io.getLong();
		}

		int setSize = Math.min(n / 2, 22);
		Sum[] left = new Sum[1 << setSize], right = new Sum[1 << setSize];
		for (int i = 0; i < (1<<setSize); i++) {
			long leftSum = 0, rightSum = 0;
		    for (int j = 0; j < setSize; j++) {
		        if (((1<<j) & i) > 0) {
					leftSum += value[j];
				}
				if (((1<<j) & i) > 0) {
					rightSum += value[j+setSize];
				}
		    }
			left[i] = new Sum(leftSum, i);
			right[i] = new Sum(rightSum, ((long) i) << setSize);
		}
		Arrays.sort(left);
		Arrays.sort(right);
		System.out.println("Sets generated");

		Random random = new Random(0);
		int tries = 0;
		while (true) {
			System.out.println("Try " + (++tries) + "...");
			ArrayList<Long> masks = new ArrayList<Long>();
			long pickedSum = left[random.nextInt(left.length)].sum + right[random.nextInt(right.length)].sum;
			for (int i = 0; i < left.length && masks.size() < 2; i++) {
				if (left[i].sum > pickedSum) break;
				int lo = 0, hi = right.length;
				while (lo < hi) {
					int x = (lo+hi)/2;
					long diff = left[i].sum + right[x].sum - pickedSum;
					if (diff == 0) {
						masks.add(left[i].mask | right[x].mask);
						break;
					}
					if (diff < 0) {
						lo = x + 1;
					} else {
						hi = x;
					}
				}
			}
			if (masks.size() == 2) {
				io.println();
				for (long mask : masks) {
					boolean first = true;
					for (int i = 0; i < setSize*2; i++) {
					    if (((1L<<i)&mask) > 0) {
							if (!first) io.print(' ');
							io.print(value[i]);
							first = false;
						}
					}

					io.println();
				}
				break;
			}
		}
	}
}
