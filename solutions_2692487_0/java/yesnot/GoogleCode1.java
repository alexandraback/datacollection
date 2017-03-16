import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

//Google Code Jam
public class GoogleCode1 {
	private static MyScanner in;
	private static PrintStream out;
	private static PrintStream sysout = System.out;
	static int caseNum;

	private static void solve() throws IOException
	{
		PreCompute();
		int C = in.nextInt();
		for (int i = 0; i < C; i++) {
			caseNum = i + 1;
			out.print("Case #" + caseNum + ": ");
			solveCase();
		}
	}

	private static void PreCompute() {
	}

	private static void solveCase() throws IOException {
		int A = in.nextInt();
		int N = in.nextInt();
		ArrayList<Integer> motes = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			int m = in.nextInt();
			motes.add(m);
		}
		Collections.sort(motes);
		int minop = N;
		for (int addn = 0; addn <= N; addn++) {
			int i = 0;
			int lasti = motes.size() - 1;
			int add = 0;
			int AA = A;
			boolean succeed = false;
			while (true) {
				if (i > lasti) {
					succeed = true;
					break;
				}
				int minm = motes.get(i);
				if (AA > minm) {
					AA += minm;
					i++;// remove i
				}
				else {
					if (add < addn) {
						AA += AA - 1;
						add++;
					}
					else {
						break;
					}
				}
			}

			if (succeed) {
				minop = Math.min(minop, addn);
				continue;
			}
			else {
				int remove = lasti - i + 1;
				minop = Math.min(minop, addn + remove);
			}

		}

		out.println(minop);
	}

	public static void main(String[] args) throws IOException {
		// helpers for input/output
		boolean usingFileForIO = true;
		if (usingFileForIO) {
			// using input.txt and output.txt as I/O
			in = new MyScanner("E:\\zin.txt");
			out = new PrintStream("E:\\zout.txt");
		}
		else {
			in = new MyScanner();
			out = System.out;
		}

		solve();
	}

	// =====================================
	static class MyScanner {
		Scanner inp = null;

		public MyScanner() throws IOException
		{
			inp = new Scanner(System.in);
		}

		public MyScanner(String inputFile) throws IOException {
			inp = new Scanner(new FileInputStream(inputFile));
		}

		public int nextInt() throws IOException {
			return inp.nextInt();
		}

		public long nextLong() throws IOException {
			return inp.nextLong();
		}

		public double nextDouble() throws IOException {
			return inp.nextDouble();
		}

		public String nextString() throws IOException {
			return inp.next();
		}

		public String nextLine() throws IOException {
			return inp.nextLine();
		}
	}

}