package gcj2014.round1C;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class B {
	public static void main(String[] args) throws Exception {
		B main = new B("B_sample.txt");
		main.solve();
	}

	private final BufferedReader in;

	public B(String input) throws Exception {
		in = new BufferedReader(new FileReader(this.getClass().getResource(input).getFile()));
	}

	private void solve() throws Exception {
		int T = getInt();
		final List<String> answers = new ArrayList<String>();
		for (int i = 0; i < T; i++) {
			answers.add("");
		}
		ExecutorService e = Executors.newFixedThreadPool(100);

		for (int c = 1; c <= T; c++) {
			final int count = c;
			final int n = getInt();
			final List<String> x = getStrs();
			final List<String> y = new ArrayList<String>();
			for (String str : x) {
				StringBuffer b = new StringBuffer();
				String prev = null;
				for (String chr : str.split("")) {
					if (!chr.equals(prev)) {
						b.append(chr);
					}
				}
				y.add(b.toString());
			}
			e.execute(new Runnable() {
				@Override
				public void run() {
					try {
						long ans = solveOne(n, y);

						answers.set(count - 1, "Case #" + count + ": " + ans);
					} catch (Throwable e) {
						e.printStackTrace();
					}
				}
			});
			// long ans = solveOne(n, y);
			// System.out.println("Case #" + c + ": " + ans);
		}
		e.shutdown();
		e.awaitTermination(5, TimeUnit.MINUTES);
		for (String answer : answers) {
			System.out.println(answer);
		}
	}

	private long solveOne(int n, List<String> x) {
		int[] per = new int[n];
		int[] inv = new int[n];
		int[] dir = new int[n];
		for (int i = 0; i < n; i++) {
			dir[i] = -1;
			per[i] = i;
			inv[i] = i;
		}
		long total = validateAndPerm(x, 0, per, inv, dir);

		return total;
	}

	private long validateAndPerm(List<String> train, int n, int[] per, int[] inv, int[] dir) {
		if (n >= per.length) {
			return isValidTrain(per, train);
		}

		long total = validateAndPerm(train, n + 1, per, inv, dir);
		for (int i = 0; i <= n - 1; i++) {
			int positionToSwap = per[inv[n] + dir[n]];
			per[inv[n]] = positionToSwap;
			per[inv[n] + dir[n]] = n;
			inv[positionToSwap] = inv[n];
			inv[n] = inv[n] + dir[n];

			total += validateAndPerm(train, n + 1, per, inv, dir);
		}
		dir[n] = -dir[n];
		return total;
	}

	private long isValidTrain(int[] per, List<String> train) {
		StringBuffer buff = new StringBuffer();
		for (int pos : per) {
			buff.append(train.get(pos));
		}
		List<String> valid = new ArrayList<String>();
		for (String car : buff.toString().split("")) {
			if (valid.size() == 0 || !car.equals(valid.get(valid.size() - 1))) {
				valid.add(car);
			}
		}
		if (valid.size() <= 3) {
			// System.out.println(buff.toString());
			return 1;
		}
		String last = valid.get(valid.size() - 1);
		String first = valid.get(0);
		Set<String> really = new HashSet<String>();
		really.addAll(valid);
		// System.out.println(buff.toString() + "< " + really + " >> " + valid);

		if (!last.equals(first) && valid.size() == really.size()) {
			return 1;
		}

		return 0;
	}

	/*
	 * File processing
	 */
	private int getInt() throws Exception {
		return Integer.valueOf(in.readLine()).intValue();
	}

	private List<String> getStrs() throws Exception {
		return Arrays.asList(in.readLine().split(" "));
	}
}
