import java.io.*;
import java.util.*;


public class B {
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
		in = new BufferedReader(new FileReader("B.in"));
		out = new PrintWriter(new FileWriter("B.out"));
		
		int qq = nextInt();
		for (int q=1; q<=qq; q++) {
			out.printf("Case #%d: ", q);
			int num = nextInt();
			int[] diners = new int[num];
			
			int best = 0;
			for (int i=0; i<num; i++) {
				diners[i] = nextInt();
				if (diners[i] > best) best = diners[i];
			}
			
			for (int i=1; i<best; i++) {
				int count = 0;
				for (int j=0; j<num; j++) {
					count += diners[j]/i;
					if (diners[j]%i == 0) count--;
				}
				if (count+i < best) best = count+i;
			}
			out.println(best);
		}
		out.close();
	}
}
