import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.*;
import java.util.Map.Entry;

public class Main {
	public static void main(String[] args) throws IOException {
		(new Main()).solve();
	}

	public Main() {
	}
	
	//MyReader in = new MyReader();
	//PrintWriter out = new PrintWriter(System.out);
	
	void solve() throws IOException {
		//BufferedReader in = new BufferedReader(new
		//InputStreamReader(System.in));
		//Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new FileReader("input.txt"));
		PrintWriter out = new PrintWriter("output.txt");
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			int k = in.nextInt() - 1;
			long[][][][] dp = new long[31][2][2][2];
			dp[30][1][1][1] = 1;
			for (int j1 = 29; j1 >= 0; j1--) {
				for (int j2 = 0; j2 < 2; j2++) {
					for (int j3 = 0; j3 < 2; j3++) {
						for (int j4 = 0; j4 < 2; j4++) {
							for (int bitA = 0; bitA < 2; bitA++) {
								for (int bitB = 0; bitB < 2; bitB++) {
									int bitK = (bitA & bitB);
									int nj2 = nextState(j1, j2, bitA, a);
									int nj3 = nextState(j1, j3, bitB, b);
									int nj4 = nextState(j1, j4, bitK, k);
									if (nj2 != -1 && nj3 != -1 && nj4 != -1) {
										dp[j1][nj2][nj3][nj4] += dp[j1 + 1][j2][j3][j4];
									}
								}
							}
						}
					}
				}
			}
			long sum = 0;
			for (int j2 = 0; j2 < 2; j2++) {
				for (int j3 = 0; j3 < 2; j3++) {
					for (int j4 = 0; j4 < 2; j4++) {
						sum += dp[0][j2][j3][j4];
					}
				}
			}
			out.println("Case #" + (i + 1) + ": " + sum);
		}
		out.close();
	}
	
	int nextState(int i, int oldState, int bit, int a) {
		int bitA = ((a >> i) & 1);
		if (oldState == 0 || bit < bitA) {
			return 0;
		}
		if (bit == bitA) {
			return 1;
		}
		return -1;
	}
	
	class MyReader {
		private BufferedReader in;
		String[] parsed;
		int index = 0;

		public MyReader() {
			in = new BufferedReader(new InputStreamReader(System.in));
		}

		public int nextInt() throws NumberFormatException, IOException {
			if (parsed == null || parsed.length == index) {
				read();
			}
			return Integer.parseInt(parsed[index++]);
		}

		public long nextLong() throws NumberFormatException, IOException {
			if (parsed == null || parsed.length == index) {
				read();
			}
			return Long.parseLong(parsed[index++]);
		}
		
		public double nextDouble() throws NumberFormatException, IOException {
			if (parsed == null || parsed.length == index) {
				read();
			}
			return Double.parseDouble(parsed[index++]);
		}
		
		public String nextString() throws IOException {
			if (parsed == null || parsed.length == index) {
				read();
			}
			return parsed[index++];
		}

		private void read() throws IOException {
			parsed = in.readLine().split(" ");
			index = 0;
		}

		public String readLine() throws IOException {
			return in.readLine();
		}
		
		public int read(char[] cbuf) throws IOException {
			return in.read(cbuf);
		}
	}

};