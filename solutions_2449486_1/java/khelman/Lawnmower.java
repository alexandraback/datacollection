package pl.helman.codejam.lawnmower;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Lawnmower {

	public static void main(String[] args) throws IOException {

		FileReader fr = new FileReader("d:\\cj\\lawn.in");
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();

		FileWriter fo = new FileWriter("d:\\cj\\lawn.out");

		// number of cases
		int t = Integer.parseInt(line.trim());

		mainLoop: for (int i = 1; i <= t; i++) {

			// read lawn size
			line = br.readLine().trim();
			String[] elems = line.split(" ");
			int n = Integer.parseInt(elems[0]);
			int m = Integer.parseInt(elems[1]);

			int lawn[][] = new int[n][m];

			// initial calculations
			int verts[] = new int[m];
			int horiz[] = new int[n];

			for (int y = 0; y < n; y++) {
				horiz[y] = 0;
			}

			for (int x = 0; x < m; x++) {
				verts[x] = 0;
			}

			for (int y = 0; y < n; y++) {
				line = br.readLine().trim();
				elems = line.split(" ");

				for (int x = 0; x < m; x++) {
					lawn[y][x] = Integer.parseInt(elems[x]);

					if (lawn[y][x] > verts[x]) {
						verts[x] = lawn[y][x];
					}

					if (lawn[y][x] > horiz[y]) {
						horiz[y] = lawn[y][x];
					}
				}
			}
			
			for (int y = 0; y < n; y++) {
				for (int x = 0; x < m; x++) {
					if (lawn[y][x] < verts[x] && lawn[y][x] < horiz[y]) {
						fo.write("Case #" + i + ": NO\n");
						continue mainLoop;	
					}
				}
			}
			
			fo.write("Case #" + i + ": YES\n");

		}

		fr.close();
		fo.close();

	}

}
