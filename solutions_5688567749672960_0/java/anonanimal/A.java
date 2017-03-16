import java.util.Arrays;
import java.util.Scanner;


public class A {
	
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int i = 0; i < T; i++)
		{
			int ans = solve(in);
			System.out.printf("Case #%d: %d\n", i+1, ans);
		}

	}
	
	static int MAX = 1000005;
	
	public static int solve(Scanner in)
	{
		int N = in.nextInt();
		int[] min = new int[MAX];
		Arrays.fill(min, MAX+1);
		
		min[1] = 1;
		
		for (int cur = 1; cur <= N; cur++)
		{
			// The next is the minimum of this + 1 or its value
			min[cur + 1] = Math.min(min[cur + 1], min[cur] + 1);

			int reverse = reverse(cur);
			min[reverse] = Math.min(min[reverse], min[cur] + 1);
		}
		
		return min[N];
	}
	
	public static int reverse(int num)
	{
		int ans = 0;
		while (num > 0) {
			ans *= 10;
			ans += (num % 10);
			num /= 10;
		}
		return ans;
	}

}
