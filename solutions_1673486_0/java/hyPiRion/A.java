import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {
	static BufferedReader stdin = new BufferedReader(
						new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer("");

	public static void main(String[] args) throws Exception {
		int T = readInt();
		for (int t = 1; t <= T; t++){
			int written = readInt(),
				total = readInt(),
				remaining = total - written;
			double[] p = new double[written],
					 P = new double[written];
			for (int i = 0; i < written; i++)
				p[i] = readDouble();

			P[0] = p[0];
			for (int i = 1; i < written; i++)
				P[i] = P[i-1] * p[i];
			
			double[] E = new double[written];
			for (int i = 0; i < written; i++){
				int tot_keystrokes = (written - 1 - i) * 2 + remaining + 1;
				E[i] = P[i] * tot_keystrokes + (1 - P[i]) * (tot_keystrokes + total + 1);
			}
			double min = 2 + total;
			for (int i = 0; i < written; i++)
				if (E[i] < min)
					min = E[i];
			
			System.out.format("Case #%d: %f\n", t, min);
		}
	}

	static String readString() throws Exception {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(stdin.readLine());
		}
		return st.nextToken();
	}

	static int readInt() throws Exception {
		return Integer.parseInt(readString());
	}

	static double readDouble() throws Exception {
		return Double.parseDouble(readString());
	}
}
