import java.util.Scanner;

public class A {
	static short[] digits = new short[9999990];
	public static void main(String[] args) {
		for(int i = 0; i < digits.length; i++)
			for(int x = i+1; x>0; x /= 10)
				digits[i] |= (1 << (x%10));
		
		Scanner in = new Scanner(System.in);
		int nt = in.nextInt();
		
		for(int t = 1; t <= nt; t++)
		{
			int res = solve( in.nextInt() );
			System.out.println( "Case #" + t + ": " + (res==-1?"INSOMNIA": res) );
		}
	}

	private static int solve(int n) {
		if(n == 0)
			return -1;
		short d = 0;
		for(int m = n; m < digits.length+1; m += n)
		{
			d |= digits[m-1];
			if(d==1023)
				return m;
		}
		throw new AssertionError(n);
	}
}
