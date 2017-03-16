import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {
	private int getAdded(long cur, int toGet) {
		if (cur == 1) {
			return Integer.MAX_VALUE/3;
		}
		
		int cnt = 0;
		while (cur <= toGet) {
			cur += cur-1;
			++cnt;
		}
		return cnt;
	}
	
	
	public void run() {
		int ntst = nextInt();
		
		for (int tst = 0; tst < ntst; ++tst) {
			long a = nextInt();
			int n = nextInt();
			int[] arr = new int[n];
			for (int i = 0; i < n; ++i) {
				arr[i] = nextInt();
			}
			Arrays.sort(arr);
			
			long[] maxSize = new long[n+1];
			int[] cntAdded = new int[n+1];
			Arrays.fill(cntAdded, -1);
			cntAdded[0] = 0;
			maxSize[0] = a;
			
			for (int i = 1; i <= n; ++i) {
				if (arr[i-1] < maxSize[i-1]) {
					cntAdded[i] = cntAdded[i-1];
					maxSize[i] = maxSize[i-1] + arr[i-1];
				}
				else {
					if (maxSize[i-1] == 1) {
						//can't add nothing
						break;
					}
					else {
						cntAdded[i] = cntAdded[i-1];
						maxSize[i] = maxSize[i-1];
						while (maxSize[i] <= arr[i-1]) {
							maxSize[i] += maxSize[i] - 1;
							++cntAdded[i];
						}
						maxSize[i] += arr[i-1];
					}
				}
			}
			
			int ans = Integer.MAX_VALUE;
			for (int i = 0; i <= n; ++i) {
				if (cntAdded[i] != -1) {
					ans = Math.min(ans, cntAdded[i] + n-i);
				}
			}
			out.println("Case #"+(tst+1)+": "+ans);
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
