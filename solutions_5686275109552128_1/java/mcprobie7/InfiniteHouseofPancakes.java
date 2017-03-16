import java.util.Scanner;
import java.io.*;


public class InfiniteHouseofPancakes {
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new File("B-large.in"));
		PrintWriter out = new PrintWriter(new File("outputBbig.txt"));
		int t = in.nextInt();
		for (int testn = 1; testn <= t; testn++)
		{
			int n = in.nextInt();
			int [] d = new int[n];
			for (int i = 0; i < n; i++) d[i] = in.nextInt();
			int ans  = 1000;
			for (int max = 1; max <= 1000; max++)
			{
				int cur = max;
				for (int j = 0; j < n; j++) 
				{
					cur += d[j] / max;
					if (d[j] % max == 0) cur--;
				}
				if (cur < ans) ans = cur;
			}
			out.println("Case #" + testn + ": " + ans);
		}
		in.close();
		out.close();
	}
}
