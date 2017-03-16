import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	private static BufferedReader in;
	private static StringTokenizer st;
	private static PrintWriter out;

	public static void main(String[] args) throws NumberFormatException, IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		st= new StringTokenizer("");
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int T = Integer.parseInt(in.readLine());
		for (int test = 1; test <=T; test++) {
			System.out.print("Case #"+test+": ");
			String s[] = in.readLine().split("/");
			long P = Long.parseLong(s[0]);
			long Q = Long.parseLong(s[1]);
			long g = gcd(P, Q);
			Q /= g; 
			P /= g;
			long pow[] = new long [42];
			pow[0] = 1;
			for (int i = 1; i < 42; i++) {
				pow[i] = pow[i-1] * 2;
			}
			boolean impossible = true;
			int k = 0;
			for (int i = 0; i < 42; i++) {
				if(pow[i] == Q){
					k = i;
					impossible = false;
					break;
				}
			}
			if(impossible){
				System.out.println("impossible");
			}else{
				if(pow[k] >= P){
					int ans = 0;
					for (int i = 0; i < k; i++) {
						if(pow[i] < P){
							ans = i;
						}
					}
					System.out.println(k - ans);
				}else{
					System.out.println("impossible");
				}
			}
		}
		
		
		
		out.close();
	}

	private static long gcd(long a, long b) {
		if(b == 0)
			return a;
		else 
			return gcd(b, a % b);
	}

	private static double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(next());
	}

	private static long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(next());
	}

	private static int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(next());
	}

	private static String next() throws IOException {
		while(!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
}
