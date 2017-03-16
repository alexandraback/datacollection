
import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

public class J12R11A implements Runnable {
	Scanner in;
	PrintWriter out;
	static String taskname = ".\\src\\A-small-attempt0";
	int test, testn, i, j, k;
	int A,B;

	public static void main(String[] args) {
		new Thread(new J12R11A()).start();
	}

	public void solve() throws Exception {
		testn = in.nextInt();
		double p, L, l;

		for (test = 0; test < testn; test++) {
			out.print("Case #" + (test + 1) + ": ");
			A = in.nextInt();
			B = in.nextInt();
			L = 1+B+1;
			p = 1;
			for (int i = 1; i <= A; i++) {
				p *= in.nextDouble();
				l=A-i+B-i+1+(1-p)*(B+1);
				if (l <L) L = l;
			}

			out.print(L+"\n");
		}
	}

	@Override
	public void run() {
		try {
			in = new Scanner(new File(taskname + ".in"));
			out = new PrintWriter(taskname+".out");
			//out = new PrintWriter(System.out, true);
			//			in = new BufferedReader( new InputStreamReader(System.in));
			//			out = new BufferedWriter( new OutputStreamWriter(System.out));
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
