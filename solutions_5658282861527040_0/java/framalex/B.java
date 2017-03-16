import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {
	
	//private long getAns(long k, long A, long B) {
		
	//}
	
	public void run() {
		int cases = nextInt();
		for (int cs = 0; cs < cases; ++cs) {
			int A = nextInt();
			int B = nextInt();
			int K = nextInt();
			
			
			
			int ans = 0;
			for (int aa = 0; aa < A; ++aa) {
				for (int bb = 0; bb < B; ++bb) {
					if ((aa & bb) < K) {
						++ans;
					}
				}
			}
			
			out.println("Case #"+ (cs+1) + ": " + ans);
		}
		out.flush();
	}
	
	private static BufferedReader br = null;
	private static StringTokenizer stk = null;
	private static PrintWriter out = null;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(new File("D:\\B.txt")));
		out = new PrintWriter("D:\\BB.txt");
		(new Thread(new B())).start();
	}
	
	public void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public String nextLine() {
		try {
			return (br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	public int nextInt() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Integer.parseInt(stk.nextToken());
	}
	
	public long nextLong() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Long.parseLong(stk.nextToken());
	}
	
	public double nextDouble() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Double.parseDouble(stk.nextToken());
	}
	
	public String nextWord() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return (stk.nextToken());
	}
}
