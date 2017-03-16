import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;


public class B {
	
	private static final String NAME = "C-small";

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader("in/" + NAME + ".in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("out/" + NAME + ".out"));
		try {
			int t = Integer.parseInt(reader.readLine());
			for (int i = 0; i < t; ++i) {
				String[] inp = reader.readLine().split(" ");
				int n = Integer.parseInt(inp[0]);
				int m = Integer.parseInt(inp[1]);
				
				inp = reader.readLine().split(" ");
				int[] typA = new int[n + 1];
				long[] countA = new long[n + 1];
				typA[0] = -1;
				for (int x = 0; x < n; ++x) {
					typA[x + 1] = Integer.parseInt(inp[2 * x + 1]);
					countA[x + 1] =	Long.parseLong(inp[2 * x]);
					if (typA[x + 1] == typA[x]) {
						countA[x] += countA[x + 1];
						--x;
						--n;
					}
				}
				
				inp = reader.readLine().split(" ");
				int[] typB = new int[m + 1];
				long[] countB = new long[m + 1];
				typB[0] = -1;
				for (int x = 0; x < m; ++x) {
					typB[x + 1] = Integer.parseInt(inp[2 * x + 1]);
					countB[x + 1] = Long.parseLong(inp[2 * x]);
					if (typB[x + 1] == typB[x]) {
						countB[x] += countB[x + 1];
						--x;
						--m;
					}
				}
				
				long res = 0;
				
				if (n == 1) {
					long sum = 0;
					for (int k = 0; k < m + 1; ++k) {
						if (typB[k] == typA[1]) {
							sum += countB[k];
						}
					}
					res = (countA[1] > sum)? sum: countA[1];
				}
				
				if (n == 2) {
					for (int k = 0; k < m + 1; ++k) {
						long tmp = 0;
						long sum1= 0;
						for (int k1 = 0; k1 <= k; ++k1) {
							if (typB[k1] == typA[1]) {
								sum1 += countB[k1];
							}
						}
						long sum2= 0;
						for (int k1 = k; k1 < m + 1; ++k1) {
							if (typB[k1] == typA[2]) {
								sum2 += countB[k1];
							}
						}
						tmp = ((countA[1] > sum1)? sum1: countA[1]) + ((countA[2] > sum2)? sum2: countA[2]);
						if (tmp > res) {
							res = tmp;
						}
					}
				}
				
				if (n == 3) {
					for (int k = 0; k < m + 1; ++k) {
						for (int l = k; l < m + 1; ++l) {
							long tmp = 0;
							long sum1= 0;
							long[] countAA = Arrays.copyOf(countA, countA.length); 
							long[] countBB = Arrays.copyOf(countB, countB.length);
							for (int k1 = 0; k1 <= k && countAA[1] > 0; ++k1) {
								if (typB[k1] == typA[1]) {
									long amount = (countBB[k1] < countAA[1])? countBB[k1]: countAA[1];
									sum1 += amount;
									countBB[k1] -= amount; 
									countAA[1] -= amount;
								}
							}
							long sum2= 0;
							for (int k1 = k; k1 <= l && countAA[2] > 0; ++k1) {
								if (typB[k1] == typA[2]) {
									long amount = (countBB[k1] < countAA[2])? countBB[k1]: countAA[2];
									sum2 += amount;
									countBB[k1] -= amount; 
									countAA[2] -= amount;
								}
							}
							long sum3= 0;
							for (int k1 = l; k1 < m + 1 && countAA[3] > 0; ++k1) {
								if (typB[k1] == typA[3]) {
									long amount = (countBB[k1] < countAA[3])? countBB[k1]: countAA[3];
									sum3 += amount;
									countBB[k1] -= amount; 
									countAA[3] -= amount;
								}
							}
							tmp = ((countA[1] > sum1)? sum1: countA[1]) + ((countA[2] > sum2)? sum2: countA[2]) + ((countA[3] > sum3)? sum3: countA[3]);
							if (tmp > res) {
								res = tmp;
							}
						}
					}
				}
				
				
				writer.write("Case #" + (i + 1) + ": ");
				writer.write("" + res);
				writer.newLine();
			}
		} finally {
			reader.close();
			writer.close();
		}
	}
}
