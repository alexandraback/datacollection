import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class C {
	static enum Status {
		USED_A, USED_B, UNUSED
	}

	private final long[] set;
	private final Status[] status;
	private long unused;

	static {
		Locale.setDefault(Locale.US);
	}

	public C(long[] set, long total) {
		this.set = set;
		this.unused = total;
		this.status = new Status[set.length];
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nrOfTestCases = scanner.nextInt();
		for (int caseNr = 1; caseNr <= nrOfTestCases; caseNr++) {
			System.out.println("Case #" + caseNr + ":\n" + solveCase(scanner));
		}
	}

	// String
	static String solveCase(Scanner scanner) {
		int count = scanner.nextInt();
		long[] set = new long[count];
		long total = 0;
		for (int i = 0; i < count; i++) {
			set[i] = scanner.nextInt();
			total += set[i];
		}
		Arrays.sort(set);
		return new C(set, total).solve();
	}

	private String solve() {
		StringBuilder sb = new StringBuilder();
		if (solveStart(set.length - 1)) {
			for (int i = 0; i < set.length; i++)
				if (status[i] == Status.USED_A)
					sb.append(set[i]).append(" ");
			sb.setCharAt(sb.length() - 1, '\n');
			for (int i = 0; i < set.length; i++)
				if (status[i] == Status.USED_B)
					sb.append(set[i]).append(" ");
			sb.setLength(sb.length() - 1);
			return sb.toString();
		} else
			return "Impossible";

	}

	private boolean solveStart(int pos) {
		if (pos < 0)
			return false;
		long cur = set[pos];
		unused -= cur;
		status[pos] = Status.USED_A;
		if (solve(pos - 1, set[pos], 0))
			return true;
		status[pos] = Status.UNUSED;
		if (solveStart(pos - 1))
			return true;
		return false;
	}

	private boolean solve(int pos, long sumA, long sumB) {
		if (sumA == sumB)
			return true;
		if (pos < 0)
			return false;
		if (sumA + unused < sumB || sumB + unused < sumA)
			return false;
		long cur = set[pos];
		unused -= cur;
		status[pos] = Status.UNUSED;
		if (solve(pos - 1, sumA, sumB))
			return true;
		status[pos] = Status.USED_A;
		if (solve(pos - 1, sumA + cur, sumB))
			return true;
		status[pos] = Status.USED_B;
		if (solve(pos - 1, sumA, sumB + cur))
			return true;
		unused += cur;
		return false;
	}
}
