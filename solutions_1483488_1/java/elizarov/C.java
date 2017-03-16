package qualification;

import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author Roman Elizarov
 */
public class C {
	public static void main(String[] args) throws IOException {
		new C().go();
	}

	Scanner in;
	PrintWriter out;

	private void go() throws IOException  {
		init();
		in = new Scanner(new File("src\\qualification\\c.in"));
		out = new PrintWriter(new File("src\\qualification\\c.out"));
		int t = in.nextInt();
		for (int tn = 1; tn <= t; tn++) {
			out.println("Case #" + tn + ": " + solveCase());
		}
		in.close();
		out.close();
	}

	int[] p = new int[10];
	int[] u = new int[2000001];
	int uh;

	private void init() {
		p[0] = 1;
		for (int i = 1; i < p.length; i++)
			p[i] = p[i - 1] * 10;
		Arrays.fill(u, -1);
	}

	private int getP(int a) {
		int i = Arrays.binarySearch(p, a);
		return i < 0 ? -i - 2 : i;
	}

	private int solveCase() {
		int a = in.nextInt();
		int b = in.nextInt();
		int ap = getP(a);
		int bp = getP(b);
		int cnt = 0;
		for (int p0 = ap; p0 <= bp; p0++) {
			int a0 = p0 == ap ? a : p[p0];
			int b0 = p0 == bp ? b : p[p0 + 1] - 1;
			cnt += solveCase(a0, b0, p0 + 1);
		}
		return cnt;
	}

	private int solveCase(int a, int b, int d) {
		int cnt = 0;
		for (int n = a; n < b; n++) {
			for (int i = 1; i < d; i++) {
				int m = (n % p[i]) * p[d - i] + n / p[i];
				if (m > n && m <= b && u[m] < 0) {
					cnt++;
					u[m] = uh;
					uh = m;
				}
			}
			while (uh > 0) {
				int next = u[uh];
				u[uh] = -1;
				uh = next;
			}
		}
		return cnt;
	}
}
