package round1B.java;

import java.util.Arrays;
import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int cases = input.nextInt();
		for(int caseno = 1; caseno <= cases; caseno++)
			System.out.printf("Case #%d: %s%n", caseno, new A().solve(input));
	}

	int max = 1000001;
	int[] dp = new int[max];
	{
		int[] reverse = new int[max];
		for(int i = 0; i < max; i++)
		{
			int x = i, y = 0;
			while(x > 0) {
				y = y*10 + x%10;
				x /= 10;
			}
			reverse[i] = y;
		}
		
		int inf = 1<<30;
		Arrays.fill(dp, inf);
		int[] queue = new int[max];
		int head = 0, tail = 0;
		queue[tail++] = 1;
		dp[1] = 1;
		
		while(head < tail) {
			int cur = queue[head++];
			for(int next : new int[]{cur+1, reverse[cur]})
				if(next < max && dp[next] == inf) {
					dp[next] = dp[cur]+1;
					queue[tail++] = next;
				}
		}
	}
	
	
	String solve(Scanner input) {
		return "" + dp[input.nextInt()];
	}
}
