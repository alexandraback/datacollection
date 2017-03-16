import java.io.*;
import java.util.*;

public class ProblemA {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner cin = new Scanner(new File("A.in"));
		PrintStream cout = new PrintStream("A.out");
		int caseN = cin.nextInt();
		for (int caseI=1; caseI<=caseN; caseI++)
		{
			int n = cin.nextInt();
			double X = 0;
			double x[] = new double[n];
			for (int i=0; i<n; i++)
			{
				x[i] = cin.nextDouble();
				X += x[i];
			}
			for (int i=0; i<n; i++)
				x[i] /= X;
			double minh = 0, maxh = 2;
			while (maxh - minh > 1e-9)
			{
				double h = (minh + maxh)/2;
				double Y = 0;
				for (int i=0; i<n; i++)
					if (x[i] < h)
						Y += h - x[i];
				if (Y < 1)
					minh = h;
				else
					maxh = h;
			}
			cout.print("Case #" + caseI + ":");
			for (int i=0; i<n; i++)
			{
				cout.print(" " + 100 * Math.max(0, minh - x[i]));
			}
			cout.println();
		}
	}

}
