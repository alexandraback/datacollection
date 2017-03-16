import java.util.*;
import java.io.*;

public class gcj2 {
	public static void main(String [] args) throws Exception
	{
		Scanner scanner = new Scanner(new FileInputStream("B-small-attempt0.in"));
		int tot = scanner.nextInt();
		int m, n;
		for (int tt = 0; tt < tot; tt ++)
		{
			n = scanner.nextInt();
			m = scanner.nextInt();
			int [][] a = new int[n][m];
			for (int j = 0; j < n; j ++)
				for (int i = 0; i < m; i ++) a[j][i] = scanner.nextInt();
			int [] maxn = new int[n];
			int [] maxm = new int[m];
			int [][] b = new int[n][m];
			for (int i = 0; i < m; i ++) for (int j = 0; j < n; j ++) b[j][i] = 100;
			for (int j = 0; j < n; j ++)
			{
				int max = 0;
				for (int i = 0; i < m; i ++) if (max < a[j][i]) max = a[j][i];
				for (int i = 0; i < m; i ++) if (b[j][i] > max) b[j][i] = max;
			}
			for (int i = 0; i < m; i ++)
			{
				int max = 0;
				for (int j = 0; j < n; j ++) if (max < a[j][i]) max = a[j][i];
				for (int j = 0; j < n; j ++) if (b[j][i] > max) b[j][i] = max;
			}
			boolean ret = true;
			for (int i = 0; i < m; i ++)
			{
				for (int j = 0; j < n; j ++)
				{
					if (b[j][i] != a[j][i])
					{
						ret = false; break;
					}
				}
				if (!ret) break;
			}
			System.out.println("Case #" + (tt + 1) + ": " + (ret?"YES":"NO"));
		}
		scanner.close();
	}
}
