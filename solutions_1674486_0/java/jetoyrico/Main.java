import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("Main/input.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("Main/output.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		A solver = new A();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class A {
	int[] count;
	int N;
	boolean[][] inherit;
	boolean found;

	public void solve(int testNumber, Scanner in, PrintWriter out) {
		N = in.nextInt();
		inherit = new boolean[N][N];
		for (int i = 0; i < N; ++i) {
			int parentCount = in.nextInt();
			for (int j = 0; j < parentCount; ++j) {
				int parent = in.nextInt() - 1;
				inherit[i][parent] = true;
			}
		}
		found = false;
		for (int i = 0; i < N; ++i) {
			if (found)
				break;
			count = new int[N];
			go(i);
		}
		if (found)
			out.print(String.format("Case #%d: Yes\n", testNumber));
		else
			out.print(String.format("Case #%d: No\n", testNumber));
	}

	private void go(int start) {
		if (found)
			return;
		count[start]++;
		if (count[start] > 1) {
			found = true;
			return;
		}
		for (int i = 0; i < N; ++i)
			if (inherit[start][i])
				go(i);
	}
}

