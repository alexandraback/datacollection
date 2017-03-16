import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class dijkstra {

	public static final int I = 2;
	public static final int J = 3;
	public static final int K = 4;

	public static final int[][] MUL = {
		{1, I, J, K},
		{I, -1, K, -J},
		{J, -K, -1, I},
		{K, J, -I, -1}};

	public static int mul(int a, int b) {
		int sign = 1;
		int a_ = a;
		int b_ = b;
		if (a < 0) {
			a_ = -a;
			sign = -sign;
		}
		if (b < 0) {
			b_ = -b;
			sign = -sign;
		}
		return sign * MUL[a_-1][b_-1];
	}

	public static int[] decode(String s) {
		int[] r = new int[s.length()];
		for (int i = 0; i < s.length(); ++i) {
			char c = s.charAt(i);
			if (c == 'i') r[i] = I;
			else if (c == 'j') r[i] = J;
			else if (c == 'k') r[i] = K;
			else throw new IllegalStateException();
		}
		return r;
	}

	public static void main(String[] args) throws Exception {
		String filename = "in.txt";
		filename = "C-small-attempt4.in";
		BufferedReader in = new BufferedReader(new FileReader(filename));
		PrintWriter out = new PrintWriter(new FileWriter("outC.txt"));

		int T = Integer.parseInt(in.readLine());
		for (int i = 1; i <= T; ++i) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			
			int L = Integer.parseInt(st.nextToken());
			String X_str = st.nextToken();
			BigInteger XI = new BigInteger(X_str);
			int X;
			X = XI.intValue();
			String s = in.readLine().trim();
			if (s.length() != L) throw new IllegalStateException();
			int[] liina = decode(s);

			// X and liina are of interest 
			boolean res = solve(liina, X);
			String lt = "Case #" + i + ": " + (res ? "YES" : "NO");
System.out.println(lt);
			out.println(lt);
		}
System.out.println("DONE");
		
		out.close();
		in.close();
	}

	private static int valAt(int pos, int[] liina) {
		return liina[pos % liina.length];
	}

	private static boolean solve(int[] liina, int X) {
		int L = liina.length;
		int LX = L * X;

		int[] triin = new int[LX+1];
		triin[LX] = 1;
		for (int i = LX-1; i >= 0; --i)
			triin[i] = mul(valAt(i, liina), triin[i+1]);
		
		int x_mul = 1;
		for (int x = 1; x <= LX; ++x) {
			x_mul = mul(x_mul, valAt(x-1, liina));
			int y_mul = 1;
			for (int y = 1; y+x <= LX; ++y) {
				y_mul = mul(y_mul, valAt(x+y-1, liina));
				for (int zk = 1; zk <= 3; ++zk) { // zk - how many full strings used
					int z = LX - x - y;
					int z_mul = triin[x+y];

					boolean xxx = try_split(x_mul, y_mul, z_mul);
					if (xxx) return true;
				}
			}
		}

		return false;
	}

	private static boolean try_split(int x_mul, int y_mul, int z_mul) {
					if (I == x_mul && J == y_mul && K == z_mul) {
						return true;
					}
		return false;
	}

}
