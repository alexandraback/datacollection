import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class A {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;

    int[][] numCounts;
    public void task() throws IOException {
        String S = reader.readLine();
        int[] count = new int[26];
        for (int i = 0; i < S.length(); i++) {
            count[S.charAt(i) - 'A']++;
        }
        go(count, new int[10], 0);
    }

    public void prepare() {
        String[] numS = new String[]{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
        numCounts = new int[10][26];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < numS[i].length(); j++) {
                numCounts[i][numS[i].charAt(j) - 'A']++;
            }
        }
    }

    public void go (int[] count, int[] ans, int cur) {
        if (cur == 10) {
            boolean allGood = true;
            for (int i = 0; i < 26; i++) {
                if (count[i] > 0) {
                    allGood = false;
                    break;
                }
            }
            if (allGood) {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < ans[i]; j++) {
                        out.print(i);
                    }
                }
                out.println();
                //out.println(Arrays.toString(ans) + ", " + Arrays.toString(count));
            }
            return;
        }
        int max = Integer.MAX_VALUE / 2;
        for (int i = 0; i < 26; i++) {
            if (numCounts[cur][i] > 0) {
                max = Math.min(count[i] / numCounts[cur][i], max);
            }
        }
        for (int t = 0; t <= max; t++) {
            for (int i = 0; i < 26; i++) {
                count[i] -= numCounts[cur][i] * t;
            }
            ans[cur] += t;
            go(count, ans, cur+1);

            for (int i = 0; i < 26; i++) {
                count[i] += numCounts[cur][i] * t;
            }
            ans[cur] -= t;
        }
    }
        
	public void solve() throws IOException {
        prepare();
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
		new A().run();
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
