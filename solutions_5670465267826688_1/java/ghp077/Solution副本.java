import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;



public class Solution {

//	1 i j k -1 -i -j -k
//	0 1 2 3  4  5  6  7

	public static final int[][] multiStructure = { { 0, 1, 2, 3, 4, 5, 6, 7 },
							{ 1, 4, 3, 6, 5, 0, 7, 2 },
							{ 2, 7, 4, 1, 6, 3, 0, 5 },
							{ 3, 2, 5, 4, 7, 6, 1, 0 },
							{ 4, 5, 6, 7, 0, 1, 2, 3 },
							{ 5, 0, 7, 2, 1, 4, 3, 6 },
							{ 6, 3, 0, 5, 2, 7, 4, 1 },
							{ 7, 6, 1, 0, 3, 2, 5, 4 } };
	public static int convert(char c) {
		switch (c) {
		case 'i':
			return 1;
		case 'j':
			return 2;
		case 'k':
			return 3;
		default:
			return 0;
		}
	}
	public static int multiply(int a, int b) {
		return multiStructure[a][b];
	}
	public static String dijkstra(ArrayList<Integer> list) {
		int ans = 0;
		boolean hasI = false;
		boolean hasK = false;
		for (int i = 0; i < list.size(); i++) {
			ans = multiply(ans, list.get(i));
			if (!hasI && ans == convert('i')) {
				hasI = true;
			}
			if (hasI && !hasK && ans == convert('k')) {
				hasK = true;
			}
		}
		return (ans == 4 && hasI && hasK) ? "YES" : "NO";
	}
	public static void C() throws IOException {
		File inf = new File("/Users/guanhaipeng/Documents/workspace/CodeJam/src/C-large.in");
		File outf = new File("/Users/guanhaipeng/Documents/workspace/CodeJam/src/output.txt");
		Scanner scanner = new Scanner(inf);
		BufferedReader in = new BufferedReader(new FileReader(inf));
		BufferedWriter out = new BufferedWriter(new FileWriter(outf));

		int caseNum = Integer.parseInt(in.readLine()) ;
		for (int i = 1; i <= caseNum; i++) {
			String string = "Case #" + i + ": ";
			// TODO
			String[] lx = in.readLine().split(" ");
			int L = Integer.parseInt(lx[0]);
			Long X = new Long(lx[1]);

			String line = in.readLine();
			int ans = 0;
			boolean hasI = false;
			boolean hasK = false;
			HashMap<Integer, Integer> ansSet = new HashMap<>();
			for (long j = 0; j < X; j++) {
				for (int j2 = 0; j2 < line.length(); j2++) {
					ans = multiply(ans, convert(line.charAt(j2)));
					if (!hasI && ans == convert('i')) {
						hasI = true;
					}
					if (hasI && !hasK && ans == convert('k')) {
						hasK = true;
					}
				}
				if (!ansSet.containsKey(ans)) {
					ansSet.put(ans, (int) (j));
				} else {
					break;
				}
			}
			if (!ansSet.containsKey(4)) {
				string += "NO";
			} else {
				int mod = ansSet.get(4);
				if ((X-1) % ansSet.size() != mod) {
					string += "NO";
				} else {
					string += (hasI && hasK) ? "YES" : "NO";
				}
			}
			// TODO
			System.out.println(string);
			out.write(string + "\n");
		}
		scanner.close();
		out.flush();
		out.close();
		in.close();
	}

	public static void main(String[] args) throws IOException {
		C();
	}

}
