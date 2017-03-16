import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		prepare();
		Scanner in = new Scanner(System.in);
		int ntests = in.nextInt();
		
		for (int test = 1; test <= ntests; test++) {
			long n = in.nextLong();
			System.out.println("Case #" + test + ": " + solve(n));
		}
	}
	private static int solve(long n) {
		if(n > 1000000)
		{
			long l = n;
			long k = 1;
			int g = 0;
			while(l >= 10)
			{
				l /= 10;
				k*=10;
				g++;
			}
			return 1+f(g)+solve(l % k);
		}
		return m[(int)n];
	}
	private static int f(int g) {
		if(g == 2)
			return 29;
		if( g % 2 == 1)
			return Integer.parseInt(1+""+(f(g-1) - 1));
		else
		{
			String a = ""+(f(g-1)-1);
			return Integer.parseInt(3+a.substring(1));
		}
	}
	static int[] m = new int[1000001];

	private static void prepare() {
		int n = 1000000;
		m[1] = 1;
		for(int i = 2; i < n + 1; i++)
		{
			int rev = reverse(i);
			if(i % 10 !=0 &&rev < i)
				m[i] = Math.min(m[rev], m[i-1]) + 1;
			else
				m[i] = m[i-1]+1;
		}
	}
	
	static int reverse(int a)
	{
		return Integer.parseInt(new StringBuilder(String.valueOf(a)).reverse().toString());
	}
}
