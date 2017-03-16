import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {

	/**
	 * @param args
	 * @throws IOException
	 * @throws NumberFormatException
	 */
	static int[] m = new int[150];
	static int N;
	public static void main(String[] args) throws NumberFormatException,
			IOException
	{
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt1.in"));
//		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter p = new PrintWriter("out.txt");
		int T = Integer.parseInt(br.readLine());
		int[][] dp = new int[15][10000];
		for (int t = 1; t <= T; t++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int A = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++)
				m[i] = Integer.parseInt(st.nextToken());
			Arrays.sort(m, 0, N);
			for(int i = 0 ; i < dp.length;i++)
				Arrays.fill(dp[i], -1);
//			int op = 0;
//			for (int i = 0; i < N; i++)
//				if (A <= m[i])
//				{
//					if (2 * A - 1 > m[i])
//					{
//						// add 
//						A = 2 * A - 1 + m[i];
//					}
//					// remove
//					op++;
//				}else
//					A += m[i];
			int op = get(0 , A);
			p.println("Case #" + t + ": " + op);
		}
		p.close();
	}
	static int[][] dp;
	private static int get(int i, int size)
	{
		if(i == N)
			return 0;
		if(m[i] < size)
			return get(i+1, size+m[i]);
		int t = get(i+1, size);
		int op = 0;
		if(size == 1)
			op = 1 << 25;
		else
			while(size <= m[i])
			{
				size = 2*size-1;
				op++;
			}
		return Math.min(get(i+1, size+m[i])+op, t+1);
	}
}
