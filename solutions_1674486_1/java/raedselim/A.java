
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws FileNotFoundException
	{
//		 Scanner scan = new Scanner(new File("A-small-attempt0.in"));
		 Scanner scan = new Scanner(new File("A-large.in"));
//		Scanner scan = new Scanner(new File("in.txt"));
		PrintWriter p = new PrintWriter(new File("out.txt"));

		int t = scan.nextInt();
		for (int k = 1; k <= t; k++)
		{
			int n = scan.nextInt();
			g = new ArrayList[n];
			v = new boolean[n];
			
			for (int i = 0; i < n; i++)
				g[i] = new ArrayList<Integer>();

			for (int i = 0; i < n; i++)
			{
				int m = scan.nextInt();
				for (int j = 0; j < m; j++)
					g[i].add(scan.nextInt()-1);
			}
			
			
			
			boolean f = false;
			for(int i = 0 ;i  < n;i++)
			{
				Arrays.fill(v, false);
				f = dfs(i);
				if(f)
					break;
			}
//			System.out.println("Case #" + k + ": " + (f? "Yes":"No"));
			p.println("Case #" + k + ": " + (f? "Yes":"No"));
		}

		p.close();
		scan.close();
	}

	static ArrayList<Integer>[] g;
	static boolean[] v;

	public static boolean dfs(int p)
	{
		v[p]  = true;
		for (int to : g[p])
			if (!v[to])
			{
				boolean f = dfs(to);
				if(f)
					return true;
			} else
				return true;
		return false;
	}

}
