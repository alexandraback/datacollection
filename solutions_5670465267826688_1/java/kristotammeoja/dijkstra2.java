import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class dijkstra2 {

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
		String filename = "in2.txt";
		filename = "C-large.in";
		BufferedReader in = new BufferedReader(new FileReader(filename));
		PrintWriter out = new PrintWriter(new FileWriter("outC.txt"));

		int T = Integer.parseInt(in.readLine());
		for (int i = 1; i <= T; ++i) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			
			int L = Integer.parseInt(st.nextToken());
			String X_str = st.nextToken();
			BigInteger XI = new BigInteger(X_str);
			int X;
			if (XI.compareTo(new BigInteger("100")) > 0) {
				X = 100+XI.mod(new BigInteger("4")).intValue();
			} else {
				X = XI.intValue();
			}
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

	// mul in positions [a, b) starting from 0
	private static int calculate_mul(int a, int b, int[] liina) {
		int mul = 1;
		for (int i = a; i < b; ++i) {
			mul = mul(mul, valAt(i, liina));
		}
		return mul;
	}

	public static class sub_mul {
		public int left;
		public int right;
		public boolean allow_to_middle = true;
		public sub_mul(int a, int b) {left = a; right = b;}
	}

	private static boolean solve(int[] liina, int X) {
		int L = liina.length;
		int total_mul = calculate_mul(0, L, liina);
boolean[] kaisa = new boolean[50000];
int kaisak = 0;

		int[] triin = new int[L+1];
		triin[L] = 1;
		for (int i = L-1; i >= 0; --i)
			triin[i] = mul(liina[i], triin[i+1]);
		
		sub_mul x_mul = new sub_mul(1, 1);
		for (int x = 1; x <= L; ++x) {
			x_mul.right = mul(x_mul.right, valAt(x-1, liina));
			sub_mul y_mul = new sub_mul(1, 1);
			for (int y = 1; y <= 2*L; ++y) {
				if (x+y <= L) {
					y_mul.left = mul(y_mul.left, valAt(x+y-1, liina));
					y_mul.allow_to_middle = false;
				} else {
					y_mul.right = mul(y_mul.right, valAt(x+y-1, liina));
					y_mul.allow_to_middle = true;
				}
				for (int zk = 1; zk <= 4; ++zk) { // zk - how many full strings used
					int z = zk*L - x - y;
					if (1 <= z && z <= L) {
						// calculat z_mul
						sub_mul z_mul = new sub_mul(triin[(x+y) % L], 1);

						int key =  10000*zk
								 + 1000*stupify(x_mul.right)
								 + 100*stupify(y_mul.left)
								 + 10*stupify(y_mul.right)*(y_mul.allow_to_middle ? 1 : 0)
								 + stupify(z_mul.left);
						if (!kaisa[key]) {
++kaisak;
							kaisa[key] = true;
							boolean xxx = try_split(x_mul, y_mul, z_mul, total_mul, zk, X);
							if (xxx) return true;
						}
					}
				}
			}
		}

		return false;
	}

	private static int stupify(int a) {
		if (a < 0) return 10+a;
		return a;
	}

	private static int mulmul(sub_mul m, int k, int total_mul) {
		int mm = m.left;
		for (int i = 0; i < k; ++i) mm = mul(mm, total_mul);
		mm = mul(mm, m.right);
		return mm;
	}

	private static boolean try_split(sub_mul x_mul, sub_mul y_mul, sub_mul z_mul, int total_mul, int zk, int X) {
		//if (true) return false;
		for (int ix = 0; ix < 4; ++ix)
			for (int iy = 0; iy < 4; ++iy)
				for (int iz = 0; iz < 4; ++iz) {
					int num_strs = ix+iy+iz+zk;
					if (y_mul.allow_to_middle == false && iy != 0) continue;
					if (num_strs > X) continue;
					if ((X-num_strs) % 4 != 0) continue;

					int p_x = mulmul(x_mul, ix, total_mul);
					int p_y = mulmul(y_mul, iy, total_mul);
					int p_z = mulmul(z_mul, iz, total_mul);

					if (I == p_x && J == p_y && K == p_z) {
						return true;
					}
				}
		return false;
	}

}
