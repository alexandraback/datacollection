import java.io.File;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;

public class ProbC {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("C-small.in"));
		PrintStream out = new PrintStream(new File("C-small.out"));
		
		int T = in.nextInt();
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int N = in.nextInt();
			String[] firsts = new String[N];
			String[] seconds = new String[N];
			for (int i = 0; i < N; i++) {
				firsts[i] = in.next();
				seconds[i] = in.next();
			}
			int max = 0;
			for (int mask = 0; mask < (1 << N); mask++) {
				HashSet<String> afirsts = new HashSet<>();
				HashSet<String> aseconds = new HashSet<>();
				for (int i = 0; i < N; i++) {
					if ((mask & (1 << i)) == 0) continue;
					afirsts.add(firsts[i]);
					aseconds.add(seconds[i]);
				}
				boolean valid = true;
				for (int i = 0; i < N; i++) {
					if ((mask & (1 << i)) != 0) continue;
					if (!afirsts.contains(firsts[i]) || !aseconds.contains(seconds[i])) {
						valid = false;
						break;
					}
				}
				if (valid) {
					max = Math.max(max, N - Integer.bitCount(mask));
				}
			}
			out.printf("Case #%d: %d%n", caseNum, max);
		}
	}
}
