import java.io.*;
import java.util.*;

public class test
{

	public static void main(String[] args) throws Exception
	{
		new test().run();
	}

	PrintWriter out = null;

	double play(int A, int B, double[] p)
	{
		double[] pp = new double[A];
		Arrays.fill(pp, 1.0);
		for (int i = 0; i < A; i++)
		{
			pp[i] = p[i];
			if (i > 0)
				pp[i] *= pp[i - 1];
		}

		double ans = Double.MAX_VALUE;

		// press enter right away
		ans = Math.min(ans, B + 2);

		// all back
		ans = Math.min(ans, A + B + 1);

		for (int i = 1; i <= A; i++)
		{
			int steps = A - i;

			double ret = steps + pp[i - 1] * (B - i + 1) + (1.0 - pp[i - 1])
					* (B - i + 1 + B + 1);
			ans = Math.min(ans, ret);
		}

		return ans;
	}

	void run() throws Exception
	{
		Scanner in = new Scanner(System.in);
		out = new PrintWriter(new FileWriter("gcj.txt"));

		int T = Integer.parseInt(in.nextLine());
		for (int i = 0; i < T; i++)
		{

			int A = in.nextInt();
			int B = in.nextInt();
			double[] p = new double[A];
			for (int j = 0; j < A; j++)
				p[j] = in.nextDouble();

			out.printf("Case #%d: %f\n", i + 1, play(A, B, p));
		}

		out.close();
	}
}
