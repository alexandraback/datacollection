import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Dijkstra {
//	static String file = "C";
	 static String file = "C-small-attempt0";

	static String yes = "YES";
	static String no = "NO";
	static int[][] result = new int[][] { { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 }, { 4, 3, -2, -1 } };

	static int res(int a, int b) {
		int r = result[(int) Math.abs(a) - 1][(int) Math.abs(b) - 1];
		if (a < 0) {
			r *= -1;
		}
		if (b < 0) {
			r *= -1;
		}
		return r;
	}

	static int[] prefix;
	static int[] suffix;
	static int[] t;
	static int l, x;
	static String token;

	static String solve(String token) {
		prefix = new int[l];
		suffix = new int[l];
		t = new int[l];
		for (int i = 0; i < t.length; i++) {
			t[i] = 0;
			switch (token.charAt(i)) {
			case 'i':
				t[i] = 2;
				break;
			case 'j':
				t[i] = 3;
				break;
			case 'k':
				t[i] = 4;
				break;
			}
		}
		prefix[0] = t[0];
		for (int i = 1; i < prefix.length; i++) {
			prefix[i] = res(prefix[i - 1], t[i]);
		}
		suffix[0] = t[l - 1];
		for (int i = 1; i < l; i++) {
			suffix[i] = res(t[l - 1 - i], suffix[i - 1]);
		}

		if (x == 1) {
			for (int i = 0; i < prefix.length; i++) {
				for (int j = 0; j < l - i - 1 - 1; j++) {
					if (prefix[i] == 2 && suffix[j] == 4) {
						int m = reverse(prefix[i], prefix[l - 1 - (j + 1)]);
						if (m == 3) {
							return yes;
						}
					}
				}
			}
		}

		if (x > 1) {
			for (int i = 1; i <= l; i++) {
				for (int j = 1; j <= l; j++) {
					for (int j2 = 0; j2 < 6; j2++) {
						for (int j3 = 0; j3 < 6; j3++) {
							long b1 = i + j2 * l;
							long b2 = l * x - 1 - (j + j3 * l);
							if (b1 <= b2) {
								int s1 = evalRegion(0, b1 - 1);
								int s2 = evalRegion(b1, b2);
								int s3 = evalRegion(b2 + 1, ((long) l) * x - 1);
								if (s1 == 2 && s2 == 3 && s3 == 4) {
									return yes;
								}
							}
						}
					}
				}
			}
		}

		return no;
	}

	private static int reverse(int i, int j) {

		for (int j2 = 1; j2 <= 4; j2++) {
			int r = res(i, j2);
			if (r == j) {
				return j2;
			}
			if (r == -j) {
				return -j2;
			}
		}
		return 0;
	}

	static int evalRegion(long from, long to) {

		if (from / l == to / l) {
			int ans = 0;
			
			int from2 = (int)from % l;
			int to2 =(int) to % l;			
			ans = reverse(from2 == 0 ? 1 : prefix[from2 - 1], prefix[to2]);
			
//			int force = bruteforceEval(from, to);
//			if (ans != force)
//				System.out.println(from + " " + to + " " + ans + " " + force);
			
			return ans;
		} else {

			int suffLng = (int) (l - ((from) % l));
			int prefLng = (int) ((to + 1) % l);

			int s1 = suffLng == 0 ? 1 : suffix[suffLng - 1];
			long cnt = to - from + 1 - suffLng - prefLng;
			
			cnt = cnt / l;
			int s2 = 0;
			if (cnt % 4 == 0) {
				s2 = 1;
			} else if (cnt % 4 == 1) {
				s2 = prefix[l - 1];
			} else if (cnt % 4 == 2) {
				s2 = res(prefix[l - 1], prefix[l - 1]);
			} else {
				s2 = res(res(prefix[l - 1], prefix[l - 1]), prefix[l - 1]);
			}
			int s3 = prefLng == 0 ? 1 : prefix[prefLng - 1];

			int ans = res(res(s1, s2), s3);
//			int force = bruteforceEval(from, to);
//			if (ans != force)
//				System.out.println(from + " " + to + " " + ans + " " + force);

			return ans;
		}
	}

	static int bruteforceEval(long from, long to) {
		int[] complete = new int[l * x];
		for (int i = 0; i < l * x; i++) {
			complete[i] = t[i % l];
		}
		int ans = 1;
		for (int i = (int) from; i <= to; i++) {			
			ans = res(ans, complete[i]);
		}

		return ans;
	}

	static int[] intArray(String l) {
		String[] vals = l.split(" ");
		int[] ans = new int[vals.length];
		for (int i = 0; i < vals.length; i++) {
			ans[i] = Integer.valueOf(vals[i]);
		}
		return ans;
	}

	public static void main(String[] args) throws IOException {
		FileInputStream fis = new FileInputStream(file + ".in");
		InputStreamReader isr = new InputStreamReader(fis);
		BufferedReader br = new BufferedReader(isr);

		FileOutputStream fos = new FileOutputStream(file + ".out");
		OutputStreamWriter isw = new OutputStreamWriter(fos);
		BufferedWriter bw = new BufferedWriter(isw);

		String line = null;
		List<String> lines = new ArrayList<String>();
		while ((line = br.readLine()) != null) {
			lines.add(line);
		}

		int problemCount = Integer.parseInt(lines.get(0));
		int currentIndex = 1;
		for (int i = 0; i < problemCount; i++) {
			String c = lines.get(currentIndex++);
			int[] a = intArray(c);
			l = a[0];
			x = a[1];
			String r = "Case #" + (i + 1) + ": " + solve(lines.get(currentIndex++));

//			System.out.println(r);
			bw.write(r);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();
	}
}
