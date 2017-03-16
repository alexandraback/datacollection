import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class C {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    public void task() throws IOException {
        int[] A = new int[3];
        A[0] = nextInt();
        A[1] = nextInt();
        A[2] = nextInt();

        int K = nextInt();

        boolean[][][] worn = new boolean[A[0]][A[1]][A[2]];

        int ans = 0;
        for (int i = 0; i < A[0]; i++) {
            for (int j = 0; j < A[1]; j++) {
                for (int k = 0; k < A[2]; k++) {


                    int dup_ij = 0;
                    int dup_ik = 0;
                    int dup_jk = 0;

                    outer: for (int i2 = 0; i2 < A[0]; i2++) {
                        for (int j2 = 0; j2 < A[1]; j2++) {
                            for (int k2 = 0; k2 < A[2]; k2++) {
                                if (worn[i2][j2][k2]) {
                                   if (i == i2 && j == j2) {
                                       dup_ij++;
                                       if (dup_ij == K) break outer;
                                   }
                                   if (i == i2 && k == k2) {
                                       dup_ik++;
                                       if (dup_ik == K) break outer;
                                   }
                                   if (j == j2 && k == k2) {
                                       dup_jk++;
                                       if (dup_jk == K) break outer;
                                   }
                                }
                            }
                        }
                    }
                    if (dup_ij == K || dup_ik == K || dup_jk == K) {

                    } else {
                        ans++;
                        worn[i][j][k] = true;
                    }

                }
            }
        }

        out.println(ans);
        for (int i = 0; i < A[0]; i++) {
            for (int j = 0; j < A[1]; j++) {
                for (int k = 0; k < A[2]; k++) {
                    if (worn[i][j][k]) {
                        out.println( (i+1) + " " + (j+1) + " " + (k+1));
                    }
                }
            }
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
		new C().run();
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
