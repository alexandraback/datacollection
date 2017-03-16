import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;


public class Osmos {
	
	public static final void main(String[] params) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("Osmos.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("Osmos.out"));
		int count = Integer.parseInt(br.readLine().trim());
		for (int test = 0; test < count; test++) {
			String[] parts = br.readLine().split(" ");
			int a = Integer.parseInt(parts[0]);
			int n = Integer.parseInt(parts[1]);
			parts = br.readLine().split(" ");
			int[] x = new int[n];
			for (int i = 0; i < n; i++) {
				x[i] = Integer.parseInt(parts[i]);
			}
			bw.write("Case #" + (test+1) + ": " + new Osmos().solve(a, n, x));
			bw.newLine();
		}
		bw.close();
		br.close();
	}
	
	private int solve(int a, int n, int[] x) {
		Arrays.sort(x);
		int[] best = new int[n + 1];
		best[0] = a;
		for (int i = 0; i < n; i++) {
			int[] nbest = new int[n + 1];
			for (int k = 0; k < best.length; k++) if (best[k] > 0) {
				if (best[k] > x[i]) {
					nbest[k] = best[k] + x[i]; // eat it
				} else {
					if (k + 1 < n + 1 && best[k] > nbest[k+1]) nbest[k + 1] = best[k]; // eliminate
					if (best[k] > 1) {
						int value = best[k], added = 0;
						while (value <= x[i]) {
							value += (value - 1);
							added++;
						}
						value += x[i];
						if (k + added < n + 1 && value > nbest[k + added]) nbest[k + added] = value; // add
					}
				}
			}
			best = nbest;
		}
		for (int i = 0; i < best.length; i++) {
			if (best[i] > 0) return i;
		}
		return -1;
	}

}
