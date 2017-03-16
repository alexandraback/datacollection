import java.io.*;
import java.util.Scanner;
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
		out.println(go(0, e));
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
