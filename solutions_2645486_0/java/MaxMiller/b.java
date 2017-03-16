import java.util.*;

public class b {

	static int[] value;
	static int e, r, n;

	static long[][] memo;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int cases = in.nextInt();
		for(int casen=1; casen<=cases; ++casen) {
			e = in.nextInt(); r = in.nextInt(); n = in.nextInt();
			value = new int[n];
			for(int i=0; i<n; ++i) value[i] = in.nextInt();

			memo = new long[e+1][n+1];
			for(long[] mem : memo) Arrays.fill(mem,-1);

			System.out.println("Case #"+casen+": "+go(e, 0));
		}
	}

	static long go(int energy, int index) {
		if(energy <= 0 || index >= n) return 0;
		if(energy > e) energy = e;

		if(memo[energy][index] != -1) return memo[energy][index];

		long max = 0;

		// Use this activity, keep doing it
		max = Math.max(max, go(energy-1, index) + value[index]);
		// Use this activity, go to next
		max = Math.max(max, go(energy-1+r, index+1) + value[index]);
		// Don't use this activity, go to next
		max = Math.max(max, go(energy+r, index+1));

		return memo[energy][index] = max;
	}
}