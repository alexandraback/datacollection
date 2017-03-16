import java.io.*;
import java.util.*;

public class ManageYourEnergy{
    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    public void run() throws Exception {
        in = new BufferedReader(new FileReader("B-small-attempt0.in"));
        out =new PrintWriter(new FileWriter("B.out"));
        //in = new BufferedReader(new InputStreamReader(System.in));
//        out = new PrintWriter(System.out);

        int T=nextInt();
        for (int i = 0; i < T; i++) {
			int E=nextInt();
			int R=nextInt();
			int N=nextInt();
			int[] v=new int[N];
			for (int j = 0; j < N; j++) {
				v[j]=nextInt();
			}
			int[][] dp=new int[N+1][E+1];
			for (int[] is : dp) {
				Arrays.fill(is, -1);
			}
			dp[0][E]=0;
			for (int j = 0; j < N; j++) {
				for (int k = 0; k <= E; k++) {
					if(dp[j][k]==-1) continue;
					for (int z = 0; z <= k; z++) {
						dp[j+1][Math.min(E, k-z+R) ]=Math.max(z*v[j]+dp[j][k],dp[j+1][Math.min(E, k-z+R) ]);
					}
				}
			}
			int maxScore=0;
			for (int j = 0; j <= E; j++) {
				maxScore=Math.max(maxScore, dp[N][j]);
			}
			out.println(String.format("Case #%d: %s", i+1,maxScore));	
		}

        out.flush();
        out.close();
        in.close();
    }

    public static void main(String[] args) throws Exception {
        new ManageYourEnergy().run();
    }

    String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(in.readLine());
            } catch (Exception e) {
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }
}
//2013-4-27 10:18:35

