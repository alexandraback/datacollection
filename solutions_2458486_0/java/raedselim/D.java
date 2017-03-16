import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class D {

	/**
	 * @param args
	 * @throws IOException 
	 */
	static int[] dp  = new int[1<<20]; 
	static int[] par  = new int[20]; 
	static int n;
	static int[] ti = new int[20];
	@SuppressWarnings("unchecked")
	static LinkedList<Integer>[] ks = new LinkedList[20];
	public static void main(String[] args) throws IOException
	{
		int[] ki = new int[205];
		BufferedReader br = new BufferedReader(new FileReader("D-small-attempt1.in"));
		PrintWriter p = new PrintWriter("out.txt");
		int T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T;t++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int k = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			Arrays.fill(ki,0);
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < k;i++)
				ki[Integer.parseInt(st.nextToken())]++;
			for(int i = 0 ; i < n;i++)
			{
				st = new StringTokenizer(br.readLine());
				ti[i] = Integer.parseInt(st.nextToken());
				int kz = Integer.parseInt(st.nextToken());
				ks[i] = new LinkedList<Integer>();
				for(int  j = 0 ; j < kz;j++)
					ks[i].add(Integer.parseInt(st.nextToken()));
			}
			String res = " IMPOSSIBLE";
			Arrays.fill(dp, -1);
			Arrays.fill(par, -1);
			if(can(0,-1,ki) == 1)
			{
				res = "";
				int cur = -1;
				for(int i = 0; i < n;i++)
					if(dp[1<<i] == 1)
					{
						cur = i;
						break;
					}
				while(cur != -1)
				{
					res += " "+(cur+1);
					cur = par[cur];
				}
			}
			p.println("Case #"+t+":"+res);
		}
		p.close();
	}
	private static int can(int mask, int last , int[] ki)
	{
		if(mask == (1 << n)-1)
			return dp[mask] = 1;
		if(dp[mask] != -1)
			return dp[mask];
		for(int i = 0 ; i < n;i++)
			if((mask&(1<<i)) == 0 && ki[ti[i]] > 0)
			{
				ki[ti[i]]--;
				for(int a:ks[i])
					ki[a]++;
				if(can(mask|(1<<i), i, ki) == 1)
				{
					if(last != -1)
						par[last] = i;
					return dp[mask] = 1;
				}
				ki[ti[i]]++;
				for(int a:ks[i])
					ki[a]--;
			}
		return dp[mask] = 0;
	}

}
