import java.util.*;
 import java.io.*;
 import java.math.BigDecimal;
import java.math.BigInteger;




public class Main {

    
	static char[] map = new char[256];
	
    private void solve() throws Exception {
    	learning("sample1.txt", "answer1.txt");
    	
    	in = new FastScanner("input.txt", "output.txt");
    	int n = in.nextInt();
    	for(int i = 1; i <= n; ++i) {
    		String[] s = in.reader.readLine().split(" ");
    		out.print("Case #" + i + ": ");
    		for(int j = 0; j < s.length; ++j) {
    			out.print(convert(s[j]));
    			if (j != s.length - 1)
    				out.print(" ");
    		}
    		out.println();
    	}
    	
    }
    private String convert(String string) {
		String ans = "";
		for(int i = 0; i < string.length(); ++i) {
			char x = map[string.charAt(i)];
			if (x == 0)
				ans += "?";
			else
				ans += x;
		}
		return ans;
	}
	private void learning(String input, String output) {
		FastScanner fs1 = new FastScanner(input, "trash.txt");
		FastScanner fs2 = new FastScanner(output, "trash1.txt");
		int n = fs1.nextInt();
		for(int i = 0; i < n; ++i) {
			String[] spl1, spl2;
			try {
				spl1 = fs1.reader.readLine().split(" ");
				spl2 = fs2.reader.readLine().split(" ");
			} catch (Exception e) {
				e.printStackTrace();
				return ;
			}
			for(int j = 0; j < spl1.length; ++j) {
				String cipher = spl1[j];
				String plain = spl2[j + 2];
				for(int v = 0; v < cipher.length(); ++v) {
					map[cipher.charAt(v)] = plain.charAt(v);
				}
			}
		}
		
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