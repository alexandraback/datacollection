import java.util.*;
import java.io.*;

import com.sun.org.apache.xerces.internal.impl.RevalidationHandler;

public class A {

	static int[] q;
	
	static void calc() {
		int n = 1000006;
		q= new int[n];
		q[1] = 1;
		for (int i = 2; i < n; i++) {
			int i1 = reverse(i);
			int q1 = q[i-1] + 1;
			int q2 = Integer.MAX_VALUE;
			if (i % 10 != 0 && i1 < i) {
				q2 = q[i1] + 1;
			}
			q[i] = Math.min(q1, q2);
		}
	}
	
	void solve() {
		int N = in.nextInt();
		out.println(q[N]);
	}

	public static int reverse(int i)
	{
		String s0 = ""+i;
		String s1 = new StringBuilder(s0).reverse().toString();
		return Integer.parseInt(s1);
	}
	
	
	/*************************************************************************/

	public static void main(String[] args) throws Exception {
		calc();
		main1();
	}

	public static void main0() {
		String s = "3 1 19 23";
		solveProblem0(s);
	}

	public static void main1() throws Exception {
		String load = "src/a-small-attempt0.in";
		String save = "src/a-small-attempt0.out";
		solveProblem1(load, save);
	}

	/*************************************************************************/

	public static void solveProblem0(String s) {
		in = new Scanner(s);
		out = new PrintWriter(System.out);
		solveAllCases();
		out.flush();
	}

	public static void solveProblem1(String load, String save)
			throws FileNotFoundException {
		in = new Scanner(new File(load));
		out = new PrintWriter(new File(save));
		solveAllCases();
		out.close();
	}
	
	/*************************************************************************/

	static void solveAllCases() {
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");
			System.out.println("Case #" + t + ": ............");
			new A().solve();
		}
	}
	
	static Scanner in;
	static PrintWriter out;
}
