import java.util.*;
import java.io.*;
import java.util.regex.*;

public class pogo {
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new File("input/pogo-small.in"));
		PrintWriter out = new PrintWriter(new File("output/pogo-small.out"));
		int sets = input.nextInt();
		input.nextLine();
		primary: for (int onSet = 1; onSet <= sets; onSet++) {
			System.out.printf("%d of %d%n", onSet, sets);
			out.printf("Case #%d: ", onSet);
			Queue<Solution> q = new LinkedList<Solution>();
			int x = input.nextInt(); int y = input.nextInt();
			q.add(new Solution(0,0,0,""));
			int[] d = {1,0,-1,0};
			int[] e = {0,1,0,-1};
			char[] c = {'E','N','W','S'};
			Map<Long, Set<Long>> cache = new HashMap<Long, Set<Long>>();
			long prev = -1;
			while(true) {
				Solution cur = q.remove();
				//System.out.printf("%d,%d %d%n", cur.x, cur.y, cur.s);
				
				for (int i=0; i<4; i++) {
					int f = cur.s+1;
					if (f != prev) {
						prev = f;
						cache.clear();
					}
					long nX = cur.x+d[i]*f; long nY = cur.y+e[i]*f;
					if (nY == y && nX == x) {
						out.println(cur.sol + c[i]);
						continue primary;
					}
					
					if (!cache.containsKey(nX)) {
						cache.put(nX, new HashSet<Long>());
					}
					if (cache.get(nX).add(nY))
						q.add(new Solution(cur.x+d[i]*f, cur.y+e[i]*f, f, cur.sol+c[i]));
				}
			}
		}
		out.close();
	}
	
	public static class Solution {
		int s = 0;
		long x, y;
		String sol;
		public Solution(long x, long y, int s, String sol) {this.s = s; this.x = x; this.y=y; this.sol = sol;}
	}
}