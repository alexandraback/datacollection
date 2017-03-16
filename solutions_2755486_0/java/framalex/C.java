import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {
	
	class Attack {
		int str, pos1, pos2;
		public Attack(int str, int pos1, int pos2) {
			this.str = str;
			this.pos1 = pos1;
			this.pos2 = pos2;
		}
	}
	public void run() {
		int ntst = nextInt();
		
		for (int tst = 0; tst < ntst; ++tst) {
			long ans = 0;
			int n = nextInt();
			
			Map<Integer, List<Attack>> att = new TreeMap<Integer, List<Attack>>();
			int[] h = new int[4000];
			for (int i = 0; i < n; ++i) {
				int d = nextInt();
				int num = nextInt();
				int w = (nextInt() + 1000)*2;
				int e = (nextInt() + 1000)*2;
				int s = nextInt();
				int dd = nextInt();
				int dp = nextInt()*2;
				int ds = nextInt();
				
				
				for (int j = 0; j < num; ++j) {
					if (!att.containsKey(d)) {
						att.put(d, new ArrayList<Attack>());
					}
					List<Attack> list = att.get(d);
					list.add(new Attack(s, w, e));
					att.put(d, list);
					
					s += ds;
					w += dp;
					e += dp;
					d += dd;
				}
			}
			
			for (int day : att.keySet()) {
				List<Attack> list = att.get(day);
				int[] add = new int[4000];
				for (Attack a : list) {
					boolean attacked = false;
					for (int i = a.pos1; i <= a.pos2; ++i) {
						if (h[i] < a.str) {
							attacked = true;
							add[i] = Math.max(add[i], a.str);
						}
					}
					if (attacked) {
						++ans;
					}
				}
				
				for (int i = 0; i < 4000; ++i) {
					if (h[i] < add[i]) {
						h[i] = add[i];
					}
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
