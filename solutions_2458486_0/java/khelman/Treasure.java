package pl.helman.codejam.treasure;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Treasure {

	public static void main(String[] args) throws IOException {

		FileReader fr = new FileReader("d:\\cj\\trea.in");
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();

		FileWriter fo = new FileWriter("d:\\cj\\trea.out");

		// number of cases
		int t = Integer.parseInt(line.trim());

		for (int c = 1; c <= t; c++) {

			line = br.readLine().trim();
			String[] elems = line.split(" ");
			int k = Integer.parseInt(elems[0]);
			int n = Integer.parseInt(elems[1]);

			int initialKeys[] = new int[201];

			int neededKey[] = new int[n];
			int keys[][] = new int[n][];

			elems = br.readLine().trim().split(" ");
			for (int i = 0; i < k; i++) {
				initialKeys[Integer.parseInt(elems[i])]++;
			}

			for (int i = 0; i < n; i++) {
				elems = br.readLine().trim().split(" ");
				neededKey[i] = Integer.parseInt(elems[0]);

				int keyCount = Integer.parseInt(elems[1]);
				keys[i] = new int[201];

				for (int j = 0; j < keyCount; j++) {
					keys[i][Integer.parseInt(elems[2 + j])]++;
				}
			}

			// very sad algorithm
			int depth = 0;
			int path[] = new int[n+1];
			boolean used[][] = new boolean[n+1][n];
			int avaiableKeys[][] = new int[n+1][201];

			avaiableKeys[0] = initialKeys;
			
			path[0] = -1;

			while (depth >= 0 && depth<n) {
				path[depth]++;
				if (path[depth] >= n) {
					path[depth] = 0;
					depth--;
					continue;
				}

				if (used[depth][path[depth]]) {
					continue;
				}

				if (avaiableKeys[depth][neededKey[path[depth]]] == 0) {
					continue;
				}
				
				//this one is ok, so go further
				used[depth][path[depth]] = true;
				
				path[depth + 1] = -1;
				for (int i = 0; i < 201; i++) {
					avaiableKeys[depth+1][i] = avaiableKeys[depth][i] + keys[path[depth]][i];
				}
				
				for (int i = 0; i < n; i++) {
					used[depth+1][i] = used[depth][i];
				}
				
				avaiableKeys[depth + 1][neededKey[path[depth]]]--;
				
				depth++;
				
//				if(depth==10) {
//					for (int i = 0; i < depth && i < n; i++) {
//						System.out.print(" ");
//						System.out.print(path[i] + 1);
//						
//					}
//					System.out.println();
//				}
				
			}
			
			if (depth < 0) {
				System.out.println("Case #" + c + ": IMPOSSIBLE\n");
				fo.write("Case #" + c + ": IMPOSSIBLE\n");
			} else {
				System.out.print("Case #" + c + ":");
				fo.write("Case #" + c + ":");
				
				for (int i = 0; i < n; i++) {
					System.out.print(" ");
					System.out.print(path[i] + 1);
					
					fo.write(" " + (path[i] + 1));
				}
				
				System.out.println("\n");
				fo.write("\n");
			}


		}

		fr.close();
		fo.close();

	}

}
