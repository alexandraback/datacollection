package codejam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;

public class ProblemB
{
	static int N;
	static int[] a, b;
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("in.txt"));
		PrintStream out = new PrintStream("out.txt");
//		out = System.out;
		
		int T = Integer.parseInt(in.readLine());
		
		for (int t = 0; t < T; t++)
		{
			N = Integer.parseInt(in.readLine());
			a = new int[N];
			b = new int[N];
			for (int i = 0; i < N; i++)
			{
				String[] tok = in.readLine().split(" ");
				a[i] = Integer.parseInt(tok[0]);
				b[i] = Integer.parseInt(tok[1]);
			}
			
			ans = Integer.MAX_VALUE;
			go(N);
//			int stars = 0;
//			int completed = 0;
//			
//			while (stars < 2*N)
//			{
//				int level = -1;
//				for (int lvl = 0; lvl < N; lvl++)
//				{
//					if (stars < a[lvl]) continue; // can't even pass with 1 star
//					if (b[lvl] < 0) continue; // already passed with 2 stars
//					if (a[lvl] < 0 && stars < b[lvl]) continue;
//					level = lvl;
//					if (stars >= b[lvl]) break;
//				}
//				if (level < 0) break;
////System.out.printf("%d (%d) #%d [%d %d]\n", completed, stars, level, a[level], b[level])
//				if (b[level] >= 0 && stars >= b[level])
//				{
//					b[level] = -1;
//					stars++;
//				}
//				if (a[level] >= 0 && stars >= a[level])
//				{
//					a[level] = -1;
//					stars++;
//				}
//				completed++;
//			}
			out.printf("Case #%d: %s\n", t+1, ans > 2*N ? "Too Bad" : ans+"");
		}
		
		out.close();
	}
	
	static int ans = 0;
	static int[] order = {0,1,2,3,4,5,6,7,8,9};
	
	static void go(int k)
	{
		if (k == 1)
		{
			solve();
			return;
		}
		for (int i = 0; i < k; i++)
		{
			int tmp = order[i];
			order[i] = order[k-1];
			order[k-1] = tmp;
			go(k-1);
			order[k-1] = order[i];
			order[i] = tmp;
		}
	}
	
	static void solve()
	{
		int stars = 0, completed = 0;
		boolean[][] passed = new boolean[N][2];
		
		for (int i = 0; i < N; i++)
		{
			int level = order[i];
			if (!passed[level][0] && stars < a[level]) return;
			if (!passed[level][1] && stars >= b[level])
			{
				passed[level][1] = true;
				stars++;
				if (!passed[level][0] && stars >= a[level])
				{
					passed[level][0] = true;
					stars++;
				}
				completed++;
			}
			else if (!passed[level][0] && stars >= a[level])
			{
				passed[level][0] = true;
				stars++;
				completed++;
			}
			boolean changed = true;
			while (changed)
			{
				changed = false;
				for (int lvl = 0; lvl < N; lvl++)
				{
					if (!passed[lvl][1] && stars >= b[lvl])
					{
						passed[lvl][1] = true;
						stars++;
						if (!passed[lvl][0])
						{
							passed[lvl][0] = true;
							stars++;
						}
						completed++;
						changed = true;
					}
				}
			}
		}
		if (stars == 2*N && completed < ans)
		{
			ans = completed;
		}
	}
}
