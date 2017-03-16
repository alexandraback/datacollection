import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class B {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    public void task() throws IOException {
        int B = nextInt();
        long M = nextLong();

        int[][] ans = new int[B][B];
        for (int i = 0; i < B; i++) {
            for (int j = 0; j < B; j++) {
                if (i < j && j < B-1) {
                    ans[i][j] = 1;
                }
            }
        }
        ans[0][B-1] = 1;

        long need = M - 1;
        long sum = 0;
        for (int i = 0; i < B-2; i++) {
            if ((need & (1L << i)) != 0) {
                ans[i+1][B - 1] = 1;
                sum += (1L << i);
            }
        }
        if (sum < need) {
            out.println("IMPOSSIBLE");
            return;
        }

        out.println("POSSIBLE");
        for (int i = 0; i < B; i++) {
            for (int j = 0; j < B; j++) {
                out.print(ans[i][j]);
            }
            out.println();
        }

    }

	public void solve() throws IOException {
		int T = nextInt();
		for(int t = 1; t <= T; t++){
			out.print("Case #" + (t) + ": ");
			task();
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new B().run();
	}
	
	public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            out = new PrintWriter(System.out);
            solve();
            reader.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

}
