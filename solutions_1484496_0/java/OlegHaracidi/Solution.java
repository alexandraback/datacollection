import java.util.*;
import java.io.*;

class IO {
	int testNum;
	static volatile int testCounter = 0;
	static volatile Scanner in;
	static volatile PrintWriter out;
	static void setIO(Scanner in, PrintWriter out) {
		IO.in = in;
		IO.out = out;
	}
}

final class SolutionC extends IO implements Runnable {
	@Override
	public void run() {
		int n;
		long[] a;
		synchronized (in) {
			testNum = ++testCounter;
			n = in.nextInt();
			a = new long[n];
			for (int i = 0; i < n; i++) a[i] = in.nextLong();
		}
		
		
		Random rand = new Random(12398276);
		
		long[] sum = new long[n + 1];
		sum[0] = 0;
		Arrays.sort(a);
		for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i - 1];
		long d;
		int[] p = new int[n];
		boolean f;
		do {
			f = false;
			d = 0;
			for (int i = n - 1; i >= 0; i--) {
				int r;
				if (Math.abs(d) > sum[i - 1]) break;
				if (d - a[i] == 0) r = -1;
				else if (d + a[i] == 0) r = 1;
				else if (Math.abs(d - a[i]) > sum[i]) r = 1;
				else if (Math.abs(d + a[i]) > sum[i]) r = -1;
				else r = rand.nextInt(3) - 1;
				d += r * a[i];
				p[i] = r;
				
				if (r != 0 && d == 0) {
					Arrays.fill(p, 0, i, 0);
					break;
				}
				
				f = (f || r != 0);
			}
		} while (!f || d != 0);

		ArrayList<Long> s1 = new ArrayList<Long>(), s2 = new ArrayList<Long>();
		
		for (int i = 0; i < n; i++) 
			if (p[i] < 0) s1.add(a[i]);
			else if (p[i] > 0) s2.add(a[i]);
			
			
		synchronized (out) {
			out.println("Case #" + testNum + ": ");
			for (long x: s1) out.print(x + " ");
			out.println();
			for (long x: s2) out.print(x + " ");
			out.println();
			out.flush();
		}
	}
}


public class Solution {

	static void solve(int testCount) {
		for (int i = 0; i < testCount; i++)	new SolutionC().run();
	}
	
	public static void main(String[] args) throws InterruptedException, FileNotFoundException {
		Scanner in = new Scanner(new FileInputStream("C-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("out.txt"));
		//Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		IO.setIO(in, out);
		
		int testCount = in.nextInt();
		solve(testCount);
		
		out.close();
	}

}
