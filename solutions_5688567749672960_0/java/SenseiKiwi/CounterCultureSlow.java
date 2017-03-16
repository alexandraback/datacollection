package round1B;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class CounterCultureSlow {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		int cases;
		
		// Precompute solutions
		// This only works for the small cases, but I want it for testing.
		int[] distances = precomputeSolutions(1000000);
		
		cases = input.nextInt();
		for (int c = 1; c <= cases; c++)
		{
			int n = input.nextInt();
			System.out.printf("Case #%d: %d\n", c, distances[n]);
		}
	}
	
	static int[] precomputeSolutions(int maxN)
	{
		int[] distances = new int[maxN + 1];
		Queue<Integer> ordering = new LinkedList<Integer>();
		ordering.add(0);
		while (!ordering.isEmpty())
		{
			int n = ordering.remove();
			if (n + 1 <= maxN && distances[n + 1] == 0)
			{
				distances[n + 1] = distances[n] + 1;
				ordering.add(n + 1);
			}
			
			int nr = reverse(n);
			if (nr <= maxN && distances[nr] == 0)
			{
				distances[nr] = distances[n] + 1;
				ordering.add(nr);
			}
		}
		return distances;
	}
	
	static int reverse(int n)
	{
		char[] digits = String.valueOf(n).toCharArray();
		int val = 0;
		for (int k = digits.length - 1; k >= 0; k--)
			val = 10 * val + digits[k] - '0';
		
		return val;
	}

}
