package QualificationRound.CookieClickerAlpha;

import java.io.PrintStream;
import java.util.Scanner;

public class Main
{
	private static Scanner in = new Scanner(System.in);
	private static PrintStream out = System.out;

	public static void main(String[] args)
	{
		int current = in.nextInt() + 1;
		for (int i = 1; i < current; i++)
		{
			check(i);
		}
	}

	private static void check(int current)
	{
		double c = in.nextDouble();
		double f = in.nextDouble();
		double x = in.nextDouble();

		double p = 2.0;
		double t = 0.0;

		while (true)
		{
			if (c / p + x / (p + f) < x / p)
			{
				t += c / p;
				p += f;
			} else
			{
				out.printf("Case #%d: %.7f\n", current, t + x / p);
				break;
			}
		}
	}
}
