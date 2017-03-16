import java.util.HashSet;
import java.util.Scanner;


class ProblemCSmall {
	// Not happy that my previous approaches didn't work and that I have to do it this way, but whatever works...
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt(), I = 0;
		while (T --> 0) {
			int A = in.nextInt(), B = in.nextInt();
			int lenA = (int) Math.log10(A), lenB = (int) Math.log10(B);
			int prevStart = A;
			HashSet<String> pairs = new HashSet<String>();
			for (int i = lenA; i <= lenB; ++i) {
				int currPow10 = (int) Math.pow(10, i);
				int start = (int) Math.max(prevStart, currPow10), end = (int) Math.min(B, 10*currPow10-1);
				for (int j = start; j <= end; ++j) {
					int k = j;
					for (int l = 0; l < i; ++l) {
						k = (k % currPow10) * 10 + (k / currPow10);
						if (k >= start && k <= end && k != j) {
							pairs.add(String.format("%07d%07d", Math.min(j, k), Math.max(j, k)));
						}
					}
				}
				prevStart = end + 1;
			}
			System.out.printf("Case #%d: %d\n", ++I, pairs.size());
		}
	}

}
