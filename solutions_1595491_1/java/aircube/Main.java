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
		int n = in.nextInt();
		int s = in.nextInt();
		int p = in.nextInt();
		int[] t = new int[n];
		for(int i = 0; i < n; ++i) {
			t[i] = in.nextInt();
		}
		int[][] d = new int[n + 1][n + 1];
		for(int[] dd : d)
			Arrays.fill(dd, -1);
				
				
		d[0][0] = 0;
		for(int i = 0; i < n; ++i) 
			for(int surp = 0; surp <= n; ++surp) {
				int cur = d[i][surp];
				if (cur == -1)
					continue;

				{
					// surprise					
					for(int d1=0; d1 <= 10; ++d1)
						for(int d2=d1; d2 <= 10; ++d2)
							for(int d3=d2; d3 <= 10; ++d3) {
								if (d1+d2+d3!=t[i] || d3-d1>2 || d3-d1==1)
									continue;
								int add = (d3 >= p ? 1 : 0);
								d[i + 1][surp + 1] = Math.max(d[i + 1][surp + 1], cur + add);
							}
				}
				{
					// not surprise
					for(int d1=0; d1 <= 10; ++d1)
						for(int d2=d1; d2 <= 10; ++d2)
							for(int d3=d2; d3 <= 10; ++d3) {
								if (d1+d2+d3!=t[i] || d3-d1 > 1)
									continue;
								int add = (d3 >= p ? 1 : 0);
								d[i + 1][surp] = Math.max(d[i + 1][surp], cur + add);
							}
				}
				
			}
		int ans = d[n][s];
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