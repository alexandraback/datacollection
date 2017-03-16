import java.util.Scanner;


public class lawn {

	public static void main(String[] args) {
		Scanner c = new Scanner(System.in);
		int t = c.nextInt();
		for(int i = 1; i <= t; ++i)	{
			System.out.print("Case #"+i+": ");
			int N = Integer.parseInt(c.next()), M = Integer.parseInt(c.next());
			int[][] lawn = new int[N][M];
			for(int j = 0; j < N; ++j)
				for(int k = 0; k < M; ++k)
					lawn[j][k] = Integer.parseInt(c.next());
			boolean possible = true;
			for(int j = 0; j < N; ++j)
				for(int k = 0; k < M; ++k)	{
					int mc = 0, mr = 0;
					for(int n = 0; n < N; ++n)
						mc = Math.max(mc, lawn[n][k]);
					for(int m = 0; m < M; ++m)
						mr = Math.max(mr, lawn[j][m]);
					if(lawn[j][k] != mr && lawn[j][k] != mc)
						possible = false;
				}
			System.out.println(possible?"YES":"NO");
		}
		c.close();
	}

}
