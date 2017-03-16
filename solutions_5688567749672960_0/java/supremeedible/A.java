import java.util.Scanner;

public class A {
	public static int flip(int x)
	{
		int flip = 0;
		
		if (x % 10 == 0)
		{
			return Integer.MAX_VALUE;
		}
		
		while (x > 0)
		{
			flip = flip * 10 + (x % 10);
			x /= 10;
		}
		
		return flip;
	}
	
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		
		int T = scan.nextInt();
		
		int[] m = new int[T];
		int N = 0;
		
		for (int Q = 0; Q < T; Q++)
		{
			m[Q] = scan.nextInt();
			
			if (m[Q] > N)
			{
				N = m[Q];
			}
		}
		
		int[] x = new int[N + 1];
		
		x[1] = 1;
		
		for (int i = 2; i <= N; i++)
		{
			int flipped = flip(i);
			
			x[i] = x[i - 1] + 1;
			
			if (flipped < i && x[flipped] < x[i])
			{
				x[i] = x[flipped] + 1;
			}
		}
		
		for (int Q = 0; Q < T; Q++)
		{
			System.out.printf("Case #%d: %d\n", Q + 1, x[m[Q]]);
		}
		
		scan.close();
	}
}
