import java.io.*;
import java.util.*;
public class b {
public static void main(String[] args) throws IOException
{
	Scanner input = new Scanner(System.in);
	PrintWriter out = new PrintWriter(new File("b.txt"));
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		out.print("Case #" + (t+1) + ": ");
		e = input.nextInt(); r = input.nextInt(); n = input.nextInt();
		v = new int[n];
		for(int i =0; i<n; i++) v[i] = input.nextInt();
		long res = 0;
		int[] link = new int[n];
		Arrays.fill(link, -1);
		for(int i = 0; i<n; i++)
			for(int j = i+1; j<n; j++)
				if(v[j]>v[i])
				{
					link[i] = j-i;
					break;
				}
		int at = 0, en = e;
		while(at<n)
		{
			if(link[at] == -1)
			{
				res += (long)en*v[at];
				en = Math.min(r,e);
				at++;
			}
			else
			{
				long needed = e - (long)link[at]*r;
				needed = Math.max(needed, 0);
				long use = Math.max(0, en-needed);
				//System.out.println(en+" "+use+" "+link[at]+" "+needed);
				en -= use;
				res += (long)use*v[at];
				at++;
				en += r;
				en = Math.min(en,e);
			}
		}
		out.println(res);
	}
	out.close();
}
static int e, r, n;
static int[] v;
public static int go(int at, int en)
{
	if(at==n) return 0;
	int res = 0;
	for(int i = 0; i<=en; i++)
	{
		res = Math.max(res, i*v[at] + go(at+1, Math.min(e, en-i+r)));
	}
	return res;
}
}
