import java.io.*;
import java.util.Arrays;

class D
{
	public static void main (String[] args)
	{
		try
		{
			InputStreamReader fi2 = new InputStreamReader(System.in);
			BufferedReader fi = new BufferedReader(fi2);
			int T = Integer.parseInt(fi.readLine());
			for (int iT = 0; iT < T; iT++)
			{
				int N = Integer.parseInt(fi.readLine());
				double[] a = new double[N];
				double[] b = new double[N];
				String[] ln_a = fi.readLine().split("\\s");
				String[] ln_b = fi.readLine().split("\\s");
				int i;
				for (i = 0; i < N; i++)
				{
					a[i] = Double.parseDouble(ln_a[i]);
					b[i] = Double.parseDouble(ln_b[i]);
				}
				Arrays.sort(a);
				Arrays.sort(b);
				int j;
				int res1 = 0;
				int res2 = 0;
				i = 0;
				for (j = 0; j < N; j++)
				{
					while ((i < N) && (a[i] < b[j])) i++;
					if (i < N)
					{
						res1++;
						i++;
					}
				}
				j = 0;
				for (i = 0; i < N; i++)
				{
					while ((j < N) && (b[j] < a[i])) j++;
					if (j == N) res2++;
					else j++;
				}
				System.out.println("Case #" + Integer.toString(iT+1) + ": " + Integer.toString(res1) + " " + Integer.toString(res2));
			}
		}
		catch (IOException e) {}
	}
}