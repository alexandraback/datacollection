import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {
	
	private boolean isCons(char c) {
		return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
	}
	
	public void run() {
		int ntst = nextInt();
		
		for (int tst = 0; tst < ntst; ++tst) {
			long ans = 0;
			char[] name = nextWord().toCharArray();
			int cons = nextInt();
			
			int curPos = -1;
			long toAdd = 0;
			int n = name.length;
			for (int i = 0; i < n; ++i) {
				if (isCons(name[i])) {
					if (curPos == -1) {
						curPos = i;
					}
					if (i - curPos + 1 >= cons) {
						toAdd = i - cons + 2;
					}
				}
				else {
					if (curPos != -1) {
						curPos = -1;
						
					}
				}
				ans += toAdd;
			}
			/*if (curPos != -1) {
				if (n - curPos >= cons) {
					toAdd = n - cons + 1;
				}
				ans += toAdd;
			}*/
			
		/*	long ans2 = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = i+1; j <= n; ++j) {
					int ok = 0;
					int cur = -1;
					for (int k = i; k < j; ++k) {
						if (isCons(name[k])) {
							if (cur == -1) {
								cur = k;
							}
						}
						else {
							if (cur != -1) {
								ok = Math.max(ok, k-cur);
								cur = -1;
							}
						}
					}
					if (cur != -1) {
						ok = Math.max(j-cur, ok);
					}
					if (ok >= cons) {
						++ans2;
					}
				}
			}
			
			if (ans != ans2) {
				System.err.println(name);
				System.err.println(ans + " " + ans2);
			}*/
			
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
