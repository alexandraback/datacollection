import java.util.Scanner;

public class energy {
	static int[] vals;
	static int[][] memo;
	static int e;
	static int gain;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++) {
			e = in.nextInt();
			gain = in.nextInt();
			int n = in.nextInt();

			vals = new int[n];
			
			for (int j = 0; j < vals.length; j++) {
				vals[j] = in.nextInt();
			}
			memo = new int[n][e+1];

			System.out.printf("Case #%d: %d\n", i + 1, recurse(0, e));
		}
	}

	private static int recurse(int index, int energy) {
		
		if (index == memo.length)
			return 0;
		else if (memo[index][energy] != 0)
			return memo[index][energy];
		
		int max = 0;
		for (int i = 0; i <= energy; i++) {
			max = Math.max(max, (i * vals[index]) + recurse(index +1, Math.min(e, energy - i + gain)));
		}
		
		return memo[index][energy] = max;
	}
}
