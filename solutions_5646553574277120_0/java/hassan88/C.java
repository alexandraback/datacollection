import java.io.*;
import java.util.*;

public class C {
	static int V, best = Integer.MAX_VALUE;
	public static void main(String[] args) throws IOException {
		BufferedInputStream bis = new BufferedInputStream(new FileInputStream("C-small-attempt1.in"));
		BufferedReader br = new BufferedReader(new InputStreamReader(bis));
		PrintWriter out = new PrintWriter(new File("C-small.out"));
		StringTokenizer st;
		int cases = Integer.parseInt(br.readLine().trim()), C, D;
		for (int c = 1; c <= cases; c++) {
			best = Integer.MAX_VALUE;
			st = new StringTokenizer(br.readLine());
			C = Integer.parseInt(st.nextToken());
			D = Integer.parseInt(st.nextToken());
			V = Integer.parseInt(st.nextToken());
			TreeSet <Integer> coins = new TreeSet<Integer>();
			st = new StringTokenizer(br.readLine());
			for(int i = 0;i < D;i++)coins.add(Integer.parseInt(st.nextToken()));
			boolean [] possible = new boolean[V+1];
			possible [0] = true;
			for(int x:coins) {
				for(int i = possible.length-1;i >= x;i--)
					if(possible[i-x])possible[i] = true;
			}
			solve(possible, coins, 0, 0);
			out.println("Case #" + c + ": " + best);
		}
		out.close();
	}
	public static int solve(boolean [] possible, TreeSet <Integer> coinsUsed, int added, int last) {
		boolean solved = true;
		for(int i = 0;i < possible.length && solved;i++)
			solved &= possible[i];
		if(added >= best)return 1000000;
		if(solved) {
			best = Math.min(best, added);
			return added;
		}
		int res = Integer.MAX_VALUE;
		for(int x = last+1;x <= V;x++) {
			if(!coinsUsed.contains(x)) {
				coinsUsed.add(x);
				boolean [] possible2 = new boolean[possible.length];
				for(int i = 0;i < possible2.length;i++)possible2[i] = possible[i];
				for(int i = possible2.length-1;i >= x;i--)
					if(possible2[i-x])
						possible2[i] = true;
				res = Math.min(res, solve(possible2, coinsUsed, added+1, x));
				coinsUsed.remove(x);
			}
		}
		return res;
	}
}