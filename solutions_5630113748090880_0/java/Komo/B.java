import java.util.*;
import java.io.*;

class B
{
	private static final String FILE = "B-small-attempt0";
	private static final String FILEIN = FILE + ".in";
	private static final String FILEOUT = FILE + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	private static void solve()
	{
		int n = in.nextInt();
		boolean[] a = new boolean[2501];
		for (int i=0;i<2*n*n-n;i++)
		{
			int h = in.nextInt();
			a[h] = !a[h];
		}
		List<Integer> l = new ArrayList<Integer>();
		for (int i=1;i<=2500;i++)
		{
			if (a[i])
			{
				l.add(i);
			}
		}
		Collections.sort(l);
		for (int i:l)
		{
			out.print(" "+i);
		}
		out.println();
		in.nextLine();
	}

	public static void main(String[] args) throws Exception
	{	
		in = new Scanner(new File(FILEIN));
		out = new PrintWriter(FILEOUT);
		int tests = in.nextInt();
		in.nextLine();
		for (int i=1;i<=tests;i++)
		{
			out.print( "Case #"+i+":");
			solve();
		}
		out.close();
	}
}