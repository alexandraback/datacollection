import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class BCodeJam
{
	public static boolean solve(int[][] v)
	{
		int n = v.length, m = v[0].length;
		int[][] t = new int[n][m];
		
		for (int j = 0; j < m; j++)
		{
			int max = v[0][j];
			for (int i = 0; i < n; i++)
				max = Math.max(v[i][j], max);
			for(int i = 0 ; i < n ; i++)
				t[i][j] = max;
		}
		boolean f = true;
		for(int i = 0 ; i < n && f ; i++)
		{
			if(Arrays.equals(t[i], v[i]))
				continue;
			int max = v[i][0];
			for(int j = 0 ; j < m ; j++)
				max = Math.max(v[i][j], max);
			for(int j = 0 ; j < m ; j++)
				t[i][j] = t[i][j] > max ? max : t[i][j];
				if(Arrays.equals(t[i], v[i]))
					continue;
			return false;
		}
		return f;
	}

	public static void main(String[] args) throws FileNotFoundException
	{
		Scanner in = new Scanner(new File("D:\\D\\B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("D:\\D\\output.txt"));
		int t = in.nextInt();
		for (int tc = 1; tc <= t; tc++)
		{
			int n = in.nextInt(), m = in.nextInt();
			int[][] v = new int[n][m];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					v[i][j] = in.nextInt();
			out.printf("Case #%d: ", tc);
			if (solve(v))
				out.println("YES");
			else
				out.println("NO");
		}
		out.close();

	}
}
