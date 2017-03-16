import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {
	
	private String rec(int pos, int mask, ArrayList<Integer> list) {
		if (Integer.bitCount(mask) == n) {
			String ans = "";
			int mm = 0;
			for (int i = 0; i < list.size(); ++i) {
				if ((mm & (1 << list.get(i))) == 0) {
					mm |= 1 << list.get(i);
					ans += zip[list.get(i)];
				}
			}
			return ans;
		}
		String ans = null;
		for (int j = 0; j < list.size(); ++j) {
			int start = list.get(j);
			for (int i = 0; i < n; ++i) {
				if ((mask & (1<<i)) == 0 && g[start].contains(i)) {
					ArrayList<Integer> l = (ArrayList<Integer>)list.clone();
					l.add(i);
					String tmp = rec(i, mask | (1<<i), l);
					if (tmp != null) {
						if (ans == null || ans.compareTo(tmp) > 0) {
							ans = tmp;
						}
					}
				}
			}
		}
		return ans;
	}
	
	int n;
	HashSet<Integer>[] g;
	String[] zip;
	public void run() {
		int cases = nextInt();
		for (int cs = 0; cs < cases; ++cs) {
			n = nextInt();
			int m = nextInt();
			zip = new String[n];
			for (int i = 0; i < n; ++i) {
				zip[i] = nextWord();
			}
			g = new HashSet[n];
			for (int i = 0; i < n; ++i) {
				g[i] = new HashSet<Integer>();
			}
			
			for (int i = 0; i < m; ++i) {
				int a = nextInt() - 1;
				int b = nextInt() - 1;
				g[a].add(b);
				g[b].add(a);
			}
			
			String ans = null;
			if (m == n*(n-1)/2) {
				Arrays.sort(zip);
				ans = "";
				for (int i = 0; i < n; ++i) {
					ans += zip[i];
				}
			}
			else {
				int min = 0;
				for (int i = 0; i < n; ++i) {
					if (zip[i].compareTo(zip[min]) < 0) {
						min = i;
					}
				}
				for (int i = min; i <= min; ++i) {
					ArrayList<Integer> list = new ArrayList<Integer>();
					list.add(i);
					String tmp = rec(i, 1<<i, list);
					if (tmp != null) {
						if (ans == null || ans.compareTo(tmp) > 0) {
							ans = tmp;
						}
					}
				}
			}
			System.err.println(cs + " " + n + " " + ans + " ");
			out.println("Case #" + (cs+1) + ": " + ans);
		}
		out.flush();
	}
	
	private static BufferedReader br = null;
	private static StringTokenizer stk = null;
	private static PrintWriter out = null;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(new File("D:\\C.txt")));
		out = new PrintWriter("D:\\CC.txt");
		(new Thread(new C())).start();
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
