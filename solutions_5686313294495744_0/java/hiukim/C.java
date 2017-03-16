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
        int N = nextInt();
        String[][] S = new String[N][];
        for (int i = 0; i < N; i++) {
            S[i] = reader.readLine().split(" ");
        }
        HashSet<String> set1 = new HashSet<String>();
        HashSet<String> set2 = new HashSet<String>();
        for (int i = 0; i < N; i++) {
            set1.add(S[i][0]);
            set2.add(S[i][1]);
        }

        int best = N;
        for (int i = 0; i < (1 << N); i++) {
            HashSet<String> sSet1 = new HashSet<String>();
            HashSet<String> sSet2 = new HashSet<String>();
            int used = 0;
            for (int j = 0; j < N; j++) {
                if ( ((1 << j) & i) != 0) {
                    sSet1.add(S[j][0]);
                    sSet2.add(S[j][1]);
                    used++;
                }
            }
            if (sSet1.size() == set1.size() && sSet2.size() == set2.size()) {
                if (used < best) {
                    best = used;
                }
            }
        }
        out.println( N - best);
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
