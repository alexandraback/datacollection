import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class B1 {

	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;
	
	public static void main(String[] args) throws IOException{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int testNumber = nextInt();
		for (int test = 1; test <= testNumber; test++) {
			pw.print("Case #"+test+": ");
			int A = nextInt();
			int B = nextInt();
			int K = nextInt();
			int ans = 0;
			for (int i = 0; i < A; i++) {
				for (int j = 0; j < B; j++) {
					if ((i & j) < K)
						ans++;
				}
			}
			pw.println(ans);
			
		}
		pw.close();
	}

	private static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	private static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	private static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	private static String next() throws IOException{
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

}
