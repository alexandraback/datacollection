import java.util.*;
import java.math.*;

public class A
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int test = 1, cases = sc.nextInt();
		int a, b;
		double p, min;
		double[] probs, mults;
		int c = 0;

		while(test <= cases)
		{
			a = sc.nextInt();
			b = sc.nextInt();

			probs = new double[a];
			mults = new double[a];

			min = b + 2;

			for(c = 0; c < a; c++)
			{
				probs[c] = sc.nextDouble();
			}

			multiplySequences(probs, mults);

			for(c = 0; c < a; c++)
			{
				min = Math.min(mults[a - c - 1] * (b - a + 1 + (2 * c)) + (1 - mults[a - c - 1]) * ((2 * b) - a + 2 + (2 * c)), min);
			}

			System.out.print("Case #" + test + ": ");
			System.out.format("%f\n", min);

			test++;
		}
	}

	public static void multiplySequences(double[] probs, double[] mults)
	{
		int size = probs.length, count = 0;
		double m = 1;

		for(count = 0; count < size; count++)
		{
			m *= probs[count];
			mults[count] = m;
		}
	}
}