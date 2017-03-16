import java.io.*;
import java.util.*;

public class A {
	static BufferedReader in;
	static StringTokenizer st;
	static PrintWriter out;
	
	static String nextToken() throws IOException {
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader("A.in"));
		out = new PrintWriter(new FileWriter("A.out"));
		
		int qq = nextInt();
		for (int q=1; q<=qq; q++) {
			out.printf("Case #%d: ", q);
			int max = nextInt();
			int ans = 0;
			int sum = 0;
			
			char[] shy = nextToken().toCharArray();
			for (int i=0; i<=max; i++) {
				if (i > sum) {
					ans += i - sum;
					sum = i;
				}
				sum += shy[i]-'0';
			}
			
			out.println(ans);
		}
		out.close();
	}
}
