import java.util.*;
import java.io.*;
import java.util.regex.*;

public class osmos {
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new File("input/osmos-large.in"));
		PrintWriter out = new PrintWriter(new File("output/osmos-large-slow.out"));
		int sets = input.nextInt();
		input.nextLine();
		primary: for (int onSet = 1; onSet <= sets; onSet++) {
			System.out.printf("%d of %d%n", onSet, sets);
			out.printf("Case #%d: ", onSet);
			long size = input.nextLong();
			int n = input.nextInt();
			Queue<Long> q = new PriorityQueue<Long>();
			for (int i=0; i<n; i++) {
				q.add(input.nextLong());
			}
			if (size == 1) {
				out.println(n);
				continue primary;
			}
			out.println(solve(q, size));
		}
		out.close();
	}
	
	public static int solve(Queue<Long> q, long size) {
		//System.out.println("SOLVING");
		if (q.size() == 0) return 0;
		long m = q.remove();
		if (m < size) {
			size += m;
			return solve(q, size);
		}
		int ops = 0;
		while (m >= size) {
			size += size-1;
			ops++;
		}
		size += m;
		return Math.min(q.size()+1, ops+solve(q, size));
	}
	
	public static int nsolve(Queue<Long> q, long size) {
		if (q.size() == 0) return 0;
		long m = q.remove();
		if (m < size) {
			size += m;
			return nsolve(q, size);
		}
		int ops = (int)(log2((int)(((double)m/size)+1.5)))-1;
		size += m;
		return Math.min(q.size()+1, ops+nsolve(q, size));
	}
	
	public static long log2(long x) {
		int r=0;
		if ((x & (x-1)) == 0) r++;
		while ((x >>= 1) != 0) {
			r++;
		}
		return r;
	}
}