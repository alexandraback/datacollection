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
			
			Map<Integer, Integer> seg = new TreeMap<Integer, Integer>();
			int curPos = -1;
			int n = name.length;
			for (int i = 0; i < n; ++i) {
				if (isCons(name[i])) {
					if (curPos == -1) {
						curPos = i;
					}
				}
				else {
					if (curPos != -1) {
						seg.put(curPos, i-1);
						curPos = -1;
						
					}
				}
			}
			if (curPos != -1) {
				seg.put(curPos, n - 1);
			}
			
			int cnt = 0;
			int[] st = new int[seg.size()];
			int[] en = new int[seg.size()];
			for (int startPos : seg.keySet()) {
				int endPos = seg.get(startPos);
				if (endPos - startPos + 1 >= cons) {
					st[cnt] = startPos;
					en[cnt] = endPos;
					++cnt;
				}
			}
			//Arrays.sort(st);
			//Arrays.sort(en);
			
		/*	for (int i = 0; i < cnt; ++i) {
				long add = 0;
				int st1 = 0;
				int st2 = en[i] - cons + 1;
				
				int en1 = en[i];
				int en2 = en1;
				if (i == cnt-1) {
					en2 = n-1;
				}
				else {
					en2 = st[i+1] + cons-2;
				}
				add = 1L*(st2-st1 + 1) * (en2 - en1 + 1);
				
				int len = en[i] - st[i] + 1;
				if (len > cons) {
					add += 1L*(len-cons)*(len-cons+1)/2;
				}
				
				ans += add;
			}
			*/
			long ans2 = 0;
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
			
			/*if (ans != ans2) {
				System.err.println(name);
				System.err.println(ans + " " + ans2);
			}*/
			
			out.println("Case #"+(tst+1)+": "+ans2);
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
