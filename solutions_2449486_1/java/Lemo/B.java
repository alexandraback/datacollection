import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class B {

	final static String PREFIX = ".\\src\\B";
//	final static String FILE_NAME = PREFIX + "-test";
//	final static String FILE_NAME = PREFIX + "-small-attempt0";
	final static String FILE_NAME = PREFIX + "-large";

	private Scanner in;
	private PrintWriter out;

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new B().solveAll();
	}

	private void solveAll() throws Exception {
		in = new Scanner(new File(FILE_NAME + ".in"));
		out = new PrintWriter(new File(FILE_NAME + ".out"));
		int tcn = in.nextInt();
		for (int tc = 1; tc <= tcn; tc++) {
			solve(tc);
		}
		out.close();
	}

	String r[] = new String[4];

	int a[][];
	int N;
	int M;
	int maxN[];
	int maxM[];
	private void solve(int tc) {
		N = in.nextInt();
		M = in.nextInt();
		a = new int[N][M];
		maxN = new int[N];
		maxM = new int[M];
		for(int n = 0; n < N; n++) {
			for(int m = 0; m < M; m++) {
				int nm = in.nextInt();
				a[n][m] = nm;
				if(nm > maxN[n]) maxN[n] = nm;
				if(nm > maxM[m]) maxM[m] = nm;
			}
		}
		
		//check
		for(int n = 0; n < N; n++) {
			for(int m = 0; m < M; m++) {
				if(a[n][m] != maxN[n] && a[n][m] != maxM[m]) {
					print("Case #%d: %s\n", tc, "NO");
					return;
				}
			}
		}
		print("Case #%d: %s\n", tc, "YES");
	}

	private void print(String format, Object ... args) {
		out.format(format, args);
		System.out.format(format, args);
	}
}
