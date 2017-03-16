import java.io.*;
import java.util.*;

public class probB {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(new File("input/B-large.in"));
		PrintWriter output = new PrintWriter(new File("output/probBres.out"));
		int lines = input.nextInt();
		input.nextLine();
		tests: for (int cline = 0; cline < lines; cline++) {
			System.out.println("On test case " + cline);
			output.print("Case #" + (cline+1) + ": ");
			int oH = input.nextInt();
			int n = input.nextInt();
			int m = input.nextInt();
			int[][] mapCeil = new int[n][m];
			int[][] mapFloor = new int[n][m];
			int[][] mapFill = new int[n][m];
			for (int i=0; i<n; i++) {
				for (int j=0; j<m; j++) {
					mapCeil[i][j] = input.nextInt();
				}
			}
			for (int i=0; i<n; i++) {
				for (int j=0; j<m; j++) {
					mapFloor[i][j] = input.nextInt();
					mapFill[i][j] = Integer.MAX_VALUE;
				}
			}
			boolean done = true;
			mapFill[0][0] = 0;
			//Navigate BEFORE the water starts to fall
			do {
				done = true;
				for (int i=0; i<n; i++) {
					for (int j=0; j<m; j++) {
						if (mapFill[i][j] != 0) continue;
						for (int x=0; x<4; x++) {
							int cN, cM;
							cN = cM = 0;
							switch (x) {
							case 0:
								cN = 1;
								break;
							case 1:
								cN = -1;
								break;
							case 2:
								cM = 1;
								break;
							case 3:
								cM = -1;
								break;
							}
							if (i + cN < 0 || i + cN >= n) continue;
							if (j + cM < 0 || j + cM >= m) continue;
							int max = Math.max(oH, Math.max(mapFloor[i][j], mapFloor[i+cN][j+cM]));
							if (mapCeil[i+cN][j+cM] - max < 50) continue;
							if (mapCeil[i][j] - max < 50) continue;
							if (mapCeil[i][j] - mapFloor[i+cN][j+cM] < 50) continue;
							if (mapFill[i+cN][j+cM] != 0) done = false;
							mapFill[i+cN][j+cM] = 0;
						}
					}
				}
				if (mapFill[n-1][m-1] == 0) {
					output.println("0.0");
					continue tests;
				}
			} while (!done);
			//Now start the actual simulation
			do {
				done = true;
				for (int i=0; i<n; i++) {
					for (int j=0; j<m; j++) {
						if (mapFill[i][j] == Integer.MAX_VALUE) continue;
						for (int x=0; x<4; x++) {
							int cN, cM;
							cN = cM = 0;
							switch (x) {
							case 0:
								cN = 1;
								break;
							case 1:
								cN = -1;
								break;
							case 2:
								cM = 1;
								break;
							case 3:
								cM = -1;
								break;
							}
							int time = mapFill[i][j];
							if (i + cN < 0 || i + cN >= n) continue;
							if (j + cM < 0 || j + cM >= m) continue;
							int h = oH - mapFill[i][j];
							h = Math.max(h, 0);
							if (mapCeil[i+cN][j+cM] - h < 50) {
								System.out.println("Waiting " + x + " " + (50 - (mapCeil[i+cN][j+cM] - h)));
								time += (50 - (mapCeil[i+cN][j+cM] - h));
								h = mapCeil[i+cN][j+cM]-50;
							}
							int max = Math.max(h, Math.max(mapFloor[i][j], mapFloor[i+cN][j+cM]));
							//But wait! If the water is the max, then we can opt to wait for it to drop a little!
							if (mapCeil[i+cN][j+cM] - max < 50) continue;
							if (mapCeil[i][j] - max < 50) continue;
							if (mapCeil[i][j] - mapFloor[i+cN][j+cM] < 50) continue;
							//You can move, determine time it takes
							if (h - mapFloor[i][j] >= 20) time += 10;
							else time += 100;
							System.out.println("Time is " + time);
							int value = Math.min(mapFill[i+cN][j+cM], time);
							System.out.println(value + " " + mapFill[i+cN][j+cM]);
							if (value != mapFill[i+cN][j+cM]) {
								mapFill[i+cN][j+cM] = value;
								done = false;
								System.out.println("CHanged");
							}
							
						}
					}
				}
			} while (!done);
			output.println(mapFill[n-1][m-1]/10.0);
		}
		output.close();
	}
}
