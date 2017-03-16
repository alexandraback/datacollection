import java.util.*;
import java.io.*;
public class a {
public static void main(String[] args) throws IOException
{
	Scanner input = new Scanner(System.in);
	PrintWriter out = new PrintWriter(new File("a.txt"));
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		out.print("Case #" + (t+1) + ": ");
		long r= input.nextLong(), tt = input.nextLong();
		long lo = 0, hi = (long)1e9+7;
		while(hi>lo+1)
		{
			long mid = (hi+lo)/2;
			if(good(r,tt,mid))
				lo = mid;
			else
				hi = mid;
		}
		out.println(good(r,tt,lo+1) ? lo+1 : lo);
	}
	out.close();
}
public static boolean good(long r, long t, long a)
{
	double used = 2.*a*r + 4.*a*(a-1)/2 + a;
	return used <= t;
}
}
