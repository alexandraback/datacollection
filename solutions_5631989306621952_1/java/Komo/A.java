import java.util.*;
import java.io.*;

class A
{
	private static final String FILE = "A-large";
	private static final String FILEIN = FILE + ".in";
	private static final String FILEOUT = FILE + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	private static void solve()
	{
		String s = in.nextLine();
		int len = s.length();
		String res = ""+s.charAt(0);
		for (int i=1;i<len;i++)
		{
			if (s.charAt(i)>=res.charAt(0))
			{
				res = s.charAt(i)+res;
			}
			else
			{
				res += s.charAt(i);
			}
		}
		out.println(res);
	}

	public static void main(String[] args) throws Exception
	{	
		in = new Scanner(new File(FILEIN));
		out = new PrintWriter(FILEOUT);
		int tests = in.nextInt();
		in.nextLine();
		for (int i=1;i<=tests;i++)
		{
			out.print( "Case #"+i+": ");
			solve();
		}
		out.close();
	}
}