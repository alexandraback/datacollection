import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {
	
	private boolean ok(double val, int[] arr, int idx) {
		double minVal = arr[idx] + sum*val;
		
		double rem = 1.0 - val;
		for (int i = 0; i < arr.length; ++i) {
			if (i != idx) {
				if (arr[i] < minVal) {
					double req = (minVal - arr[i])/sum;
					rem -= req;
				}
			}
		}
		
		return rem >= 0.0;
	}
	
	private int sum = 0;
	public void run() {
		int tst = nextInt();
		for (int i = 0; i < tst; ++i) {
			int n = nextInt();
			int[] arr = new int[n];
			sum = 0;
			for (int j = 0; j < n; ++j) {
				arr[j] = nextInt();
				sum += arr[j];
			}
			
			double[] ans = new double[n];
			for (int j = 0; j < n; ++j) {
				double l = 0.0;
				double r = 1.0;
				
				for (int iter = 0; iter < 100; ++iter) {
					double mid = (l+r)/2;
					
					if (ok(mid, arr, j)) {
						l = mid;
					}
					else {
						r = mid;
					}
				}
				
				ans[j] = l;
			}
			
			out.print("Case #"+(i+1)+":");
			for (int j = 0; j < n; ++j) {
				out.printf(Locale.ENGLISH, " %.8f", ans[j]*100);
			}
			out.println();
		}
		out.flush();
	}
	
	private static BufferedReader br = null;
	private static StringTokenizer stk = null;
	private static PrintWriter out = null;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(new File("D:\\A.txt")));
		out = new PrintWriter("D:\\AA.txt");
		(new Thread(new A())).start();
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
