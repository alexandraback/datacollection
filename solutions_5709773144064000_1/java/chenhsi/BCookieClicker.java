import java.util.*;
import java.io.*;

public class BCookieClicker
{
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new BufferedReader(new FileReader("B-large.in")));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-large.out")));
		
		int t = in.nextInt();
		for (int i = 1; i <= t; i++)
		{
			double c = in.nextDouble();
			double f = in.nextDouble();
			double x = in.nextDouble();

			double best = Double.MAX_VALUE;
			boolean almostDone = false;

			double income = 2.0;
			double timePassed = 0;
			while (true)
			{
				double temp = x / income + timePassed;
				if (temp < best)
					best = temp;
				else
				{
					if (almostDone)
						break;
					almostDone = true;
				}
				timePassed += c / income;
				income += f;
			}
			out.println("Case #" + i + ": " + best);
		}
		out.flush();
		out.close();
	}
}