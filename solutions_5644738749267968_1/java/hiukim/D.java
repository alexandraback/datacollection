import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class D {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    public void task() throws IOException {
    	int N = nextInt();
    	double[] A = new double[N];
    	double[] B = new double[N];
    	for (int i = 0; i < N; i++) {
    		A[i] = nextDouble();
    	}
    	for (int i = 0; i < N; i++) {
    		B[i] = nextDouble();
    	}
    	Arrays.sort(A);
    	Arrays.sort(B);
    	
    	int lose = 0;
    	int curA = 0;
    	int curB = 0;
    	int cntB = 0;
    	while (curA < N && curB < N-lose) {
    		if (A[curA] < B[curB]) {
    			curA++;
    			if (cntB > 0) cntB--;
    			else lose++;
    		} else {
    			curB++;
    			cntB++;
    		}
    	}
    	int ans1 = N-lose;

    	int beat = 0;
    	curB = 0;
    	for (int i = 0; i < N; i++) {
    		while (curB < N && B[curB] < A[i]) {
    			curB++;
    		}
    		if (curB < N) {
    			curB++;
    			beat++;
    		}
    		if (curB == N) break;    		
    	}
    	int ans2 = N - beat;
    	
    	out.println(ans1 + " " + ans2);
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
		new D().run();
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
