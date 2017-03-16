import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		prepare();
		Scanner in = new Scanner(System.in);
		int ntests = in.nextInt();
		
		for (int test = 1; test <= ntests; test++) {
			int n = in.nextInt();
			System.out.println("Case #" + test + ": " + solve(n));
		}
	}
	private static int solve(int n) {
		return m[n];
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
