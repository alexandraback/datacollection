import java.io.*;
import java.math.*;
import java.util.*;

public class Round1CA implements Runnable {
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	boolean file = true;
	String fileName = "A-small";

	public static void main(String[] args) throws Exception {
		new Round1CA().run();
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
		
		int cases = nextInt();
		for(int step = 1; step <= cases; step++){
			n = nextInt();
			links = new ArrayList[n];
			for(int i=0; i<n; i++)
				links[i] = new ArrayList<Integer>();
			for(int i=0; i<n; i++){
				int m = nextInt();
				for(int j=0; j<m; j++){
					links[i].add(nextInt()-1);
				}
				//System.out.println(links[i]);
			}
			boolean ans = false;
			for(int i=0; i<n; i++){
				used = new boolean[n];
				if (dfs(i)) {
					ans = true; break;
				}
			}
			out.println("Case #"+step+": "+(ans?"Yes":"No"));
		}
	}
	ArrayList<Integer> links[];
	int n;
	boolean []used;
	boolean dfs(int x){
		boolean result = false;
		//System.out.println("dfs in "+x);
		used[x] = true;
		for(int to:links[x]){
			if(!used[to])
				result |= dfs(to);
			else return true;
		}
		return result;
	}
}