import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class ___1A {

	public static void main(String[] args) {

		try {

			Scanner scanner = new Scanner(new File("A-large.in"));
			BufferedWriter br = new BufferedWriter(new FileWriter("out.txt"));
			int T, i, j, t, k;
			T = scanner.nextInt();

			for (t = 0; t < T; t++) {
				boolean finalFound = false;
				int nodes = scanner.nextInt();
				int[] times = new int[nodes];
				int[] beginTimes = new int[nodes];
				for (i = 0; i < nodes; i++) {
					times[i] = 0;
					beginTimes[i] = 0;
				}
				int[][] matrix = new int[nodes][];
				for (i = 0; i < nodes; i++) {
					int N = scanner.nextInt();
					beginTimes[i] = N;
					matrix[i] = new int[N];
					for (j = 0; j < N; j++) {
						matrix[i][j] = scanner.nextInt();
						times[matrix[i][j] - 1]++;
					}
				}
				
				int node;

				for (node = 0; node < nodes; node++) {
					if (times[node] > 1) {
						boolean[] info = new boolean[nodes];
						for (i = 0; i < nodes; i++) {
							info[i] = false;
						}
						boolean changed = false;
						while (true) {

							for (i = 0; i < matrix.length; i++) {
								for (j = 0; j < matrix[i].length; j++) {
									if (matrix[i][j] == node + 1
											|| info[matrix[i][j] - 1] == true) {
										if (info[i] != true) {
											info[i] = true;

											changed = true;
										}
									}
								}
							}
							if (!changed)
								break;
							changed = false;
						}

						finalFound = false;
						for (i = 0; i < matrix.length; i++) {
							int sum = 0;
							for (j = 0; j < matrix[i].length; j++) {
								if (matrix[i][j] == node + 1
										|| info[matrix[i][j] - 1]) {
									sum++;
								}
							}
							if (sum > 1) {
								finalFound = true;
							}
						}
						if (finalFound) {
							break;
						}

					}
				}
				
				
				if (finalFound) {
					br.write("Case #" + (t + 1) + ": " + "Yes");
					//br.newLine();
				} else {
					br.write("Case #" + (t + 1) + ": " + "No");
				}
				br.newLine();
			}
			br.close();
		} catch (IOException ex) {

		}

	}

}
