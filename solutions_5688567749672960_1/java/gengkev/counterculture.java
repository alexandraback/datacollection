import java.io.*;

public class counterculture {
	private static final int MAX_POW_10 = 18;
	private static final long[] powersOf10 = new long[MAX_POW_10];
	static {
		long temp = 1;
		for (int i = 0; i < MAX_POW_10; i++) {
			powersOf10[i] = temp;
			temp *= 10;
		}
	}

	private static final boolean useStandardInput = false;
	private static final String filename = "round1B/A-large";
	private static final boolean log = true;

	private static void run() throws IOException {
		final int T = readLineInt();

		for (int i = 1; i <= T; i++) {
			long N = readLineLong();
			long result = calculate(N);
			output(i, String.valueOf(result));
		}
	}

	private static long calculate(long N) {
		long count = 0;
		int N_digits = digits(N);

		if (N < 21) return N;
		count += 9; // start at 10

		for (int digits = 2; digits <= N_digits; digits++) {
			int digits_important = digits / 2;

			long n = powersOf10[digits - 1];
			long n_next = powersOf10[digits];

			if (N >= n_next) {
				long skip_start = n + (powersOf10[digits_important] - 1);
				long skip_end = reverse(skip_start);

				long add_to_count = skip_start - n + 1; // +1 to include n
				add_to_count += n_next - skip_end;

				log("max skip with " + digits + " digits: " + n + " -> " + skip_start + " ==> " +
						skip_end + " -> " + n_next + " (c = " + add_to_count + ")");
				count += add_to_count;
			}
			else {
				// n <= N < n_next
				if (N_digits != digits) throw new IllegalStateException();

				if (n == N) {
					log("final: n == N == " + n + " (c = 0)");
					break;
				}

				// for N = 12345, this is 123
				long N_important = N / powersOf10[digits - digits_important];

				// for N = 12345, this is 45
				// for N = 900, N_important = 9 but should be 8
				long N_insignificant = N % powersOf10[digits - digits_important];
				if (N_insignificant == 0) {
					N_important -= 1;
				}
				if (N_important == 0) {
					throw new IllegalStateException();
				}

				// for N = 12345, this is 321
				// these make up the last digits of skip_start, first digits of skip_end
				long N_important_r = reverse(N_important);

				if (digits(N_important) > digits_important || digits(N_important_r) > digits_important) {
					throw new IllegalStateException("2");
				}

				long skip_start = n + N_important_r;
				long skip_end = reverse(skip_start);

				if (skip_start == skip_end) { // oops
					long add_to_count = N - n;
					log("final: not skipping: " + n + " -> " + N + " (c = " + add_to_count + ")");
					count += add_to_count;
					break;
				}

				if (!(n < skip_start && skip_start < skip_end && skip_end <= N)) {
					throw new IllegalStateException("3");
				}

				long add_to_count = skip_start - n + 1; // +1 to include n
				add_to_count += N - skip_end;

				log("final skip with " + digits + " digits: " + n + " -> " + skip_start + " ==> " +
						skip_end + " -> " + N + " (c = " + add_to_count + ")");
				count += add_to_count;
				break;
			}
		}


		/*
		for (int n = 1; n < N; count++) {
			int r = reverse(n);
			if (r > n + 1 && r <= N) {
				log(n + "=>" + r);
				n = r;
			} else {
				n++;
			}
		}
		*/
		return count + 1; // include final
	}

	private static int digits(long n) {
		for (int i = 0; i < MAX_POW_10; i++) {
			if (n < powersOf10[i])
				return i;
		}
		throw new IllegalArgumentException();
	}
	private static long reverse(long n) {
		if (n < 0) throw new IllegalArgumentException();
		int[] temp = new int[MAX_POW_10];
		int i = 0;
		while (n != 0) {
			temp[i++] = (int)(n % 10);
			n /= 10;
		}
		for (int j = 0; j < i; j++) {
			n = (n * 10) + temp[j];
		}
		return n;
	}

	// ----------------------------------------------------------------------------------------------------------------
	// competition helper methods

	private static BufferedReader reader;
	private static BufferedWriter writer;

	public static void main(String[] args) throws IOException {
		if (useStandardInput) {
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new BufferedWriter(new StringWriter());
		} else {
			reader = new BufferedReader(new FileReader(filename + ".in"));
			writer = new BufferedWriter(new FileWriter(filename + ".out"));
		}
		run();
		reader.close();
		writer.close();
		if (!useStandardInput)
			System.out.println("FINISHED for file " + filename);
		System.exit(0);
	}

	private static String readLine() throws IOException {
		return reader.readLine();
	}
	private static int readLineInt() throws IOException {
		return Integer.parseInt(readLine());
	}
	private static long readLineLong() throws IOException {
		return Long.parseLong(readLine());
	}
	private static int[] readLineIntArray() throws IOException {
		String[] strings = readLine().split("\\s");
		int L = strings.length;
		int[] ints = new int[L];
		for (int i = 0; i < L; i++) {
			ints[i] = Integer.parseInt(strings[i]);
		}
		return ints;
	}

	private static void output(int caseNo, String str) throws IOException {
		String output = "Case #" + caseNo + ": " + str + "\n";
		System.out.print("OUT: " + output);
		if (!useStandardInput) {
			writer.write(output);
		}
	}

	private static void log(String s) {
		if (log) System.out.println(s);
	}
	private static void log(String s, boolean newline) {
		if (log) System.out.print(s + (newline ? "\n" : ""));
	}
}
