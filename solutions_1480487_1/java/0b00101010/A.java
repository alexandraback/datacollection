import java.util.Scanner;

public class A {
	public static void main (String[] args)
	{
		Scanner scan = new Scanner(System.in);
		int c = scan.nextInt();
		int n, x, nt;
		double target, target2, result;
		for (int cn = 1; cn <= c; cn++)
		{
			n = scan.nextInt();
			int[] Ji = new int[n];
			x = 0;
			for (int i = 0; i < n; i++)
			{
				Ji[i] = scan.nextInt();
				x += Ji[i];
			}
			System.out.print("Case #" + cn + ":");
			target = (2.0 * x) / n;
			target2 = target;
			if (n > 2)
			{
				int t = 0;
				int xt = 0;
				for (int j = 0; j < n; j++)
					if (Ji[j] <= target)
					{
						t++;
						xt += Ji[j];
					}
				target2 = (xt + (double) x) / t;
			}
			for (int i = 0; i < n; i++)
			{
				System.out.print(" ");
				if (Ji[i] >= target)
					System.out.print("0.0");
				else
				{
					result = 100 * (target2 - Ji[i]) / x;
					System.out.print(((result <= 0.0) ? "0.0" : result));
				}
			}
			System.out.println();
		}
	}
}
