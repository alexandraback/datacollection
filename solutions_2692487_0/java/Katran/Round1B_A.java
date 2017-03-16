import java.io.*;
import java.math.*;
import java.util.*;

public class Round1B_A implements Runnable {
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	boolean file = true;
	String fileName = "A-small";

	public static void main(String[] args) throws Exception {
		new Round1B_A().run();
	}

	private String next() throws Exception {
		if (st == null || !st.hasMoreElements())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	private int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	private long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	private double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}

	public void run() {
		try {
			if (file)
				in = new BufferedReader(new FileReader(fileName+".in"));
			else
				in = new BufferedReader(new InputStreamReader(System.in));
			if (file)
				out = new PrintWriter(new FileWriter(fileName+".out"));
			else
				out = new PrintWriter(System.out);
			solve();
		} catch (Exception ex) {
			throw new RuntimeException(ex);
		} finally {
			out.close();
		}
	}

	public void solve() throws Exception {
		long oo = 100000000000L;
		int cases = Integer.parseInt(in.readLine());
		for(int step = 1; step <= cases; step++){
			x = nextInt();
			a = new int[n = nextInt()];
			long ans = oo;
			for(int i=0; i<n; i++){
				a[i] = nextInt();
			}
			Arrays.sort(a);
			int lesser = 0;
			for(int i=0; i<n; i++, lesser++){
				if (x > a[i]){
					x += a[i];
				}else break;
			}
			System.out.println("Case ["+step+"]\tX = "+x+"\tlesser = "+lesser);
			if (lesser == n){
				printAns(step, 0); continue;
			}
			if (x == 1){
				printAns(step, n); continue;
			}
			for(int adds = 1; adds<=n; adds++){
				long curX = x;
				int l2 = lesser;
				for(int i=0; i<adds; i++){
					curX += (curX-1);
					for(int j=l2; j<n; j++, l2++){
						if (curX > a[j]){
							curX += a[j];
						} else{
							break;
						}
					}
					if (curX > oo) break;
				}
				ans = Math.min(ans, adds + (n-l2));
			}
			if (ans > n-lesser){
//				System.out.println("test is "+step+" ans = "+ans);
				ans = n-lesser;
			}
//			System.out.println("Case ["+step+"]\t Ans = "+ans+"\n");
			printAns(step, ans);
		}
	}
	int n, a[];
	long x;
	
	boolean can(int steps){
		
		return false;
	}
	
	void printAns(int step, long ans){
		out.println("Case #"+step+": "+ans);
	}
	
	public void printArr(int []a, int limit){
		for(int i=0; i<Math.min(a.length, limit); i++)
			System.out.print(a[i]+", ");
		System.out.println();
	}
	
}