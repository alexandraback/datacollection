import java.util.*;
 import java.io.*;
 import java.math.BigDecimal;
import java.math.BigInteger;




public class Main {

    
	
    private void solve() throws Exception {
    	int test = in.nextInt();
    	for(int t=1; t <= test; ++t) {
    		solveTest(t);
    		out.println();
    	}
    }
	private void solveTest(int testNum) {
		int a=in.nextInt();
		int b=in.nextInt();
		int ans = 0;
		int[] used = new int[10000000];
		int T=1;
		for(int n=a; n <= b; ++n) {
			String str=Integer.toString(n);
			++T;
			for(int shift=0; shift < str.length(); ++shift) {
				str = str.substring(1) + str.charAt(0);
				if (str.charAt(0) == '0')
					continue;
				int m = Integer.parseInt(str);
				if (m < a || m > b || m <= n || used[m] == T)
					continue;
				used[m] = T;
				//out.println(n + " " + m);
				++ans;
			}
		}
		out.print("Case #" + testNum + ": " + ans);
		
	}
	private void run() {
        try {
            long start = System.currentTimeMillis();
            in = new FastScanner("input.txt", "output.txt");
            solve();
            out.flush();
            System.err.print("running time = " + (System.currentTimeMillis() - start) * 1e-3);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    
    public static void main(String[] args) {
        Main main = new Main();
        main.run();
    }
    FastScanner in;
    static PrintWriter out;
    static class FastScanner {
        public BufferedReader reader;
        private StringTokenizer tokenizer;
        public FastScanner(String input, String output) {
            try {
                reader = new BufferedReader(new FileReader(new File(input)));
                out = new PrintWriter(new File(output));
                tokenizer = null;
            } catch (Exception e) {
                reader = new BufferedReader(new InputStreamReader(System.in));
                out = new PrintWriter(System.out);
                tokenizer = null;
            }
        }
        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }
        public String nextToken() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
            return tokenizer.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(nextToken());
        }
        long nextLong() {
            return Long.parseLong(nextToken());
        }
    }
 }