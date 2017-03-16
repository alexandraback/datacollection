import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		solve(new int[]{2,2,3,2});
		Scanner in = new Scanner(System.in);
		int nt = in.nextInt();
		for (int t = 1; t <= nt; t++) {
			int n = in.nextInt();
			int[] f = new int[n];
			for (int i = 0; i < n; i++)
				f[i] = in.nextInt() - 1;
			System.out.println("Case #" + t + ": " + solve(f));
		}
	}

	private static int solve(int[] f) {
		int res = 0;
		for (int i = 0; i < f.length; i++) {
			int len = cycleFrom(f, i);
			if (len > res)
				res = len;
		}
		
		int[][] dist = new int[f.length][f.length];
		for(int i = 0; i < f.length; i++)
			for(int j = 0; j < f.length; j++)
				if(i != j)
					dist[i][j] = -1;
		
		for(int i = 0; i < f.length; i++)
		{
			int d = 1;
			int j = f[i];
			while(dist[i][j] == -1)
			{
				dist[i][j] = d++;
				j = f[j];
			}
		}
		
		int sum = 0;
		for (int i = 0; i < f.length; i++)
			if (i == f[f[i]] && i < f[i]) {
				int a = 0;
				int b = 0;
				for(int k = 0; k < f.length; k++)
					if(k != i && k != f[i])
					{
						int dToA = dist[k][i];
						int dToB = dist[k][f[i]];
						if(dToA == -1)
							continue;
						if(dToA < dToB)
						{
							if(a < dToA)
								a = dToA;
						}else
						{
							if(b < dToB)
								b = dToB;
						}
					}
				sum += a+b+2;
			}
		return Math.max(sum, res);
	}

	private static int cycleFrom(int[] f, int i) {
		int[] used = new int[f.length];
		int j = 0;
		while (used[i] == 0) {
			used[i] = ++j;
			i = f[i];
		}
		return j - used[i] + 1;
	}
}
