import java.util.Scanner;


public class BoxFactory {
	
	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);

		int cases = input.nextInt();
		for (int c = 1; c <= cases; c++)
		{
			System.out.println("Case #" + c + ": " + solve(input));
		}
		
		input.close();
	}

	private static long solve(Scanner input) {
		
		int n = input.nextInt();
		int m = input.nextInt();
		long[] tCounts = new long[n];
		long[] tTypes = new long[n];
		long[] bCounts = new long[m];
		long[] bTypes = new long[m];
		
		for (int k = 0; k < n; k++)
		{
			tCounts[k] = input.nextLong();
			tTypes[k] = input.nextLong();
		}
		for (int k = 0; k < m; k++)
		{
			bCounts[k] = input.nextLong();
			bTypes[k] = input.nextLong();
		}
		return compute(0, 0, tCounts, tTypes, bCounts, bTypes);
	}

	private static long compute(int tDepth, int bDepth, long[] tCounts, long[] tTypes,
			long[] bCounts, long[] bTypes) {
		
		if (tDepth == tCounts.length || bDepth == bCounts.length)
			return 0;
		
		if (tTypes[tDepth] == bTypes[bDepth])
		{
			long drop = Math.min(tCounts[tDepth], bCounts[bDepth]);
			tCounts[tDepth] -= drop;
			bCounts[bDepth] -= drop;

			int tnDepth = tDepth + (tCounts[tDepth] == 0 ? 1 : 0);
			int bnDepth = bDepth + (bCounts[bDepth] == 0 ? 1 : 0);
			
			long result = compute(tnDepth, bnDepth, tCounts, tTypes, bCounts, bTypes);
			tCounts[tDepth] += drop;
			bCounts[bDepth] += drop;
			
			return result + drop;
		}
		else
		{
			long a = compute(tDepth + 1, bDepth, tCounts, tTypes, bCounts, bTypes);
			long b = compute(tDepth, bDepth + 1, tCounts, tTypes, bCounts, bTypes);
			return Math.max(a, b);
		}
	}
}
