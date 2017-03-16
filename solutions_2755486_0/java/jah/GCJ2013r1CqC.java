package gcj;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

public class GCJ2013r1CqC {
	private static final int MAX_EAST = 1000000;
	private static final int MAX_WEST = -1000000;

	public static void main(String[] args) throws Exception {
		final String FILE_DIR = "/Users/jhorwitz/Downloads/";
		File inFile = new File(FILE_DIR + "C-small-attempt0.in");
		File outFile = new File(FILE_DIR + "gcj2013R1C-qC-s.txt");
		Writer writer = new FileWriter(outFile);
		Scanner scanner = new Scanner(inFile);

		int T = scanner.nextInt();
		for (int t = 1; t <= T; ++t) {
			int N = scanner.nextInt();

			long[] d = new long[N];
			long[] n = new long[N];
			long[] w = new long[N];
			long[] e = new long[N];
			long[] s = new long[N];
			long[] deltaD = new long[N];
			long[] deltaP = new long[N];
			long[] deltaS = new long[N];

			// initialize values to store boundaries
			long lastDayAllTribes = -1;
			long westernLimitAllTribes = MAX_EAST+1;
			long easternLimitAllTribes = MAX_WEST-1;

			for (int tribe = 0; tribe < N; ++tribe) {
				d[tribe] = scanner.nextLong();
				n[tribe] = scanner.nextLong();
				w[tribe] = scanner.nextLong();
				e[tribe] = scanner.nextLong();
				s[tribe] = scanner.nextLong();
				deltaD[tribe] = scanner.nextLong();
				deltaP[tribe] = scanner.nextLong();
				deltaS[tribe] = scanner.nextLong();

				long lastDayThisTribe = d[tribe] + n[tribe]*deltaD[tribe];
				lastDayAllTribes = Math.max(lastDayAllTribes, lastDayThisTribe);
				long westernLimitThisTribe;
				long easternLimitThisTribe;
				if (deltaP[tribe] > 0) { // tribe goes east
					westernLimitThisTribe = w[tribe];
					easternLimitThisTribe = e[tribe] + (n[tribe] - 1)*deltaP[tribe];
				} else { // tribe goes west
					westernLimitThisTribe = w[tribe] + (n[tribe] - 1)*deltaP[tribe];
					easternLimitThisTribe = e[tribe];
				}
				westernLimitAllTribes = Math.min(westernLimitAllTribes, westernLimitThisTribe);
				easternLimitAllTribes = Math.max(easternLimitAllTribes, easternLimitThisTribe);
			}

			long[] wallHeightWhereZeroMeansFarthestWest = new long[(int)(easternLimitAllTribes - westernLimitAllTribes)];
			long numSuccessfulAttacks = 0;
			for (int day = 0; day <= lastDayAllTribes; ++day) {
				long[] nextWallHeight = wallHeightWhereZeroMeansFarthestWest.clone();
				for (int tribe = 0; tribe < N; ++tribe) {
					boolean attackSucceeds = false;
					if (day < d[tribe] || day > d[tribe] + (n[tribe] - 1)*deltaD[tribe] || (day - d[tribe]) % deltaD[tribe] != 0) continue; // this tribe doesn't attack today

					long numAttacksSoFarFromThisTribe = (day - d[tribe]) / deltaD[tribe];

					long wForToday = w[tribe] + (numAttacksSoFarFromThisTribe)*deltaP[tribe];
					long eForToday = e[tribe] + (numAttacksSoFarFromThisTribe)*deltaP[tribe];
					long sForToday = s[tribe] + (numAttacksSoFarFromThisTribe)*deltaS[tribe];
					for (long posFromFarthestWest = wForToday-westernLimitAllTribes; posFromFarthestWest < eForToday-westernLimitAllTribes; ++posFromFarthestWest) {
						if (wallHeightWhereZeroMeansFarthestWest[(int)posFromFarthestWest] < sForToday) {
							attackSucceeds = true;
							nextWallHeight[(int)posFromFarthestWest] = sForToday;
						}
					}

					if(attackSucceeds) ++numSuccessfulAttacks;
				}
				wallHeightWhereZeroMeansFarthestWest = nextWallHeight;
			}

			output(writer, t, String.valueOf(numSuccessfulAttacks));
		}
		scanner.close();
		writer.close();
	}

	public static void output(Writer w, int t, String s) throws IOException {
		w.write("Case #" + t + ": " + s + "\n");
		System.out.println("Case #" + t + ": " + s);
	}
}