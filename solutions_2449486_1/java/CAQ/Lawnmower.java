package gcj2013;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Lawnmower {
	static String PATH = "/home/caq/Desktop/gcj2013/qual/", PROBLEM = "B",
			SIZE = "large", ATTEMPT = "0";

	static boolean mapOK(int[][] map) {
		int N = map.length, M = map[0].length;
		// check each point
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				int number = map[j][k];
				boolean hasAGreater = false;
				for (int nn = 0; nn < N; nn++) {
					if (map[nn][k] > number) {
						hasAGreater = true;
						break;
					}
				}
				if (!hasAGreater)
					continue; // this point is valid
				hasAGreater = false;
				for (int mm = 0; mm < M; mm++) {
					if (map[j][mm] > number) {
						hasAGreater = true;
						break;
					}
				}
				if (!hasAGreater)
					continue; // this point is valid
				// this point is invalid
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) throws IOException {

		String filename = PATH + PROBLEM + "-" + SIZE;
		if (SIZE.equals("small"))
			filename += "-attempt" + ATTEMPT;
		Scanner sc = new Scanner(new File(filename + ".in"));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(filename + ".out"));
		int total = sc.nextInt();
		for (int i = 0; i < total; i++) {
			// each case
			int N = sc.nextInt(), M = sc.nextInt();
			int[][] map = new int[N][];
			for (int j = 0; j < N; j++) {
				map[j] = new int[M];
				for (int k = 0; k < M; k++) {
					map[j][k] = sc.nextInt();
				}
			}
			boolean result = mapOK(map);
			bw.write("Case #" + (i + 1) + ": " + (result ? "YES" : "NO"));
			bw.newLine();
		}

		bw.close();
		sc.close();
		System.out.println("Finished.");
	}

}
