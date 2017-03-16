import java.util.*;
public class C {
	public static void printSubset(int subset, int[] arr) {
		StringBuffer buf = new StringBuffer();
		for (int i = 0; i < arr.length; i++) {
			if ((subset & (1<<i)) != 0) buf.append(arr[i]).append(' ');
		}
		System.out.println(buf.toString().trim());
	}
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		CASE: for (int ca = 1; ca <= T; ca++) {
			int N = s.nextInt();
			int[] S = new int[N];
			int sum = 0;
			for (int i = 0; i < N; i++) { S[i] = s.nextInt(); sum += S[i]; }
			int[] seen = new int[sum+1];
			Arrays.fill(seen, -1);
			seen[0] = 0;
			System.out.printf("Case #%d:\n",ca);
			for (int i = 0; i < N; i++) {
				for (int x = sum - S[i]; x >= 0; x--) {
					if (seen[x] != -1) {
						if (seen[x + S[i]] != -1) {
							printSubset(seen[x + S[i]], S);
							printSubset(seen[x] | (1<<i), S);
							continue CASE;
						}
						seen[x + S[i]] = seen[x] | (1<<i);
					}
				}
			}
			System.out.println("Impossible");
		}
	}
}
