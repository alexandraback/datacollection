import java.util.*;
import java.io.*;

public class TaskA {

	FastScanner in;
	PrintWriter out;

	public int doit(String s, char c, int[] a) {
		int x = a[c - 'A'];
		for ( int i = 0; i < s.length(); i++){
			a[s.charAt(i) - 'A'] -= x;
		}
		return x;
	}

	public void solve() throws IOException {
		int q = in.nextInt();
		for (int qq = 1; qq <= q; qq++) {
			out.print("Case #" + qq + ": ");
			String s = in.next();
			int[] a = new int[50];
			for (int i = 0; i < s.length(); i++) {
				a[s.charAt(i) - 'A']++;
			}
			int[] ans = new int[10];

			// 0 ZERO
			ans[0] = doit("ZERO",'Z',a);

			// 6 SIX
			ans[6] = doit("SIX",'X',a);

			// 7 SEVEN
			ans[7] = doit("SEVEN",'S',a);

			// 2 TWO
			ans[2] = doit("TWO",'W',a);

			// 8 EIGHT
			ans[8] = doit("EIGHT",'G',a);

			// 3 THREE
			ans[3] = doit("THREE",'H',a);

			// 4 FOUR
			ans[4] = doit("FOUR",'U',a);
			

			// 5 FIVE
			ans[5] = doit("FIVE",'F',a);
			
			// 1 ONE
			ans[1] = doit("ONE",'O',a);

			// 9 NINE
			ans[9] = doit("NINE",'E',a);



			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < ans[i]; j++) {
					out.print(i);
				}
			}
			out.println();

		}

	}

	public void run() {
		try {
			in = new FastScanner(new File("input.in"));
			out = new PrintWriter(new File("output.out"));

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
	}

	public static void main(String[] arg) {
		new TaskA().run();
	}
}
