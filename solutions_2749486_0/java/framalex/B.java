import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {
	class V implements Comparable<V> {
		int x, y, dist;
		char dir;		
		public V(int x, int y, int dist) {
			this.x = x;
			this.y = y;
			this.dist = dist;
			this.dir = ' ';
		}
		
		public int compareTo(V a) {
			if (this.dist == a.dist) {
				if (a.x == this.x) {
					return this.y -a.y;
				}
				return this.x-a.x;
			}
			return this.dist-a.dist;
		}
	}
	
	int[] dx = {-1, 0, 1, 0};
	int[] dy = {0, -1, 0, 1};
	char[] ch = {'W', 'S', 'E', 'N'};
	public void run() {
		int ntst = nextInt();
		
		for (int tst = 0; tst < ntst; ++tst) {
			int X = nextInt();
			int Y = nextInt();
			TreeSet<V> set = new TreeSet<V>();
			set.add(new V(0, 0, 0));
			HashMap<Long, V> way = new HashMap<Long, V>();
			int dist = 0;
			while (!set.isEmpty()) {
				V v = set.pollFirst();
				
				for (int k = 0; k < 4; ++k) {
					int step = v.dist+1;
					int x = v.x+dx[k]*step;
					int y = v.y+dy[k]*step;
					
					V tmp = new V(x, y, v.dist+1);
					if (!set.contains(tmp)) {
						tmp.dir = ch[k];
						set.add(tmp);
					}
				}
				way.put((v.x+5000)*100000000000000L + (v.y+5000)*1000000000L + v.dist, v);
				if (v.x == X && v.y == Y) {
					dist = v.dist;
					break;
				}
			}
			
			String ans = "";
			int x = X;
			int y = Y;
			int iter = dist;
			for (int i = 0; i < iter; ++i) {
				long hash = (x+5000)*100000000000000L + (y+5000)*1000000000L + dist;
				V v = way.get(hash);
				int k = 0;
				for (int tmp = 0; tmp < 4; ++tmp) {
					if (v.dir == ch[tmp]) {
						k = tmp;
						break;
					}
				}
				
				ans = ch[k] + ans;
				x -= dx[k]*dist;
				y -= dy[k]*dist;
				--dist;
			}
			out.println("Case #"+(tst+1)+": "+ans);
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
